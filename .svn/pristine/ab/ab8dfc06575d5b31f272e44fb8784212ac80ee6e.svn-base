#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include <functional>

/**
 *
 * @param aParent
 * @param aLabel
 * @param anActionFunction
 * @param
 * @return
 */
Button* makeButton( 	Window* aParent,
						const std::string& aLabel,
						const std::function< void( CommandEvent&) >& anActionFunction)
{
	Button* button = new Button( aParent, DEFAULT_ID, WXSTRING(aLabel));
	button->Bind(wxEVT_COMMAND_BUTTON_CLICKED, anActionFunction);
	return button;
}

#endif // DANU_BUTTON_HPP_
