#include "WidgetDebugTraceFunction.hpp"
#include "LogTextCtrl.hpp"

WidgetDebugTraceFunction::WidgetDebugTraceFunction( LogTextCtrl* aLogTextCtrl) :
				outputControl( aLogTextCtrl)
{
}

WidgetDebugTraceFunction::~WidgetDebugTraceFunction()
{
}

void WidgetDebugTraceFunction::trace( const std::string& aText)
{
	// create any type of command event here
	CommandEvent event( wxEVT_COMMAND_MENU_SELECTED, TRACE_EVENT);
	event.SetString( WXSTRING( aText));

	// TODO: should we decide this runtime?
	// Send in a thread-safe way
	// As we need synchronous handling of the trace (otherwise we loose
	// messages in case of a crash) we use ProcessEvent. It will
	// slow down the application though.
	//         outputCtrl->ProcessEvent(event);
	// In case we can get away with asynchronous event handling
	wxPostEvent( outputControl, event);
}

