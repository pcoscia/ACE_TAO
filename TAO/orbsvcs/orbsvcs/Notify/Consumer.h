/* -*- C++ -*- */
/**
 *  @file Consumer.h
 *
 *  $Id$
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_CONSUMER_H
#define TAO_Notify_CONSUMER_H
#include /**/ "ace/pre.h"

#include "notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/CosNotifyCommC.h"
#include "orbsvcs/CosNotificationC.h"
#include "Peer.h"
#include "Event.h"

class TAO_Notify_ProxySupplier;
class TAO_Notify_Proxy;

/**
 * @class TAO_Notify_Consumer
 *
 * @brief Astract Base class for wrapping consumer objects that connect to the EventChannel
 *
 */
class TAO_Notify_Export TAO_Notify_Consumer : public TAO_Notify_Peer
{
public:
  /// Constuctor
  TAO_Notify_Consumer (TAO_Notify_ProxySupplier* proxy);

  /// Destructor
  virtual ~TAO_Notify_Consumer ();

  /// Access Specific Proxy.
  TAO_Notify_ProxySupplier* proxy_supplier (void);

  /// Access Base Proxy.
  virtual TAO_Notify_Proxy* proxy (void);

  /// Push <event> to this consumer.
  void push (const TAO_Notify_Event* event ACE_ENV_ARG_DECL);

  /// Push <event> to this consumer.
  void push (const TAO_Notify_Event_var& event ACE_ENV_ARG_DECL);

  /// Push <event> to this consumer.
  virtual void push (const CORBA::Any& event ACE_ENV_ARG_DECL) = 0;

  /// Push <event> to this consumer.
  virtual void push (const CosNotification::StructuredEvent& event ACE_ENV_ARG_DECL) = 0;

  /// Dispatch the pending events
  void dispatch_pending (ACE_ENV_SINGLE_ARG_DECL);

  /// Is the connection suspended?
  CORBA::Boolean is_suspended (void);

  /// Suspend Connection
  void suspend (ACE_ENV_SINGLE_ARG_DECL);

  /// Resume Connection
  void resume (ACE_ENV_SINGLE_ARG_DECL);

protected:
  // Dispatch updates
  virtual void dispatch_updates_i (const CosNotification::EventTypeSeq& added,
                                   const CosNotification::EventTypeSeq& removed
                                   ACE_ENV_ARG_DECL);

  /// Push Implementation.
  virtual void push_i (const TAO_Notify_Event* event ACE_ENV_ARG_DECL) = 0;

  /// Push Implementation.
  virtual void push_i (const TAO_Notify_Event_var& event ACE_ENV_ARG_DECL) = 0;

  /// Get the shared Proxy Lock
  TAO_SYNCH_MUTEX* proxy_lock (void);

  /// The Proxy that we associate with.
  TAO_Notify_ProxySupplier* proxy_;

  /// Events pending to be delivered.
  TAO_Notify_Event_Collection* event_collection_;

  /// Suspended Flag.
  CORBA::Boolean is_suspended_;

  /// Interface that accepts offer_changes
  CosNotifyComm::NotifyPublish_var publish_;
};

#if defined (__ACE_INLINE__)
#include "Consumer.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* TAO_Notify_CONSUMER_H */
