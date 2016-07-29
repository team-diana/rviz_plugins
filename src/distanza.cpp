#include <iostream>
#include <sstream>

#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

#include <rviz/viewport_mouse_event.h>
#include <rviz/visualization_manager.h>
#include <rviz/geometry.h>
#include <rviz/properties/vector_property.h>
#include <rviz/selection/selection_manager.h>

#include "distanza.h"

namespace rviz_plugins
{

Distanza::Distanza()
{
  shortcut_key_ = 'd';
}

Distanza::~Distanza()
{
}

void Distanza::onInitialize()
{
}

void Distanza::activate()
{
}

void Distanza::deactivate()
{
}

int Distanza::processMouseEvent( rviz::ViewportMouseEvent& event )
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

void Distanza::save( rviz::Config config ) const
{
}

void Distanza::load( const rviz::Config& config )
{
}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Distanza, rviz::Tool )
