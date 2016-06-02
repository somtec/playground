/*
 * helpers.c
 *
 *  Created on: Jun 2, 2016
 *      Author: som
 */


#include <stdlib.h>
#include "helpers.h"

void bubblesort(int data[], int length)
{
	int i = 0, j = 0;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (data[i] > data[j])
			{
				int tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
		}
	}
}

void fill_random(int data[], int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		data[i]= rand();
	}
}
