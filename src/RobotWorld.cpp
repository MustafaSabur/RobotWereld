#include "RobotWorld.hpp"
#include "Logger.hpp"
#include "Robot.hpp"
#include "WayPoint.hpp"
#include "Goal.hpp"
#include "Wall.hpp"
#include <algorithm>

/**
 *
 */
/* static */RobotWorld& RobotWorld::RobotWorld::getRobotWorld()
{
	static RobotWorld robotWorld;
	return robotWorld;
}
/**
 *
 */
RobotPtr RobotWorld::newRobot(	const std::string& aName,
								const Point& aPosition /*= Point(-1,-1)*/,
								bool aNotifyObservers /*= true*/)
{
	RobotPtr robot( new Robot( aName, aPosition));
	robots.push_back( robot);
	if (aNotifyObservers == true)
	{
		notifyObservers();
	}
	return robot;

}
/**
 *
 */
WayPointPtr RobotWorld::newWayPoint(	const std::string& aName,
									const Point& aPosition /*= Point(-1,-1)*/,
									bool aNotifyObservers /*= true*/)
{
	WayPointPtr wayPoint(new WayPoint( aName, aPosition));
	wayPoints.push_back( wayPoint);
	if (aNotifyObservers == true)
	{
		notifyObservers();
	}
	return wayPoint;

}
/**
 *
 */
GoalPtr RobotWorld::newGoal(	const std::string& aName,
							const Point& aPosition /*= Point(-1,-1)*/,
							bool aNotifyObservers /*= true*/)
{
	GoalPtr goal( new Goal( aName, aPosition));
	goals.push_back( goal);
	if (aNotifyObservers == true)
	{
		notifyObservers();
	}
	return goal;
}
/**
 *
 */
WallPtr RobotWorld::newWall(const Point& aPoint1,
							const Point& aPoint2,
							bool aNotifyObservers /*= true*/)
{
	WallPtr wall( new Wall( aPoint1, aPoint2));
	walls.push_back( wall);
	if (aNotifyObservers == true)
	{
		notifyObservers();
	}
	return wall;
}
/**
 *
 */
void RobotWorld::deleteRobot( 	RobotPtr aRobot,
								bool aNotifyObservers /*= true*/)
{
	auto i = std::find_if( robots.begin(), robots.end(), [aRobot](RobotPtr r)
	{
		return aRobot->getName() == r->getName();
	});
	if (i != robots.end())
	{
		robots.erase( i);
		if (aNotifyObservers == true)
		{
			notifyObservers();
		}
	}
}
/**
 *
 */
void RobotWorld::deleteWayPoint( 	WayPointPtr aWayPoint,
									bool aNotifyObservers /*= true*/)
{
	auto i = std::find_if( wayPoints.begin(), wayPoints.end(), [aWayPoint]( WayPointPtr w)
	{
		return aWayPoint->getName() == w->getName();
	});
	if (i != wayPoints.end())
	{
		wayPoints.erase( i);
		if (aNotifyObservers == true)
		{
			notifyObservers();
		}
	}
}
/**
 *
 */
void RobotWorld::deleteGoal( 	GoalPtr aGoal,
								bool aNotifyObservers /*= true*/)
{
	auto i = std::find_if( goals.begin(), goals.end(), [aGoal]( GoalPtr g)
	{
		return aGoal->getName() == g->getName();
	});
	if (i != goals.end())
	{
		goals.erase( i);

		if (aNotifyObservers == true)
		{
			notifyObservers();
		}
	}
}
/**
 *
 */
void RobotWorld::deleteWall( 	WallPtr aWall,
								bool aNotifyObservers /*= true*/)
{
	auto i = std::find_if( walls.begin(), walls.end(), [aWall]( WallPtr w)
	{
		return
		aWall->getPoint1() == w->getPoint1() &&
		aWall->getPoint2() == w->getPoint2();
	});
	if (i != walls.end())
	{
		walls.erase( i);

		if (aNotifyObservers == true)
		{
			notifyObservers();
		}
	}
}
/**
 *
 */
RobotPtr RobotWorld::getRobotByName( const std::string& aName) const
{
	for (RobotPtr robot : robots)
	{
		if (robot->getName() == aName)
		{
			return robot;
		}
	}
	return NULL;
}
/**
 *
 */
WayPointPtr RobotWorld::getWayPointByName( const std::string& aName) const
{
	for (WayPointPtr wayPoint : wayPoints)
	{
		if (wayPoint->getName() == aName)
		{
			return wayPoint;
		}
	}
	return NULL;
}
/**
 *
 */
GoalPtr RobotWorld::getGoalByName( const std::string& aName) const
{
	for (GoalPtr goal : goals)
	{
		if (goal->getName() == aName)
		{
			return goal;
		}
	}
	return NULL;
}

/**
 *
 */
const std::vector< RobotPtr >& RobotWorld::getRobots() const
{
	return robots;
}
/**
 *
 */
const std::vector< WayPointPtr >& RobotWorld::getWayPoints() const
{
	return wayPoints;
}
/**
 *
 */
const std::vector< GoalPtr >& RobotWorld::getGoals() const
{
	return goals;
}
/**
 *
 */
const std::vector< WallPtr >& RobotWorld::getWalls() const
{
	return walls;
}
/**
 *
 */
void RobotWorld::populate( int aNumberOfWalls /*= 2*/)
{
	RobotWorld::getRobotWorld().newRobot( "Thijs", Point( 50, 50),false);

	static Point coordinates[] = { Point( 100, 400), Point( 350, 300),
	Point( 300, 100),
									Point( 350, 200) };

	for (int i = 0; i < 2 * aNumberOfWalls; i += 2)
	{
		RobotWorld::getRobotWorld().newWall( coordinates[i], coordinates[i + 1],false);
	}

	RobotWorld::getRobotWorld().newGoal( "Leon", Point( 450, 450),false);

	notifyObservers();
}
/**
 *
 */
void RobotWorld::unpopulate( bool aNotifyObservers /*= true*/)
{
	robots.clear();
	wayPoints.clear();
	goals.clear();
	walls.clear();

	if (aNotifyObservers)
	{
		notifyObservers();
	}
}

/**
 *
 */
RobotWorld::RobotWorld()
{
}
/**
 *
 */
RobotWorld::~RobotWorld()
{
	// No notification while I am in the destruction mode!
	disableNotification();
	unpopulate();
}

