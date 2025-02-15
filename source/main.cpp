#include "scene.h"

#include "raylib.h"

#include "oscpack/osc/OscReceivedElements.h"
#include "oscpack/osc/OscPacketListener.h"
#include "oscpack/ip/UdpSocket.h"

#include <iostream>
#include <memory>
#include <cstring>

#define PORT 7000

class MaxReceiver : public osc::OscPacketListener {
    protected:
    
        virtual void ProcessMessage( const osc::ReceivedMessage& message, 
                    const IpEndpointName& remoteEndpoint )
        {
            (void) remoteEndpoint; // suppress unused parameter warning

            std::cout << message.AddressPattern() << std::endl;
        }
    };

int main() {
    SetTargetFPS(60);
    std::cout << "running -------------" << std::endl;
    MaxReceiver maxReceiver;

    UdpListeningReceiveSocket s(
            IpEndpointName(IpEndpointName::ANY_ADDRESS, PORT),
            &maxReceiver);

    std::unique_ptr<Scene> scene = std::make_unique<Scene>();

    while (!WindowShouldClose()) {
        scene->showGrid();
        scene->draw();
    }

    s.RunUntilSigInt();

    return 0;
}
