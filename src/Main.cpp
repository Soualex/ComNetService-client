#include <iostream>
#include <cstdio>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

int main()
{
    TcpSocket socket;
    Socket::Status socket_status;

    socket_status = socket.connect("127.0.0.1", 9983);
    socket.setBlocking(false);

    if (socket_status == Socket::Done)
    {
        cout << "Server address : " << socket.getRemoteAddress() << endl;
        cout << "Server port : " << socket.getRemotePort() << endl;
    }
    else
    {
        cout << "Connection error !" << endl;
    }


    while (socket_status == Socket::Done)
    {
                string message;
                Packet packet;

                if (socket.receive(packet) == Socket::Done)
                {
                    if (packet >> message)
                    {
                        cout << message << endl;
                    }
                    else
                    {
                        cout << "Message could not be read !" << endl;
                    }
                }
        else
        {
            Packet packet;
            string message;

            cout << "Votre message : ";
            cin >> message;
            packet << message;
            
            if (socket.send(packet) != Socket::Done)
            {
                cout << "Failed to sent the message..." << endl;
            }
            else
            {
                cout << "Message sent !" << endl;
            }
        }
    }

  return 0;
}
