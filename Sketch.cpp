#include <TimerOne.h>
#include <known_16bit_timers.h>
#include <LiquidCrystal.h>
#include "minhalib.h"

const int trigger= 7;
const int echo =  8;
int *pVet = NULL;
int i=0 ;
int contSobrepos=0 ;
LiquidCrystal lcd(12, 11, 6, 5, 4,3);
int tam = random(30,50);
int contwait=0;

void interrupt()
{
	lcd.clear();
	lcd.setCursor(0, 0);
	parkingstatus(trigger,echo);
	contSobrepos = EntradaEsobrePos(i,tam,pVet,trigger,echo,contSobrepos);
	i++;
	printlinha1(contSobrepos,i,tam,pVet,lcd);
	printlinha2(i,tam,pVet,lcd);
	lcd.print(" ");
}
void wait()
{
	contwait++;
	if(contwait%5 == 0)
	{
		interrupt();
	}
}
void setup()
{
	
	Timer1.initialize(1000000);         
	Timer1.attachInterrupt(wait);
	pinMode(trigger,OUTPUT);
	pinMode(echo,INPUT);
	pinMode(9,OUTPUT);
	pinMode(10,OUTPUT);
	lcd.begin(16, 2);
	lcd.setCursor(0,0);
	lcd.print("Emilio Gaudeda Junior");
	lcd.setCursor(0,1);
	lcd.print("GRR20191670");
	pVet = (int*) malloc(tam);
}
void loop()
{
}