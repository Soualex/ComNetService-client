#include "AppWindow.h"

void AppWindow::Render()
{
	
}

void AppWindow::checkEvents()
{
	Event event;

	while (pollEvent(event))
	{
		switch (event.type)
		{
			case Event::Closed:
				window.close();
			break;

			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Return))
				{
					Packet packet;

					packet << input_message.getString().toAnsiString();

					socket.send(packet);
				}
			break;

			case Event::TextEntered:
				if (event.text.unicode < 128 && !Keyboard::isKeyPressed(Keyboard::Return))
				{
					// input_message.setString(input_message.getString().toAnsiString()+static_cast<char>(event.text.unicode));

					cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
				}
			break;

			default:
			break;
		}
	}
}