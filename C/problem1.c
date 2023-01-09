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

// --------------------------- add new product ------------------------------------
void addProd(struct Node **head_ref)
{
    int id;
    int price;
    char name[20];
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Product ID: ");
    scanf("%d", &id);
    fflush(stdin);

    printf("\nEnter Product Name: ");
    // scanf("%s",name);
    scanf("%[^\n]s", name);
    // fgets(name, 20, stdin);
    // fflush(stdin);

    printf("\nEnter Product Price: ");
    scanf("%d", &price);
    fflush(stdin);

    new_node->prod.id = id;
    strcpy(new_node->prod.name, name);
    new_node->prod.price = price;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

// --------------------------- update product by id --------------------------------
void updateProd(struct Node *head_ref)
{
    int id;
    char name[20];
    int price;

    printf("\nEnter ID of the product you want to update: ");
    scanf("%d", &id);
    fflush(stdin);

    while (head_ref != NULL)
    {
        if (head_ref->prod.id == id)
        {
            printf("\nThe product name is %s and product price is %d", head_ref->prod.name, head_ref->prod.price);
            printf("\nEnter new name for Product : ");
            // scanf("%s", name);
            // fgets(name, 20, stdin);
            // fflush(stdin);
            scanf("%[^\n]s", name);
            strcpy(head_ref->prod.name, name);

            printf("\nEnter new price for Product : ");
            scanf("%d", &price);
            fflush(stdin);
            head_ref->prod.price = price;
            printf("\nThe updated product name is %s and updated product price is %d", head_ref->prod.name, head_ref->prod.price);
            break;
        }
        else if (head_ref->next == NULL)
        {
            printf("\nNo product found by id %d", id);
            head_ref = head_ref->next;
        }
        else
        {
            head_ref = head_ref->next;
        }
    }
}

// --------------------------- delete product by id --------------------------------
void deleteProd(struct Node **head_ref)
{
    int id;
    printf("\nEnter ID of the product you want to delete: ");
    scanf("%d", &id);
    fflush(stdin);

    struct Node *temp = *head_ref;
    struct Node *prev;

    if (temp != NULL && temp->prod.id == id)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    };

    while (temp != NULL && temp->prod.id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nNo product with id %d", id);
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// --------------------------- search product by name --------------------------------
void searchProd(struct Node *head_ref)
{
    char name[20];
    printf("\nEnter name of the product you want to search: ");
    // scanf("%[^\n]s", name);
    fflush(stdin);
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;
    // scanf("%[^\n]s", name);

    int flag = 1;
    while (head_ref != NULL)
    {
        if (strcasecmp(head_ref->prod.name, name) == 0)
        {
            printf("\nThe product ID is %d and product price is %d", head_ref->prod.id, head_ref->prod.price);
            head_ref = head_ref->next;
            flag = 0;
        }
        else if (head_ref->next == NULL && flag == 1)
        {
            printf("\nNo product found by name %s", name);
            head_ref = head_ref->next;
        }
        else
        {
            head_ref = head_ref->next;
        }
    }
}

// --------------------------- find product by id --------------------------------
void findProd(struct Node *head_ref)
{
    int id;
    printf("\nEnter ID of the product you want to find: ");
    scanf("%d", &id);
    fflush(stdin);

    while (head_ref != NULL)
    {
        if (head_ref->prod.id == id)
        {
            printf("\nThe product name is %s and product price is %d", head_ref->prod.name, head_ref->prod.price);
            break;
        }
        else if (head_ref->next == NULL)
        {
            printf("\nNo product found by id %d", id);
            head_ref = head_ref->next;
            // break;
        }
        else
        {
            head_ref = head_ref->next;
        }
    }
}

// --------------------------- display all product --------------------------------
void displayProd(struct Node *head_ref)
{
    while (head_ref != NULL)
    {
        /* code */
        printf("\n%d", head_ref->prod.id);
        printf("\t%s", head_ref->prod.name);
        printf("\t%d", head_ref->prod.price);

        head_ref = head_ref->next;
    }
}

// --------------------- write linked list to file --------------------------
void save(struct Node *head_ref)
{
    FILE *fp = fopen("productList.txt", "w");
    while (head_ref != NULL)
    {
        fprintf(fp, "Product ID: %d\nProduct Name: %s\n Product Price: %d\n", head_ref->prod.id, head_ref->prod.name, head_ref->prod.price);
        head_ref = head_ref->next;
    }
    fclose(fp);
}

// -------------------------------------------------------------------MAIN---------------------------------------------------------------
int main()
{
    int choice;
    struct Node *head = NULL;

    /*char arr[1000];      ------------------------> code to read file, it is working
    FILE *fo = fopen("productList.txt", "r");
    while(fgets(arr, 1000, (FILE*)fo))
    {
        printf(arr);
    }
    fclose(fo);*/
    
    enum operation {ADD_PRODUCT=1, UPDATE_PRODUCT=2, DELETE_PRODUCT=3, SEARCH_BY_PRODUCT_NAME=4, FIND_BY_PRODUCT_ID=5, DISPLAY_PRODUCT=6, SAVE_PRODUCTS=7, EXIT=8};
    
    printf("What you want to do?\n1.Add product\n2.Update product\n3.Delete product\n4.Search product by name\n5.Find product bu ID\n6.Display products\n7.Save products\n8.Exit");
    do
    {
        printf("\nSelect your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case (ADD_PRODUCT):
            addProd(&head);
            break;
        case (UPDATE_PRODUCT):
            updateProd(head);
            break;
        case (DELETE_PRODUCT):
            deleteProd(&head);
            break;
        case (SEARCH_BY_PRODUCT_NAME):
            searchProd(head);
            break;
        case (FIND_BY_PRODUCT_ID):
            findProd(head);
            break;
        case (DISPLAY_PRODUCT):
            displayProd(head);
            break;
        case (SAVE_PRODUCTS):
            save(head);
            break;
        case (EXIT):
            printf("Thanks for coming by!!");
            break;
        default:
            printf("\nInvalid query");
            break;
        }
    } while (choice != 8);

    return 0;
}
