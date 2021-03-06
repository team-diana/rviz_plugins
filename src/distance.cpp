#include "distance.h"

namespace rviz_plugins
{

	Distance::Distance()
	{
		shortcut_key_ = 'd';

		topic = n.advertise<std_msgs::String>("distance_topic", 1000);
	}


	void Distance::activate()
	{
	}

	void Distance::deactivate()
	{
	}

	int Distance::processMouseEvent( rviz::ViewportMouseEvent& event )
	{
		Ogre::Vector3 pos;
		if( context_->getSelectionManager()->get3DPoint( event.viewport, event.x, event.y, pos ) && event.leftDown())
		{
			std_msgs::String msg;
			std::stringstream ss;
			ss << pos;
			msg.data = ss.str();
			topic.publish(msg);
		}
	}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Distance, rviz::Tool )
