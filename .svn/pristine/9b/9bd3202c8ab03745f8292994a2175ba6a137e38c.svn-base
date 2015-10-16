/*
 * Copyright (c) 2014 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to RobotWorld@Askesis.nl.
 *
 * Author: jkr
 */

#include "ModelObject.hpp"
#include <sstream>
#include "TypeInfo.hpp"

/**
 *
 */
ModelObject::ModelObject() : objectId(ObjectId::newObjectId())
{
}
/**
 *
 */
ModelObject::~ModelObject()
{
}
/**
 *
 */
std::string ModelObject::asString() const
{
	std::ostringstream os;
	os << __PRETTY_FUNCTION__ << " : " << typeinfoFor(*this) <<  ", " << "ObjectId: " <<  getObjectId();
	return os.str();
}
/**
 *
 */
std::string ModelObject::asDebugString() const
{
	std::ostringstream os;
	os << __PRETTY_FUNCTION__ << " : " << typeinfoFor(*this) << "\n";
	os << "ObjectId: " <<  getObjectId();
	return os.str();
}
