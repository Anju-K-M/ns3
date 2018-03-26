#include "ns3/core-module.h"
#include "ns3/applications-module.h"

#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/netanim-module.h"


using namespace ns3;


int
main (int argc, char *argv[])
{
  CommandLine cmd;
  cmd.Parse (argc, argv);


  NodeContainer nodes;
  nodes.Create (5);


  MobilityHelper mobility;



  mobility.SetPositionAllocator ("ns3::GridPositionAllocator",
                                     "MinX", DoubleValue (10.0),
                                     "MinY", DoubleValue (30.0),
                                    "DeltaX", DoubleValue (10.0),
                                     "DeltaY", DoubleValue (10.0),
                                     "GridWidth", UintegerValue (15),
                                     "LayoutType", StringValue ("RowFirst"));
      // each object will be attached a static position.
      // i.e., once set by the "position allocator", the
      // position will never change.
      mobility.SetMobilityModel ("ns3::ConstantPositionMobilityModel");

      // finalize the setup by attaching to each object
      // in the input array a position and initializing
     // this position with the calculated coordinates.
      mobility.Install (nodes);

     // iterate our nodes and print their position.
      for (NodeContainer::Iterator j = nodes.Begin ();  j != nodes.End (); ++j)
        {
          Ptr<Node> object = *j;
          Ptr<MobilityModel> position = object->GetObject<MobilityModel> ();
          NS_ASSERT (position != 0);
          Vector pos = position->GetPosition ();
          std::cout << "x=" << pos.x << ", y=" << pos.y << ", z=" << pos.z << std::endl;
        }







  AnimationInterface anim("demo.xml");

  anim.SetBackgroundImage("/home/user/Downloads/roa.png",0, 0, 0.05, 0.055, 1.0);
  for(int i=0;i<5;i++)
	  anim.UpdateNodeImage (i, anim.AddResource ("/home/user/Documents/i.png") );



  //this file created in the ns-3.27

    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
  }
