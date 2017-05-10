#include "display_distance.h"

namespace rviz_plugins
{
	Display_distance::Display_distance( QWidget* parent ): rviz::Panel( parent )
	{
		sub = nh.subscribe("distance_topic", 1000, this.topic_callback);

		new QLabel("Distance:", this);
		distance = new QLabel("null", this);
	}

	void Display_distance::topic_callback(const std_msgs::String::ConstPtr& msg)
	{
		distance->setText( msg->data.c_str() ) ;
	}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Display_distance, rviz::Panel )
