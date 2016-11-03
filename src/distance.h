#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
#include <sstream>
#include <std_msgs/String.h>

#include <ros/ros.h>
#include <rviz/tool.h>
#include <rviz/viewport_mouse_event.h>
#include <rviz/visualization_manager.h>
#include <rviz/geometry.h>
#include <rviz/properties/vector_property.h>
#include <rviz/selection/selection_manager.h>

#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

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

	class Distance: public rviz::Tool
	{
		Q_OBJECT

		public:
		Distance();

		virtual void activate();
		virtual void deactivate();
		virtual int processMouseEvent( rviz::ViewportMouseEvent& event );

		protected:
		ros::NodeHandle n;
		ros::Publisher topic;
	};

}

#endif
