#include "Observer.hpp"
#include "Notifier.hpp"

/**
 *
 */
Observer::Observer()
{
}
/**
 *
 */
Observer::~Observer()
{
}
/**
 *
 */
bool Observer::operator==( const Observer& aObserver) const
{
	return this == &aObserver;
}
/**
 *
 */
bool Observer::operator<( const Observer& aObserver) const
{
	return this < &aObserver;
}
/**
 *
 */
void Observer::handleNotificationsFor( Notifier& aNotifier)
{
	aNotifier.addObserver( *this);
}
/**
 *
 */
void Observer::stopHandlingNotificationsFor( Notifier& aNotifier)
{
	aNotifier.removeObserver( *this);
}

