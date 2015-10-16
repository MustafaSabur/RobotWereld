#include "Widgets.hpp"

/**
 *
 */
std::string GetTextFromUser(	const std::string& aTitleBarMessage,
								const std::string& aMessage,
								const std::string& aDefaultValue /* = "" */,
								Window* aParent /* = NULL */,
								bool UNUSEDPARAM(centre) /* = false */,
								const Point& aPoint /* = DefaultPosition */)
{
	std::string text( STDSTRING( wxGetTextFromUser( WXSTRING( aTitleBarMessage), WXSTRING( aMessage), WXSTRING( aDefaultValue), aParent, aPoint.x, aPoint.y)));
	return text;
}

