#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - a function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: given array
 * @size: size of array
 **/
void bubble_sort(int *array, size_t size)
{
	size_t j, k, temp;

	for (j = 0; j < size; j++)
	{
		for (k = 0; k < size - j - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
