#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *sorted = NULL; // Sorted list
    listint_t *current = *list;

    while (current != NULL)
    {
        listint_t *next = current->next; // Store the next node before modifying current

        if (sorted == NULL || sorted->n >= current->n)
        {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            listint_t *search = sorted;
            while (search->next != NULL && search->next->n < current->n)
                search = search->next;

            current->next = search->next;
            if (search->next != NULL)
                search->next->prev = current;
            search->next = current;
            current->prev = search;
        }

        current = next; // Move to the next node
    }

    *list = sorted; // Update the head of the list
}
