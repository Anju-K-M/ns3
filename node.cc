//header files

#include "../build/ns3/command-line.h"
#include "../build/ns3/node-container.h"
#include "../build/ns3/simulator.h"
#include "ns3/netanim-module.h"



//name space declartion
using namespace ns3;


//main function
int main(int argc,char *argv[])
{

//terminal lines
CommandLine cmd;
cmd.Parse(argc,argv);



//node creation minimum code
NodeContainer node;
node.Create(1);

AnimationInterface  anim("node1.xml");

//AnimationInterface anim ("mysimulation.xml");
uint32_t resourceId1;
resourceId1 = anim.AddResource ("/home/user/Documents/i.png");
anim.UpdateNodeImage(0, resourceId1);  // "0" is the Node ID



anim.SetBackgroundImage("/home/user/Downloads/roa.png",0, 0, 0.075, 0.090, 1.0);


//anim.UpdateNodeImage (1, anim.AddResource ("/home/user/Documents/i.png") );
// simulator ruuning and destroy
Simulator::Run();
//Simulator::Destroy();
}
