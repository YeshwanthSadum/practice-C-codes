/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item{
int item_id;
char item_name[20];
float item_unit_price;
int item_current_stock;
};

struct store{
struct item* arr;
int c_size;
int t_size;
};

struct store* init(int size)
{
    struct store* st;
    st = (struct store*)malloc(sizeof(struct store));
    st->arr = (struct item*)malloc(sizeof(struct item)*size);
    st->c_size=0;
    st->t_size=size;
    return st;
}

store_item(struct store* st,int sl_num, char ch[], float price, int stock)
{
    if(st->c_size==st->t_size)
    {
        printf("Store is full\n");
    }
    st->arr[st->c_size].item_id = sl_num;
    strcpy(st->arr[st->c_size].item_name,ch);
    st->arr[st->c_size].item_unit_price = price;
    st->arr[st->c_size].item_current_stock = stock;
    st->c_size++;

}
main()
{
    struct store* st;
    int i;
    char ch[50];
    st = init(24);
    store_item(st,1,"bread",210,20);
    store_item(st,2,"bun",100,0);
    store_item(st,3,"apple",211,12);
    store_item(st,4,"mango",211,10);
    store_item(st,5,"bannana",21,1341);

    while(1)
    {
        printf("\nPlease enter the name of product : ");
        scanf("%s", &ch);
        //printf("\nitem %s\n", st->arr[0].item_name);

        for(i=0;i<st->c_size;i++)
        {
            if(!strcmp(st->arr[i].item_name,ch))
            {
                if(st->arr[i].item_current_stock>0)
                {
                    st->arr[i].item_current_stock--;
                    printf("Item sold : %s, stock left : %d \n", ch, st->arr[i].item_current_stock);
                }
                else {
                    printf("Out of stock\n");
                }
            }
        }

    }

}

*/
