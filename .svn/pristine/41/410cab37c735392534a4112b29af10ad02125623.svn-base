#ifndef ROBOTWORLDCANVAS_HPP_
#define ROBOTWORLDCANVAS_HPP_

#include "Config.hpp"
#include "Widgets.hpp"
#include "ViewObject.hpp"
#include "Observer.hpp"
#include <vector>
#include "NotificationHandler.hpp"
#include "RobotWorld.hpp"

class Shape;
typedef std::shared_ptr<Shape> ShapePtr;
class RobotShape;
typedef std::shared_ptr<RobotShape> RobotShapePtr;
class GoalShape;
typedef std::shared_ptr<GoalShape> GoalShapePtr;
class WayPointShape;
typedef std::shared_ptr<WayPointShape> WayPointShapePtr;
class WallShape;
typedef std::shared_ptr<WallShape> WallShapePtr;
class NotifyEvent;

class RobotWorldCanvas :	public ScrolledCanvas,
							public ViewObject

{
	public:
		/**
		 *
		 */
		RobotWorldCanvas( Window* anOwner);
		/**
		 *
		 */
		RobotWorldCanvas( Window* anOwner,
		                  ModelObjectPtr aModelObject);
		/**
		 *
		 */
		virtual ~RobotWorldCanvas();
		/**
		 * The canvas is partially displayed in a scrolling window. Hence, the user viewable part of this window
		 * is probably just a part of this window. This function takes a point in the (visible) scrolling window coordinates
		 * and translates it to this canvas windows coordinates. It takes into account the number of lines and number of
		 * pixels between lines.
		 */
		Point devicePointFor( const Point& aScreenPoint) const;
		/**
		 * This function is the opposite of devicePointFor(): it translates canvas coordinates to scrolling window coordinates
		 *
		 * @see devicePointFor( const Point&)
		 */
		Point screenPointFor( const Point& aDevicePoint) const;
		/**
		 * @name Event handling enabling functions
		 *
		 */
		//@{
		virtual void enableHandlePaint( bool enable = true);
		virtual void enableHandleSize( bool enable = true);

		virtual void enableLeftDownHandling( bool enable = true);
		virtual void enableLeftUpHandling( bool enable = true);
		virtual void enableLeftDClickHandling( bool enable = true);

		virtual void enableMiddleDownHandling( bool enable = true);
		virtual void enableMiddleUpHandling( bool enable = true);
		virtual void enableMiddleDClickHandling( bool enable = true);

		virtual void enableRightDownHandling( bool enable = true);
		virtual void enableRightUpHandling( bool enable = true);
		virtual void enableRightDClickHandling( bool enable = true);

		virtual void enableMouseMotionHandling( bool enable = true);

		virtual void enableKeyHandling( bool enable = true);

		virtual void enableActivationHandling( bool enable = true);
		virtual void enableSelectionHandling( bool enable = true);

		virtual void enableItemMenuHandling( bool enable = true);

		virtual void enableDragAndDropHandling( bool enable = true);
		//@}
		/**
		 *
		 * @return true if any shape is selected, false otherwise
		 */
		bool isShapeSelected() const;
		/**
		 *
		 * @return A selected Shape if any, NULL otherwise.
		 */
		virtual ShapePtr getSelectedShape() const;
		/**
		 * Sets the given Shape as the selected shape.
		 * If selectionEnabled is set to true, handleSelection() of both the old and new
		 * selected shape will be called after setting their selection as appropriate.
		 *
		 * @param 	aSelectedShape 	The new Shape that will be selected. If NULL it acts as mere de-selecting of the current
		 * 							selected shape
		 */
		virtual void setSelectedShape( ShapePtr aSelectedShape);

		/**
		 *
		 * @param 	aPoint
		 * @return 	True if any Shape returns true for Shape.ocuppies(aPoint), false otherwise.
		 *
		 * @see Shape::occupies(const Point&)
		 */
		virtual bool isShapeAt( const Point& aPoint) const;
		/**
		 * TODO: are the points scrolling or canvas points?
		 * @param 	aPoint
		 * @return 	The first Shape in iteration order that returns true for Shape.ocuppies(aPoint). If
		 * 			no such Shape exists NULL will be returned.
		 */
		virtual ShapePtr getShapeAt( const Point& aPoint) const;
		/**
		 * Selects the Shape that returns true for Shape.ocuppies(aPoint).
		 * @param aPoint
		 * @return
		 */
		virtual bool selectShapeAt( const Point& aPoint);

		/**
		 * @name Type safe accessors and mutators
		 */
		//@{
		/**
		 * Type safe accessor
		 */
		RobotWorldPtr getRobotWorld() const;
		/**
		 * Type safe mutator
		 */
		void setRobotWorld( RobotWorldPtr aRobotWorld);
		//@}
		/**
		 * @name Observer functions
		 */
		//@{
		/**
		 * A Notifier will call this function if this Observer will handle the notifications of that
		 * Notifier. It is the responsibility of the Observer to filter any events it is interested in.
		 * This function should only be called from the main thread because wxWidgets does not allow
		 * for painting widgets in a background thread: all painting should be done in the main thread.
		 * Therefore all notifications are routed to handleBackGroundNotification() as a convenience.
		 *
		 */
		virtual void handleNotification();
		//@}
		/**
		 * A Notifier that runs in a background thread should call this function instead of handleNotification().
		 * handleNotification() is routed to this function as a convenience. Bad for performance though.
		 */
		virtual void handleBackGroundNotification();
		/**
		 * Asks the world to populates itself with a robot, a goal and the given number of walls
		 */
		void populate( int aNumberOfWalls = 2);
		/**
		 * Removes everything from the world
		 */
		void unpopulate();
	protected:
		/**
		 * Common initialise function
		 */
		void initialise();
		/**
		 *
		 */
		void render( wxDC& dc);
		/**
		 * @name Event handling functions
		 *
		 * Override these functions if the default handling is not what you want
		 */
		//@{
		virtual void handlePaint( PaintEvent& event);
		virtual void handleSize( SizeEvent& event);

		virtual void handleLeftDown( MouseEvent& event);
		virtual void handleLeftUp( MouseEvent& event);
		virtual void handleLeftDClick( MouseEvent& event);

		virtual void handleMiddleDown( MouseEvent& event);
		virtual void handleMiddleUp( MouseEvent& event);
		virtual void handleMiddleDClick( MouseEvent& event);

		virtual void handleRightDown( MouseEvent& event);
		virtual void handleRightUp( MouseEvent& event);
		virtual void handleRightDClick( MouseEvent& event);

		virtual void handleMouseMotion( MouseEvent& event);

		virtual void handleKey( KeyEvent& event);

		virtual void handleBeginLeftDrag( ShapePtr aShape);
		virtual void handleEndDrag( ShapePtr aShape);

		virtual void handleAddRobot( CommandEvent& event);
		virtual void handleEditRobot( CommandEvent& event);
		virtual void handleDeleteRobot( CommandEvent& event);

		virtual void handleAddWayPoint( CommandEvent& event);
		virtual void handleEditWayPoint( CommandEvent& event);
		virtual void handleDeleteWayPoint( CommandEvent& event);

		virtual void handleAddGoal( CommandEvent& event);
		virtual void handleEditGoal( CommandEvent& event);
		virtual void handleDeleteGoal( CommandEvent& event);

		virtual void handleAddWall( CommandEvent& event);
		virtual void handleEditWall( CommandEvent& event);
		virtual void handleDeleteWall( CommandEvent& event);

		virtual void handleShapeInfo( CommandEvent& event);

		virtual void handleNotification( NotifyEvent& aNotifyEvent);

		//@}
		virtual void handleActivation( ShapePtr aShape);
		virtual void handleSelection( ShapePtr aShape);


		/**
		 *
		 */
		virtual void handleMenu( const Point& aScreenPoint);
		/**
		 *
		 */
		virtual void handleItemMenu( 	ShapePtr aSelectedShape,
										const Point& aPoint);
		/**
		 *
		 */
		void deleteShape( RobotShapePtr aRobotShape);
		/**
		 *
		 */
		void deleteShape( GoalShapePtr aGoalShape);
		/**
		 *
		 */
		void deleteShape( WayPointShapePtr aWayPointShape);
		/**
		 *
		 */
		void deleteShape( WallShapePtr aWallShape);
		/**
		 *
		 */
		void deleteGenericShape( ShapePtr aShape);
	private:
		/**
		 * @name Event handlers
		 *
		 */
		//@{
		void OnPaint( PaintEvent& event);
		void OnSize( SizeEvent& event);

		void OnLeftDown( MouseEvent& event);
		void OnLeftUp( MouseEvent& event);
		void OnLeftDClick( MouseEvent& event);

		void OnMiddleDown( MouseEvent& event);
		void OnMiddleUp( MouseEvent& event);
		void OnMiddleDClick( MouseEvent& event);

		void OnRightDown( MouseEvent& event);
		void OnRightUp( MouseEvent& event);
		void OnRightDClick( MouseEvent& event);

		void OnMouseMotion( MouseEvent& event);

		void OnKeyDown( KeyEvent& event);
		void OnCharDown( KeyEvent& event);

		void OnAddRobot( CommandEvent& event);
		void OnEditRobot( CommandEvent& event);
		void OnDeleteRobot( CommandEvent& event);

		void OnAddWayPoint( CommandEvent& event);
		void OnEditWayPoint( CommandEvent& event);
		void OnDeleteWayPoint( CommandEvent& event);

		void OnAddGoal( CommandEvent& event);
		void OnEditGoal( CommandEvent& event);
		void OnDeleteGoal( CommandEvent& event);

		void OnAddWall( CommandEvent& event);
		void OnEditWall( CommandEvent& event);
		void OnDeleteWall( CommandEvent& event);

		void OnShapeInfo( CommandEvent& event);

		void OnNotificationEvent( NotifyEvent& aNotifyEvent);
		//@}

		std::vector< ShapePtr > shapes;

		enum
		{
			IDLE,
			DRAWING,
			CANCELDRAWING,
			RESIZING,
			CANCELRESIZING,
			STARTDRAGGING,
			DRAGGING,
			CANCELDRAGGING
		} actionStatus;

		Point popupPoint;Point startActionPoint;Point endActionPoint;Point actionOffset;Size startActionSize;

		ShapePtr startActionShape;
		ShapePtr endActionShape;

		ShapePtr selectedShape;

		bool activationEnabled;
		bool selectionEnabled;
		bool menuItemEnabled;
		bool dandEnabled;

		NotificationHandler< std::function< void( NotifyEvent&) > > * notificationHandler;
};

#endif /* ROBOTWORLDCANVAS_HPP_ */
