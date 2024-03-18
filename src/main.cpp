#include "Unpacker2.h"

int main() {

  Unpacker2 unpacker;


  std::string inputFile = "input.bin";
  std::string inputPath = "";
  std::string outputPath = "";
  std::string configFile = "config.xml";
  int numberOfEvents = 1000;
  int refChannelOffset = 0;
  std::string totCalibFile = "tot_calibration.txt";
  std::string tdcCalibFile = "tdc_calibration.txt";

  // Call UnpackSingleStep method
  unpacker.UnpackSingleStep(inputFile, inputPath, outputPath, configFile, numberOfEvents, refChannelOffset, totCalibFile, tdcCalibFile);

  return 0;
}
