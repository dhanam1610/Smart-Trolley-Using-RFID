#include<lpc21xx.h>
#include<string.h>
#include"data_function.h" 
#define sw3 12//for total switch
volatile int penprice=10;
volatile int pencilprice=15;
volatile int pentotal=0;
volatile int penciltotal=0;
volatile int total=0;
void addmode(void)  __irq //EINT0
{
char tag[13];
read_rfid(tag);
if(strncmp(tag,"060067D961D9",12)==0){
pentotal+=penprice;
command(0xc0);
integer(pentotal);
}
else if(strncmp(tag,"060067882CC5",12)==0){
penciltotal+=pencilprice;
command(0xc5);
integer(penciltotal);
}
VICVectAddr=0;
EXTINT=0x01;
}
void removemode(void) __irq //EINT1
{
char tag[13];
read_rfid(tag);
if(strncmp(tag,"060067D961D9",12)==0){
pentotal-=penprice;
command(0xc0);
integer(pentotal);
}
else if(strncmp(tag,"060067882CC5",12)==0){
penciltotal-=pencilprice;
command(0xc5);
integer(penciltotal);
}
VICVectAddr=0;
EXTINT=0x02;
}
int main(){
init();
config();
command(0x80);
string("SMART TROLLEY USING RFID");
seconds(3);
command(0x01);
command(0x80);
string("Pen");
command(0x84);
string("Pencil");
command(0x8B);
string("Total");

PINSEL0 |=0x20000000;
PINSEL1 |=0x00000001; 


VICIntSelect=0;//irq;

VICVectCntl0=(0x20)|14;
VICVectAddr0=(unsigned long)addmode;

VICVectCntl1=(0x20)|15;
VICVectAddr1=(unsigned long)removemode;

EXTMODE=0x03;//edge sesitivity
EXTPOLAR=0x00;//falling edge sensitivity

VICIntEnable=(1<<14)|(1<<15);
while(1){
if(((IOPIN0>>sw3)&1)==0){
total=pentotal+penciltotal;
command(0xcb);
integer(total);
milli(300);
}
}
}


