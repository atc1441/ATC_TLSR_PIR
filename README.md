# ATC_TLSR_PIR
Custom firmware for the cheap Telink TLSR based PIR Bluetooth/Zigbee Sensors



# Infos:

WebSerial Firmware flasher Tool: 
https://atc1441.github.io/ATC_TLSR_Paper_UART_Flasher.html

WebBluetooth Firmware OTA Flashing:
https://atc1441.github.io/ATC_TLSR_Paper_OTA_writing.html

#### Compiling:
Python needs to be installed
##### Windows:
To compile under windows navigate with a command prompt to the "Firmware" folder

Enter "makeit.exe" and wait till the Compiling is done.


##### Linux:
Navigate with a Terminal into the "Firmware" Folder

Enter "make" and wait till the Compiling is done.

#### Flashing:
Open the Compiled .bin firmware with the WebSerial Flasher and write it to Flash.

On first Connection it is needed to Unlock the flash of the TLSR8359
