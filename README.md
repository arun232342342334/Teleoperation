# Teleoperation

It uses string messages for publishing the keys to the topic /key_clicks and the provided Arduino code the node which subscribes the same topic via rosserial protocol and giving commands to motors.

### Clone the Repo

 > git clone https://github.com/arun232342342334/Teleoperation.git

clone the package to your src folder in your workspace or copy the teleop_key.py code to your scripts folder and upload the teleop_ardi.ino file to your Arduino dev board

### Launching the teleop node

> roslaunch teleop teleop.launch
> 
