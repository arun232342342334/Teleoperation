#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

void messageCb(const std_msgs::String& msg){
  const char *key = msg.data;
  if (strcmp(key, "w") == 0) {
    // Code to move motor forward
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
  } else if (strcmp(key, "s") == 0) {
    // Code to move motor backward
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  } else if (strcmp(key, "a") == 0) {
    // Code to turn motor left
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  } else if (strcmp(key, "d") == 0) {
    // Code to turn motor right
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
  }
  else if (strcmp(key, "z") == 0) {
    // Code to  motor stop
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
  }
}

ros::Subscriber<std_msgs::String> sub("key_clicks", &messageCb);

void setup(){
  nh.initNode();
  nh.subscribe(sub);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop(){
  nh.spinOnce();
  delay(10);
}
