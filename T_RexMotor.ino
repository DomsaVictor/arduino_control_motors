  //motor1 RIGHT
#define A1    4
#define B1    5
#define PWM1  6
  
  //motor2 LEFT
#define A2    9
#define B2    8
#define PWM2  10

int state;
int flag = 0;

void setup() {
  Serial.begin(9600);
  
  //motor1
    pinMode(A1 , OUTPUT);
    pinMode(B1 , OUTPUT);
    pinMode(PWM1 , OUTPUT);
 
  //motor2
    pinMode(A2 , OUTPUT);
    pinMode(B2 , OUTPUT);
    pinMode(PWM2 , OUTPUT);
}



void loop() {
    if(Serial.available() > 0){
      state = Serial.read();
      flag = 0;
    }

    if( state == 'S' ){
      M1STOP();
      M2STOP();
      if(flag == 0){
        Serial.println("T-rex: stop");
        flag = 1;
      }
    }
    else if( state == 'F' ){
      M1Forward(100);
      M2Forward(100);
      if( flag == 0 ){
        Serial.println("T-rex: Forward");
        flag = 1;
      }
    }
    else if(state == 'B' ){
      M1Backward(100);
      M2Backward(100);
      if(flag == 0 ){
        Serial.println("T-rex: Backward");
        flag = 1;
      }
    }

    else if( state == 'R' ){
       M1Backward(100);
       M2Forward(100);
    }
    else if (state == 'L' ){
      M1Forward(100);
      M2Backward(100);
    }
    else if (state == 'G' ){
      M1Forward(250);
      M2Forward(50);
    }
    else if (state == 'I' ){
      M1Forward(50);
      M2Forward(250);
    }
    else if(state == 'H'){
      M1Backward(250);
      M2Backward(50);
    }
    else if (state == 'J'){
      M1Backward(50);
      M2Backward(250);
    }
}

    //motor 1 move forward
void M1Forward(int PWM1_val){
    analogWrite(PWM1, PWM1_val);
    digitalWrite(A1 , LOW);
    digitalWrite(B1 , HIGH);
}

    //motor 1 move backward
void M1Backward(int PWM1_val){
    analogWrite(PWM1, PWM1_val);
    digitalWrite(A1 , HIGH);
    digitalWrite(B1 , LOW);
}

    //motor 1 stop
void M1STOP (){
    analogWrite(PWM1, 0);
    digitalWrite(A1 , LOW);
    digitalWrite(B1 , LOW);
}


    //motor 2 move forward
void M2Forward(int PWM2_val){
    analogWrite(PWM2, PWM2_val);
    digitalWrite(A2 , LOW);
    digitalWrite(B2 , HIGH);
}

    //motor 2 move backward
void M2Backward(int PWM2_val){
    analogWrite(PWM2, PWM2_val);
    digitalWrite(A2 , HIGH);
    digitalWrite(B2 , LOW);
}

    //motor 2 stop
void M2STOP (){
    analogWrite(PWM2, 0);
    digitalWrite(A2 , LOW);
    digitalWrite(B2 , LOW);
}


