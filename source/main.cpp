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
    
        virtual void ProcessMessage( const osc::ReceivedMessage& m, 
                    const IpEndpointName& remoteEndpoint )
        {
            (void) remoteEndpoint; // suppress unused parameter warning
    
            try{
                // example of parsing single messages. osc::OsckPacketListener
                // handles the bundle traversal.
                
                if (m.AddressPattern() == "/test1" ) {
                    // example #1 -- argument stream interface
                    osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
                    bool a1;
                    osc::int32 a2;
                    float a3;
                    const char *a4;
                    args >> a1 >> a2 >> a3 >> a4 >> osc::EndMessage;
                    
                    std::cout << "received '/test1' message with arguments: "
                        << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
                    
                }else if (m.AddressPattern() == "/test2") {
                    // example #2 -- argument iterator interface, supports
                    // reflection for overloaded messages (eg you can call 
                    // (*arg)->IsBool() to check if a bool was passed etc).
                    osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
                    bool a1 = (arg++)->AsBool();
                    int a2 = (arg++)->AsInt32();
                    float a3 = (arg++)->AsFloat();
                    const char *a4 = (arg++)->AsString();
                    if( arg != m.ArgumentsEnd() )
                        throw osc::ExcessArgumentException();
                    
                    std::cout << "received '/test2' message with arguments: "
                        << a1 << " " << a2 << " " << a3 << " " << a4 << "\n";
                }
            }catch( osc::Exception& e ){
                // any parsing errors such as unexpected argument types, or 
                // missing arguments get thrown as exceptions.
                std::cout << "error while parsing message: "
                    << m.AddressPattern() << ": " << e.what() << "\n";
            }
        }
    };

int main() {
    SetTargetFPS(60);

    MaxReceiver maxReceiver;

    std::unique_ptr<Scene> scene = std::make_unique<Scene>();

    while (!WindowShouldClose()) {
        scene->showGrid();
        scene->draw();
    }

    return 0;
}
