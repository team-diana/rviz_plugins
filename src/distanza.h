#ifndef DISTANZA_H
#define DISTANZA_H

#include <ros/ros.h>
#include <rviz/tool.h>
#include <std_msgs/String.h>

namespace Ogre
{
class SceneNode;
class Vector3;
}

namespace rviz
{
class VectorProperty;
class VisualizationManager;
class ViewportMouseEvent;
}

namespace rviz_plugins
{

class Distanza: public rviz::Tool
{
Q_OBJECT
public:
  Distanza();
  ~Distanza();

  virtual void onInitialize();

  virtual void activate();
  virtual void deactivate();

  virtual int processMouseEvent( rviz::ViewportMouseEvent& event );

  virtual void load( const rviz::Config& config );
  virtual void save( rviz::Config config ) const;

private:
  ros::NodeHandle n;
  ros::Publisher topic = n.advertise<std_msgs::String>("topic_distanza", 1000);
};

}

#endif
