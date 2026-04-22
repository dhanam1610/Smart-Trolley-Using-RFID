#include<lpc21xx.h>
#define datapins 0xf<<4
#define rs 1<<10
#define e 1<<11
void init(void);
void command(unsigned char);
void data(unsigned char);
void string(unsigned char*);
void milliseconds(unsigned int);
void read_rfid(char*);
void totall(int,int);
void init(void){
IODIR0|=datapins|e|rs;
command(0x01);
command(0x02);
command(0x0c);
command(0x28);
}
void command(unsigned char cmd){
IOCLR0=datapins;
IOSET0=(cmd&0xf0)<<0;
IOCLR0=rs;
IOSET0=e;
milliseconds(2);
IOCLR0=e;

IOCLR0=datapins;
IOSET0=(cmd&0x0f)<<4;
IOCLR0=rs;
IOSET0=e;
milliseconds(2);
IOCLR0=e;
}
void data(unsigned char d){
IOCLR0=datapins;
IOSET0=(d&0xf0)<<0;
IOSET0=rs;
IOSET0=e;
milliseconds(2);
IOCLR0=e;

IOCLR0=datapins;
IOSET0=(d&0x0f)<<4;
IOSET0=rs;
IOSET0=e;
milliseconds(2);
IOCLR0=e;
}
void string(unsigned char*s){
char i=0;
while(*s){
data(*s++);
i++;
if(i==14){
command(0xc0);
}
}
}
void integer(unsigned int n){
unsigned arr[10];
int i=0,j;
if(n==0){
data('0');
return;
}
while(n>0){
arr[i]=n%10;
n=n/10;
i++;
}
for(j=i-1;j>=0;j--){
data(arr[j]+48);
}
}
void seconds(unsigned int n){
T0PR=1500000-1;
T0TCR=0x01;
while(T0TC<n);
T0TCR=0x03;
T0TCR=0x00;
}
void milliseconds(unsigned int n){
T0PR=15000-1;
T0TCR=0x01;
while(T0TC<n);
T0TCR=0x03;
T0TCR=0x00;
}
void config(void){
PINSEL0|=0x5;
U0LCR=0x83;
U0DLL=97;
U0DLM=0;
U0LCR=0x03;
}
void milli(unsigned int n){
T1PR=15000-1;
T1TCR=0x01;
while(T1TC<n);
T1TCR=0x03;
T1TCR=0x00;
}
void read_rfid(char*tag)
{
int i=0;
while(i<12)
{
while((U0LSR&1)==0);
tag[i] = U0RBR;
i++;
}
tag[12]='\0';
}






