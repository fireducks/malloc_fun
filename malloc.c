#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

node *insert_array(int *array, int sizeof_array, node *n);

int main(void)
{
    node *list = NULL;
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    list = n;

    int array[] = {4,2,6};

    n = insert_array(array, sizeof(array), n);

    n->next = NULL;

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i, %p\n", tmp->number, tmp->next);
    }

    //add new array after '2'
    int new_array[] = {3,8};

    n = list;

    while(n->number != 2)
    {
        n = n->next;
    }

    node *temp = n->next;

    n->next = malloc(sizeof(node));
    n = n->next;

    n = insert_array(new_array, sizeof(new_array), n);

    n->next = temp;

printf("new array-\n");
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i, %p\n", tmp->number, tmp->next);
    }


    //free all the addresses
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

}

node *insert_array(int *array, int sizeof_array, node *n)
{
    for (int i = 0; i < sizeof_array / sizeof(array[0]); i++)
    {
        n->number = array[i];

        if (i < (sizeof_array / sizeof(array[0])) - 1)
        {
            n->next = malloc(sizeof(node));
            n = n->next;
        }
    }

    return n;
}