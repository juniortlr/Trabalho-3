#include "minhalib.h"
#include <Arduino.h>
#include <LiquidCrystal.h>
#include "media.h"
#include "soma.h"

float DistanciaCM(int triggerr, int echoo)
{
	float dist;
	digitalWrite(triggerr,LOW);
	delayMicroseconds(5);
	digitalWrite(triggerr,HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerr,LOW);
	
	dist=pulseIn(echoo,HIGH);
	return dist;
}
int Regrad3(int trigger, int echo)
{
	return map(DistanciaCM(trigger,echo), 400, 18500, 0, 255);
}
void parkingstatus(int trigger, int echo)
{
	float entrada = DistanciaCM(trigger, echo)/57.0;
	if(entrada > 60){
		analogWrite(9, 0);
		analogWrite(10,255);
	}
	else if(entrada<30)
	{
		analogWrite(9,255);
		analogWrite(10,0);
	}
	else
	{
		analogWrite(9,255-Regrad3(trigger,echo));
		analogWrite(10,Regrad3(trigger,echo));
	}
}

void printlinha1(int contsobrePos, int cont,int tam,int *pVet,LiquidCrystal &lcd)
{
	if(contsobrePos == 0)
	{
		if(cont == 1)
		{
			lcd.print(pVet[0]);
		}
		else if(cont == 2)
		{
			lcd.print(pVet[1]);
			lcd.print(" ");
			lcd.print(pVet[0]);
		}
		else if(cont >= 3)
		{
			lcd.print(pVet[cont-1]);
			lcd.print(" ");
			lcd.print(pVet[cont-2]);
			lcd.print(" ");
			lcd.print(pVet[cont-3]);
		}
	}

	else if(contsobrePos >0)
	{
		if(cont-(contsobrePos*tam) == 0)//6-5 //11-10//16-15
		{
			lcd.print(pVet[tam-1]);
			lcd.print(" ");
			lcd.print(pVet[tam-2]);
			lcd.print(" ");
			lcd.print(pVet[tam-3]);
		}
		if(cont-(contsobrePos*tam) == 1)
		{
			lcd.print(pVet[0]);
			lcd.print(" ");
			lcd.print(pVet[tam-1]);
			lcd.print(" ");
			lcd.print(pVet[tam-2]);
		}
		if(cont-(contsobrePos*tam) == 2)
		{
			lcd.print(pVet[1]);
			lcd.print(" ");
			lcd.print(pVet[0]);
			lcd.print(" ");
			lcd.print(pVet[tam-1]);
		}
		if(cont-(contsobrePos*tam) >= 3)//9-5//14-10//19-15
		{
			lcd.print(pVet[cont-(contsobrePos*tam)-3]);
			lcd.print(" ");
			lcd.print(pVet[cont-(contsobrePos*tam)-2]);
			lcd.print(" ");
			lcd.print(pVet[cont-(contsobrePos*tam)-1]);
		}
	}
	lcd.setCursor(8,0);
	lcd.print("i");
	lcd.print(cont);
	lcd.print(" ");
	lcd.print("$");
	lcd.print(contsobrePos);
}
int EntradaEsobrePos(int cont,int tam,int *pVet,int trigger, int echo, int contSobrepos)
{
	if(contSobrepos == 0)
	{
		if(cont == tam)
		{
			pVet[cont-(tam*contSobrepos)] = DistanciaCM(trigger,echo)/57.0;
			contSobrepos++;
		}
		else
		{
			pVet[cont] = DistanciaCM(trigger,echo)/57.0;
		}
	}
	if(contSobrepos >0)
	{
		if(cont >= tam*(contSobrepos+1))
		{
			pVet[cont-(tam*contSobrepos)] = DistanciaCM(trigger,echo)/57.0;
			contSobrepos++;
		}
		else
		{
			pVet[cont-(tam*contSobrepos)] = DistanciaCM(trigger,echo)/57.0;
		}
	}
	return contSobrepos;
}

void printlinha2(int cont,int tam,int *pVet,LiquidCrystal &lcd)
{
	lcd.setCursor(0,1);
	lcd.print("S:");
	lcd.print(soma(pVet,tam,cont));
	lcd.print("M:");
	lcd.print(media(cont,pVet,tam));
}

