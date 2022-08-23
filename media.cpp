#include "minhalib.h"
#include "media.h"

float media(int cont,int *pVet,int tam)
{
	if(cont<=tam)
	{
		return (float)soma(pVet,tam,cont)/(float)cont;
	}
	else
	return (float)soma(pVet,tam,cont)/(float)tam;
}