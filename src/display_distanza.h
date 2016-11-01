#ifndef TELEOP_PANEL_H
#define TELEOP_PANEL_H

#include <iostream>

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <rviz/panel.h>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

namespace rviz_plugins
{
	class Display_distanza: public rviz::Panel
	{
		Q_OBJECT

		public:
		Display_distanza( QWidget* parent = 0 );

		QHBoxLayout *display;
		QVBoxLayout *layout;

		protected:
		ros::NodeHandle nh;
		ros::Subscriber sub;
	};

} // end namespace rviz_plugins

#endif
