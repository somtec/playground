/*
 * Main.c
 *
 *  Created on: Jun 2, 2016
 *      Author: som
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "helpers.h"

int minimum(int data[], int length);
int maximum(int data[], int length);
int spannweite(int data[], int length);
int sum(int data[], int length);
double average(int data[], int length);
double median(int data[], int length);
double variance(int data[], int length);
double stddev(int data[], int length);
void printarray(int data[], int length);



int main(int argc, char* argv[])
{
	int ANZAHL = 0;
	printf("Anzahl Elemente: ");
	scanf("%d",&ANZAHL);

	int testarray[ANZAHL];

	int i = 0;
	for (i = 0;i< ANZAHL;i++)
		{
			printf("Element %d eingeben: ", i);
			scanf("%d",&testarray[i]);
		}

	printf("vor Sortierung\n");
	printarray(testarray,ANZAHL);

	printf("Minimum: %d\n", minimum(testarray, ANZAHL));
	printf("Maximum: %d\n", maximum(testarray, ANZAHL));
	printf("Spannweite: %d\n", spannweite(testarray, ANZAHL));
	printf("Summe: %d\n", sum(testarray, ANZAHL));
	printf("arithm. Mittel: %f\n", average(testarray,ANZAHL));
	printf("Median: %f\n", median(testarray, ANZAHL));
	printf("Varianz: %f\n", variance(testarray, ANZAHL));
	printf("Standardabw.: %f\n", stddev(testarray, ANZAHL));
	return 0;
}
int spannweite(int data[], int length)
{
	bubblesort(data, length);
	int minimum = data[0];
	int maximum = data[length -1];
	return (maximum - minimum);
}

double average(int data[], int length)
{

	return (double)sum(data,length)/ length;
}

double median(int data[], int length)
{
	int medianposition;
	double medianwert;
	bubblesort( data, length);

	if (length % 2 == 1)
	{
		medianposition = (length +1)/2;
		medianwert = data[medianposition -1];
	}
	else
	{
		medianposition = length/2;
		medianwert = (data[medianposition -1] + data[medianposition])/2;
	}
	return medianwert;
}

int minimum(int data[], int length)
{
	bubblesort(data, length);
	printf("nach Sortierung\n");
	printarray(data, length);
	return data[0];
}

int maximum(int data[], int length)
{
	bubblesort(data, length);
	return data[length -1];
}

int sum(int data[], int length)
{
	int i = 0;
	int summe = 0;

	for (i = 0; i < length; i++)
	{
		summe +=data[i];
	}
	return summe;
}

double variance(int data[], int length)
{
	int i = 0;
	double summe_quadrat_abweichung = 0;
	double mittelwert = average(data,length);

	for (i = 0; i < length; i ++)
	{
		summe_quadrat_abweichung += (data[i] - mittelwert)*(data[i] - mittelwert);
	}
	return summe_quadrat_abweichung/(length-1);
}

double stddev(int data[], int length)
{
	return sqrt(variance(data,length));
}

void printarray(int data[], int length)
{
	int i = 0;

	for (i = 0; i < length; i++)
	{
		printf("Wert %d = %d\n",i ,data[i]);
	}

	return ;
}
