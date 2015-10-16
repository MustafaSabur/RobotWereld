#include "RobotWorldCanvas.hpp"
#include "Logger.hpp"
#include "RectangleShape.hpp"
#include "LineShape.hpp"
#include "RobotShape.hpp"
#include "Robot.hpp"
#include "WayPointShape.hpp"
#include "WayPoint.hpp"
#include "GoalShape.hpp"
#include "Goal.hpp"
#include "WallShape.hpp"
#include "Wall.hpp"
#include "RobotWorld.hpp"
#include "NotificationEvent.hpp"
#include <algorithm>

enum
{
	ID_ABOUT,
	ID_ADD_ROBOT,
	ID_EDIT_ROBOT,
	ID_DELETE_ROBOT,
	ID_ADD_WAYPOINT,
	ID_EDIT_WAYPOINT,
	ID_DELETE_WAYPOINT,
	ID_ADD_GOAL,
	ID_EDIT_GOAL,
	ID_DELETE_GOAL,
	ID_ADD_WALL,
	ID_EDIT_WALL,
	ID_DELETE_WALL,
	ID_SHAPE_INFO
};

/**
 *
 */
RobotWorldCanvas::RobotWorldCanvas( Window* anOwner) :
				ScrolledCanvas( anOwner, DEFAULT_ID),
				popupPoint( DefaultPosition),
				startActionPoint( DefaultPosition),
				endActionPoint( DefaultPosition),
				actionOffset( DefaultPosition),
				startActionSize( DefaultSize),
				startActionShape( NULL),
				endActionShape( NULL),
				selectedShape( NULL),
				activationEnabled( false),
				selectionEnabled( false),
				menuItemEnabled( false),
				dandEnabled( true),
				notificationHandler( NULL)
{
	initialise();
}

/**
 *
 */
RobotWorldCanvas::RobotWorldCanvas( Window* anOwner,
                                    ModelObjectPtr aModelObject) :

					ScrolledCanvas( anOwner, DEFAULT_ID),
					ViewObject(aModelObject),
					popupPoint( DefaultPosition),
					startActionPoint( DefaultPosition),
					endActionPoint( DefaultPosition),
					actionOffset( DefaultPosition),
					startActionSize( DefaultSize),
					startActionShape( NULL),
					endActionShape( NULL),
					selectedShape( NULL),
					activationEnabled( false),
					selectionEnabled( false),
					menuItemEnabled( false),
					dandEnabled( true),
					notificationHandler( NULL)
{
	initialise();
}
/**
 *
 */
RobotWorldCanvas::~RobotWorldCanvas()
{
	shapes.clear();

	PopEventHandler();

	if (notificationHandler)
	{
		delete notificationHandler;
	}
}
/**
 *
 */
Point RobotWorldCanvas::devicePointFor( const Point& aScreenPoint) const
{
	Point devicePoint;
	/*owner->getCanvas()->*/CalcUnscrolledPosition( aScreenPoint.x, aScreenPoint.y, &devicePoint.x, &devicePoint.y);
	return devicePoint;
}
/**
 *
 */
Point RobotWorldCanvas::screenPointFor( const Point& aDevicePoint) const
{
	Point screenPoint;
	/*owner->getCanvas()->*/CalcScrolledPosition( aDevicePoint.x, aDevicePoint.y, &screenPoint.x, &screenPoint.y);
	return screenPoint;
}
/**
 *
 */
void RobotWorldCanvas::enableHandlePaint( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_PAINT, wxPaintEventHandler( RobotWorldCanvas::OnPaint));
	} else
	{
		Disconnect( wxEVT_PAINT, wxPaintEventHandler( RobotWorldCanvas::OnPaint));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableHandleSize( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_SIZE, SizeEventHandler( RobotWorldCanvas::OnSize));
	} else
	{
		Disconnect( wxEVT_SIZE, SizeEventHandler( RobotWorldCanvas::OnSize));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableLeftDownHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnLeftDown));
	} else
	{
		Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnLeftDown));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableLeftUpHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_LEFT_UP, wxMouseEventHandler( RobotWorldCanvas::OnLeftUp));
	} else
	{
		Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( RobotWorldCanvas::OnLeftUp));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableLeftDClickHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnLeftDClick));
	} else
	{
		Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnLeftDClick));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableMiddleDownHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnMiddleDown));
	} else
	{
		Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnMiddleDown));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableMiddleUpHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( RobotWorldCanvas::OnMiddleUp));
	} else
	{
		Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( RobotWorldCanvas::OnMiddleUp));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableMiddleDClickHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnMiddleDClick));
	} else
	{
		Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnMiddleDClick));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableRightDownHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnRightDown));
	} else
	{
		Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( RobotWorldCanvas::OnRightDown));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableRightUpHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( RobotWorldCanvas::OnRightUp));
	} else
	{
		Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( RobotWorldCanvas::OnRightUp));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableRightDClickHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnRightDClick));
	} else
	{
		Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( RobotWorldCanvas::OnRightDClick));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableMouseMotionHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_MOTION, wxMouseEventHandler( RobotWorldCanvas::OnMouseMotion));
	} else
	{
		Disconnect( wxEVT_MOTION, wxMouseEventHandler( RobotWorldCanvas::OnMouseMotion));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableKeyHandling( bool enable /* = true */)
{
	if (enable == true)
	{
		Connect( wxEVT_KEY_DOWN, KeyEventHandler(RobotWorldCanvas::OnKeyDown));
		Connect( wxEVT_CHAR, wxCharEventHandler( RobotWorldCanvas::OnCharDown));
	} else
	{
		Disconnect( wxEVT_KEY_DOWN, KeyEventHandler(RobotWorldCanvas::OnKeyDown));
		Disconnect( wxEVT_CHAR, wxCharEventHandler( RobotWorldCanvas::OnCharDown));
	}
}
/**
 *
 */
void RobotWorldCanvas::enableActivationHandling( bool enable /* = true */)
{
	activationEnabled = enable;
}
/**
 *
 */
void RobotWorldCanvas::enableSelectionHandling( bool enable /* = true */)
{
	selectionEnabled = enable;
}
/**
 *
 */
void RobotWorldCanvas::enableItemMenuHandling( bool enable /* = true */)
{
	menuItemEnabled = enable;
}
/**
 *
 */
void RobotWorldCanvas::enableDragAndDropHandling( bool enable /*= true*/)
{
	dandEnabled = enable;
}
/**
 *
 */
bool RobotWorldCanvas::isShapeSelected() const
{
	return selectedShape != NULL;
}
/**
 *
 */
ShapePtr RobotWorldCanvas::getSelectedShape() const
{
	return selectedShape;
}
/**
 *
 */
void RobotWorldCanvas::setSelectedShape( ShapePtr aSelectedShape)
{
	ShapePtr previousSelectedShape = selectedShape;
	selectedShape = NULL;

	// No de-selection if there is no previous or new shape
	// and no re-selection of the current shape
	if (previousSelectedShape && aSelectedShape && previousSelectedShape->getObjectId() != aSelectedShape->getObjectId())
	{
		previousSelectedShape->setSelected( false);
		if (selectionEnabled)
		{
			previousSelectedShape->handleSelection();
		}
	}

	selectedShape = aSelectedShape;

	if (selectedShape)
	{
		selectedShape->setSelected();
		if (selectionEnabled)
		{
			selectedShape->handleSelection();
		}
	}
}
/**
 *
 */
bool RobotWorldCanvas::isShapeAt( const Point& aPoint) const
{
	for (ShapePtr shape : shapes)
	{
		if (shape->occupies( aPoint))
		{
			return true;
		}
	}
	return false;
}
/**
 *
 */
ShapePtr RobotWorldCanvas::getShapeAt( const Point& aPoint) const
{
	for (ShapePtr shape : shapes)
	{
		if (shape->occupies( aPoint))
		{
			return shape;
		}
	}
	return NULL;
}
/**
 *
 */
bool RobotWorldCanvas::selectShapeAt( const Point& aPoint)
{
	for (ShapePtr shape : shapes)
	{
		if (shape->occupies( aPoint))
		{
			setSelectedShape( shape);
			return true;
		}
	}
	return false;
}
/**
 *
 */
RobotWorldPtr RobotWorldCanvas::getRobotWorld() const
{
	return std::dynamic_pointer_cast<RobotWorld>(getModelObject());
}
/**
 *
 */
void RobotWorldCanvas::setRobotWorld( RobotWorldPtr aRobotWorld)
{
	setModelObject(std::dynamic_pointer_cast<ModelObject>(aRobotWorld));
}
/**
 *
 */
void RobotWorldCanvas::handleNotification()
{
	handleBackGroundNotification();
}
/**
 *
 */
void RobotWorldCanvas::handleBackGroundNotification()
{
	// Posting the message will put the notification event in the applications
	// message loop, hence making sure it is handled in the main thread.
	NotifyEvent event( wxEVT_NOTIFICATIONEVENT, 1000);
	wxPostEvent( notificationHandler, event);
	//notificationHandler->ProcessEvent(event);
}

/**
 *
 */
void RobotWorldCanvas::populate( int aNumberOfWalls /*= 2*/)
{
	RobotWorld::getRobotWorld().populate(aNumberOfWalls);
}
/**
 *
 */
void RobotWorldCanvas::unpopulate()
{
	shapes.clear();
	RobotWorld::getRobotWorld().unpopulate();
}

/**
 *
 */
void RobotWorldCanvas::initialise()
{
	SetMinSize( Size( 500, 500));

	notificationHandler = new NotificationHandler< std::function< void( NotifyEvent&) > >( [this](NotifyEvent& anEvent){this->OnNotificationEvent(anEvent);});
	PushEventHandler( notificationHandler);

	Connect( wxEVT_PAINT, wxPaintEventHandler( RobotWorldCanvas::OnPaint));
	Connect( wxEVT_SIZE, SizeEventHandler( RobotWorldCanvas::OnSize));

	SetBackgroundColour( WXSTRING( "WHITE"));
	SetFocus();

	enableHandlePaint();
	enableHandleSize();

	enableLeftDownHandling();
	enableLeftUpHandling();
	enableLeftDClickHandling();

	enableMiddleDownHandling();
	enableMiddleUpHandling();
	enableMiddleDClickHandling();

	enableRightDownHandling();
	enableRightUpHandling();
	enableRightDClickHandling();

	enableMouseMotionHandling();

	enableKeyHandling();

	enableActivationHandling();
	enableSelectionHandling();

	enableItemMenuHandling();

	handleNotificationsFor( RobotWorld::getRobotWorld());
}
/**
 *
 */
void RobotWorldCanvas::render( wxDC& dc)
{
	for (ShapePtr shape : shapes)
	{
//		Logger::log("Drawing shape: " + shape->asString());
		shape->draw( dc);
//		Logger::log("Done drawing shape: " + shape->asString());
	}
	if (startActionShape != NULL && actionStatus == DRAWING)
	{
		dc.SetPen( wxPen( wxColor( 0, 0, 0), 1)); // black line, 1 pixels thick
		dc.DrawLine( startActionShape->getCentre().x, startActionShape->getCentre().y, endActionPoint.x, endActionPoint.y);
	}
}
/**
 *
 */
void RobotWorldCanvas::handlePaint( PaintEvent& UNUSEDPARAM(event))
{
	wxPaintDC dc( this);
	render( dc);
}
/**
 *
 */
void RobotWorldCanvas::handleSize( SizeEvent& event)
{
//	wxClientDC dc(const_cast<RobotWorldCanvas*>(this));
//	timeTextSize = dc.GetTextExtent( _T("00:00"));
//	Refresh();
	event.Skip();
}
/**
 *
 */
void RobotWorldCanvas::handleLeftDown( MouseEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	Point screenPoint = event.GetPosition();

	startActionPoint = screenPoint;
	endActionPoint = startActionPoint;
	actionStatus = IDLE;

	if (selectShapeAt( screenPoint))
	{
		ShapePtr shape = getSelectedShape();

		WallShapePtr wall = std::dynamic_pointer_cast<WallShape>( shape);
		if (wall)
		{
			Logger::log( "Wall" + wall->asString());
			RectangleShapePtr wallEndPoint = wall->hasEndPointAt( screenPoint);
			if (wallEndPoint)
			{
				setSelectedShape( wallEndPoint);
				shape = getSelectedShape();
			}
		}else
		{
			Logger::log( "Nope, no wall???");
		}

		if (shape)
		{
			startActionShape = shape;
			endActionShape = NULL;
			actionOffset = shape->getCentre() - startActionPoint;

			if (event.ControlDown())
			{
				actionStatus = DRAWING;
			} else
			{
				actionStatus = DRAGGING;
			}
		}
	}else
	{
		Logger::log( "Nothing selected...");
	}

	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleLeftUp( MouseEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	RectangleShapePtr startRectangleShape = std::dynamic_pointer_cast<RectangleShape>( startActionShape);
	RectangleShapePtr endRectangeShape = std::dynamic_pointer_cast<RectangleShape>( getShapeAt( event.GetPosition()));

	switch (actionStatus)
	{
		case IDLE:
		{
			break;
		}
		case DRAWING:
		{
			if (startRectangleShape && endRectangeShape)
			{
				ShapePtr lineShape( new LineShape( startRectangleShape, endRectangeShape));
				shapes.push_back( lineShape);
			}
			break;
		}
		case RESIZING:
		{
			break;
		}
		case STARTDRAGGING:
		{
			break;
		}
		case DRAGGING:
		{
			if (dandEnabled && startActionPoint != endActionPoint)
			{
				handleEndDrag( selectedShape);
			}
			break;
		}
		default:
		{
			break;
		}
	}
	startActionPoint = DefaultPosition;
	endActionPoint = DefaultPosition;

	startActionShape = NULL;
	endActionShape = NULL;
	actionStatus = IDLE;

	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleLeftDClick( MouseEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	Point screenPoint = event.GetPosition();
	if (isShapeAt( screenPoint))
	{
		ShapePtr shape = getShapeAt( screenPoint);
		if (shape && activationEnabled)
		{
			shape->handleActivated();
		}
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleMiddleDown( MouseEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	// We must set the focus or any keyboard events will get lost
	//SetFocus();

	//Point devicePoint = devicePointFor(event.GetPosition());
}
/**
 *
 */
void RobotWorldCanvas::handleMiddleUp( MouseEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);
}
/**
 *
 */
void RobotWorldCanvas::handleMiddleDClick( MouseEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);
}
/**
 *
 */
void RobotWorldCanvas::handleRightDown( MouseEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	// We must set the focus or any keyboard events will get lost
	SetFocus();
	Point screenPoint = event.GetPosition();
	actionStatus = IDLE;

	if (selectShapeAt( screenPoint))
	{
	}
	Refresh();

}
/**
 *
 */
void RobotWorldCanvas::handleRightUp( MouseEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	actionStatus = IDLE;

	if (menuItemEnabled)
	{
		popupPoint = event.GetPosition();
		if (isShapeAt( popupPoint))
		{
			handleItemMenu( getShapeAt( popupPoint), popupPoint);
			return;
		}
		if (!isShapeAt( popupPoint))
		{
			handleMenu( popupPoint);
			return;
		}
	}
}
/**
 *
 */
void RobotWorldCanvas::handleRightDClick( MouseEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);
}
/**
 *
 */
void RobotWorldCanvas::handleMouseMotion( MouseEvent& event)
{
	if (event.Moving() == true && event.Dragging() == false)
	{
		return;
	}
	if (event.Moving() == false && event.Dragging() == true && startActionShape != NULL)
	{
		int tolerance = 2;
		int dx = std::abs( event.GetPosition().x - startActionPoint.x);
		int dy = std::abs( event.GetPosition().y - startActionPoint.y);
		if (dx <= tolerance && dy <= tolerance)
		{
			return;
		}

		switch (actionStatus)
		{
			case RESIZING:
			{
				Logger::log( "Dragging to resize");

//				Size size = startActionSize;
//
//				Point mousePosition = ScreenToClient(wxGetMousePosition());
//				int dx = mousePosition.x - startActionPoint.x;
//				int dy = mousePosition.y - startActionPoint.y;
//				if( mousePosition.x < startActionShape->getCentre().x)
//				{
//					dx = -dx;
//				}
//				if( mousePosition.y < startActionShape->getCentre().y)
//				{
//					dy = -dy;
//				}
//
//				size.x += 2*dx;
//				size.y += 2*dy;
//
//				startActionShape->setSize(size);
				Refresh();
				break;
			}
			case DRAGGING:
			{
				startActionShape->setCentre( event.GetPosition() + actionOffset);
				endActionPoint = event.GetPosition();
				Refresh();
				break;
			}
			case DRAWING:
			{
				endActionPoint = event.GetPosition();
				Refresh();
				break;
			}
			default:
			{
				Logger::log( "Just moving, nothing to see...");
			}
		}
	}
}
/**
 *
 */
void RobotWorldCanvas::handleKey( KeyEvent& event)
{
	Logger::log( __PRETTY_FUNCTION__);

	switch (event.GetKeyCode())
	{
		case WXK_DELETE:
		case WXK_NUMPAD_DELETE:
		{
			break;
		}
		case WXK_ESCAPE:
		{
			switch (actionStatus)
			{
				case DRAWING:
				{
					actionStatus = CANCELDRAWING;
					break;
				}
				case RESIZING:
				{
					actionStatus = CANCELRESIZING;
					break;
				}
				case DRAGGING:
				{
					actionStatus = CANCELDRAGGING;
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		default:
		{
			break;
		}
	}
}
/**
 *
 */
void RobotWorldCanvas::handleBeginLeftDrag( ShapePtr aShape)
{
	aShape->handleBeginLeftDrag();
}
/**
 *
 */
void RobotWorldCanvas::handleEndDrag( ShapePtr aShape)
{
	Logger::log( __PRETTY_FUNCTION__ + aShape->asDebugString());

	RobotShapePtr robotShape = std::dynamic_pointer_cast<RobotShape>(aShape);
	if (robotShape)
	{
		robotShape->getRobot()->setPosition( robotShape->getCentre(), false);
		return;
	}
	// Handles both WayPoint and Goal
	WayPointShapePtr wayPointShape = std::dynamic_pointer_cast<WayPointShape>(aShape);
	if (wayPointShape)
	{
		wayPointShape->getWayPoint()->setPosition( wayPointShape->getCentre(), false);
		return;
	}
	// Handle the RectangleShapes that are part of a wall
	RectangleShapePtr rectangleShape = std::dynamic_pointer_cast<RectangleShape>(aShape);
	if (rectangleShape)
	{
		for (ShapePtr shape : shapes)
		{
			WallShapePtr wall = std::dynamic_pointer_cast<WallShape>( shape);
			if (wall)
			{
				if (wall->hasEndPoint( rectangleShape))
				{
					wall->updateEndPoint( rectangleShape);
					return;
				}
			}
		}
	}
	/*aShape->handleEndDrag();*/
}
/**
 *
 */
void RobotWorldCanvas::handleAddRobot( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	ShapePtr robot( new RobotShape( RobotWorld::getRobotWorld().newRobot( "Thijs", popupPoint), this));
	shapes.push_back( robot);

	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleEditRobot( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);


	RobotShapePtr shape = std::dynamic_pointer_cast<RobotShape>( getSelectedShape());
	if (shape)
	{
		std::string name = GetTextFromUser( "The new Robot name:", "Enter a new name");

		if (name != "" && name != shape->getRobot()->getName())
		{
			shape->setTitle( name);
			shape->getRobot()->setName( name);
		}
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleDeleteRobot( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	RobotShapePtr shape = std::dynamic_pointer_cast<RobotShape>( getSelectedShape());
	if (shape)
	{
		deleteShape( shape);
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleAddWayPoint( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	ShapePtr wayPoint( new WayPointShape( RobotWorld::getRobotWorld().newWayPoint( "Joost", popupPoint)));
	shapes.push_back( wayPoint);
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleEditWayPoint( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	WayPointShapePtr shape = std::dynamic_pointer_cast<WayPointShape>( getSelectedShape());
	if (shape)
	{
		std::string name = GetTextFromUser( "The new WayPoint name:", "Enter a new name");

		if (name != "" && name != shape->getWayPoint()->getName())
		{
			shape->setTitle( name);
			shape->getWayPoint()->setName( name);
		}
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleDeleteWayPoint( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	WayPointShapePtr shape = std::dynamic_pointer_cast<WayPointShape>( getSelectedShape());
	if (shape)
	{
		deleteShape( shape);
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleAddGoal( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	ShapePtr goal( new GoalShape( RobotWorld::getRobotWorld().newGoal( "Leon", popupPoint)));
	shapes.push_back( goal);
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleEditGoal( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	GoalShapePtr shape = std::dynamic_pointer_cast<GoalShape>( getSelectedShape());
	if (shape)
	{
		std::string name = GetTextFromUser( "The new Goal name:", "Enter a new name");

		if (name != "" && name != shape->getGoal()->getName())
		{
			shape->setTitle( name);
			shape->getGoal()->setName( name);
		}
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleDeleteGoal( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	GoalShapePtr shape = std::dynamic_pointer_cast<GoalShape>( getSelectedShape());
	if (shape)
	{
		deleteShape( shape);
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleAddWall( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	RectangleShapePtr start( new RectangleShape( popupPoint));
	RectangleShapePtr end( new RectangleShape( popupPoint + Point( 50, 50)));

	ShapePtr wall( new WallShape( RobotWorld::getRobotWorld().newWall( start->getCentre(), end->getCentre(),false), start, end));

	shapes.push_back( wall);
	shapes.push_back( start);
	shapes.push_back( end);

	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleEditWall( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);
}
/**
 *
 */
void RobotWorldCanvas::handleDeleteWall( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	WallShapePtr shape = std::dynamic_pointer_cast<WallShape>( getSelectedShape());
	if (shape)
	{
		deleteShape( shape);
	}
	Refresh();
}
/**
 *
 */
void RobotWorldCanvas::handleShapeInfo( CommandEvent& UNUSEDPARAM(event))
{
	Logger::log( __PRETTY_FUNCTION__);

	if (isShapeSelected())
	{
		Logger::log( getSelectedShape()->asDebugString());
	}
}
void RobotWorldCanvas::handleNotification( NotifyEvent& UNUSEDPARAM(aNotifyEvent))
{
	//	Logger::log(__PRETTY_FUNCTION__);

		const std::vector< RobotPtr >& robots = RobotWorld::getRobotWorld().getRobots();
		for(RobotPtr robot : robots)
		{
			auto result = std::find_if(	shapes.begin(),
			                           	shapes.end(),
			                           	[robot](ShapePtr aShape)
			                           	{
											if(aShape->getModelObject())
											{
												return aShape->getModelObject()->getObjectId() == robot->getObjectId();
			                           		}
											return false;
			                           	});
			if( result == shapes.end())
			{
				ShapePtr shape(new RobotShape(robot,this));
				shapes.push_back(shape);
			}
		}

		const std::vector< WayPointPtr >& wayPoints = RobotWorld::getRobotWorld().getWayPoints();
		for(WayPointPtr waypoint : wayPoints)
		{
			auto result = std::find_if(	shapes.begin(),
			                           	shapes.end(),
			                           	[waypoint](ShapePtr aShape)
			                           	{
											if(aShape->getModelObject())
											{
												return aShape->getModelObject()->getObjectId() == waypoint->getObjectId();
											}
											return false;
			                           	});
			if( result == shapes.end())
			{
				ShapePtr shape(new WayPointShape(waypoint));
				shapes.push_back(shape);
			}
		}

		const std::vector< GoalPtr >& goals = RobotWorld::getRobotWorld().getGoals();
		for(GoalPtr goal : goals)
		{
			auto result = std::find_if(	shapes.begin(),
			                           	shapes.end(),
			                           	[goal](ShapePtr aShape)
			                           	{
											if(aShape->getModelObject())
											{
												return aShape->getModelObject()->getObjectId() == goal->getObjectId();
											}
											return false;
			                           	});
			if( result == shapes.end())
			{
				ShapePtr shape(new GoalShape(goal));
				shapes.push_back(shape);
			}
		}

		const std::vector< WallPtr >& walls = RobotWorld::getRobotWorld().getWalls();
		for(WallPtr wall : walls)
		{
			auto result = std::find_if(	shapes.begin(),
			                           	shapes.end(),
			                           	[wall](ShapePtr aShape)
			                           	{
											if(aShape->getModelObject())
											{
												return aShape->getModelObject()->getObjectId() == wall->getObjectId();
											}
											return false;
			                           	});
			if( result == shapes.end())
			{
				RectangleShapePtr point1( new RectangleShape( wall->getPoint1()));
				RectangleShapePtr point2( new RectangleShape( wall->getPoint2()));
				ShapePtr shape(new WallShape(wall,point1,point2));
				shapes.push_back(std::dynamic_pointer_cast<Shape>(point1));
				shapes.push_back(std::dynamic_pointer_cast<Shape>(point2));
				shapes.push_back(shape);
			}
		}

		Refresh();

}
/**
 *
 */
void RobotWorldCanvas::handleActivation( ShapePtr aShape)
{
	aShape->handleActivated();
}
/**
 *
 */
void RobotWorldCanvas::handleSelection( ShapePtr aShape)
{
	aShape->handleSelection();
}
/**
 *
 */
void RobotWorldCanvas::handleMenu( const Point& UNUSEDPARAM(aScreenPoint))
{
	Menu popupMenu;

	popupMenu.Append( ID_ADD_ROBOT, _T( "Add robot"), _T( "ID_ADD_ROBOT2"));
	Connect( ID_ADD_ROBOT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnAddRobot));

	popupMenu.Append( ID_ADD_WAYPOINT, _T( "Add waypoint"), _T( "ID_ADD_WAYPOINT2"));
	Connect( ID_ADD_WAYPOINT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnAddWayPoint));

	popupMenu.Append( ID_ADD_GOAL, _T( "Add goal"), _T( "ID_ADD_GOAL2"));
	Connect( ID_ADD_GOAL, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnAddGoal));

	popupMenu.Append( ID_ADD_WALL, _T( "Add wall"), _T( "ID_ADD_WALL2"));
	Connect( ID_ADD_WALL, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnAddWall));

	popupMenu.Append( wxID_ABOUT, _T( "About"), _T( "Show about dialog"));
	PopupMenu( &popupMenu);
}
/**
 *
 */
void RobotWorldCanvas::handleItemMenu( 	ShapePtr aSelectedShape,
										const Point& UNUSEDPARAM(aPoint))
{
	Menu popupMenu;

	if(std::dynamic_pointer_cast<RobotShape>(aSelectedShape))
	{
		popupMenu.Append( ID_EDIT_ROBOT, _T( "Edit robot"), _T( "ID_EDIT_ROBOT"));
		Connect( ID_EDIT_ROBOT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnEditRobot));
		popupMenu.Append( ID_DELETE_ROBOT, _T( "Delete robot"), _T( "ID_DELETE_ROBOT"));
		Connect( ID_DELETE_ROBOT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnDeleteRobot));
	} else if(std::dynamic_pointer_cast<GoalShape>(aSelectedShape))
	{
		popupMenu.Append( ID_EDIT_GOAL, _T( "Edit goal"), _T( "ID_EDIT_GOAL"));
		Connect( ID_EDIT_GOAL, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnEditGoal));
		popupMenu.Append( ID_DELETE_GOAL, _T( "Delete goal"), _T( "ID_DELETE_GOAL"));
		Connect( ID_DELETE_GOAL, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnDeleteGoal));
	} else if(std::dynamic_pointer_cast<WayPointShape>(aSelectedShape))
	{
		popupMenu.Append( ID_EDIT_WAYPOINT, _T( "Edit waypoint"), _T( "ID_EDIT_WAYPOINT"));
		Connect( ID_EDIT_WAYPOINT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnEditWayPoint));
		popupMenu.Append( ID_DELETE_WAYPOINT, _T( "Delete waypoint"), _T( "ID_DELETE_WAYPOINT"));
		Connect( ID_DELETE_WAYPOINT, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnDeleteWayPoint));
	} else if(std::dynamic_pointer_cast<WallShape>(aSelectedShape))
	{
		popupMenu.Append( ID_DELETE_WALL, _T( "Delete wall"), _T( "ID_DELETE_WALL"));
		Connect( ID_DELETE_WALL, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnDeleteWall));
	} else
	{
		Logger::log( "Huh?: " + aSelectedShape->asDebugString());
	}

	popupMenu.Append( ID_SHAPE_INFO, _T( "Show info"), _T( "ID_SHAPE_INFO"));
	Connect( ID_SHAPE_INFO, wxEVT_COMMAND_MENU_SELECTED, CommandEventHandler(RobotWorldCanvas::OnShapeInfo));

	popupMenu.Append( wxID_ABOUT, _T( "About"), _T( "Show about dialog"));
	PopupMenu( &popupMenu);
}
/**
 *
 */
void RobotWorldCanvas::deleteShape( RobotShapePtr aRobotShape)
{
	aRobotShape->stopHandlingNotificationsFor( *aRobotShape->getRobot());
	RobotWorld::getRobotWorld().deleteRobot( aRobotShape->getRobot(), false);
	deleteGenericShape( aRobotShape);

}
/**
 *
 */
void RobotWorldCanvas::deleteShape( GoalShapePtr aGoalShape)
{
	aGoalShape->stopHandlingNotificationsFor( *aGoalShape->getGoal());
	RobotWorld::getRobotWorld().deleteGoal( aGoalShape->getGoal(), false);
	deleteGenericShape( aGoalShape);
}
/**
 *
 */
void RobotWorldCanvas::deleteShape( WayPointShapePtr aWayPointShape)
{
	aWayPointShape->stopHandlingNotificationsFor( *aWayPointShape->getWayPoint());
	RobotWorld::getRobotWorld().deleteWayPoint( aWayPointShape->getWayPoint(), false);
	deleteGenericShape( aWayPointShape);
}
/**
 *
 */
void RobotWorldCanvas::deleteShape( WallShapePtr aWallShape)
{
	RectangleShapePtr start = aWallShape->hasEndPointAt( aWallShape->getBegin());
	RectangleShapePtr end = aWallShape->hasEndPointAt( aWallShape->getEnd());
	RobotWorld::getRobotWorld().deleteWall( aWallShape->getWall(), false);
	deleteGenericShape( aWallShape);
	deleteGenericShape( start);
	deleteGenericShape( end);
}
/**
 *
 */
void RobotWorldCanvas::deleteGenericShape( ShapePtr aShape)
{
	if (isShapeSelected() && aShape->getObjectId() == getSelectedShape()->getObjectId())
	{
		setSelectedShape( NULL);
	}
	shapes.erase( std::find_if( shapes.begin(), shapes.end(), [aShape](ShapePtr s)
	{
		return aShape->getObjectId() == s->getObjectId();
	}));
}
/**
 *
 */
void RobotWorldCanvas::OnPaint( PaintEvent& event)
{
	handlePaint( event);
}
/**
 *
 */
void RobotWorldCanvas::OnSize( SizeEvent& event)
{
	handleSize( event);
}
/**
 *
 */
void RobotWorldCanvas::OnLeftDown( MouseEvent& event)
{
	handleLeftDown( event);
}
/**
 *
 */
void RobotWorldCanvas::OnLeftUp( MouseEvent& event)
{
	handleLeftUp( event);
}
/**
 *
 */
void RobotWorldCanvas::OnLeftDClick( MouseEvent& event)
{
	handleLeftDClick( event);
}
/**
 *
 */
void RobotWorldCanvas::OnMiddleDown( MouseEvent& event)
{
	handleMiddleDown( event);
}
/**
 *
 */
void RobotWorldCanvas::OnMiddleUp( MouseEvent& event)
{
	handleMiddleUp( event);
}
/**
 *
 */
void RobotWorldCanvas::OnMiddleDClick( MouseEvent& event)
{
	handleMiddleDClick( event);
}
/**
 *
 */
void RobotWorldCanvas::OnRightDown( MouseEvent& event)
{
	handleRightDown( event);
}
/**
 *
 */
void RobotWorldCanvas::OnRightUp( MouseEvent& event)
{
	handleRightUp( event);
}
/**
 *
 */
void RobotWorldCanvas::OnRightDClick( MouseEvent& event)
{
	handleRightDClick( event);
}
/**
 *
 */
void RobotWorldCanvas::OnMouseMotion( MouseEvent& event)
{
	handleMouseMotion( event);
}
/**
 *
 */
void RobotWorldCanvas::OnKeyDown( KeyEvent& event)
{
	handleKey( event);
}
/**
 *
 */
void RobotWorldCanvas::OnCharDown( KeyEvent& event)
{
	handleKey( event);
}
/**
 *
 */
void RobotWorldCanvas::OnAddRobot( CommandEvent& event)
{
	handleAddRobot( event);
}
/**
 *
 */
void RobotWorldCanvas::OnEditRobot( CommandEvent& event)
{
	handleEditRobot( event);
}
/**
 *
 */
void RobotWorldCanvas::OnDeleteRobot( CommandEvent& event)
{
	handleDeleteRobot( event);
}
/**
 *
 */
void RobotWorldCanvas::OnAddWayPoint( CommandEvent& event)
{
	handleAddWayPoint( event);
}
/**
 *
 */
void RobotWorldCanvas::OnEditWayPoint( CommandEvent& event)
{
	handleEditWayPoint( event);
}
/**
 *
 */
void RobotWorldCanvas::OnDeleteWayPoint( CommandEvent& event)
{
	handleDeleteWayPoint( event);
}
/**
 *
 */
void RobotWorldCanvas::OnAddGoal( CommandEvent& event)
{
	handleAddGoal( event);
}
/**
 *
 */
void RobotWorldCanvas::OnEditGoal( CommandEvent& event)
{
	handleEditGoal( event);
}
/**
 *
 */
void RobotWorldCanvas::OnDeleteGoal( CommandEvent& event)
{
	handleDeleteGoal( event);
}
/**
 *
 */
void RobotWorldCanvas::OnAddWall( CommandEvent& event)
{
	handleAddWall( event);
}
/**
 *
 */
void RobotWorldCanvas::OnEditWall( CommandEvent& UNUSEDPARAM(event))
{

}
/**
 *
 */
void RobotWorldCanvas::OnDeleteWall( CommandEvent& event)
{
	handleDeleteWall( event);
}
/**
 *
 */
void RobotWorldCanvas::OnShapeInfo( CommandEvent& event)
{
	handleShapeInfo( event);
}
/**
 *
 */
void RobotWorldCanvas::OnNotificationEvent( NotifyEvent& aNotifyEvent)
{
	handleNotification(aNotifyEvent);
}
