//
// $Id$
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    sequence_ch.cpp
//
// = DESCRIPTION
//    Visitor generating code for Sequence in the client header
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

ACE_RCSID (be_visitor_sequence, 
           sequence_ch, 
           "$Id$")

// Root visitor for client header.
be_visitor_sequence_ch::be_visitor_sequence_ch (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_sequence_ch::~be_visitor_sequence_ch (void)
{
}

int be_visitor_sequence_ch::visit_sequence (be_sequence *node)
{
  if (node->defined_in () == 0)
    {
      // The node is a nested sequence, and has had no scope defined.
      node->set_defined_in (DeclAsScope (this->ctx_->scope ()));
    }

  // First create a name for ourselves.
  if (node->create_name (this->ctx_->tdef ()) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ch::"
                         "visit_sequence - "
                         "failed creating name\n"), 
                        -1);
    }

  if (node->cli_hdr_gen () || node->imported ())
    {
      return 0;
    }

  be_type *bt = 0;
  TAO_OutStream *os = this->ctx_->stream ();

  // Retrieve the base type since we may need to do some code
  // generation for the base type.
  bt = be_type::narrow_from_decl (node->base_type ());

  if (bt == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "(%N:%l) be_visitor_sequence_ch::"
                         "visit_sequence - "
                         "Bad element type\n"), 
                        -1);
    }

  *os << be_nl << be_nl << "// TAO_IDL - Generated from" << be_nl
      << "// " << __FILE__ << ":" << __LINE__;

  // Generate the appropriate sequence type.
  switch (node->managed_type ())
    {
    case be_sequence::MNG_OBJREF:
      {
        be_interface *elem = be_interface::narrow_from_decl (bt);

        if (node->unbounded ())
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Unbounded_Object_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life," << be_nl
                << elem->fwd_helper_name () << "_cast" << be_uidt_nl
                << "> " << node->local_name () << ";" << be_uidt << be_uidt;
          }
        else
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Bounded_Object_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life," << be_nl
                << elem->fwd_helper_name () << "_cast," << be_nl
                << node->max_size ()->ev ()->u.ulval << be_uidt_nl
                << "> " << node->local_name () << ";" << be_uidt << be_uidt;
          }

        // Generate the _var and _out types only if we are not anonymous.
        if (this->ctx_->tdef () != 0)
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_VarSeq_Var_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << "TAO_Object_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_var;" << be_uidt << be_uidt;

            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Seq_Out_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << node->local_name () << "_var," << be_nl
                << "TAO_Object_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_out;" << be_uidt << be_uidt;
          }
      }

      break;
    case be_sequence::MNG_ABSTRACT:
      {
        be_interface *elem = be_interface::narrow_from_decl (bt);

        if (node->unbounded ())
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Unbounded_Abstract_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << "> " << node->local_name () << ";" << be_uidt << be_uidt;
          }
        else
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Bounded_Object_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life," << be_nl
                << node->max_size ()->ev ()->u.ulval << be_uidt_nl
                << "> " << node->local_name () << ";" << be_uidt << be_uidt;
          }

        // Generate the _var and _out types only if we are not anonymous.
        if (this->ctx_->tdef () != 0)
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_VarSeq_Var_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << "TAO_Abstract_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_var;" << be_uidt << be_uidt;

            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Seq_Out_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << node->local_name () << "_var," << be_nl
                << "TAO_Abstract_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_out;" << be_uidt << be_uidt;
          }
      }

      break;
    case be_sequence::MNG_PSEUDO:
      if (node->unbounded ())
        {
        }
      else
        {
        }

      break;
    case be_sequence::MNG_VALUE:
      {
        be_interface *elem = be_interface::narrow_from_decl (bt);

        if (node->unbounded ())
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Unbounded_Valuetype_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt_nl
                << node->local_name () << ";" << be_uidt;
          }
        else
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Bounded_Valuetype_Sequence<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life," << be_nl
                << node->max_size ()->ev ()->u.ulval << be_uidt_nl
                << ">" << be_uidt_nl
                << node->local_name () << ";" << be_uidt;
          }

        // Generate the _var and _out types only if we are not anonymous.
        if (this->ctx_->tdef () != 0)
          {
            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_VarSeq_Var_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << "TAO_Valuetype_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_var;" << be_uidt << be_uidt;

            *os << be_nl << be_nl
                << "typedef" << be_idt_nl
                << "TAO_Seq_Out_T<" << be_idt << be_idt_nl
                << node->local_name () << "," << be_nl
                << node->local_name () << "_var," << be_nl
                << "TAO_Valuetype_Manager<" << be_idt << be_idt_nl
                << bt->name () << "," << be_nl
                << bt->name () << "_var," << be_nl
                << elem->fwd_helper_name () << "_life" << be_uidt_nl
                << ">" << be_uidt << be_uidt_nl
                << "> " << node->local_name () << "_out;" << be_uidt << be_uidt;
          }
      }

      break;
    case be_sequence::MNG_STRING:
      if (node->unbounded ())
        {
        }
      else
        {
        }

      break;
    case be_sequence::MNG_WSTRING:
      if (node->unbounded ())
        {
        }
      else
        {
        }

      break;
    default: // Not a managed type.
      if (bt->base_node_type () == AST_Decl::NT_array)
        {
          if (node->unbounded ())
            {
              *os << be_nl << be_nl
                  << "typedef" << be_idt_nl
                  << "TAO_Unbounded_Array_Sequence<"
                  << be_idt << be_idt_nl
                  << bt->name () << "," << be_nl
                  << bt->fwd_helper_name () << "_life" << be_uidt_nl
                  << ">" << be_uidt_nl
                  << node->local_name () << ";" << be_uidt;
            }
          else
            {
              *os << be_nl << be_nl
                  << "typedef" << be_idt_nl
                  << "TAO_Bounded_Array_Sequence<"
                  << be_idt << be_idt_nl
                  << bt->name () << "," << be_nl
                  << bt->fwd_helper_name () << "_life," << be_nl
                  << node->max_size ()->ev ()->u.ulval << be_uidt_nl
                  << ">" << be_uidt_nl
                  << node->local_name () << ";" << be_uidt;
            }
        }
      else
        {
          if (node->unbounded ())
            {
              *os << be_nl << be_nl
                  << "typedef" << be_idt_nl
                  << "TAO_Unbounded_Sequence<" << be_idt << be_idt_nl
                  << bt->name () << be_uidt_nl
                  << ">" << be_uidt_nl
                  << node->local_name () << ";" << be_uidt;
            }
          else
            {
              *os << be_nl << be_nl
                  << "typedef" << be_idt_nl
                  << "TAO_Bounded_Sequence<" << be_idt << be_idt_nl
                  << bt->name () << "," << be_nl
                  << node->max_size ()->ev ()->u.ulval << be_uidt_nl
                  << ">" << be_uidt_nl
                  << node->local_name () << ";" << be_uidt;
            }
        }

      // Generate the _var and _out types only if we are not anonymous.
      if (this->ctx_->tdef () != 0)
        {
          AST_Type::SIZE_TYPE st = bt->size_type ();

          *os << be_nl << be_nl
              << "typedef" << be_idt_nl
              << (st == AST_Type::FIXED ? "TAO_FixedSeq_Var_T<" 
                                        : "TAO_VarSeq_Var_T<")
              << be_idt << be_idt_nl
              << node->local_name () << "," << be_nl
              << bt->name () << be_uidt_nl
              << ">" << be_uidt_nl
              << node->local_name () << "_var;" << be_uidt;

          *os << be_nl << be_nl
              << "typedef" << be_idt_nl
              << "TAO_Seq_Out_T<" << be_idt << be_idt_nl
              << node->local_name () << "," << be_nl
              << node->local_name () << "_var," << be_nl
              << bt->name () << be_uidt_nl
              << ">" << be_uidt_nl
              << node->local_name () << "_out;" << be_uidt;
        }

      break;
    }

  node->cli_hdr_gen (1);
  return 0;
}

