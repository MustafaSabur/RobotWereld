#ifndef LOGTEXTCTRL_HPP_
#define LOGTEXTCTRL_HPP_

#include "Config.hpp"
#include "Widgets.hpp"

enum
{
	TRACE_EVENT = 1000
};

/**
 * A text widget that accepts the tracing of a trace function.
 */
class LogTextCtrl : public wxTextCtrl
{
	public:
		/**
		 * @name Constructors and destructor
		 */
		//@{
		/**
		 *
		 */
		LogTextCtrl( 	Window* aParent,
						WindowId aWindowId = DEFAULT_ID,
						long aStyle = wxTE_READONLY | wxTE_MULTILINE | wxTE_DONTWRAP,
						const std::string& anInitialText = "",
						const Point& aPoint = DefaultPosition,
						const Size& aSize = DefaultSize);
		virtual ~LogTextCtrl();
		//@}
		/**
		 *
		 * @param aString
		 */
		virtual void log( const std::string& aString);
	protected:
		/**
		 *
		 * @param anEvent
		 */
		virtual void trace( CommandEvent& anEvent);
	private:
};
// class LogTextCtrl

#endif // LOGTEXTCTRL_HPP_
