/*
 * WallShape.cpp
 *
 *  Created on: 21 Oct 2012
 *      Author: jkr
 */

#include "WallShape.hpp"
#include "Wall.hpp"
#include "RectangleShape.hpp"
#include <sstream>

/**
 *
 */
WallShape::WallShape( 	WallPtr aWall,
						RectangleShapePtr aRectangleShape1,
						RectangleShapePtr aRectangleShape2) :
				LineShape( std::dynamic_pointer_cast<ModelObject>(aWall), aRectangleShape1, aRectangleShape2, "", 1, 0)
{
}
/**
 *
 */
WallShape::~WallShape()
{
}
/**
 *
 */
WallPtr WallShape::getWall() const
{
	return std::dynamic_pointer_cast<Wall>(getModelObject());
}
/**
 *
 */
void WallShape::setWall( WallPtr aWall)
{
	setModelObject(std::dynamic_pointer_cast<ModelObject>(aWall));
}
/**
 *
 */
void WallShape::setSelectedAt(	const Point& aPoint /*= DefaultPosition*/,
								bool aSelected /*= true*/)
{
	UNUSEDCAST( aPoint);
	setSelected( aSelected);
}
/**
 *
 */
RectangleShapePtr WallShape::hasEndPointAt( const Point& aPoint)
{
	if (getNode1()->occupies( aPoint))
	{
		return getNode1();
	}
	if (getNode2()->occupies( aPoint))
	{
		return getNode2();
	}
	return NULL;
}
/**
 *
 */
bool WallShape::hasEndPoint( RectangleShapePtr aRectangleShape)
{
	return getNode1()->getObjectId() == aRectangleShape->getObjectId() || getNode2()->getObjectId() == aRectangleShape->getObjectId();
}

/**
 *
 */
void WallShape::updateEndPoint( RectangleShapePtr aRectangleShape)
{
	if (getNode1()->getObjectId() == aRectangleShape->getObjectId())
	{
		std::cerr << "Setting node1" << std::endl;
		getWall()->setPoint1( aRectangleShape->getCentre(), false);
		return;
	}
	if (getNode2()->getObjectId() == aRectangleShape->getObjectId())
	{
		std::cerr << "Setting node2" << std::endl;
		getWall()->setPoint2( aRectangleShape->getCentre(), false);
		return;
	}
}
/**
 *
 */
void WallShape::draw( wxDC& dc)
{
	if (isSelected())
	{
		dc.SetPen( wxPen( WXSTRING( "RED"), getLineWidth(), wxSOLID));
	} else
	{
		dc.SetPen( wxPen( WXSTRING( "BLACK"), getLineWidth(), wxSOLID));
	}

	dc.DrawLine( getNode1()->getCentre().x, getNode1()->getCentre().y, getNode2()->getCentre().x, getNode2()->getCentre().y);
}
/**
 *
 */
bool WallShape::occupies( const Point& aPoint) const
{
	if (getNode1()->occupies( aPoint) || getNode2()->occupies( aPoint) || Shape2DUtils::isOnLine( getBegin(), getEnd(), aPoint, 2))
	{
		return true;
	}
	return false;
}
/**
 *
 */
std::string WallShape::asString() const
{
	std::ostringstream os;
	os << LineShape::asDebugString() << " WallShape: " << Shape2DUtils::asString( getBegin()) << "->" << Shape2DUtils::asString( getEnd());
	return os.str();
}
/**
 *
 */
std::string WallShape::asDebugString() const
{
	std::ostringstream os;
	os << "WallShape:\n";
	os << LineShape::asDebugString() << "\n";
	if (getWall())
	{
		os << getWall()->asDebugString();
	}
	return os.str();
}

