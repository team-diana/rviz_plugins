#ifndef DISPLAY_DISTANCE_H
#define DISPLAY_DISTANCE_H

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <rviz/panel.h>

#include <QLabel>

namespace rviz_plugins
{
	class Display_distance: public rviz::Panel
	{
		Q_OBJECT

		public:
			Display_distance( QWidget* parent = 0 );

		protected:
			ros::NodeHandle nh;
			ros::Subscriber sub;

		private:
			QLabel* distance;

			void topic_callback(const std_msgs::String::ConstPtr& msg);
	};

} // end namespace rviz_plugins

#endif
