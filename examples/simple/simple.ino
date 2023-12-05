#include "melody.h"

melody* mlo;

void setup() {
  Serial.begin(9600);
  mlo=new melody(/*Pin*/);
}

void loop() {
  mlo->play(mlo->M_Dallas);
  delay(1000);
}
