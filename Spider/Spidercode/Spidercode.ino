#include <Servo.h>
 
Servo FR;
int FRpos = 0;
Servo FL;
int FLpos = 0;

Servo MR;
int MRpos = 0;
Servo ML;
int MLpos = 0;

Servo BR;
int BRpos = 0;
Servo BL;
int BLpos = 0;
 
Servo FT;
int FTpos = 0;
Servo BT;
int BTpos = 0;
 
long previousMillis = 0;       
 
void setup() {
  FR.attach(3);
  FL.attach(5);

  MR.attach(9);
  ML.attach(6);
  
  BR.attach(12);
  BL.attach(13);

  FT.attach(11);
  BT.attach(10);

  //Initial Position
  FR.write(0);
  FL.write(0);

  MR.write(0);
  ML.write(0);
  
  BR.write(0);
  BL.write(0);

  FT.write(90);
  BT.write(90);
 
  updatePos(0,0,0,0,0,0,90,90);
 
  Serial.begin(9600);
    
}
 
void loop() {
 delay(1000);
 moveServos(120,120,120,120,120,120,75,90,5);
 delay(400);
 moveServos(0,0,0,0,0,0,65,100,5);
 delay(400); 
 moveServos(120,120,120,120,120,120,85,80,5);
 delay(400); 
 moveServos(0,0,0,0,0,0,75,90,5); 
} 
 
void updatePos(int FRval,int MLval,int BRval,int FLval,int MRval,int BLval,int FTval,int BTval){
  FRpos = FRval;
  MLpos = MLval;
  BRpos = BRval;
  FLpos = FLval;
  MRpos = MRval;
  BLpos = BLval;
  FTpos = FTval;
  BTpos = BTval;
}
 
void moveServos(int FRval,int MLval,int BRval,int FLval,int MRval,int BLval,int FTval,int BTval, long inter){
  float FRdif = -(FRpos - FRval);
  float MLdif = -(FLpos - FLval);
  float BRdif = -(BRpos - BRval);
  float FLdif = -(BLpos - BLval);
  float MRdif = -(MRpos - MRval);
  float BLdif = -(MLpos - MLval);
  float FTdif = -(FTpos - FTval);
  float BTdif = -(BTpos - BTval);
 
  float diffs[8]={FRdif,MLdif,BRdif,FLdif,MRdif,BLdif,FTdif,BTdif};
  float maxDiff = 0;
  for(int i = 0; i < 8; i++)
  {
    if(abs(diffs[i]) > maxDiff) {
        maxDiff = abs(diffs[i]);
    }
  }
  if(maxDiff > 0){
    float FRinc = FRdif/maxDiff;
    float MLinc = MLdif/maxDiff;
    float BRinc = BRdif/maxDiff;
    float FLinc = FLdif/maxDiff;
    float MRinc = MRdif/maxDiff;
    float BLinc = BLdif/maxDiff;
    float FTinc = FTdif/maxDiff;
    float BTinc = BTdif/maxDiff;
 
    float FRcpos = FRpos;
    float MLcpos = MLpos;
    float BRcpos = BRpos;
    float FLcpos = FLpos;
    float MRcpos = MRpos;
    float BLcpos = BLpos;
    float FTcpos = FTpos;
    float BTcpos = BTpos;
    
    int inc = 0;
    while(inc < maxDiff){
      //unsigned long currentMillis = millis();
      //if(currentMillis - previousMillis > inter) {
        //currentMillis = previousMillis;
        
        FRcpos += FRinc;
        MLcpos += MLinc;
        BRcpos += BRinc;
        FLcpos += FLinc;
        MRcpos += MRinc;
        BLcpos += BLinc;
        FTcpos += FTinc;
        BTcpos += BTinc;
        
        FR.write(round(FRcpos));
        ML.write(round(MLcpos));
        BR.write(round(BRcpos));
        FL.write(round(FLcpos));
        MR.write(round(MRcpos));
        BL.write(round(BLcpos));
        FT.write(round(FTcpos));
        BT.write(round(BTcpos));
        
        delay(inter);
        inc++;
      //}
    }
    updatePos(FRcpos,MLcpos,BRcpos,FLcpos,MRcpos,BLcpos,FTcpos,BTcpos);
  }
  
}
