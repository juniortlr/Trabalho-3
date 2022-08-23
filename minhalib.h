#include <LiquidCrystal.h>

#ifndef MINHALIB_H_
#define MINHALIB_H_

void alocacaoincial(int *pVet, int tamincial);
void printlinha2(int cont,int tam,int *pVet,LiquidCrystal &lcd);
float DistanciaCM(int triggerr, int echoo);
int Regrad3(int trigger, int echo);
void parkingstatus(int trigger, int echo);
float soma(int *pVet,int tam,int cont);
void printlinha1(int contsobrePos, int cont,int tam,int *pVet,LiquidCrystal &lcd);
int EntradaEsobrePos(int cont,int tam,int *pVet,int trigger, int echo, int contSobrepos);
float media(int cont,int *pVet,int tam);


#endif /* MINHALIB_H_ */