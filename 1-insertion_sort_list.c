#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 *
 * Description: Prints the list after each time two nodes are swapped.
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insertion_point;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        insertion_point = current->prev;
        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            if (insertion_point->prev != NULL)
                insertion_point->prev->next = current;
            current->prev = insertion_point->prev;
            insertion_point->prev = current;
            insertion_point->next = current->next;
            if (current->next != NULL)
                current->next->prev = insertion_point;
            current->next = insertion_point;
            if (*list == insertion_point)
                *list = current;

            print_list(*list);
            insertion_point = current->prev;
        }
        current = current->next;
    }
}

