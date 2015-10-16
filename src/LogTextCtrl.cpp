#include "LogTextCtrl.hpp"

/**
 *
 */
LogTextCtrl::LogTextCtrl( 	Window* aParent,
							WindowId aWindowId /*  = DEFAULT_ID */,
							long aStyle /* = wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP */,
							const std::string& anInitialText /* = "" */,
							const Point& aPoint /* = DefaultPosition */,
							const Size& aSize /* = DefaultSize */) :
				wxTextCtrl( aParent, aWindowId, WXSTRING( anInitialText), aPoint, aSize, aStyle)
{
	Connect( TRACE_EVENT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( LogTextCtrl::trace));
}
/**
 *
 */
LogTextCtrl::~LogTextCtrl()
{
}
/**
 *
 */
void LogTextCtrl::log( const std::string& aString)
{
	AppendText( WXSTRING( aString + "\n"));
}
/**
 *
 */
void LogTextCtrl::trace( CommandEvent& anEvent)
{
	log( STDSTRING( anEvent.GetString()));
}
