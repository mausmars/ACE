#include "ace/Log_Msg.h"
// $Id$

#include "Logging_Acceptor.h"
#include "Logging_Handler.h"
#include "Reactor_Singleton.h"

// Initialize peer_acceptor object.

int
Logging_Acceptor::open (const ACE_INET_Addr &addr)
{
  // Reuse addr if already in use.
  if (this->peer_acceptor_.open (addr, 1) == -1)
    return -1;
  else
    return 0;
}

// Default constructor.

Logging_Acceptor::Logging_Acceptor (void)
{
}

// Performs termination activities.

int
Logging_Acceptor::handle_close (ACE_HANDLE, ACE_Reactor_Mask)
{
  return this->peer_acceptor_.close ();
}

Logging_Acceptor::~Logging_Acceptor (void)
{
  this->handle_close (ACE_INVALID_HANDLE, 
		      ACE_Event_Handler::READ_MASK);
}

// Returns underlying device descriptor.

ACE_HANDLE
Logging_Acceptor::get_handle (void) const
{ 
  return this->peer_acceptor_.get_handle (); 
}

// Accepts connections from client and registers new object with the
// ACE_Reactor.

int
Logging_Acceptor::handle_input (ACE_HANDLE)
{
  Logging_Handler *svc_handler = new Logging_Handler;

  // Accept the connection from a client client daemon.

  if (this->peer_acceptor_.accept (*svc_handler) == -1)
    ACE_ERROR_RETURN ((LM_ERROR, "%p", "accept failed"), -1);
  else if (svc_handler->open () == -1)
    svc_handler->close ();

  return 0;
}
