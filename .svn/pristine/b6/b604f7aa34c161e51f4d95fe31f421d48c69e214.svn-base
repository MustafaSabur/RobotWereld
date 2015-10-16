#include "Logger.hpp"
#include "MainApplication.hpp"
#include "MainFrameWindow.hpp"
#include "WidgetDebugTraceFunction.hpp"

/* static */bool Logger::disable = false;
/**
 *
 */
/*static*/void Logger::log( const std::string& aMessage)
{
	MainFrameWindow* frame = dynamic_cast< MainFrameWindow* >( TheApp().GetTopWindow());
	if (frame && !disable)
	{
		frame->getTraceFunction()->trace( aMessage);
	}
}
/**
 *
 */
/* static */void Logger::setDisable( bool aDisable /*= true*/)
{
	disable = aDisable;
}
