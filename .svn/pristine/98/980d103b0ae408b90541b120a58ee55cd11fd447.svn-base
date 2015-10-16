#include "GoalShape.hpp"
#include "Goal.hpp"
#include "Logger.hpp"
#include <sstream>

/**
 *
 */
GoalShape::GoalShape( GoalPtr aGoal) :
				WayPointShape( std::dynamic_pointer_cast<WayPoint>(aGoal))
{
	Logger::log("Goal: " + aGoal->asString() + asString());
}
/**
 *
 */
GoalShape::~GoalShape()
{
}
/**
 *
 */
GoalPtr GoalShape::getGoal() const
{
	return std::dynamic_pointer_cast<Goal>(getModelObject());
}
/**
 *
 */
void GoalShape::setGoal( GoalPtr aGoal)
{
	setModelObject(std::dynamic_pointer_cast<ModelObject>(aGoal));
}
/**
 *
 */
void GoalShape::handleNotification()
{
	Logger::log( __PRETTY_FUNCTION__);
}
/**
 *
 */
std::string GoalShape::asString() const
{
	std::ostringstream os;

	os << "GoalShape " << WayPointShape::asString();

	return os.str();
}
/**
 *
 */
std::string GoalShape::asDebugString() const
{
	std::ostringstream os;

	os << "GoalShape:\n";
	os << WayPointShape::asDebugString() << "\n";
	// Goal has not use in this version so we do not print it
//	if(getGoal())
//	{
//		os << getGoal()->asDebugString();
//	}

	return os.str();
}
