#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursive function to perform quick sort.
 * @array: The array to sort.
 * @low: The low index of the partition to sort.
 * @high: The high index of the partition to sort.
 * @size: The size of the array.
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = _partition(array, low, high, size);

        _quick_sort(array, low, pi - 1, size);
        _quick_sort(array, pi + 1, high, size);
    }
}

/**
 * _partition - Partitions the array and returns the pivot index.
 * @array: The array to partition.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot element.
 */
int _partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            _swap(&array[i], &array[j]);
            print_array(array, size);
        }
    }
    _swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

/**
 * _swap - Swaps two integers.
 * @a: The first integer.
 * @b: The second integer.
 */
void _swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}