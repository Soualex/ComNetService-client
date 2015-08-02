#ifndef APPWINDOW_H
#define APPWINDOW_H

#include <SFML/Graphic.hpp>

class AppWindow : public sf::RenderWindow
{
	public:
		void render();
		void checkEvents();
};

#endif