This repo has the source code for running a esp8266 with the blynk firmware as said this is just for starting up a 3 phase genset remotely
instrutions for running this code
before all of this do make a blynk account and make a new template with mapping to 
virtualpins and its accompaning items
download the source code or git clone the repo or fork the repo 
open up your choice of programmer such as ArduinoIDE/CLI or esptool for flashing the firmware 
open up the code and place all the *.h header files in the same dir 
open and edit the main_code.ino file and 
```c++
#define BLYNK_TEMPLATE_ID "template_id" // replace with the respective template id
#define BLYNK_TEMPLATE_NAME "template_name" // replace with the respective template name
```
try to build the firmware or verify if there are any errors prior to flashing 
finally flash the firware with 
plug in the board and power it up 
next open up the blynk app then add new device scan for the device and connect to it 
map the button and then its done post setup includes mapping of virtual pins for the actual pins 
