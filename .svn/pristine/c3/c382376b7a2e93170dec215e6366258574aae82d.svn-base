#ifndef NOTIFICATIONEVENT_HPP_
#define NOTIFICATIONEVENT_HPP_

#include "Config.hpp"
#include "Widgets.hpp"

#define EVT_NOTIFICATION(id, fn) \
    DECLARE_EVENT_TABLE_ENTRY( wxEVT_NOTIFICATIONEVENT, id, -1, \
    (wxObjectEventFunction) (wxEventFunction) (wxCommandEventFunction) (wxNotifyEventFunction) \
    wxStaticCastEvent( NotificationEventFunction, & fn ), (wxObject *) NULL ),

extern const wxEventType wxEVT_NOTIFICATIONEVENT;

typedef void (wxEvtHandler::*NotificationEventFunction)( NotifyEvent&);

#endif // NOTIFICATIONEVENT_HPP_
