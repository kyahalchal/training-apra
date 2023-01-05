#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Product
{
    int id;
    int price;
    char name[20];
};

struct Node
{
    struct Product prod;
    struct Node *next;
};

// --------------------------- delete product by id --------------------------------
void delete(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref;
    struct Node *prev;

    if (temp != NULL && temp->prod.id == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    };

    while (temp != NULL && temp->prod.id != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("No product with id %d\n", key);
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// --------------------------- update product by id --------------------------------
void update(struct Node *head_ref, int x, int y, char c[])
{
    while (head_ref != NULL)
    {
        if (head_ref->prod.id == x)
        {
            printf("The product name is %s and product price is %d\n", head_ref->prod.name, head_ref->prod.price);
            strcpy(head_ref->prod.name, c);
            head_ref->prod.price = y;
            printf("The updated product name is %s and updated product price is %d\n", c, y);
            break;
        }
        else if (head_ref->next == NULL)
        {
            printf("No product found by id %d\n", x);
            head_ref = head_ref->next;
        }
        else
        {
            head_ref = head_ref->next;
        }
    }
}

// --------------------------- search product by name --------------------------------
void search(struct Node *head_ref, char c[20])
{
    int flag = 1;
    while (head_ref != NULL)
    {
        if (strcmp(head_ref->prod.name, c) == 0)
        {
            printf("The product ID is %d and product price is %d\n", head_ref->prod.id, head_ref->prod.price);
            head_ref = head_ref->next;
            flag = 0;
        }
        else if (head_ref->next == NULL && flag == 1)
        {
            printf("No product found by name %s\n", c);
            head_ref = head_ref->next;
        }
        else
        {
            head_ref = head_ref->next;
        }
    }
}

// --------------------------- display all product --------------------------------
void printList(struct Node *n)
{
    while (n != NULL)
    {
        /* code */
        printf("%d\t", n->prod.id);
        printf("%d\t", n->prod.price);
        printf("%s\n", n->prod.name);

        n = n->next;
    }
}

// --------------------------- create new product ------------------------------------
void push(struct Node **head_ref, int x, int y, char c[20])
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->prod.id = x;
    new_node->prod.price = y;
    strcpy(new_node->prod.name, c);
    new_node->next = *head_ref;

    *head_ref = new_node;
}

int main()
{
    /* code */
    struct Node *head = NULL;

    push(&head, 1, 100, "Apple");
    push(&head, 2, 200, "Ball");
    push(&head, 3, 300, "Cube");
    push(&head, 4, 400, "Apple");

    printList(head);

    search(head, "Apple");
    search(head, "Zebra");

    update(head, 1, 282, "Rice");

    printList(head);

    search(head, "Apple");

    delete (&head, 6);
    delete (&head, 2);

    printList(head);

    push(&head, 5, 500, "Mouse");
    push(&head, 6, 600, "Table");
    push(&head, 7, 700, "Bed");

    search(head, "Table");

    printList(head);

    FILE *fp = fopen("productList.txt", "w");
    while (head != NULL)
    {
        fprintf(fp, "Product ID: %d\t Product Price: %d\t Product Name: %s\n", head->prod.id, head->prod.price, head->prod.name);
        head = head->next;
    }
    fclose(fp);

    return 0;
}
