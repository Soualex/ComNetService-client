#include <iostream>
#include <cstdio>
#include "Network/Network.h"

using namespace std;
using namespace sf;

int main()
{
    AppWindow app_window;
    Network network;

    app_window.create(VideoMode(800, 600), "ComNetService");

    while (app_window.isOpen())
    {
        if (network.isConnected())
        {

        }
        else
        {
            LoginWindow login_window;

            login_window.create(VideoMode(800, 600), "Connexion");

            while (login_window.isOpen())
            {
                
            }
        }
    }

    return 0;
}
