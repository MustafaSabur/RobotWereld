#ifndef WIDGETDEBUGTRACEFUNCTION_HPP_
#define WIDGETDEBUGTRACEFUNCTION_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include "DebugTraceFunction.hpp"

class LogTextCtrl;

/**
 *
 */
class WidgetDebugTraceFunction : public DebugTraceFunction
{
	public:
		/**
		 * @param aLogTextCtrl The TextCtrl derived class that will receive the trace string as message
		 * @param useFile If true the trace will also be logged in the file "guitrace.log".
		 */
		WidgetDebugTraceFunction( LogTextCtrl* aLogTextCtrl);
		/**
		 *
		 */
		virtual ~WidgetDebugTraceFunction();

		/**
		 *
		 * @param aText The text that will be send to the final trace destination.
		 */
		virtual void trace( const std::string& aText);
	private:
		/**
		 *
		 */
		LogTextCtrl* outputControl;
};

#endif // WIDGETDEBUGTRACEFUNCTION_HPP_
