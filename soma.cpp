#include "soma.h"

float soma(int *pVet,int tam,int cont)
{
	float aux = 0.0;
	if(cont >= tam)
	{
		for (int a = 0; a < tam; a++)
		{
			aux += *(pVet + a);
		}
	}
	else
	{
		for (int a = 0; a < cont; a++)
		{
			aux += *(pVet + a);
		}
	}
	
	return aux;
}