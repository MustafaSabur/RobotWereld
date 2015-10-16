#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "Config.hpp"

#include <queue>
#include <string>
#include "Thread.hpp"
#include <boost/chrono.hpp>

template< typename QueueContentType >
class Queue
{
	public:
		/**
		 *
		 */
		void enqueue( const QueueContentType& anElement)
		{
			std::unique_lock< std::mutex > lock( queueBusy);
			queue.push( anElement);
			queueFull.notify_one();
		}
		/**
		 *
		 */
		QueueContentType dequeue()
		{
			std::unique_lock< std::mutex > lock( queueBusy);
			while (queue.empty())
				queueFull.wait( lock);

			QueueContentType front = queue.front();
			queue.pop();
			return front;
		}
		/**
		 *
		 */
		size_t size() const
		{
			return queue.size();
		}

	private:
		std::queue< QueueContentType > queue;
		std::mutex queueBusy;
		std::condition_variable queueFull;
};

#endif /* QUEUE_HPP_ */
