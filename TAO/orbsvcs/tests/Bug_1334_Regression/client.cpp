//
// $Id$
//
#include "tao/corba.h"

// Attempts to resolve the NameService.
// Returns:
//    0  if the NameService was resolved
//    1  if the NameService could not be resolved
//    2  if something else went wrong
//
int main( int argc, char *argv[] )
{
   try
   {
      CORBA::ORB_var orb = CORBA::ORB_init( argc, argv ) ;

      try
      {
         CORBA::Object_var naming =
            orb->resolve_initial_references( "NameService" ) ;
         if( CORBA::is_nil( naming.in() ) )
         {
            return 1 ;
         }
      }
      catch( CORBA::Exception& e )
      {
         return 1 ;
      }
   }
   catch( CORBA::Exception& e )
   {
      return 2 ;
   }

   return 0 ;
}
