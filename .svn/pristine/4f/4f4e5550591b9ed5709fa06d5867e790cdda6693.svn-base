#ifndef VIEWOBJECT_HPP_
#define VIEWOBJECT_HPP_

/*
 * Copyright (c) 2014 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to RobotWorld@Askesis.nl.
 *
 * Author: jkr
 */

#include "Observer.hpp"
#include "ObjectId.hpp"
#include "ModelObject.hpp"

/**
 *
 */
class ViewObject : public Observer
{
	public:
		/**
		 * @name Constructors and destructor
		 */
		//@{
		/**
		 * Default constructor
		 */
		ViewObject();
		/**
		 * ModelObject constructor
		 */
		ViewObject(ModelObjectPtr aModelObject);
		/**
		 * Destructor
		 */
		virtual ~ViewObject();
		//@}

		/**
		 * @name Accessors and mutators
		 */
		//@{
		/**
		 * Accessor for the ViewObject objectId
		 */
		const ObjectId& getObjectId() const;
		/**
		 * Accessor for the ModelObject
		 */
		ModelObjectPtr getModelObject() const;
		/**
		 * Mutator for the ModelObject
		 *
		 * See rebindModelObject and resetViewObject
		 */
		void setModelObject(ModelObjectPtr aModelObject) ;
		//@}
	protected:
		/**
		 * @name ViewObject implementation
		 */
		//@{
		/**
		 * Stops observing the current ModelObject, starts observing the new ModelObjects and
		 * displays it by calling ViewObject::resetViewObject
		 */
		virtual void rebindModelObject(ModelObjectPtr aModelObject);
		//@}

	private:
		ObjectId objectId;
		ModelObjectPtr modelObject;
};

#endif // VIEWOBJECT_HPP_ 
