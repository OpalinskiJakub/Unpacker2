# UNPACKER2:

## About:
Tool to unpack the .hld binary data into ROOT tree structure. This README is probably outdated, so be watchful

## Prerequisite:
- ROOT at least 6.0
- BOOST at least 1.50 to run tests

## Installation:
Please see the file called [INSTALL](INSTALL).


## Usage:
- use as library to another program

## Setup description file:
All fields are required

- main module <READOUT>
  - inside one can specify the board which act as hubs of readout modules as <DATA_SOURCE>
    - <TYPE> possible: TRB2_S, HUB2, TRB3, SHOWER
    - <TRBNET_ADDRESS>, in case of standalone board put 0000
    - <HUB_ADDRESS>
    - <REFERENCE_CHANNEL> 
    - <MODULES> collection of modules connected to the hub 
      - <TYPE> possible: TRB2, HPTDC_HR, HPTDC_VHR, ECAL_ADC, LATTICE_TDC
      - <TRBNET_ADDRESS>
      - <NUMBER_OF_CHANNELS>
      - <CHANNEL_OFFSET>
      - <RESOLUTION>
      - <MEASUREMENT_TYPE> possible TDC, ADC


eg for standalone TRB2 with 4 TDCs running in high resolution:
<?xml version="1.0"?>
<READOUT>
  <DEBUG>OFF</DEBUG>
  <DATA_SOURCE>
    <TYPE>TRB2_S</TYPE>
    <TRBNET_ADDRESS>0000</TRBNET_ADDRESS>
    <HUB_ADDRESS>0372</HUB_ADDRESS>
    <REFERENCE_CHANNEL>31</REFERENCE_CHANNEL>
    <MODULES>
      <MODULE>
	<TYPE>HPTDC_HR</TYPE>
	<TRBNET_ADDRESS>0000</TRBNET_ADDRESS>
	<NUMBER_OF_CHANNELS>32</NUMBER_OF_CHANNELS>
	<CHANNEL_OFFSET>0</CHANNEL_OFFSET>
	<RESOLUTION>100</RESOLUTION>
	<MEASUREMENT_TYPE>TDC</MEASUREMENT_TYPE>
      </MODULE>
      <MODULE>
	<TYPE>HPTDC_HR</TYPE>
	<TRBNET_ADDRESS>0001</TRBNET_ADDRESS>
	<NUMBER_OF_CHANNELS>32</NUMBER_OF_CHANNELS>
	<CHANNEL_OFFSET>32</CHANNEL_OFFSET>
	<RESOLUTION>100</RESOLUTION>
	<MEASUREMENT_TYPE>TDC</MEASUREMENT_TYPE>
      </MODULE>
      <MODULE>
	<TYPE>HPTDC_HR</TYPE>
	<TRBNET_ADDRESS>0002</TRBNET_ADDRESS>
	<NUMBER_OF_CHANNELS>32</NUMBER_OF_CHANNELS>
	<CHANNEL_OFFSET>64</CHANNEL_OFFSET>
	<RESOLUTION>100</RESOLUTION>
	<MEASUREMENT_TYPE>TDC</MEASUREMENT_TYPE>
      </MODULE>
      <MODULE>
	<TYPE>HPTDC_HR</TYPE>
	<TRBNET_ADDRESS>0003</TRBNET_ADDRESS>
	<NUMBER_OF_CHANNELS>32</NUMBER_OF_CHANNELS>
	<CHANNEL_OFFSET>96</CHANNEL_OFFSET>
	<RESOLUTION>100</RESOLUTION>
	<MEASUREMENT_TYPE>TDC</MEASUREMENT_TYPE>
      </MODULE>
    </MODULES>
  </DATA_SOURCE>
</READOUT>