#include "display_distanza.h"

namespace rviz_plugins
{
	QLabel* distanza;

	void topic_callback(const std_msgs::String::ConstPtr& msg)
	{
		distanza->clear();
		distanza->setText( msg->data.c_str() ) ;
	}

	Display_distanza::Display_distanza( QWidget* parent ): rviz::Panel( parent )
	{
		sub = nh.subscribe("topic_distanza", 1000, topic_callback);

		display = new QHBoxLayout;
		display->addWidget( new QLabel( "Distanza:" ));

		distanza = new QLabel;
		distanza->setText("none");

		display->addWidget( distanza );

		layout = new QVBoxLayout;
		layout->addLayout( display );
		setLayout( layout );
	}

} // end namespace rviz_plugins

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(rviz_plugins::Display_distanza,rviz::Panel )
