#include <Arduino.h>

# define X 2
# define Y 3
# define Z 4
# define W 5


int x,y,z,w,term1,term2,term3,term4,term5,out;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(X,INPUT);
  pinMode(Y,INPUT);
  pinMode(Z,INPUT);
  pinMode(W,INPUT);
  // put your setup code here, to run once:
}


int nand2(int x, int y)
{
   return !(x && y); // Two input NAND gate
}

int nand3(int x, int y, int z)
{
   return !((x && y) && z); // Three input NAND gate
}

int nand4(int x, int y, int z, int w)
{
   return !((x && y) && (z && w)); // 4 input NAND gate
}

int nand5(int x, int y, int z, int w, int a)
{
   return !((x && y) && (z && w) && a ); // 5 input NAND gate
}


void loop() {
  
    x=digitalRead(X);
    y=digitalRead(Y);
    z=digitalRead(Z);
    w=digitalRead(W);
	
    term1 = nand2(nand2(y,y),nand2(z,z));
    term2 = nand2(x,nand2(y,y));
    term3 = nand3(x,nand2(z,z),nand2(w,w));
    term4 = nand3(x,z,w);
    term5 = nand4(nand2(x,x),y,z,nand2(w,w));
    out = nand5(term1,term2,term3,term4,term5);

    if(out==1)
        digitalWrite(LED_BUILTIN,HIGH);
    else
        digitalWrite(LED_BUILTIN,LOW);
}
