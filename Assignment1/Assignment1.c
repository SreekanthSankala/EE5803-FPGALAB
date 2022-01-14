#include <stdio.h>

int main(){
    unsigned char F; //output
    unsigned char one = 0x01; //used for displaying the output in bit
    unsigned char  X=0x00,Y=0x01,Z=0x01,W=0x00; //inputs in hex

    F = ( (~Y)&(~Z) ) | ( X&(~Y) )  | ( X&((~Z)&(~W)) )  | ( X&(Z&W) )  | ( (~X)&(Y&Z)&(~W) )  ;
   
    printf("Input (X,Y,W,Z) = %x%x%x%x",one&X,one&Y,one&Z,one&W);
    printf("\n");
    printf("Output F = %x\n" ,one&F);
    return 0;
}
