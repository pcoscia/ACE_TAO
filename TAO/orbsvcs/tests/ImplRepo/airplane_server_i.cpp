// $Id$

#include "airplane_server_i.h"
#include "ace/Get_Opt.h"
#include "ace/Read_Buffer.h"

ACE_RCSID(ImplRepo, airplane_server_i, "$Id$")

Airplane_Server_i::Airplane_Server_i (void)
  : server_impl_ (0),
    ior_output_file_ (0),
    ir_helper_ (0),
    use_ir_ (0)
{
  // Nothing
}

int
Airplane_Server_i::parse_args (void)
{
  ACE_Get_Opt get_opts (this->argc_, this->argv_, "do:i");
  int c;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'd':  // debug flag.
        TAO_debug_level++;
        break;
      case 'i':  // Use the IR
        this->use_ir_ = 1;
        break;
      case 'o':  // output the IOR to a file.
        this->ior_output_file_ = ACE_OS::fopen (get_opts.optarg, "w");
        if (this->ior_output_file_ == 0)
          ACE_ERROR_RETURN ((LM_ERROR,
                             "Unable to open %s for writing: %p\n",
                             get_opts.optarg), -1);
        break;
      case '?':  // display help for use of the server.
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-d]"
                           " [-i]"
                           " [-o] <ior_output_file>"
                           "\n",
                           argv_ [0]),
                          1);
      }

  // Indicates successful parsing of command line.
  return 0;
}

int
Airplane_Server_i::init (int argc, char** argv, CORBA::Environment &ACE_TRY_ENV)
{
  char poa_name[] = "plane";

  ACE_TRY 
    {
      // Call the init of <TAO_ORB_Manager> to initialize the ORB and
      // create a child POA under the root POA.
      if (this->orb_manager_.init_child_poa (argc, argv, poa_name, ACE_TRY_ENV) == -1)
        ACE_ERROR_RETURN ((LM_ERROR, "%p\n", "init_child_poa"), -1);

      ACE_TRY_CHECK;
    
      this->argc_ = argc;
      this->argv_ = argv;

      int retval = this->parse_args ();

      if (retval != 0)
        return retval;

      ACE_NEW_RETURN (this->server_impl_, Airplane_i (this->use_ir_), -1);

      CORBA::String_var server_str  =
        this->orb_manager_.activate_under_child_poa ("server",
                                                     this->server_impl_,
                                                     ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (this->use_ir_ == 1)
        ACE_NEW_RETURN (this->ir_helper_, IR_Helper (poa_name,
                                                     this->orb_manager_.child_poa (),
                                                     this->orb_manager_.orb (),
                                                     TAO_debug_level),
                        -1);

      PortableServer::ObjectId_var id =
        PortableServer::string_to_ObjectId ("server");

      CORBA::Object_var server_obj =
        this->orb_manager_.child_poa ()->id_to_reference (id.in (),
                                                          ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (this->use_ir_ == 1)
        {
          this->ir_helper_->change_object (server_obj.inout (), ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }
       
      server_str =
        this->orb_manager_.orb ()->object_to_string (server_obj.in (),
                                                     ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (TAO_debug_level > 0)
        ACE_DEBUG ((LM_DEBUG, "The IOR is: <%s>\n", server_str.in ()));

      if (this->ior_output_file_)
        {
          ACE_OS::fprintf (this->ior_output_file_, "%s", server_str.in ());
          ACE_OS::fclose (this->ior_output_file_);
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Airplane_i::init");
      ACE_RETHROW;
    }
  ACE_ENDTRY;
  
  ACE_CHECK_RETURN (-1);

  return 0;
}

int
Airplane_Server_i::run (CORBA::Environment &ACE_TRY_ENV)
{
  ACE_TRY
    {
      if (this->use_ir_ == 1)
        {
          this->ir_helper_->notify_startup (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }

      this->orb_manager_.run (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      if (this->use_ir_ == 1)
        {
          this->ir_helper_->notify_shutdown (ACE_TRY_ENV);
          ACE_TRY_CHECK;
        }
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION, "Airplane_Server_i::run");
      ACE_RETHROW;
    }
  ACE_ENDTRY;
  
  ACE_CHECK_RETURN (-1);

  return 0;
}

Airplane_Server_i::~Airplane_Server_i (void)
{
  delete this->ir_helper_;
  delete this->server_impl_;
}
