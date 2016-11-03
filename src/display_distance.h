#ifndef DISPLAY_DISTANCE_H
#define DISPLAY_DISTANCE_H

#include <iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <rviz/panel.h>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

namespace rviz_plugins
{
	class Display_distance: public rviz::Panel
	{
		Q_OBJECT

		public:
		Display_distance( QWidget* parent = 0 );

		QHBoxLayout *display;
		QVBoxLayout *layout;

		protected:
		ros::NodeHandle nh;
		ros::Subscriber sub;
	};

} // end namespace rviz_plugins

#endif
