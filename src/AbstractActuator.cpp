#include "AbstractActuator.hpp"
#include "AbstractAgent.hpp"

/**
 *
 */
AbstractActuator::AbstractActuator() :
				agent( NULL)
{
}
/**
 *
 */
AbstractActuator::AbstractActuator( AbstractAgent* anAgent) :
				agent( anAgent)
{
}
/**
 *
 */
AbstractActuator::~AbstractActuator()
{
}
/**
 *
 */
void AbstractActuator::attachAgent( AbstractAgent* anAgent)
{
	agent = anAgent;
}
/**
 *
 */
void AbstractActuator::detachAgent()
{
	agent = NULL;
}
/**
 *
 */
std::string AbstractActuator::asString() const
{
	return "AbstractActuator";
}
/**
 *
 */
std::string AbstractActuator::asDebugString() const
{
	return asString();
}

