// This may look like C, but it's really -*- C++ -*-
//
// ============================================================================
//
// = LIBRARY
//    TAO
// 
// = FILENAME
//    corba.h
//
// = DESCRIPTION
//     MASTER HEADER file for C/C++ Win32 interface to a CORBA 2.0 ORB.
//     Include only this file, to see all ORB interfaces declared.
//
//     This interface uses COM as the basis for its binary standard,
//     and follows the OMG C++ mapping for compilers which don't
//     support C++ exceptions (COM doesn't use them) or namespaces.
//     Objects which are implemented using this source base support
//     OLE Automation.
//
//     XXX Note re status of this as reference, cosubmitted with RFP?
//
// = AUTHOR
//     Copyright 1994-1995 by Sun Microsystems Inc.
// 
// ============================================================================

#if !defined(TAO_CORBA_H)
#define TAO_CORBA_H

// ACE specific includes
#include "ace/OS.h"
#include "ace/Get_Opt.h"
#include "ace/Log_Msg.h"
#include "ace/SOCK_Stream.h"
#include "ace/Synch_T.h"
#include "ace/ACE.h"
#include "ace/Synch.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/SString.h"
#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/SOCK_Connector.h"
#include "ace/Strategies.h"
#include "ace/Connector.h"
#include "ace/Singleton.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Synch.h"
#include "ace/Svc_Handler.h"

// COM stuff
#include <objbase.h>
#include <initguid.h>

// ORB configuration
#include "tao/orbconf.h"

#include "tao/orb.h"

// Alignment macros
#include "tao/align.h"

// Defines CORBA namespace
#include "tao/corbacom.h"

// individual CORBA classes
#include "tao/sequence.h"
#include "tao/varout.h"
#include "tao/any.h"
#include "tao/poa.h"

#include "tao/params.h"
#include "tao/client_factory.h"
#include "tao/client_factory.h"
#include "tao/server_factory.h"
#include "tao/default_client.h"
#include "tao/default_server.h"

#include "tao/except.h"
#include "tao/orbobj.h"
#include "tao/nvlist.h"
#include "tao/object.h"
#include "tao/orbobj.h"
#include "tao/principa.h"
#include "tao/request.h"
#include "tao/svrrqst.h"
#include "tao/typecode.h"

// Marshaling
#include "tao/marshal.h"
#include "tao/cdr.h"
#include "tao/stub.h"

// TAO specific includes
#include "tao/connect.h"
#include "tao/orb_core.h"
#include "tao/objtable.h"
#include "tao/optable.h"
#include "tao/debug.h"

// GIOP - IIOP related includes 
#include "tao/iiopobj.h"
#include "tao/iioporb.h"
#include "tao/giop.h"

//#include "tao/xdr.h"

// The following *.i files are always included here
#  if !defined(__ACE_INLINE__)
#    undef ACE_INLINE
#    define ACE_INLINE inline
#    define do_undef_on_ACE_INLINE
#  endif

#include "tao/orb_core.i"
#include "tao/corbacom.i"
#include "tao/sequence.i"
#include "tao/typecode.i"
#include "tao/any.i"
#include "tao/cdr.i"
#include "tao/stub.i"
#include "tao/object.i"
#include "tao/orbobj.i"
#include "tao/marshal.i"
#include "tao/poa.i"
#include "tao/giop.i"
#include "tao/iioporb.i"
#include "tao/iiopobj.i"

#  if defined (do_undef_on_ACE_INLINE)
#    undef do_undef_on_ACE_INLINE
#    undef ACE_INLINE
#    define ACE_INLINE
#  endif /* do_undef_on_ACE_INLINE */

// the following *.i files are conditionally included here
#if defined (__ACE_INLINE__)
#include "tao/params.i"
#include "tao/server_factory.i"
#include "tao/default_client.i"
#include "tao/default_server.i"
#include "tao/connect.i"
#endif /* __ACE_INLINE__ */

#if defined (__ACE_INLINE__)
#endif /* __ACE_INLINE__ */

#include "tao/singletons.h"

#if !defined (ACE_NESTED_CLASS)
#if defined (ACE_WIN32)
#define ACE_NESTED_CLASS(SCOPE,CLASS) CLASS
#else /* !ACE_WIN32 */
#define ACE_NESTED_CLASS(SCOPE,CLASS) SCOPE::CLASS
#endif /* ACE_WIN32 */
#endif /* ACE_NESTED_CLASS */

#endif /* TAO_CORBA_H */
