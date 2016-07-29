#include "display_distanza.h"

namespace rviz_plugins
{

QLabel* distanza;

Display_distanza::Display_distanza( QWidget* parent )
  : rviz::Panel( parent )
{
  sub = nh.subscribe("topic_distanza", 1000, topic_callback);

  QHBoxLayout* display = new QHBoxLayout;
  display->addWidget( new QLabel( "Distanza:" ));
  distanza = new QLabel;
  distanza->setText("none");
  display->addWidget( distanza );

  QVBoxLayout* layout = new QVBoxLayout;
  layout->addLayout( display );
  setLayout( layout );
}

void topic_callback(const std_msgs::String::ConstPtr& msg)
{
  distanza->clear();
  distanza->setText( msg->data.c_str() ) ;
}

void Display_distanza::save( rviz::Config config ) const
{
}

void Display_distanza::load( const rviz::Config& config )
{
}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Display_distanza,rviz::Panel )
