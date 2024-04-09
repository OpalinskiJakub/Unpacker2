#include "Unpacker2.h"

int main() {

  Unpacker2 unpacker;

  std::string inputFile = "xx14099113231.hld";
  std::string inputPath = "/home/jakub/CLionProjects/Unpacker2/data/";
  std::string outputPath = "/home/jakub/CLionProjects/Unpacker2/data/output/";
  std::string configFile = "/home/jakub/CLionProjects/Unpacker2/data/conf_trb3.xml";
  int numberOfEvents = 20;
  int refChannelOffset = 20;
  std::string totCalibFile = "";
  std::string tdcCalibFile = "/home/jakub/CLionProjects/Unpacker2/data/tdccalib.root";

  Unpacker2::EventHdr eventHeader = unpacker.hdr;
  std::cout << "Value seqNr before: " << eventHeader.seqNr << std::endl;
  unpacker.UnpackSingleStep(inputFile, inputPath, outputPath, configFile, numberOfEvents, refChannelOffset, totCalibFile, tdcCalibFile);
  std::cout << std::endl << "Value seqNr after: " << eventHeader.seqNr << std::endl;

  return 0;
}
