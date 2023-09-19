
#include <AFMotor.h>
int speedx=120; 
int speedy=180;
AF_DCMotor motorFR(1);
AF_DCMotor motorFL(2);
AF_DCMotor motorBR(3);
AF_DCMotor motorBL(4);



void brake()
 {
                          
                          motorFR.setSpeed(0); 
                          motorFL.setSpeed(0);
                          motorBR.setSpeed(0);
                          motorBL.setSpeed(0);
                          }
                          
  void forward()
  {           
                          
                          motorFR.setSpeed(speedx);
                          motorFL.setSpeed(speedx);
                          motorBR.setSpeed(speedx);
                          motorBL.setSpeed(speedx);
                          motorFR.run(FORWARD);
                          motorFL.run(FORWARD);
                          motorBR.run(FORWARD);
                          motorBL.run(FORWARD);
                          }


                          
void left_90()
 {                        
                          motorFR.setSpeed(speedy);
                          motorFL.setSpeed(speedy);
                          motorBR.setSpeed(speedy);
                          motorBL.setSpeed(speedy);
                          motorFR.run(BACKWARD);
                          motorFL.run(FORWARD);
                          motorBR.run(BACKWARD);
                          motorBL.run(FORWARD);
                          }


void left_full_90()
 {                                              
                         
                          motorFR.setSpeed(speedx);
                          motorFL.setSpeed(speedy);
                          motorBR.setSpeed(speedx);
                          motorBL.setSpeed(speedy);
                          motorFR.run(FORWARD);
                          motorFL.run(BACKWARD);
                          motorBR.run(FORWARD);
                          motorBL.run(BACKWARD);
                          
                          
                          }
                                                   
void right_90()
 {                       

                          motorFR.setSpeed(speedy);
                          motorFL.setSpeed(speedy);
                          motorBR.setSpeed(speedy);
                          motorBL.setSpeed(speedy);
                          motorFR.run(FORWARD);
                          motorFL.run(BACKWARD);
                          motorBR.run(FORWARD);
                          motorBL.run(BACKWARD);
                          
                          
                          }

            
 
 
                                                

void turn_180(){
                          motorFR.setSpeed(speedx);
                          motorFL.setSpeed(speedx);
                          motorBR.setSpeed(speedx);
                          motorBL.setSpeed(speedx);
                          motorFR.run(FORWARD);
                          motorFL.run(BACKWARD);
                          motorBR.run(FORWARD);
                          motorBL.run(BACKWARD);
                          delay(1000);
                          motorFR.run(BRAKE);
                          motorFL.run(BRAKE);
                          motorBR.run(BRAKE);
                          motorBL.run(BRAKE);
                          delay(500);}




                          
void setup() {

  
 pinMode(22,OUTPUT);
 pinMode(23,OUTPUT);
 pinMode(25,OUTPUT); //Vcc of IR sensors  other two snesors Vcc directly connected with 5V.
 
 pinMode(33,OUTPUT);  //Vcc of Front Middle Ultra Sonic
 pinMode(27,OUTPUT);  //GND of Front middle Ultrasonic
 
 pinMode(43,OUTPUT);   //Vcc of Middle front left Ultra Sonic 
 pinMode(37,OUTPUT);   //Gnd of Middle front left Ultra Sonic
 
 pinMode(45,OUTPUT);   //Vcc of Back left Ultra Sonic
 pinMode(51,OUTPUT);   //Gnd of Back Ledt Ultra sonnic
 

 digitalWrite(22,HIGH);
 digitalWrite(23,HIGH);
 digitalWrite(25,HIGH);
 digitalWrite(33,HIGH);
 digitalWrite(43,HIGH);
 digitalWrite(45,HIGH);
 digitalWrite(27,LOW);
 digitalWrite(37,LOW);
 digitalWrite(51,LOW);

 motorFR.setSpeed(0); 
 motorFL.setSpeed(0);
 motorBR.setSpeed(0);
 motorBL.setSpeed(0);

 delay(1000);
  
  Serial.begin(9600);
  
  }



void loop() {

   if ((analogRead(A15)>400)& (analogRead(A14)>400)&(analogRead(A13)>400)&(analogRead(A12)>400)&(analogRead(A11)>400)){
    delay(20);
    right_90();
    
    
    }


  
  else if ((analogRead(A15)<70) or (analogRead(A14)<70)){
    delay(20);
    left_90();}                  //left only most detecting

  
 else if ((analogRead(A11)<70)& (analogRead(A12)<70)&(analogRead(A13)<70)&(analogRead(A14)<70)){
    delay(20);
    left_90();
    
    }
  
  else if ((analogRead(A15)<70)& (analogRead(A14)<70)&(analogRead(A13)<70)&(analogRead(A12)<70)&(analogRead(A11)<70)){
    delay(20);
    left_90();
    
    }
    
  

  else if ((analogRead(A11)<70)& (analogRead(A12)<=70)&(analogRead(A13)<70)){
    forward();
    delay(30); 
    

    if ((analogRead(A13)>800)){
      right_90();}
    else if ((analogRead(A13)<70)){
      forward();}
    
    
    }

  
   else if ((analogRead(A12)<70) and (analogRead(A11)<70)and (analogRead(A13)<70) ){
    
    right_90();}                  //left only most detecting
   
   else if ((analogRead(A12)<70) or (analogRead(A11)<70) ){
    
    right_90();}        
  
 
   else if ((analogRead(A13)<70)){forward();
  }
  


else if ((analogRead(A15)<70)){left_90();}
else if ((analogRead(A14)<70)){left_90();}
else if ((analogRead(A12)<70)){right_90();}
else if ((analogRead(A11)<70)){right_90();}

  
else{forward();}
  
  
                                      



int x1= analogRead(A15);
int x2=analogRead(A14);
int x3=analogRead(A13);
int x4=analogRead(A12);
int x5=analogRead(A11);


Serial.println(x5);



}








  
                            
