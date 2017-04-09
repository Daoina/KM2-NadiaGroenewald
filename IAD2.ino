//We always have to include the library
#include "LedControlMS.h"
#define NBR_MTX 1 
//
/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

int buttonOne = 2;
int buttonTwo = 3;
int buttonThree = 4;

bool happy;
bool neutral;
bool sad;

int val = 0;

/* we always wait a bit between updates of the display */
unsigned long delaytime=1000;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  pinMode(buttonOne, INPUT);
  pinMode(buttonTwo, INPUT);
  pinMode(buttonThree, INPUT);
  lc.shutdown(0,false);
  /* Set the brightness*/ 
lc.setIntensity(0,15); // Maximale lichtsterkte
  /* and clear the display */
  lc.clearDisplay(0);
}
void writeHappy() {
  lc.clearDisplay(0);
  byte h[4]={B00000000,B00100000,B01001110,B01000000};
  lc.setRow(0,0,h[0]);
  lc.setRow(0,1,h[1]);
  lc.setRow(0,2,h[2]);
  lc.setRow(0,3,h[3]);
  lc.setRow(0,4,h[3]);
  lc.setRow(0,5,h[2]);
  lc.setRow(0,6,h[1]);
  lc.setRow(0,7,h[0]);
}
// dit is de functie die de led matrix blij laat kijken

void writeNeutral()
{
  lc.clearDisplay(0);
  byte n[4]={B00000000,B01000000,B01001110,B01000000};
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[3]);
  lc.setRow(0,5,n[2]);
  lc.setRow(0,6,n[1]);
  lc.setRow(0,7,n[0]);
}

// dit is de functie die de led matrix neutraal laat kijken

void writeSad()
{
  lc.clearDisplay(0);
  byte s[4]={B00000000,B01000000,B00101110,B00100000};
  lc.setRow(0,0,s[0]);
  lc.setRow(0,1,s[1]);
  lc.setRow(0,2,s[2]);
  lc.setRow(0,3,s[3]);
  lc.setRow(0,4,s[3]);
  lc.setRow(0,5,s[2]);
  lc.setRow(0,6,s[1]);
  lc.setRow(0,7,s[0]);
}

// dit is de functie die de led matrix verdrietig laat kijken

void loop() { 
    val = digitalRead(buttonOne);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    writeHappy();
    delay(1000);
    lc.clearDisplay(0);
  }

//als buttonOne (pin 2) ingedruk wordt, word functie writeHappy aangeroepen, daarna is er een korte delay en wordt het LED matrix gecleared.

    val = digitalRead(buttonTwo);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    writeNeutral();
    delay(1000);
    lc.clearDisplay(0);
  }

 //als buttonTwo (pin 3) ingedruk wordt, word functie writeNeutral aangeroepen, daarna is er een korte delay en wordt het LED matrix gecleared.

    val = digitalRead(buttonThree);  // read input value
  if (val == HIGH) {         // check if the input is HIGH (button released)
    writeSad();
    delay(1000);
    lc.clearDisplay(0);
  } 

//als buttonThree (pin 4) ingedruk wordt, word functie writeSad aangeroepen, daarna is er een korte delay en wordt het LED matrix gecleared.

  
}
