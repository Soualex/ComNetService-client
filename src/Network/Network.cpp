#include "Network.h"

using namespace sf;

void Network::connect()
{
	socket_status = socket.connect("127.0.0.1", 9983);

    if (socket_status == Socket::Done)
    {
        socket.setBlocking(false);
        
    	cout << "Connected to " << socket.getRemoteAddress() << " on port " << socket.getRemotePort() << "." << endl;
    }
    else
    {
        cout << "Connection error !" << endl;
    }
}

void Network::disconnect()
{
	
}

bool Network::isConnected()
{
	if (socket_status != Socket::Disconnected)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

Packet Network::checkLine()
{
    Packet packet;

    switch (socket.receive(packet))
    {
    	case Socket::Done:
            return packet;
    	break;

    	case Socket::NotReady:
    	break;

      	case Socket::Partial:
    	break;

    	case Socket::Disconnected:
    		socket_status = Socket::Disconnected;
    	break;

     	case Socket::Error:
    	break;
    }
}

void Network::send(Packet packet)
{

}