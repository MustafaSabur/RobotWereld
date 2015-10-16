/*
 * Copyright (c) 2014 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to RobotWorld@Askesis.nl.
 *
 * Author: jkr
 */

#include "ViewObject.hpp"

ViewObject::ViewObject() : objectId(ObjectId::newObjectId())
{
}

ViewObject::ViewObject(ModelObjectPtr aModelObject) :
				objectId(ObjectId::newObjectId()),
				modelObject(aModelObject)
{
	if(modelObject)
	{
		handleNotificationsFor(*modelObject);
	}
}

ViewObject::~ViewObject()
{
}

/**
 *
 */
const ObjectId& ViewObject::getObjectId() const
{
	return objectId;
}
/**
 *
 */
ModelObjectPtr ViewObject::getModelObject() const
{
	return modelObject;
}
/**
 *
 */
void ViewObject::setModelObject(ModelObjectPtr aModelObject)
{
	rebindModelObject(aModelObject);
}
/**
 * This function will call ModelObject::addReference.
 * It will stop handling the notifications for the old object,
 * start handling the notifications for the new object
 * and reset this ViewObject (derived) class.
 *
 * See ViewObject::resetViewObject
 */
void ViewObject::rebindModelObject(ModelObjectPtr aModelObject)
{
	if(modelObject)
	{
		stopHandlingNotificationsFor(*modelObject);
	}

	modelObject = aModelObject;

	if(modelObject)
	{
		handleNotificationsFor(*modelObject);
	}
}



