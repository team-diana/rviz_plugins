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

void topic_callback(const std_msgs::String::ConstPtr& msg);

class Display_distanza: public rviz::Panel
{
Q_OBJECT

public:
  Display_distanza( QWidget* parent = 0 );

  virtual void load( const rviz::Config& config );
  virtual void save( rviz::Config config ) const;

protected:
  ros::NodeHandle nh;
  ros::Subscriber sub;
};

} // end namespace rviz_plugins

#endif
