  #include <Servo.h>

#define servo 9
#define fim_de_curso 3
#define led_ligado 5
#define led_borrifa 4

Servo myservo;  
typedef enum state
{
  OFF,
  ON
}st;
int estado = OFF;
   // variable to store the servo position
void ativa()
{
  estado = ON;
}

void setup() {
  myservo.attach(servo);  // attaches the servo on pin 9 to the servo object
  pinMode(led_ligado, OUTPUT);
  pinMode(led_borrifa, OUTPUT);
  pinMode(fim_de_curso, INPUT_PULLUP);
  myservo.write(0);
  digitalWrite(led_ligado,HIGH);
  attachInterrupt (digitalPinToInterrupt(fim_de_curso),ativa,FALLING);
}


void loop() {
 //myservo.write(0);
   if(estado == ON)
   {
      digitalWrite(led_borrifa, HIGH);
      myservo.write(179);
      delay(500);
      digitalWrite(led_borrifa,LOW);
      estado = OFF;
   }
  
   /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);
  }       */
     myservo.write(0);
   //myservo.write(0);
}
