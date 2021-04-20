int SER  = 2;
int RCLK = 3;  
int SRCLK = 4; 


int datos1 = 255;
//int datos1 = 111111111;
int datos2 = 85;
//int datos1 = B01010101;

void setup()
{
  pinMode(SER , OUTPUT);
  pinMode(RCLK , OUTPUT);
  pinMode(SRCLK , OUTPUT);

}

void loop(){

  shiftOut(SER, SRCLK, LSBFIRST, datos2);
  shiftOut(SER, SRCLK, LSBFIRST, datos1);
  
  digitalWrite(RCLK, 1);  
  digitalWrite(RCLK, 0);

  
}