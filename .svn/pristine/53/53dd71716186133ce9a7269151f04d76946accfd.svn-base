#ifndef MODELOBJECT_HPP_
#define MODELOBJECT_HPP_

/*
 * Copyright (c) 2014 Joost Kraaijeveld. See license.txt for details.
 * For information, bug reports and additions send an e-mail to RobotWorld@Askesis.nl.
 *
 * Author: jkr
 */

#include <boost/noncopyable.hpp>
#include <memory>
#include "Notifier.hpp"
#include "ObjectId.hpp"


class ModelObject;
typedef std::shared_ptr<ModelObject> ModelObjectPtr;

/**
 *
 */
class ModelObject : public boost::noncopyable,
					public Notifier
{
	public:
		/**
		 * @name Constructors and destructor
		 */
		//@{
		/**
		 *
		 */
		ModelObject();
		/**
		 *
		 */
		virtual ~ModelObject();
		//@}
		/**
		 * @name Operators
		 */
		//@{
		/**
		 * Equal to operator
		 */
		bool operator==( const ModelObject& aModelObject) const
		{
			return objectId == aModelObject.objectId;
		}
		/**
		 * Less than operator
		 */
		bool operator<( const ModelObject& aModelObject) const
		{
			return objectId < aModelObject.objectId;
		}
		//@}
		/**
		 *
		 */
		const ObjectId& getObjectId() const {return  objectId;}
		/**
		 * @name Debug functions
		 */
		//@{
		/**
		 * Returns a 1-line description of the object
		 */
		virtual std::string asString() const;
		/**
		 * Returns a description of the object with all data of the object usable for debugging
		 */
		virtual std::string asDebugString() const;
		//@}

	private:
		ObjectId objectId;
};

#endif // MODELOBJECT_HPP_ 
