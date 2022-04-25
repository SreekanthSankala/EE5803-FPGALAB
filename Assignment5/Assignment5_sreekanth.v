module Assignment5_sreekanth(
input wire x,
input wire y,
input wire z,
input wire w,
output wire redled,
output wire greenled,
output wire blueled
);

reg out;
always @(*)
begin
out= ((!y)&(!z)) | ((x)&(!y)) | ((x)&(!z)&(!w)) | ((x)&(z)&(w)) | ((!x)&(y)&(z)&(w));
if(out==1)
begin
redled=1;
end
else
begin
redled=0;
end
end
endmodule
