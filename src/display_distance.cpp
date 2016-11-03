#include "display_distance.h"

namespace rviz_plugins
{
	QLabel* distance;

	void topic_callback(const std_msgs::String::ConstPtr& msg)
	{
		distance->clear();
		distance->setText( msg->data.c_str() ) ;
	}

	Display_distance::Display_distance( QWidget* parent ): rviz::Panel( parent )
	{
		sub = nh.subscribe("distance_topic", 1000, topic_callback);

		display = new QHBoxLayout;
		display -> addWidget( new QLabel( "Distance:" ));

		distance = new QLabel;
		distance -> setText("none");

		display -> addWidget( distance );

		layout = new QVBoxLayout;
		layout -> addLayout( display );
		setLayout( layout );
	}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Display_distance, rviz::Panel )
