#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

const int numRows = 4;
const int numCols = 4;
char k[numRows][numCols] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols] = {5,4,3,2};
Keypad myKeypad = Keypad(makeKeymap(k),rowPins,colPins,numRows,numCols);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo myservo;

const String password = "2B8D";
String in_pass;

void setup() 
{
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("    WELCOME!    ");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print(" Automatic Lock ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Password?");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Then press '*' !");
  delay(1000);
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("waiting.........");
  delay(2000);
  lcd.clear();
}

void loop() 
{
  char keypressed = myKeypad.getKey();
  if(keypressed != NO_KEY)
  {
    lcd.setCursor(0, 0);
    myservo.attach(13);
  	if (keypressed == '*')
  	{ 
      if(password == in_pass)
      {
      	for(int pos=0;pos<=180;pos++)
  	  	{
    	  myservo.write(pos);
  		  delay(5);
  	  	}
      	lcd.print("....UNLOCKED....");
        delay(2000);
        for(int pos=180;pos>=0;pos--)
  	  	{
    	  myservo.write(pos);
  		  delay(5);
      	}
      	lcd.clear();
      	lcd.print(".....LOCKED.....");
      }
      else
      {
      	myservo.write(0);
      	lcd.clear();
      }
      in_pass = "";
  	}
    else
    {
      in_pass += keypressed;
      myservo.write(0);
      lcd.clear();
    }
  }
}
 
