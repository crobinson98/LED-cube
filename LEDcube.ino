#define EFFECT_DELAY 500 
#define DO 554 
#define RE 622
#define ME 698
#define FA 740
#define SOL 831
#define LA 932
#define SE 1047
#define DO2 1109

int time=600; // defining length of time of sound

const byte LevelDelay = 1;  

//  connecting the levels to the pins of the Arduino
const byte T1 = 5; 
const byte T2 = 10;
const byte T3 = 6;
const byte T4 = 9;


// connecting the DM13A terminals with the Arduino pins.
const byte =13;
const byte din = 11;
const byte clkpin = 12;
const byte interruptPin = 2; // connecting the reciver terminal

//connecting collector terminal to the Arduino terminal
int latchPin =7;
int latchPin=7;
int clockPin=4;
int dataPin=8;

//cube functions decleration
void setLevel(int data, int lvl); 
void setCube(int data);

//defining boolian variable
volatile boolean skipFlag=false;

//defining numbers of seven segment
int arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x67};

void setup()
{


	Serial.begin(9600);  //Rate of information transfer

	//defining the levels to output
	pinMode(T1,OUTPUT);
	pinMode(T2, OUTPUT);
	pinMode(T3, OUTPUT);
	pinMode(T4, OUTPUT);

	//defining DM13A terminals to output
	pinMode(lat,OUTPUT);
	pinMode(din, OUTPUT);
	pinMode(clkpin, OUTPUT);

	//shot four of the levels and DM13A terminal
	digitalWrite(T1,LOW);
	digitalWrite(T2, LOW);
	digitalWrite(T3, LOW);
	digitalWrite(T4, LOW);
	digitalWrite(lat, LOW); 

	//defining collector termimals to output
	pinMode(latchPin,OUTPUT);
	pinMode(clockPin,OUTPUT);
	pinMode(dataPin,OUTPUT);

	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), CountAndSkip, FALLING);


	dispNum(1);
}

byte numOfEffects = 8; 
volatile byte effectCounter = 1; 

void CountAndSkip() {
	static unsigned long lastTime = 0;
	if (millis() - lastTime > 200) { //debounce
		lastTime = millis();
		skipFlag = true; //skip delays, functions
		effectCounter++;
	if (effectCounter == numOfEffects)
		effectCounter = 1;

		dispNum(effectCounter);
	}
}


//turns on seven segment display
void dispNum(int num){
	digitalWrite(latchPin,LOW);
	shiftOut(dataPin,clockPin,MSBFIRST,arr[num]);
	digitalWrite(latchPin,HIGH);
}



void mDelay(unsigned long dly) { // לאפקטים הצלילים התאמת
unsigned long mTime = millis();
while (dly > (millis() - mTime))
switch(effectCounter)
{
case 1: tone1();
break;
case 2: tone2();
break;
case 3: tone3();
break;
case 4: tone4();
break;
case 5: tone5();
break;
case 6: tone6();
break;
case 7: tone7();
break;
}
}

אפקטים //
void effect1() {

int arr[3]={0xff00, 0xf00f, 0x00ff};
for(int i=0;i<3;i++)
{
setLevel(arr[i], 3);
setLevel(arr[i], 2);
cubeLoop(EFFECT_DELAY);
}

38

setLevel(0, 3);
setLevel(0xf00f, 2);
setLevel(0xf00f, 1);
cubeLoop(EFFECT_DELAY);
setLevel(0, 2);
for(int i=3;i>=0;i--)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
cubeLoop(EFFECT_DELAY);
}
setLevel(0, 0);
setLevel(0, 1);

skipFlag = false;
}

void effect2() {

int
arr[16]={0x0080,0x0088,0x8088,0x8888,0x8c88,0x8e88,0x8f88,0x9f88,0x9f89,0x9f99,0
x9fb9,0x9ff9,0x9ffd,0xdffd,0xfffd,0xffff};
int
arr2[16]={0xfffd,0xdffd,0x9ffd,0x9ff9,0x9fb9,0x9f99,0x9f89,0x9f88,0x8f88,0x8d88,0x8c8
8,0x8888,0x8088,0x0088,0x0080,0x0000};
for(int j=0;j<4;j++)
{
for(int i=0;i<16;i++)
{
if(j==0)
{
setLevel(arr[i], 0);

39

}
if(j==1) {
setLevel(arr[i], 1);
setLevel(arr[i], 0);
}
if(j==2) {
setLevel(arr[i], 1);
setLevel(arr[i], 0);
setLevel(arr[i], 2);
}
if(j==3)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
setLevel(arr[i], 2);
setLevel(arr[i], 3);
}

cubeLoop(EFFECT_DELAY/4);
}
cubeLoop(EFFECT_DELAY);
for(int i=0;i<16;i++) {
if(j==0) {
setLevel(arr2[i], 0);
}
if(j==1) {
setLevel(arr2[i], 1);

40

setLevel(arr2[i], 0);
}
if(j==2) {
setLevel(arr2[i], 1);
setLevel(arr2[i], 0);
setLevel(arr2[i], 2);
}
if(j==3) {
setLevel(arr2[i], 1);
setLevel(arr2[i], 0);
setLevel(arr2[i], 2);
setLevel(arr2[i], 3);
}

cubeLoop(EFFECT_DELAY/13); }
cubeLoop(EFFECT_DELAY);
}
skipFlag = false;
}

void effect3() {
setLevel(0x10, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 3);

41

cubeLoop(EFFECT_DELAY/5);
setLevel(0x30, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x70, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0xf0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x98, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x8098, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x8898, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0890, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0890, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x08f0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0cf0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0ef0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0ff0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0990, 2);

42

cubeLoop(EFFECT_DELAY/5);
setLevel(0x0990, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x8998, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x9998, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x9999, 0);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x9999, 0);
setLevel(0x0990, 1);
setLevel(0x0ff0, 3);
setLevel(0x0990, 2);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x9999, 0);
setLevel(0x0990, 1);
setLevel(0x0ff0, 3);
setLevel(0x0990, 2);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);

43

setLevel(0x0, 3);

cubeLoop(EFFECT_DELAY/5);

skipFlag = false;

}

void effect4() {
for(int n=2;n<50;n++) {
setLevel(0x80, 0);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xc8, 0);
setLevel(0x80, 1);
cubeLoop(EFFECT_DELAY/n);
setLevel(0x80ec, 0);
setLevel(0xc8, 1);
setLevel(0x80, 2);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xc8fe, 0);
setLevel(0x80ec, 1);
setLevel(0xc8, 2);
setLevel(0x80, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xecff, 0);
setLevel(0xc8fe, 1);
setLevel(0x80ec, 2);
setLevel(0xc8, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xfeff, 0);

44

setLevel(0xecff, 1);
setLevel(0xecff, 2);
setLevel(0x80ec, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xfeff, 1);
setLevel(0xecff, 2);
setLevel(0xecff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xfeff, 2);
setLevel(0xecff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xffff, 2);
setLevel(0xfeff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xffff, 2);
setLevel(0xffff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/n); }

skipFlag = false;

45

}
void effect5()
{
int
arr[16]={0x4000,0x0010,0x0200,0x0004,0x1000,0x0080,0x0020,0x8000,0x0002,0x040
0,0x0100,0x0040,0x0800,0x0001,0x2000,0x0008};
int
arr2[16]={0x4000,0x4010,0x4210,0x4214,0x5214,0x5294,0x52b4,0xd2b4,0xd2b6,0xd6
b6,0xd7b6,0xd7f6,0xdff6,0xdff7,0xfff7,0xffff};
for(int n=0,i=0;n<16;n++,i++)
{
setLevel(arr[n], 3);
cubeLoop(EFFECT_DELAY/15);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr[n], 2);
cubeLoop(EFFECT_DELAY/15);
setLevel(0x0, 2);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr[n], 1);
cubeLoop(EFFECT_DELAY/15);
setLevel(0x000, 1);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr2[i], 0);
cubeLoop(EFFECT_DELAY/2);
}
cubeLoop(EFFECT_DELAY*2);
setLevel(0,0);
cubeLoop(EFFECT_DELAY*2);

skipFlag = false;

46

}
void effect6() {
for(int j=5;j<10;j++) {
for(int i=0;i<2;i++) {
setLevel(0x2184, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0,0);
}
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++)
{
setLevel(0x2184, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 1);
cubeLoop(EFFECT_DELAY/j);

47

setLevel(0x4812, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 1); }
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++)
{
setLevel(0x2184, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 2); }
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++) {
setLevel(0x2184, 3);
cubeLoop(EFFECT_DELAY/j);

48

setLevel(0x300c, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 3); }
cubeLoop(EFFECT_DELAY/j);

}

for(int i=0;i<7;i++) {
setLevel(0x2184, 0);
setLevel(0x2184, 1);
setLevel(0x2184, 2);
setLevel(0x2184, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x300c, 0);
setLevel(0x300c, 1);
setLevel(0x300c, 2);
setLevel(0x300c, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0xc003, 0);
setLevel(0xc003, 1);
setLevel(0xc003, 2);
setLevel(0xc003, 3);

49

cubeLoop(EFFECT_DELAY/6);
setLevel(0x4812, 0);
setLevel(0x4812, 1);
setLevel(0x4812, 2);
setLevel(0x4812, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x4422, 0);
setLevel(0x4422, 1);
setLevel(0x4422, 2);
setLevel(0x4422, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x2244, 0);
setLevel(0x2244, 1);
setLevel(0x2244, 2);
setLevel(0x2244, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x0,0);
setLevel(0x0,1);
setLevel(0x0,2);
setLevel(0x0,3);
}

skipFlag = false;

}
void effect7()
{
int arr0[8]={0x7a5a,0x7ada,0x7bda,0xfbda,0xfbdb,0xffdb,0xfffb,0xffff};//02
int arr1[8]={0xa5e5,0xb5e5,0xb5ed,0xb7ed,0xbfed,0xffed,0xfffd,0xffff};//13
int arr3[2]={1,3},arr4[2]={2,0};
for(int i=0;i<2;i++)
{

50

setLevel(0x5a5a, 0);
setLevel(0x5a5a, 2);
setLevel(0xa5a5, 1);
setLevel(0xa5a5, 3);
cubeLoop(EFFECT_DELAY);
setLevel(0x5a5a, 1);
setLevel(0x5a5a, 3);
setLevel(0xa5a5, 0);
setLevel(0xa5a5, 2);
cubeLoop(EFFECT_DELAY);
}
for(int m=0;m<2;m++)
{
for(int i=0;i<8;i++)
{
setLevel(arr0[i], arr3[m]);
cubeLoop(EFFECT_DELAY/5);
setLevel(arr1[i], arr4[m]);
cubeLoop(EFFECT_DELAY/5);
}

}
cubeLoop(EFFECT_DELAY);

skipFlag = false;

}

ה //
void setEffect() {
switch (effectCounter) {

51

case 0:
effect1();
break;
case 1:
effect2();
break;
case 2:
effect3();
break;
case 3:
effect4();
break;
case 4:
effect5();
break;
case 5:
effect6();
break;
case 6:
effect7();
break;

default:
// statements
break;
}
}

52

int
t1[]={time/2,time/2,time/2,time/2,time/20,time/2,time/2,time/20,time,time/2,time/2,time/20
,time,time/2,time/2,time/20,time,time/20,
time/2,time/2,time/2,time/2,time/20,time/2,time/2,time/20,time,time/2,time/2,time/20,time
,time/2,time/2,time/20,time
,time,time/20,time,time/2,time/2,time/20,time,time/2,time/2,time/20,time,time/2,time/2,tim
e,time,
time/20,time,time/2,time/2,time/20,time,time/2,time/2,time/20,time,time/2,time/2,time};
int
s1[]={DO,ME,DO,ME,0,ME,SOL,0,SOL,FA,RE,0,RE,ME,DO,0,DO,0,DO,ME,DO,ME,0,
ME,SOL,0,SOL,FA,RE,0,RE,ME,DO,0,DO,FA,0,FA,SOL,ME,0,ME,FA,RE,0,RE,DO,ME,
SOL,FA,0,FA,SOL,ME,0,ME,FA,RE,0,RE,DO,ME,DO};
void tone1()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t1[counter])
{
ttime = millis();
if (counter < sizeof(t1) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s1[counter] == 0)
noTone(3);
else
tone(3, s1[counter]);

}
}

53

//merotsei keptaoun
int
t5[]={time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time/20,time/2,time,time/2,ti
me,time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time,time/2,time/2,time*2,
time/20,time/2,time/20,time/2,time/2,time/2,time*2,time/2,time/20,time/2,time/2,time/2,ti
me*2,time/20,time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time/2,time/2,time/2,
time/2,time*2};
int
s5[]={SOL,0,SOL,ME,SOL,LA,SOL,ME,0,ME,RE,ME,RE,SOL,0,SOL,ME,SOL,LA,SOL,
ME,RE,ME,RE,DO,0,DO,0,DO,ME,SOL,DO2,LA,0,LA,DO2,LA,SOL,0,SOL,0,SOL,ME,S
OL,LA,SOL,ME,RE,FA,ME,RE,DO};

void tone5()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t5[counter])
{
ttime = millis();
if (counter < sizeof(t5) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s5[counter] == 0)
noTone(3);
else
tone(3, s5[counter]);

}
}

54

//kan kan
int
t3[]={time,time/20,time,time/2,time/2,time/2,time/2,time,time/20,time,time/20,time/2,time/
2,time/2,time/2,time,
time/20,time,time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,
time/2,time/2,time/2,time/2,
time,time/20,time,time/2,time/2,time/2,time/2,time,time/20,time,time/20,time/2,tim
e/2,time/2,time/2,time,time/20,time,
time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time*2};
int
s3[]={DO,0,DO,RE,FA,ME,RE,SOL,0,SOL,0,SOL,LA,ME,FA,RE,0,RE,0,RE,FA,ME,RE,
DO,DO2,SE,LA,SOL,FA,ME,RE,DO,0,DO,RE,
FA,ME,RE,SOL,0,SOL,0,SOL,LA,ME,FA,RE,0,RE,0,RE,FA,ME,RE,DO,SOL,RE,
ME,DO};

void tone3()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t3[counter])
{
ttime = millis();
if (counter < sizeof(t3) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s3[counter] == 0)
noTone(3);

55

else
tone(3, s3[counter]);

}
}

//boker yov higia
int
t4[]={time/2,time/2,time/2,time/2,time,time/20,time,time/2,time/2,time/2,time/2,time*2,tim
e/2,time/2,time/2,time/2,time*2,time/2,time/20,time/2,time/20,time/2,time/20,time/2,time/
2,time/20,
time/2,time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time,time/2,time/20,time/
2,time/20,time/2,time/20,time/2,time/2,time/20,time/2,time/20,time,time/2,time/2,time/2,ti
me/2,time*2};
int
s4[]={DO,RE,ME,FA,SOL,0,SOL,LA,FA,DO2,LA,SOL,LA,FA,DO2,LA,SOL,FA,0,FA,0,F
A,0,FA,ME,0,ME,0,ME,RE,FA,ME,RE,DO,ME,SOL,FA,0,FA,0,FA,0,FA,ME,0,ME,0,ME,
RE,FA,ME,RE,DO};

void tone4()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t4[counter])
{
ttime = millis();
if (counter < sizeof(t4) / sizeof(int) - 1)
{
counter ++;
}

56

else counter = 0;
if(s4[counter] == 0)
noTone(3);
else
tone(3, s4[counter]);

}
}

//laila tov
int t2[]={time/2, time/2,time,time/2,time/2,time,time/2,time/2,time,time/2,time/2,time};
int s2[]={DO,RE,ME,RE,DO,RE,DO,RE,ME,RE,ME,DO};
void tone2()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t2[counter])
{
ttime = millis();
if (counter < sizeof(t2) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s2[counter] == 0)
noTone(3);
else
tone(3, s2[counter]);

}
}

57

העובדים החרוצים עמוד 59//
int
t6[]={time/2,time/2,time/20,time/2,time/20,time/2,time/2,time/2,time/20,time/2,time/20,tim
e/2,time/2,time/2,time/2,time/2,time,time/20,time/2,time/2,time/20,time/2,time/20,time/2,t
ime/2,time/2,time/20,time/2
,time/20,time/2,time/2,time/2,time/20,time/2,time/20,time/2,time/2,time/2,time/20,time/2,t
ime/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time,time/2,time/2,time/2,ti
me/2,time/2,time};
int
s6[]={ME,SOL,0,SOL,0,SOL,DO2,SOL,0,SOL,0,SOL,FA,ME,RE,DO,RE,0,RE,FA,0,FA,
0,FA,ME,SOL,0,SOL,0,SOL,RE,FA,0,FA,0,FA,RE,SOL,0,SOL,0,SOL,DO2,SOL,FA,ME,
RE,DO,ME,SOL,DO2,SOL,FA,ME,RE,DO};

void tone6()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t6[counter])
{
ttime = millis();
if (counter < sizeof(t6) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s6[counter] == 0)
noTone(3);
else
tone(3, s6[counter]);

}

58

}

//shir shel ema
int
t7[]={time/2,time/2,time/2,time/2,time/2,time/20,time/2,time,time/2,time/2,time/2,time/2,ti
me/2,time/20,time/2,time,time/20};
int s7[]={DO,RE,ME,DO,RE,0,RE,ME,DO,RE,ME,DO,RE,0,RE,DO,0};

void tone7()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t7[counter])
{
ttime = millis();
if (counter < sizeof(t7) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s7[counter] == 0)
noTone(3);
else
tone(3, s7[counter]);

}
}

59

void loop()
{

setEffect();
}

int level[4]; //cube data

void cubeLoop(unsigned long updateTime) {
unsigned long mTime = millis();
while (updateTime > (millis() - mTime)) { //{
// && !skipFlag);
// if (skipFlag)
// return;
for (int c = 0; c < 4; c++) {
setCube(level[c]);
digitalWrite(T1, LOW);
digitalWrite(T2, LOW);
digitalWrite(T3, LOW);
digitalWrite(T4, LOW);
if (c == 0)
digitalWrite(T1, HIGH);
else if (c == 1)

60

digitalWrite(T2, HIGH);
else if (c == 2)
digitalWrite(T3, HIGH);
else if (c == 3)
digitalWrite(T4, HIGH);
mDelay(LevelDelay);
}
}
}

void setCube(int data) {
shiftOut(din, clkpin, LSBFIRST, data >> 8);
shiftOut(din, clkpin, LSBFIRST, data);
digitalWrite(lat, HIGH);
digitalWrite(lat, LOW);
}

void setLevel(int data, int lvl) {
if (lvl >= 0 && lvl < 4)
level[lvl] = data;
}
//#include <SdFat.h>

#define EFFECT_DELAY 500
#define DO 554
#define RE 622
#define ME 698
#define FA 740
#define SOL 831
#define LA 932
#define SE 1047
#define DO2 1109

61

int time = 600;

const byte LevelDelay = 1;

const byte T1 = 5;
const byte T2 = 10;
const byte T3 = 6;
const byte T4 = 9;
const byte lat = 13;
const byte din = 11;
const byte clkpin = 12;
const byte interruptPin = 2;
void setLevel(int data, int lvl);
void setCube(int data);
volatile boolean skipFlag = false;
//595
int latchPin=7;
int clockPin=4;
int dataPin=8;

int arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x67};

void setup()
{
Serial.begin(9600);
pinMode(T1, OUTPUT);
pinMode(T2, OUTPUT);
pinMode(T3, OUTPUT);
pinMode(T4, OUTPUT);
pinMode(lat, OUTPUT);

62

pinMode(din, OUTPUT);
pinMode(clkpin, OUTPUT);
digitalWrite(T1, LOW);
digitalWrite(T2, LOW);
digitalWrite(T3, LOW);
digitalWrite(T4, LOW);
digitalWrite(lat, LOW);

pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);

pinMode(interruptPin, INPUT);
attachInterrupt(digitalPinToInterrupt(interruptPin), CountAndSkip, FALLING); //

dispNum(1);
}

byte numOfEffects = 8;
volatile byte effectCounter = 1;

void CountAndSkip() {
static unsigned long lastTime = 0;
if (millis() - lastTime > 200) { //debounce
lastTime = millis();
skipFlag = true; //skip delays, functions
effectCounter++;
if (effectCounter == numOfEffects)
effectCounter = 1;

63

dispNum(effectCounter);
}
}

void dispNum(int num){
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,MSBFIRST,arr[num]);
digitalWrite(latchPin,HIGH);
}

void mDelay(unsigned long dly) {
unsigned long mTime = millis();
while (dly > (millis() - mTime))
switch(effectCounter)
{
case 1: tone1();
break;
case 2: tone2();
break;
case 3: tone3();
break;
case 4: tone4();
break;
case 5: tone5();
break;
case 6: tone6();
break;
case 7: tone7();
break;
}

64

//{
//Serial.println(millis()-mTime);// && !skipFlag);
//}
}

void effect1() {

int arr[3]={0xff00, 0xf00f, 0x00ff};
for(int i=0;i<3;i++)
{
setLevel(arr[i], 3);
setLevel(arr[i], 2);
cubeLoop(EFFECT_DELAY);
}
setLevel(0, 3);
setLevel(0xf00f, 2);
setLevel(0xf00f, 1);
cubeLoop(EFFECT_DELAY);
setLevel(0, 2);
for(int i=3;i>=0;i--)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
cubeLoop(EFFECT_DELAY);
}
setLevel(0, 0);
setLevel(0, 1);

skipFlag = false;
}

65

void effect2() {

int
arr[16]={0x0080,0x0088,0x8088,0x8888,0x8c88,0x8e88,0x8f88,0x9f88,0x9f89,0x9f99,0
x9fb9,0x9ff9,0x9ffd,0xdffd,0xfffd,0xffff};
int
arr2[16]={0xfffd,0xdffd,0x9ffd,0x9ff9,0x9fb9,0x9f99,0x9f89,0x9f88,0x8f88,0x8d88,0x8c8
8,0x8888,0x8088,0x0088,0x0080,0x0000};
for(int j=0;j<4;j++)
{
for(int i=0;i<16;i++)
{
if(j==0)
{
setLevel(arr[i], 0);
}
if(j==1)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
}
if(j==2)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
setLevel(arr[i], 2);
}
if(j==3)
{
setLevel(arr[i], 1);
setLevel(arr[i], 0);
setLevel(arr[i], 2);

66

setLevel(arr[i], 3);
}

cubeLoop(EFFECT_DELAY/4);
}
cubeLoop(EFFECT_DELAY);
for(int i=0;i<16;i++) {
if(j==0) {
setLevel(arr2[i], 0);
}
if(j==1) {
setLevel(arr2[i], 1);
setLevel(arr2[i], 0);
}
if(j==2) {
setLevel(arr2[i], 1);
setLevel(arr2[i], 0);
setLevel(arr2[i], 2);
}
if(j==3) {
setLevel(arr2[i], 1);
setLevel(arr2[i], 0);
setLevel(arr2[i], 2);
setLevel(arr2[i], 3);
}

cubeLoop(EFFECT_DELAY/13);

67

}
cubeLoop(EFFECT_DELAY);
}
skipFlag = false;
}

void effect3() {
setLevel(0x10, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x10, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x30, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x70, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0xf0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x90, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x98, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x8098, 0);
cubeLoop(EFFECT_DELAY/5);

68

setLevel(0x8898, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0890, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0890, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x08f0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0cf0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0ef0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0ff0, 3);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0990, 2);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x0990, 1);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x8998, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x9998, 0);
cubeLoop(EFFECT_DELAY/5);
setLevel(0x9999, 0);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x9999, 0);
setLevel(0x0990, 1);
setLevel(0x0ff0, 3);

69

setLevel(0x0990, 2);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1)
;
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x9999, 0);
setLevel(0x0990, 1);
setLevel(0x0ff0, 3);
setLevel(0x0990, 2);
cubeLoop(EFFECT_DELAY/2);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);

cubeLoop(EFFECT_DELAY/5);

skipFlag = false;

}

void effect4() {
for(int n=2;n<50;n++) {
setLevel(0x80, 0);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xc8, 0);
setLevel(0x80, 1);
cubeLoop(EFFECT_DELAY/n)
;

70

setLevel(0x80ec, 0);
setLevel(0xc8, 1);
setLevel(0x80, 2);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xc8fe, 0);
setLevel(0x80ec, 1);
setLevel(0xc8, 2);
setLevel(0x80, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xecff, 0);
setLevel(0xc8fe, 1);
setLevel(0x80ec, 2);
setLevel(0xc8, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xfeff, 0);
setLevel(0xecff, 1);
setLevel(0xecff, 2);
setLevel(0x80ec, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xfeff, 1);
setLevel(0xecff, 2);
setLevel(0xecff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xfeff, 2);
setLevel(0xecff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xffff, 2);

71

setLevel(0xfeff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0xffff, 0);
setLevel(0xffff, 1);
setLevel(0xffff, 2);
setLevel(0xffff, 3);
cubeLoop(EFFECT_DELAY/n);
setLevel(0x0, 0);
setLevel(0x0, 1);
setLevel(0x0, 2);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/n);
}

skipFlag = false;

}
void effect5()
{
int
arr[16]={0x4000,0x0010,0x0200,0x0004,0x1000,0x0080,0x0020,0x8000,0x0002,0x040
0,0x0100,0x0040,0x0800,0x0001,0x2000,0x0008};
int
arr2[16]={0x4000,0x4010,0x4210,0x4214,0x5214,0x5294,0x52b4,0xd2b4,0xd2b6,0xd6
b6,0xd7b6,0xd7f6,0xdff6,0xdff7,0xfff7,0xffff};
for(int n=0,i=0;n<16;n++,i++)
{
setLevel(arr[n], 3);
cubeLoop(EFFECT_DELAY/15);
setLevel(0x0, 3);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr[n], 2);

72

cubeLoop(EFFECT_DELAY/15);
setLevel(0x0, 2);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr[n], 1);
cubeLoop(EFFECT_DELAY/15);
setLevel(0x000, 1);
cubeLoop(EFFECT_DELAY/15);
setLevel(arr2[i], 0);
cubeLoop(EFFECT_DELAY/2);
}
cubeLoop(EFFECT_DELAY*2);
setLevel(0,0);
cubeLoop(EFFECT_DELAY*2);

skipFlag = false;

}
void effect6() {
for(int j=5;j<10;j++) {
for(int i=0;i<2;i++) {
setLevel(0x2184, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 0);

73

cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 0);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0,0);
}
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++)
{
setLevel(0x2184, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 1);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 1); }
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++)
{
setLevel(0x2184, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 2);

74

cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 2);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 2); }
cubeLoop(EFFECT_DELAY/j);

for(int i=0;i<2;i++) {
setLevel(0x2184, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x300c, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0xc003, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4812, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x4422, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x2244, 3);
cubeLoop(EFFECT_DELAY/j);
setLevel(0x0, 3); }
cubeLoop(EFFECT_DELAY/j);

}

for(int i=0;i<7;i++)

75

{
setLevel(0x2184, 0);
setLevel(0x2184, 1);
setLevel(0x2184, 2);
setLevel(0x2184, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x300c, 0);
setLevel(0x300c, 1);
setLevel(0x300c, 2);
setLevel(0x300c, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0xc003, 0);
setLevel(0xc003, 1);
setLevel(0xc003, 2);
setLevel(0xc003, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x4812, 0);
setLevel(0x4812, 1); setLevel(0x4812, 2);
setLevel(0x4812, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x4422, 0);
setLevel(0x4422, 1);
setLevel(0x4422, 2);
setLevel(0x4422, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x2244, 0);
setLevel(0x2244, 1);
setLevel(0x2244, 2);
setLevel(0x2244, 3);
cubeLoop(EFFECT_DELAY/6);
setLevel(0x0,0);

76

setLevel(0x0,1);
setLevel(0x0,2);
setLevel(0x0,3);
}

skipFlag = false;

}
void effect7()
{
int arr0[8]={0x7a5a,0x7ada,0x7bda,0xfbda,0xfbdb,0xffdb,0xfffb,0xffff};//02
int arr1[8]={0xa5e5,0xb5e5,0xb5ed,0xb7ed,0xbfed,0xffed,0xfffd,0xffff};//13
int arr3[2]={1,3},arr4[2]={2,0};
for(int i=0;i<2;i++)
{
setLevel(0x5a5a, 0);
setLevel(0x5a5a, 2);
setLevel(0xa5a5, 1);
setLevel(0xa5a5, 3);
cubeLoop(EFFECT_DELAY);
setLevel(0x5a5a, 1);
setLevel(0x5a5a, 3);
setLevel(0xa5a5, 0);
setLevel(0xa5a5, 2);
cubeLoop(EFFECT_DELAY);
}
for(int m=0;m<2;m++)
{
for(int i=0;i<8;i++)
{
setLevel(arr0[i], arr3[m]);
cubeLoop(EFFECT_DELAY/5);

77

setLevel(arr1[i], arr4[m]);
cubeLoop(EFFECT_DELAY/5);
}

}
cubeLoop(EFFECT_DELAY);

skipFlag = false;

}

מעבר מאפקט לאפקט בכל לחיצת שלט //
void setEffect() {
switch (effectCounter) {
case 0:
effect1();
break;
case 1:
effect2();
break;
case 2:
effect3();
break;
case 3:
effect4();
break;
case 4:
effect5();
break;
case 5:
effect6();

78

break;
case 6:
effect7();
break;

default:
// statements
break;
}

}

פונקציות הצלילים //

int
t1[]={time/2,time/2,time/2,time/2,time/20,time/2,time/2,time/20,time,time/2,time/2,time/20
,time,time/2,time/2,time/20,time,time/20,
time/2,time/2,time/2,time/2,time/20,time/2,time/2,time/20,time,time/2,time/2,time/20,time
,time/2,time/2,time/20,time
,time,time/20,time,time/2,time/2,time/20,time,time/2,time/2,time/20,time,time/2,time/2,tim
e,time,
time/20,time,time/2,time/2,time/20,time,time/2,time/2,time/20,time,time/2,time/2,time};
int
s1[]={DO,ME,DO,ME,0,ME,SOL,0,SOL,FA,RE,0,RE,ME,DO,0,DO,0,DO,ME,DO,ME,0,
ME,SOL,0,SOL,FA,RE,0,RE,ME,DO,0,DO,FA,0,FA,SOL,ME,0,ME,FA,RE,0,RE,DO,ME,
SOL,FA,0,FA,SOL,ME,0,ME,FA,RE,0,RE,DO,ME,DO};
void tone1()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t1[counter])

79

{
ttime = millis();
if (counter < sizeof(t1) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s1[counter] == 0)
noTone(3);
else
tone(3, s1[counter]);

}
}

//merotsei keptaoun
int
t5[]={time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time/20,time/2,time,time/2,ti
me,time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time,time/2,time/2,time*2,
time/20,time/2,time/20,time/2,time/2,time/2,time*2,time/2,time/20,time/2,time/2,time/2,ti
me*2,time/20,time/2,time/20,time/2,time/2,time/2,time/2,time/2,time,time/2,time/2,time/2,
time/2,time*2};
int
s5[]={SOL,0,SOL,ME,SOL,LA,SOL,ME,0,ME,RE,ME,RE,SOL,0,SOL,ME,SOL,LA,SOL,
ME,RE,ME,RE,DO,0,DO,0,DO,ME,SOL,DO2,LA,0,LA,DO2,LA,SOL,0,SOL,0,SOL,ME,S
OL,LA,SOL,ME,RE,FA,ME,RE,DO};

void tone5()
{
static int counter = 0;
static unsigned long ttime = millis();

80

if (millis() - ttime > t5[counter])
{
ttime = millis();
if (counter < sizeof(t5) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s5[counter] == 0)
noTone(3);
else
tone(3, s5[counter]);

}
}

//kan kan
int
t3[]={time,time/20,time,time/2,time/2,time/2,time/2,time,time/20,time,time/20,time/2,time/
2,time/2,time/2,time,
time/20,time,time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,
time/2,time/2,time/2,time/2,
time,time/20,time,time/2,time/2,time/2,time/2,time,time/20,time,time/20,time/2,tim
e/2,time/2,time/2,time,time/20,time,
time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time*2};
int
s3[]={DO,0,DO,RE,FA,ME,RE,SOL,0,SOL,0,SOL,LA,ME,FA,RE,0,RE,0,RE,FA,ME,RE,
DO,DO2,SE,LA,SOL,FA,ME,RE,DO,0,DO,RE,
FA,ME,RE,SOL,0,SOL,0,SOL,LA,ME,FA,RE,0,RE,0,RE,FA,ME,RE,DO,SOL,RE,
ME,DO};

81

void tone3()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t3[counter])
{
ttime = millis();
if (counter < sizeof(t3) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s3[counter] == 0)
noTone(3);
else
tone(3, s3[counter]);

}
}

//boker yov higia
int
t4[]={time/2,time/2,time/2,time/2,time,time/20,time,time/2,time/2,time/2,time/2,time*2,tim
e/2,time/2,time/2,time/2,time*2,time/2,time/20,time/2,time/20,time/2,time/20,time/2,time/
2,time/20,
time/2,time/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time,time/2,time/20,time/
2,time/20,time/2,time/20,time/2,time/2,time/20,time/2,time/20,time,time/2,time/2,time/2,ti
me/2,time*2};

82

int
s4[]={DO,RE,ME,FA,SOL,0,SOL,LA,FA,DO2,LA,SOL,LA,FA,DO2,LA,SOL,FA,0,FA,0,F
A,0,FA,ME,0,ME,0,ME,RE,FA,ME,RE,DO,ME,SOL,FA,0,FA,0,FA,0,FA,ME,0,ME,0,ME,
RE,FA,ME,RE,DO};

void tone4()
{
static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t4[counter])
{
ttime = millis();
if (counter < sizeof(t4) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s4[counter] == 0)
noTone(3);
else
tone(3, s4[counter]);

}
}

//laila tov
int t2[]={time/2, time/2,time,time/2,time/2,time,time/2,time/2,time,time/2,time/2,time};
int s2[]={DO,RE,ME,RE,DO,RE,DO,RE,ME,RE,ME,DO};
void tone2()
{
static int counter = 0;

83

static unsigned long ttime = millis();
if (millis() - ttime > t2[counter])
{
ttime = millis();
if (counter < sizeof(t2) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s2[counter] == 0)
noTone(3);
else
tone(3, s2[counter]);

}
}

העובדים החרוצים עמוד 59//
int
t6[]={time/2,time/2,time/20,time/2,time/20,time/2,time/2,time/2,time/20,time/2,time/20,tim
e/2,time/2,time/2,time/2,time/2,time,time/20,time/2,time/2,time/20,time/2,time/20,time/2,t
ime/2,time/2,time/20,time/2
,time/20,time/2,time/2,time/2,time/20,time/2,time/20,time/2,time/2,time/2,time/20,time/2,t
ime/20,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time/2,time,time/2,time/2,time/2,ti
me/2,time/2,time};
int
s6[]={ME,SOL,0,SOL,0,SOL,DO2,SOL,0,SOL,0,SOL,FA,ME,RE,DO,RE,0,RE,FA,0,FA,
0,FA,ME,SOL,0,SOL,0,SOL,RE,FA,0,FA,0,FA,RE,SOL,0,SOL,0,SOL,DO2,SOL,FA,ME,
RE,DO,ME,SOL,DO2,SOL,FA,ME,RE,DO};

void tone6()
{

84

static int counter = 0;
static unsigned long ttime = millis();
if (millis() - ttime > t6[counter])
{
ttime = millis();
if (counter < sizeof(t6) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s6[counter] == 0)
noTone(3);
else
tone(3, s6[counter]);

}
}

//shir shel ema
int
t7[]={time/2,time/2,time/2,time/2,time/2,time/20,time/2,time,time/2,time/2,time/2,time/2,ti
me/2,time/20,time/2,time,time/20};
int s7[]={DO,RE,ME,DO,RE,0,RE,ME,DO,RE,ME,DO,RE,0,RE,DO,0};

void tone7()
{
static int counter = 0;

85

static unsigned long ttime = millis();
if (millis() - ttime > t7[counter])
{
ttime = millis();
if (counter < sizeof(t7) / sizeof(int) - 1)
{
counter ++;
}
else counter = 0;
if(s7[counter] == 0)
noTone(3);
else
tone(3, s7[counter]);

}
}

התכנית הראשית //
void loop()
{

setEffect();
}

int level[4]; //cube data

86

void cubeLoop(unsigned long updateTime) { // המתאימה הקומה הדלקת
unsigned long mTime = millis();
while (updateTime > (millis() - mTime)) {
for (int c = 0; c < 4; c++) {
setCube(level[c]); //
digitalWrite(T1, LOW);
digitalWrite(T2, LOW);
digitalWrite(T3, LOW);
digitalWrite(T4, LOW);
if (c == 0)
digitalWrite(T1, HIGH);
else if (c == 1)
digitalWrite(T2, HIGH);
else if (c == 2)
digitalWrite(T3, HIGH);
else if (c == 3)
digitalWrite(T4, HIGH);
mDelay(LevelDelay);
}
}
}
void setCube(int data) { // המתאימים הלדים הדלקת
shiftOut(din, clkpin, LSBFIRST, data >> 8);
shiftOut(din, clkpin, LSBFIRST, data);
digitalWrite(lat, HIGH);
digitalWrite(lat, LOW);
}
void setLevel(int data, int lvl) { // המתאימה הקומה הגדרת
if (lvl >= 0 && lvl < 4)
level[lvl] = data;
}

