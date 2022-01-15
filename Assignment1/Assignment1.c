#include<stdio.h>
#include<stdbool.h>

bool nand2(bool x, bool y)
{
   return !(x && y); // Two input NAND gate
}

bool nand3(bool x, bool y, bool z)
{
   !((x && y) && z); // Three input NAND gate
}

bool nand4(bool x, bool y, bool z, bool w)
{
   !((x && y) && (z && w)); // 4 input NAND gate
}

bool nand5(bool x, bool y, bool z, bool w, bool a)
{
   !((x && y) && (z && w) && a ); // 5 input NAND gate
}



int main()
{
   bool X = true, Y = false, Z = false, W = false;
   bool F;
   bool term1, term2, term3, term4, term5; // These terms are for readability

   term1 = nand2(nand2(Y,Y),nand2(Z,Z));
   term2 = nand2(X,nand2(Y,Y));
   term3 = nand3(X,nand2(Z,Z),nand2(W,W));
   term4 = nand3(X,Z,W);
   term5 = nand4(nand2(X,X),Y,Z,nand2(W,W));

   F = nand5(term1,term2,term3,term4,term5);

   printf("Input (X,Y,Z,W) = %x%x%x%x",X,Y,Z,W);
   printf("\n");
   printf("Output F = %x\n" ,F);
   
}
