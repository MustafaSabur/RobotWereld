#ifndef ACTIONFUNCTIONTYPETRAITS_HPP_
#define ACTIONFUNCTIONTYPETRAITS_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include <functional>

struct ActionFunctionTypeTraitsTracing
{
};

template< typename ActionFunction >
struct ActionFunctionTypeTraits
{
		void call( 	ActionFunction& anActionFunction,
					CommandEvent&)
		{
			anActionFunction();
		}
};

template< >
struct ActionFunctionTypeTraits< std::function< void( CommandEvent&) > >
{
		void call( 	std::function< void( CommandEvent&) >& anActionFunction,
					CommandEvent& event)
		{
			anActionFunction( event);
		}
};
/**
 * Dummy function to allow for usage of not-yet implemented
 * std::function<void (CommandEvent&)> functions
 * @param
 */
void Ooops( CommandEvent&);

#endif /* ACTIONFUNCTIONTYPETRAITS_HPP_ */
