#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4;

int greenled = 13;
int redled = 12;
int whiteled = 11;

#define password_lenght 5

 char Data[password_lenght];
 char master[password_lenght]= "0000";
 byte datacount = 0,mastercount=0;
 bool pass_is_good;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(greenled,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(whiteled,OUTPUT);
  Serial.print("enter password");
  digitalWrite(whiteled, HIGH);


}
  
void loop(){

  char customKey = customKeypad.getKey();
    
  
  
  if (customKey){
    Data[datacount] = customKey;
    Serial.print(Data[datacount]);
    datacount++;
        digitalWrite(greenled, LOW);
    digitalWrite(redled, LOW);
    digitalWrite(whiteled, HIGH);
    
  }
  
  if(datacount == password_lenght-1) // if the array index is equal to the number of expected chars, compare data to master
  {

    Serial.print("Password is ");

    if(!strcmp(Data, master)) // equal to (strcmp(Data, Master) == 0)
      {Serial.print("Good");
          digitalWrite(greenled, HIGH);
          digitalWrite(redled, LOW);
          digitalWrite(whiteled, LOW);
      }
    else{
      Serial.print("Bad");
       digitalWrite(greenled, LOW);
       digitalWrite(redled, HIGH);
       digitalWrite(whiteled, LOW);  
        }
    delay(1000);// added 1 second delay to make sure the password is completely shown on screen before it gets cleared.
    clearData();   
  }
}

void clearData()
{
  while(datacount !=0)
  {   // This can be used for any array size, 
    Data[datacount--] = 0; //clear array for new data
  }
  return;
}

  
  
