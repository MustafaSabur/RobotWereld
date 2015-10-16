#ifndef NOTIFICATIONHANDLER_HPP_
#define NOTIFICATIONHANDLER_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include "NotificationFunctionTypeTraits.hpp"
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "NotificationEvent.hpp"

/*
 *
 */
template< typename NotificationFunction >
class NotificationHandler : public EventHandler
{
	public:
		NotificationHandler( const NotificationFunction& aNotificationFunction) :
						function( aNotificationFunction)
		{
			Connect( wxEVT_NOTIFICATIONEVENT, (wxObjectEventFunction)(wxEventFunction)static_cast< NotificationEventFunction >( &NotificationHandler::OnNotificationEvent));
		}
		virtual ~NotificationHandler()
		{
		}
		/**
		 *
		 */
		void OnNotificationEvent( NotifyEvent& aNotifyEvent)
		{
			NotificationFunctionTypeTraits< NotificationFunction > caller;
			caller.call( function, aNotifyEvent);
		}
	private:
		NotificationFunction function;
};

#endif // NOTIFICATIONHANDLER_HPP_
