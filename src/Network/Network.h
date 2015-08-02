#ifndef NETWORK_H
#define NETWORK_H

#include <SFML/Network.hpp>

class Network
{
	public:
		void connect();
		void disconnect();
		void isConnected();
		Packet checkLine();
		void send(sf::Packet packet);

	private:
		sf::TcpSocket socket;
		sf::Socket::Status socket_status;
};

#endif