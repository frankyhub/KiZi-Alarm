/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: KiZi Alarm - Einfache Alarmanlage für das Kinderzimmer

**************************************************************************************************
Version: 08.11.2023
**************************************************************************************************
Board: NANO
**************************************************************************************************
Libraries:
https://github.com/espressif/arduino-esp32/tree/master/libraries
C:\Users\User\Documents\Arduino
D:\gittemp\Arduino II\A156_Wetterdaten_V3
**************************************************************************************************
C++ Arduino IDE V1.8.19
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json
**************************************************************************************************/

#define ALARM 4
#define POWER 2
int Buzzer = 7;
#define BWM 8

int pauseALARM = 150;
int oldMillis_ALARM = 0;
bool ALARMstate = LOW;
bool BWMstate = HIGH;
bool BWMNstate = LOW;
bool BWMstate_old = HIGH;

long prellZeit = 80;
long BWMmillis_old = 0;

void setup() {
  pinMode(ALARM, OUTPUT);
  pinMode(POWER, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(BWM, INPUT_PULLUP);
}

void loop() {
  digitalWrite(POWER, HIGH); //ON LED
  BWMstate = digitalRead(BWM);
  BWMNstate = !BWMstate;

  if (BWMNstate != BWMstate_old && millis() - BWMmillis_old > prellZeit) {

  if (millis() - oldMillis_ALARM >= pauseALARM) {
    
    ALARMstate = !ALARMstate;
    digitalWrite(ALARM, ALARMstate);
    oldMillis_ALARM = millis();
    tone(Buzzer, 2500);
     delay(100);
  }  

  }
   noTone(Buzzer);
   digitalWrite(ALARM, LOW);
}
