#include <SoftwareSerial.h>
#include <PCD8544.h>
PCD8544 lcd;

// Define the data transmit/receive pins in Arduino

#define TxD 8

#define RxD 9

SoftwareSerial mySerial(RxD, TxD); // RX, TX for Bluetooth

int emp_no = 0;
int Count = 0;

void setup() {

  mySerial.begin(9600); // For Bluetooth

  Serial.begin(9600); // For the IDE monitor Tools -> Serial Monitor
  Count = 0;
  // Any code that you want to run once....
  lcd.begin(84, 48);
  lcd.setCursor(0, 0);
  lcd.print("   Welcome  ");
  lcd.setCursor(0, 1);
  lcd.print("Attendance");
  lcd.setCursor(0, 2);
  lcd.print("Management");
  lcd.print("System");
  delay(200);

}

void loop() {

  // put your main code here, to run repeatedly:

  boolean isValidInput; do {
    byte c; // get the next character from the bluetooth serial port

    while ( !mySerial.available() ) ; // LOOP...

    c = mySerial.read(); // Execute the option based on the character recieved

    Serial.print(c); // Print the character received to the IDE serial monitor

    switch ( c ) {

      case 49: // You've entered a

        // Do the code you need when 'a' is received.....

        mySerial.println( "Employee" ); mySerial.println( "1, " ); mySerial.println( "Your attendance is marked" );

        isValidInput = true;
        Count = Count + 1;
        emp_no = 1;
        lcd.setCursor(0, 0);
        lcd.print("   ATTENDANCE  ");
        lcd.setCursor(0, 1);
        lcd.print(" Count = ");
        lcd.print(Count);
        lcd.setCursor(0, 2);
        lcd.print("Employee ");
        lcd.print(emp_no);
        lcd.print(" marked in");
        delay(200);

        break;

      case 50: // You've entered a

        // Do the code you need when 'a' is received.....

        mySerial.println( "Employee" ); mySerial.println( "1, " ); mySerial.println( "Thank You" );

        isValidInput = true;
        Count = Count - 1;
        emp_no = 1;
        lcd.setCursor(0, 0);
        lcd.print("   ATTENDANCE  ");
        lcd.setCursor(0, 1);
        lcd.print(" Count = ");
        lcd.print(Count);
        lcd.setCursor(0, 2);
        lcd.print("Employee ");
        lcd.print(emp_no);
        lcd.print(" marked out");
        delay(200);

        break;

      case 51: // You've entered a

        // Do the code you need when 'a' is received.....

        mySerial.println( "Employee" ); mySerial.println( "2, " ); mySerial.println( "Your attendance is marked" );

        isValidInput = true;
        Count = Count + 1;
        emp_no = 2;
        lcd.setCursor(0, 0);
        lcd.print("   ATTENDANCE  ");
        lcd.setCursor(0, 1);
        lcd.print(" Count = ");
        lcd.print(Count);
        lcd.setCursor(0, 2);
        lcd.print("Employee ");
        lcd.print(emp_no);
        lcd.print(" marked in");
        delay(200);

        break;

      case 52: // You've entered a

        // Do the code you need when 'a' is received.....

        mySerial.println( "Employee" ); mySerial.println( "2, " ); mySerial.println( "Thank You" );

        isValidInput = true;
        Count = Count - 1;
        emp_no = 2;
        lcd.setCursor(0, 0);
        lcd.print("   ATTENDANCE  ");
        lcd.setCursor(0, 1);
        lcd.print(" Count = ");
        lcd.print(Count);
        lcd.setCursor(0, 2);
        lcd.print("Employee ");
        lcd.print(emp_no);
        lcd.print(" marked out");
        delay(200);

        break;

      default:

        // Do the code you need when any other character is received.....

        mySerial.println( "Not registered" );
        isValidInput = false;

        break;

    }


  } while ( isValidInput == true ); // Repeat the loop

}
