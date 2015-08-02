#ifndef PACKET_H
#define PACKET_H

#include <SFML/Network.hpp>

class Packet : public sf::Packet
{
	public:
		bool isStandard();
};

#endif