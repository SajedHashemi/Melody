# Melody
Play melody notes. support Arduino platform.<br><br>

### How to use:
- Download the zip file and add it to the list of available Arduino libraries through the [Add ZIP Library] option
- Put the following line at the beginning of the file and in the head tag
```C++
#include "melody.h"
```

#### Example:
```C++
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
```

**Note**: The default melodies in the library include the following:<br>
0 = M_Happy_Birthday<br>
1 = M_Beautiful_Life<br>
2 = M_Money_Money<br>
3 = M_Mamma_Mia<br>
4 = M_Gimme_Gimme_Gimme<br>
5 = M_Batman<br>
6 = M_Diva<br>
7 = M_Dallas<br>
8 = M_Love_Me_Tender<br>
9 = M_Godfather<br>

**Note**: By sending a string containing notes in a format similar to the example below, it is executed through [play] Melody method
Example:
```C++
mlo.play("D2(1/8),Dis2(1/16),D2(1/8),E2(1/16),Dis2(1/8),D2(1/16)");
```

**Note**: You can play the melody by sending an array including frequency, duration and delay.
Example:
```C++
const int Dallas[]={
  12/*Number of notes*/,
  1274/*Frq*/, 65/*Duration*/, 125/*Delay*/,  //C2(1/16)
  954 , 174 , 250 ,  //F2(1/8)
  0   , 0   , 125 ,  //P(1/16)
  1274, 65  , 125 ,  //C2(1/16)
  637 , 261 , 250 ,  //C3(1/8)
  0   , 0   , 125 ,  //P(1/16)
  954 , 87  , 125 ,  //F2(1/16)
  758 , 215 , 250 ,  //A2(1/8)
  850 , 98  , 125 ,  //G2(1/16)
  758 , 107 , 125 ,  //A2(1/16)
  954 , 174 , 250 ,  //F2(1/8)
  1274, 130 , 250    //C2(1/8)
};
```
### Thank you
