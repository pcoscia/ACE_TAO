// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:151

#ifndef _TAO_IDL_ORIG_IORTABLEC_H_
#define _TAO_IDL_ORIG_IORTABLEC_H_

#include /**/ "ace/pre.h"

#include "tao/corba.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "iortable_export.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO TAO_IORTable_Export

#if defined (TAO_EXPORT_NESTED_CLASSES)
#  if defined (TAO_EXPORT_NESTED_MACRO)
#    undef TAO_EXPORT_NESTED_MACRO
#  endif /* defined (TAO_EXPORT_NESTED_MACRO) */
#  define TAO_EXPORT_NESTED_MACRO TAO_IORTable_Export
#endif /* TAO_EXPORT_NESTED_CLASSES */

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option push -w-rvl -w-rch -w-ccc -w-inl
#endif /* __BORLANDC__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:48

TAO_NAMESPACE  IORTable
{
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_IORTABLE_LOCATOR__ODDS_N_ENDS_CH_)
#define _IORTABLE_LOCATOR__ODDS_N_ENDS_CH_
  
  class Locator;
  typedef Locator *Locator_ptr;
  struct tao_Locator_life;
  
  typedef
    TAO_Objref_Var_T<
        Locator,
        tao_Locator_life
      >
    Locator_var;
  
  typedef
    TAO_Objref_Out_T<
        Locator,
        tao_Locator_life
      >
    Locator_out;
  
  struct TAO_IORTable_Export tao_Locator_life
  {
    static Locator_ptr tao_duplicate (Locator_ptr);
    static void tao_release (Locator_ptr);
    static Locator_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Locator_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_IORTable_Export tao_Locator_cast
  {
    static Locator_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_IORTABLE_ALREADYBOUND_CH_)
#define _IORTABLE_ALREADYBOUND_CH_
  
  class TAO_IORTable_Export AlreadyBound : public CORBA::UserException
  {
  public:
    
    AlreadyBound (void);
    AlreadyBound (const AlreadyBound &);
    ~AlreadyBound (void);

    AlreadyBound &operator= (const AlreadyBound &);
    
    static AlreadyBound *_downcast (CORBA::Exception *);
    static CORBA::Exception *_alloc (void);

    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:51

#if !defined (_IORTABLE_NOTFOUND_CH_)
#define _IORTABLE_NOTFOUND_CH_
  
  class TAO_IORTable_Export NotFound : public CORBA::UserException
  {
  public:
    
    NotFound (void);
    NotFound (const NotFound &);
    ~NotFound (void);

    NotFound &operator= (const NotFound &);
    
    static NotFound *_downcast (CORBA::Exception *);
    static CORBA::Exception *_alloc (void);

    virtual CORBA::Exception *_tao_duplicate (void) const;

    virtual void _raise (void);

    virtual void _tao_encode (
        TAO_OutputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      ) const;
    
    virtual void _tao_decode (
        TAO_InputCDR &
        ACE_ENV_ARG_DECL_NOT_USED
      );
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/exception_ch.cpp:125
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_interface.cpp:567

#if !defined (_IORTABLE_TABLE__ODDS_N_ENDS_CH_)
#define _IORTABLE_TABLE__ODDS_N_ENDS_CH_
  
  class Table;
  typedef Table *Table_ptr;
  struct tao_Table_life;
  
  typedef
    TAO_Objref_Var_T<
        Table,
        tao_Table_life
      >
    Table_var;
  
  typedef
    TAO_Objref_Out_T<
        Table,
        tao_Table_life
      >
    Table_out;
  
  struct TAO_IORTable_Export tao_Table_life
  {
    static Table_ptr tao_duplicate (Table_ptr);
    static void tao_release (Table_ptr);
    static Table_ptr tao_nil (void);
    static CORBA::Boolean tao_marshal (
        Table_ptr,
        TAO_OutputCDR &
      );
  };
  
  struct TAO_IORTable_Export tao_Table_cast
  {
    static Table_ptr tao_narrow (
        CORBA::Object_ptr
        ACE_ENV_ARG_DECL
      );
    static CORBA::Object_ptr tao_upcast (void *);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IORTABLE_TABLE_CH_)
#define _IORTABLE_TABLE_CH_
  
  class TAO_IORTable_Export Table
    : public virtual CORBA::Object
  {
  public:
    typedef Table_ptr _ptr_type;
    typedef Table_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static Table_ptr _duplicate (Table_ptr obj);
    
    static Table_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Table_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Table_ptr _nil (void)
      {
        return (Table_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void bind (
        const char * object_key,
        const char * IOR
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , IORTable::AlreadyBound
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void rebind (
        const char * object_key,
        const char * IOR
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void unbind (
        const char * object_key
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , IORTable::NotFound
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual void set_locator (
        IORTable::Locator_ptr the_locator
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    Table (void);
    virtual ~Table (void);
  
  private:
    Table (const Table &);
    void operator= (const Table &);
  };

#endif /* end #if !defined */
  
  // TAO_IDL - Generated from
  // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:54

#if !defined (_IORTABLE_LOCATOR_CH_)
#define _IORTABLE_LOCATOR_CH_
  
  class TAO_IORTable_Export Locator
    : public virtual CORBA::Object
  {
  public:
    typedef Locator_ptr _ptr_type;
    typedef Locator_var _var_type;
    static int _tao_class_id;
    
    // The static operations.
    static Locator_ptr _duplicate (Locator_ptr obj);
    
    static Locator_ptr _narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Locator_ptr _unchecked_narrow (
        CORBA::Object_ptr obj
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      );
    
    static Locator_ptr _nil (void)
      {
        return (Locator_ptr)0;
      }
    
    
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_operation/operation_ch.cpp:46
    
    virtual char * locate (
        const char * object_key
        ACE_ENV_ARG_DECL_WITH_DEFAULTS
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException
        , IORTable::NotFound
      )) = 0;
    
    // TAO_IDL - Generated from
    // W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_interface/interface_ch.cpp:211
    
    virtual void *_tao_QueryInterface (ptrdiff_t type);
    
    virtual const char* _interface_repository_id (void) const;
    virtual CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    Locator (void);
    virtual ~Locator (void);
  
  private:
    Locator (const Locator &);
    void operator= (const Locator &);
  };

#endif /* end #if !defined */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_module/module_ch.cpp:67

}
TAO_NAMESPACE_CLOSE // module IORTable

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:48

#ifndef __ACE_INLINE__

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORTable_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IORTable::AlreadyBound &);
TAO_IORTable_Export CORBA::Boolean operator>> (TAO_InputCDR &, IORTable::AlreadyBound &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_exception/cdr_op_ch.cpp:52

TAO_IORTable_Export CORBA::Boolean operator<< (TAO_OutputCDR &, const IORTable::NotFound &);
TAO_IORTable_Export CORBA::Boolean operator>> (TAO_InputCDR &, IORTable::NotFound &);

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_visitor_root/cdr_op.cpp:64

#endif /* __ACE_INLINE__ */

// TAO_IDL - Generated from
// W:\ACE_wrappers\TAO\TAO_IDL\be\be_codegen.cpp:1018

#if defined (__ACE_INLINE__)
#include "IORTableC.i"
#endif /* defined INLINE */

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif /* _MSC_VER */

#if defined (__BORLANDC__)
#pragma option pop
#endif /* __BORLANDC__ */

#include /**/ "ace/post.h"
#endif /* ifndef */

