#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bike{
int bike_id;
char bike_name[50];
int bike_cc;
float hourly_charges;
};

struct rentals{
struct bike* bike_arr;
int c_size;
int t_size;
};

struct rentals* init(int size)
{
    struct rentals* pt;
    pt = (struct rentals*)malloc(sizeof(struct rentals));
    pt->bike_arr = (struct bike*)malloc(sizeof(struct bike)*size);
    pt->c_size=0;
    pt->t_size=size;
    return pt;
};

void store(struct rentals* pt, int id, char ch[], int bikecc)
{
    pt->bike_arr[pt->c_size].bike_id=id;
    strcpy(pt->bike_arr[pt->c_size].bike_name,ch);
    pt->bike_arr[pt->c_size].bike_cc=bikecc;
    if(bikecc<=125)
    pt->bike_arr[pt->c_size].hourly_charges=20;
    else if(bikecc<=350)
        pt->bike_arr[pt->c_size].hourly_charges=20;
    else pt->bike_arr[pt->c_size].hourly_charges=25;
    pt->c_size++;
}
main()
{
    struct rentals* pt;
    int cc, hours;
    int i;
    int flag=1;
    char name[50];
    pt = init(20);
    store(pt,1,"pulsar",200);
    store(pt,2,"duke",200);
    store(pt,3,"duke",390);
    store(pt,4,"duke",790);
    store(pt,5,"Adventure",390);
    store(pt,6,"tvs50",50);
    store(pt,7,"Access125",125);


        printf("Please enter the bike name, cc and number of hours\n");
        scanf("%s %d %d",&name, &cc, &hours);

        for(i=0;i<pt->c_size;i++)
        {
            if(!strcmp(pt->bike_arr[i].bike_name,name) && pt->bike_arr[i].bike_cc==cc)
            {
               printf("\ncost : %f",((pt->bike_arr[i].hourly_charges)*(hours)));
               flag=0;
            }
        }
        if(flag==1)
        {
            printf("\nBike not found");
        }
}
