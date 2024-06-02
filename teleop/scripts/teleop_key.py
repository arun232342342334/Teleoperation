#!/usr/bin/env python3

import rospy
from std_msgs.msg import String
from sound_play.msg import SoundRequest
from sound_play.libsoundplay import SoundClient

def keyboard_input_publisher():
    rospy.init_node('keyboard_input_publisher', anonymous=True)
    pub = rospy.Publisher('key_clicks', String, queue_size=10)

    while not rospy.is_shutdown():
        key = input("Enter key (q to quit): ")
        voice_command = ""
        if key == "w":
        	voice_command= "Moving forward"
        	rospy.loginfo(voice_command)
        if key == "s":
        	voice_command= "Moving Backwards"
        	rospy.loginfo(voice_command)
        if key == "d":
        	voice_command= "Turning right"
        	rospy.loginfo(voice_command)
        if key == "a":
        	voice_command= "Turning left"
        	rospy.loginfo(voice_command)
        if key == "z":
        	voice_command= "stopping"
        	rospy.loginfo(voice_command)
        if key == "q":
        	voice_command= "Terminating"
        	rospy.loginfo(voice_command)
        	break
        if key == "w" or key == "s" or key == "a" or key == "d" or key == "z" or key == "q":	
        	pub.publish(key)
        else:
        	rospy.loginfo("INVALID INPUT")
        sound_out= SoundClient()
        sound_out.say(voice_command)
        

if __name__ == '__main__':
    try:
        keyboard_input_publisher()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

