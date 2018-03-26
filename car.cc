#include "ns3/core-module.h"
#include "ns3/mobility-module.h"
#include "ns3/ns2-mobility-helper.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main (int argc, char *argv[])
{

// Create Ns2MobilityHelper with the specified trace log file as parameter
 Ns2MobilityHelper ns2 = Ns2MobilityHelper ("MobisimFreeway.txt");
 // Create Moble nodes.
 NodeContainer MobileNodes;
 MobileNodes.Create (5);
 // configure movements for each node, while reading trace file
 ns2.Install ();
 AnimationInterface  anim("car.xml");
 //Setup Some image icon for the moving vehicles
 for(int i=0;i<5;i++) anim.UpdateNodeImage (i, anim.AddResource ("/home/user/Documents/i.png") );
 //Simulator::Stop (Seconds (100));


 Simulator::Run();
 Simulator::Destroy();
 return 0;
}
