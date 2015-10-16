#include "RobotShape.hpp"
#include <cmath>
#include "Notifier.hpp"
#include "Robot.hpp"
#include "Goal.hpp"
#include "Logger.hpp"
#include "RobotWorldCanvas.hpp"
#include "RobotWorld.hpp"

/**
 *
 */
RobotShape::RobotShape( RobotPtr aRobot,
						RobotWorldCanvas* aRobotWorldCanvas) :
				RectangleShape( std::dynamic_pointer_cast<ModelObject>(aRobot), aRobot->getPosition(), aRobot->getName()),
				robotWorldCanvas( aRobotWorldCanvas)
{
}
/**
 *
 */
RobotShape::~RobotShape()
{
}
/**
 *
 */
RobotPtr RobotShape::getRobot() const
{
	return std::dynamic_pointer_cast<Robot>(getModelObject());
}
/**
 *
 */
void RobotShape::setRobot( RobotPtr aRobot)
{
	setModelObject(std::dynamic_pointer_cast<ModelObject>(aRobot));
}
/**
 *
 */
void RobotShape::handleActivated()
{
	Logger::log( __PRETTY_FUNCTION__);

	GoalPtr goal = RobotWorld::getRobotWorld().getGoalByName( "Leon");
	if (goal)
	{
		Point goalPosition = goal->getPosition();
		Point robotPosition = getRobot()->getPosition();
		getRobot()->setFront( Vector( goalPosition, robotPosition), false);
	}
}
/**
 *
 */
void RobotShape::handleSelection()
{
	Logger::log( __PRETTY_FUNCTION__);
	if (robotWorldCanvas->isShapeSelected() && robotWorldCanvas->getSelectedShape()->getObjectId() == getObjectId())
	{
		setSelected();
	} else
	{
		setSelected(false);
	}
}
/**
 *
 */
void RobotShape::handleNotification()
{
	setCentre( getRobot()->getPosition());
	robotWorldCanvas->handleNotification();
}
/**
 *
 */
void RobotShape::draw( wxDC& dc)
{
	// The minimum size of the RectangleShape is the size of the title
	titleSize = dc.GetTextExtent( WXSTRING( title));
	if (size.x < (titleSize.x + 2 * spacing + 2 * borderWidth))
	{
		size.x = titleSize.x + 2 * spacing + 2 * borderWidth;
	}
	if (size.y < (titleSize.y + 2 * spacing + 2 * borderWidth))
	{
		size.y = titleSize.y + 2 * spacing + 2 * borderWidth;
	}
	if (getRobot()->getSize() != size)
	{
		getRobot()->setSize( size, false);
	}

	dc.SetPen( wxPen( WXSTRING( "PALE GREEN"), borderWidth, wxSOLID));

	const OpenSet& openSet = getRobot()->getAStar().getOpenSet();
	for (const Vertex& vertex : openSet)
	{
		dc.DrawPoint( vertex.asPoint());
	}

//	dc.SetPen( wxPen(WXSTRING("LIGHT GREY"), borderWidth, wxSOLID));
//	ClosedSet closedSet = robot->astar.getClosedSet();
//	for(Vertex vertex : closedSet)
//	{
//		dc.DrawPoint(vertex.asPoint());
//	}

	const std::vector< Vertex >& path = getRobot()->getPath();
	if (path.size() != 0)
	{
		dc.SetPen( wxPen( WXSTRING( "BLACK"), borderWidth, wxSOLID));
		for (const Vertex& vertex : path)
		{
			dc.DrawPoint( vertex.asPoint());
		}
	}

	// Draws a rectangle with the given top left corner, and with the given size.
	dc.SetBrush( *wxWHITE_BRUSH);
	if (isSelected())
	{
		dc.SetPen( wxPen( WXSTRING( getSelectionColour()), borderWidth, wxSOLID));
	} else
	{
		dc.SetPen( wxPen( WXSTRING( getNormalColour()), borderWidth, wxSOLID));
	}

	Point cornerPoints[] = { getRobot()->getFrontRight(), getRobot()->getFrontLeft(), getRobot()->getBackLeft(), getRobot()->getBackRight() };
	dc.DrawPolygon( 4, cornerPoints);

	dc.SetPen( wxPen( WXSTRING( "RED"), borderWidth, wxSOLID));
	dc.DrawPoint( cornerPoints[1]);
	dc.SetPen( wxPen( WXSTRING( "GREEN"), borderWidth, wxSOLID));
	dc.DrawPoint( cornerPoints[0]);
	dc.SetPen( wxPen( WXSTRING( "INDIAN RED"), borderWidth, wxSOLID));
	dc.DrawPoint( cornerPoints[2]);
	dc.SetPen( wxPen( WXSTRING( "PALE GREEN"), borderWidth, wxSOLID));
	dc.DrawPoint( cornerPoints[3]);

	double angle = Shape2DUtils::getAngle( getRobot()->getFront()) + 0.5 * PI;

	dc.SetPen( wxPen( WXSTRING( "BLACK"), 1, wxSOLID));
	dc.DrawLine( centre.x, centre.y, centre.x + std::cos( angle - 0.5 * PI) * 25, centre.y + std::sin( angle - 0.5 * PI) * 25);

	// Bounty of 0.25 points for anyone who makes the name turn
	// with the front of the robot, while text centre being displayed in the
	// centre of the robot, bottom of the text to the back of the robot.
	dc.DrawRotatedText( WXSTRING( title), centre.x - titleSize.x / 2, centre.y - titleSize.y / 2, angle - PI);

}
/**
 *
 */
bool RobotShape::occupies( const Point& aPoint) const
{
	Point cornerPoints[] = { getRobot()->getFrontRight(), getRobot()->getFrontLeft(), getRobot()->getBackLeft(), getRobot()->getBackRight() };
	return Shape2DUtils::isInsidePolygon( cornerPoints, 4, aPoint);
}
/**
 *
 */
void RobotShape::setCentre( const Point& aPoint)
{
	getRobot()->setPosition( aPoint, false);
	RectangleShape::setCentre( getRobot()->getPosition());
}
/**
 *
 */
std::string RobotShape::asString() const
{
	std::ostringstream os;

	os << "RobotShape " << RectangleShape::asString();

	return os.str();
}
/**
 *
 */
std::string RobotShape::asDebugString() const
{
	std::ostringstream os;

	os << "RobotShape:\n";
	os << RectangleShape::asDebugString() << "\n";
	if (getRobot())
	{
		os << getRobot()->asDebugString();
	}

	return os.str();
}
