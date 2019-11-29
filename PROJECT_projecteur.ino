#include <Keypad.h>
int vitesse = 100;
const byte ROWS = 4;
const byte COLS = 4;
const int RELAY1 = 10;
const int RELAY2 = 11;
const int RELAY3 = 12;
const int RELAY4 = 13;



int patern1 = 0;
int patern2 = 0;
int patern3 = 0;
int patern4 = 0;

int state = 0;



unsigned long previousMillis1 = 100 ;
float currentMillis ;




char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode (RELAY1, OUTPUT);
  pinMode (RELAY2, OUTPUT);
  pinMode (RELAY3, OUTPUT);
  pinMode (RELAY4, OUTPUT);


}

void loop() {
  currentMillis = millis();

  char customKey = customKeypad.getKey();
  int relay1 = digitalRead(RELAY1);
  int relay2 = digitalRead(RELAY2);
  int relay3 = digitalRead(RELAY3);
  int relay4 = digitalRead(RELAY4);

  if (customKey == '0') {
    vitesse = vitesse + 5;
    Serial.print (vitesse);
    Serial.print ('\n');
  }

  if (customKey == '*') {
    vitesse = vitesse - 5;
    Serial.print (vitesse);
    Serial.print ('\n');
  }

  if (customKey == 'A') {                       //1 LED
    if (relay1 == LOW) {
      digitalWrite(RELAY1, HIGH);
    }
    if (relay1 == HIGH) {
      digitalWrite(RELAY1, LOW);
    }
  }

  if (customKey == 'B') {                       //1 LED
    if (relay2 == LOW) {
      digitalWrite(RELAY2, HIGH);
    }
    if (relay2 == HIGH) {
      digitalWrite(RELAY2, LOW);
    }
  }

  if (customKey == 'C') {                     //1 LED
    if (relay3 == LOW) {
      digitalWrite(RELAY3, HIGH);
    }
    if (relay3 == HIGH) {
      digitalWrite(RELAY3, LOW);

    }
  }
  if (customKey == 'D') {                      //1 LED
    if (relay4 == LOW) {
      digitalWrite(RELAY4, HIGH);
    }
    if (relay4 == HIGH) {
      digitalWrite(RELAY4, LOW);

    }
  }

  if (customKey == '1') {                     //1 secance

    if (patern1 == 1) {
      patern1 = patern1 - 1;
      state = 0;
    }
    else
      patern1++;
    Serial.print (patern1);
    Serial.print ('\n');
  }




  if (customKey == '2') {                     //2 secance

    if (patern2 == 1) {
      patern2 = patern2 - 1;
      state = 0;
    }
    else
      patern2++;
    Serial.print (patern2);
    Serial.print ('\n');
  }



  if (customKey == '4') {                     //3 secance

    if (patern3 == 1) {
      patern3 = patern3 - 1;
      state = 0;
    }
    else
      patern3++;
    Serial.print (patern3);
    Serial.print ('\n');
  }

  if (patern3 == 1) {
    patern1 = 0;
    patern2 = 0  ;
    Paterne3();
  }  
  if (patern2 == 1) {
    patern1 = 0;
    patern3 = 0;
    Paterne2();
  }
  if (patern1 == 1) {
    patern2 = 0;
    patern3 = 0 ;
    Paterne1();
  }



}



void Paterne1 () {
  byte validation;
  validation = currentMillis - previousMillis1;

  Serial.print ('\n');
  Serial.print ("hey");
  Serial.print ('\n');
  Serial.print ("currentMillis av:   ");
  Serial.print (currentMillis);
  Serial.print ('\n');
  Serial.print ("previousMillis1 av: ");
  Serial.print (previousMillis1);
  Serial.print ('\n');
  Serial.print ("validation:         ");
  Serial.print (validation);
  Serial.print ('\n');


  if (validation <= vitesse  ) {

    if (state == 9) {
      state = 0;
    }

    if (state == 8) {
      state++;
    }

    if (state == 7) {
      digitalWrite (RELAY4, LOW);
      state++;
      Serial.print ("relay4:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 6) {
      digitalWrite (RELAY3, LOW);
      state++;
      Serial.print ("relay3:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 5) {
      digitalWrite (RELAY2, LOW);
      state++;
      Serial.print ("relay2:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 4) {
      digitalWrite (RELAY1, LOW);
      validation = currentMillis - previousMillis1;
      state++;
      Serial.print ("relay1:             ");
      Serial.print (state);
      Serial.print ('\n');
    }
    if (state == 3) {
      digitalWrite (RELAY4, HIGH);
      state++;
      Serial.print ("relay4:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }
    if (state == 2) {
      digitalWrite (RELAY3, HIGH);
      state++;
      Serial.print ("relay3:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 1) {
      digitalWrite (RELAY2, HIGH);
      state++;
      Serial.print ("relay2:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 0) {
      digitalWrite (RELAY1, HIGH);
      validation = currentMillis - previousMillis1;
      state++;
      Serial.print ("relay1:             ");
      Serial.print (state);
      Serial.print ('\n');
    }




  }









  Serial.print ("currentMillis ap:   ");
  Serial.print (currentMillis);
  Serial.print ('\n');
  Serial.print ("previousMillis1 ap: ");
  Serial.print (previousMillis1);
  Serial.print ('\n');
  Serial.print ("validation:         ");
  Serial.print (validation);
  Serial.print ('\n');
  Serial.print ("state:              ");
  Serial.print (state);
  Serial.print ('\n');


}

void Paterne2() {

  byte validation;
  validation = currentMillis - previousMillis1;

  Serial.print ('\n');
  Serial.print ("hey");
  Serial.print ('\n');
  Serial.print ("currentMillis av:   ");
  Serial.print (currentMillis);
  Serial.print ('\n');
  Serial.print ("previousMillis1 av: ");
  Serial.print (previousMillis1);
  Serial.print ('\n');
  Serial.print ("validation:         ");
  Serial.print (validation);
  Serial.print ('\n');


  if (validation <= vitesse  ) {

    if (state == 9) {
      state = 0;
    }
    if (state == 8) {
      state++;
    }


    if (state == 7) {
      digitalWrite (RELAY2, LOW);
      state++;
      Serial.print ("relay4:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 6) {
      digitalWrite (RELAY3, LOW);
      state++;
      Serial.print ("relay3:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 5) {
      digitalWrite (RELAY1, LOW);
      state++;
      Serial.print ("relay2:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 4) {
      digitalWrite (RELAY4, LOW);
      validation = currentMillis - previousMillis1;
      state++;
      Serial.print ("relay1:             ");
      Serial.print (state);
      Serial.print ('\n');
    }
    if (state == 3) {
      digitalWrite (RELAY2, HIGH);
      state++;
      Serial.print ("relay4:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }
    if (state == 2) {
      digitalWrite (RELAY3, HIGH);
      state++;
      Serial.print ("relay3:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 1) {
      digitalWrite (RELAY1, HIGH);
      state++;
      Serial.print ("relay2:             ");
      Serial.print (state);
      Serial.print ('\n');
      previousMillis1 = currentMillis;
    }

    if (state == 0) {
      digitalWrite (RELAY4, HIGH);
      validation = currentMillis - previousMillis1;
      state++;
      Serial.print ("relay1:             ");
      Serial.print (state);
      Serial.print ('\n');
    }




  }









  Serial.print ("currentMillis ap:   ");
  Serial.print (currentMillis);
  Serial.print ('\n');
  Serial.print ("previousMillis1 ap: ");
  Serial.print (previousMillis1);
  Serial.print ('\n');
  Serial.print ("validation:         ");
  Serial.print (validation);
  Serial.print ('\n');
  Serial.print ("state:              ");
  Serial.print (state);
  Serial.print ('\n');
}


void Paterne3() {

  byte validation;
  validation = currentMillis - previousMillis1;




  if (validation <= vitesse  ) {

    if (state == 2) {
      state = 0;
    }
    if (state == 2) {
      state++;
    }    
    if (state == 1) {
      digitalWrite (RELAY1, HIGH);
      digitalWrite (RELAY2, HIGH);
      digitalWrite (RELAY3, HIGH);
      digitalWrite (RELAY4, HIGH);
      state++;
      previousMillis1 = currentMillis;
    }


    if (state == 0) {
      digitalWrite (RELAY1, LOW);
      digitalWrite (RELAY2, LOW);
      digitalWrite (RELAY3, LOW);
      digitalWrite (RELAY4, LOW);
      state++;
      previousMillis1 = currentMillis;
    }






  }









  Serial.print ("currentMillis ap:   ");
  Serial.print (currentMillis);
  Serial.print ('\n');
  Serial.print ("previousMillis1 ap: ");
  Serial.print (previousMillis1);
  Serial.print ('\n');
  Serial.print ("validation:         ");
  Serial.print (validation);
  Serial.print ('\n');
  Serial.print ("state:              ");
  Serial.print (state);
  Serial.print ('\n');
}
