#include "melody.h"

void melody::note(int n, int d){
  tone(this->_tonePin, n, d);
  delay(d*1.30);
  noTone(this->_tonePin);
}
  
void melody::play(const int * a_melody){
  for(int thisNote = 0; thisNote < a_melody[0]; thisNote++) {
    int noteDuration = a_melody[(thisNote*3)+2];
    //int pauseBetweenNotes = noteDuration * 1.30;
    int pauseBetweenNotes = a_melody[(thisNote*3)+3];
    tone(_tonePin, a_melody[(thisNote*3)+1], noteDuration);
    delay(pauseBetweenNotes);
    noTone(_tonePin);
  }
}

void melody::play(String s_melody){
  int v=0, nn=0, ml=s_melody.length();
  s_melody.trim();
  this->noteIndex=0;
  for(;v<ml;v++) if(s_melody[v]==',') nn++;
  v=0;
  nn++;
  this->notes=(int*)malloc(((nn*3)+1)*sizeof(int));
  this->notes[this->noteIndex++]=nn;
  for(int i=0;i<nn;i++){
    int j=0;
    char c='\0', note[11]={NULL};
    do{
      c=s_melody[v++];
      if(c!=',') note[j++]=c;
    }while(c!=',' && v<ml);
    note[j]='\0';
    this->frqFunction(note);
  }
  play(this->notes);
  free(this->notes);
}
  
void melody::play(int n_melody){
  if(n_melody>=0 && n_melody<=9)
    play(Melodies[n_melody]);
  else
    play(Dallas);
}

void melody::frqFunction(char * note){
  int puls=0;
  if(strstr(note,"A1")!=NULL){notes[noteIndex++]=1515;puls=880;}
  else if(strstr(note,"A2")!=NULL){notes[noteIndex++]=758;puls=1720;}
  else if(strstr(note,"A3")!=NULL){notes[noteIndex++]=388;puls=3440;}
  else if(strstr(note,"B1")!=NULL){notes[noteIndex++]=1350;puls=988;}
  else if(strstr(note,"B2")!=NULL){notes[noteIndex++]=675;puls=1976;}
  else if(strstr(note,"B3")!=NULL){notes[noteIndex++]=337;puls=3972;}
  else if(strstr(note,"C1")!=NULL){notes[noteIndex++]=2548;puls=523;}
  else if(strstr(note,"C2")!=NULL){notes[noteIndex++]=1274;puls=1047;}
  else if(strstr(note,"C3")!=NULL){notes[noteIndex++]=637;puls=2093;}
  else if(strstr(note,"D1")!=NULL){notes[noteIndex++]=2270;puls=587;}
  else if(strstr(note,"D2")!=NULL){notes[noteIndex++]=1135;puls=1175;}
  else if(strstr(note,"D3")!=NULL){notes[noteIndex++]=566;puls=2350;}
  else if(strstr(note,"E1")!=NULL){notes[noteIndex++]=2022;puls=659;}
  else if(strstr(note,"E2")!=NULL){notes[noteIndex++]=1011;puls=1319;}
  else if(strstr(note,"E3")!=NULL){notes[noteIndex++]=483;puls=2638;}
  else if(strstr(note,"F1")!=NULL){notes[noteIndex++]=1909;puls=698;}
  else if(strstr(note,"F2")!=NULL){notes[noteIndex++]=954;puls=1397;}
  else if(strstr(note,"F3")!=NULL){notes[noteIndex++]=477;puls=2794;}
  else if(strstr(note,"G1")!=NULL){notes[noteIndex++]=1701;puls=784;}
  else if(strstr(note,"G2")!=NULL){notes[noteIndex++]=850;puls=1568;}
  else if(strstr(note,"G3")!=NULL){notes[noteIndex++]=425;puls=3136;}
  else if(strstr(note,"H1")!=NULL){notes[noteIndex++]=248;puls=337;}
  else if(strstr(note,"H2")!=NULL){notes[noteIndex++]=124;puls=675;}
  else if(strstr(note,"H3")!=NULL){notes[noteIndex++]=62;puls=1350;}
  else if(strstr(note,"Ais1")!=NULL){notes[noteIndex++]=1430;puls=932;}
  else if(strstr(note,"Ais2")!=NULL){notes[noteIndex++]=715;puls=1865;}
  else if(strstr(note,"Ais3")!=NULL){notes[noteIndex++]=358;puls=3730;}
  else if(strstr(note,"Cis1")!=NULL){notes[noteIndex++]=2405;puls=554;}
  else if(strstr(note,"Cis2")!=NULL){notes[noteIndex++]=1203;puls=1109;}
  else if(strstr(note,"Cis3")!=NULL){notes[noteIndex++]=601;puls=2218;}
  else if(strstr(note,"Dis1")!=NULL){notes[noteIndex++]=2143;puls=622;}
  else if(strstr(note,"Dis2")!=NULL){notes[noteIndex++]=1071;puls=1245;}
  else if(strstr(note,"Dis3")!=NULL){notes[noteIndex++]=536;puls=2490;}
  else if(strstr(note,"Fis1")!=NULL){notes[noteIndex++]=1802;puls=740;}
  else if(strstr(note,"Fis2")!=NULL){notes[noteIndex++]=901;puls=1480;}
  else if(strstr(note,"Fis3")!=NULL){notes[noteIndex++]=450;puls=2960;}
  else if(strstr(note,"Gis1")!=NULL){notes[noteIndex++]=1605;puls=831;}
  else if(strstr(note,"Gis2")!=NULL){notes[noteIndex++]=803;puls=1661;}
  else if(strstr(note,"Gis3")!=NULL){notes[noteIndex++]=401;puls=3322;}
  else notes[noteIndex++]=0;
    
  if(strstr(note,"(1/1)")!=NULL) notes[noteIndex++]=puls;
  else if(strstr(note,"(1/2)")!=NULL) notes[noteIndex++]=(puls/2);
  else if(strstr(note,"(1/4)")!=NULL) notes[noteIndex++]=(puls/4);
  else if(strstr(note,"(1/8)")!=NULL) notes[noteIndex++]=(puls/8);
  else if(strstr(note,"(1/16)")!=NULL) notes[noteIndex++]=(puls/16);
  else if(strstr(note,"(1/32)")!=NULL) notes[noteIndex++]=(puls/32);
    
  if(strstr(note,"(1/1)")!=NULL) notes[noteIndex++]=2000;
  else if(strstr(note,"(1/2)")!=NULL) notes[noteIndex++]=1000;
  else if(strstr(note,"(1/4)")!=NULL) notes[noteIndex++]=500;
  else if(strstr(note,"(1/8)")!=NULL) notes[noteIndex++]=250;
  else if(strstr(note,"(1/16)")!=NULL) notes[noteIndex++]=125;
  else if(strstr(note,"(1/32)")!=NULL) notes[noteIndex++]=62;
}
