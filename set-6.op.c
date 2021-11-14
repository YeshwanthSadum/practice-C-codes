#include "set-6.h"
struct parking* init(int size)
{
    struct parking* p;
    p=(struct parking*)malloc(sizeof(struct parking));
    p->c=(struct car*)malloc(sizeof(struct car)*200);
    p->c_size=0;
    p->t_size=size;
};

void enter_vehicle(struct parking* p, int vehicle_st, int num, float in)
{
    if(p->c_size<p->t_size)
    {
        p->c[p->c_size].vehicle_status=vehicle_st;
        p->c[p->c_size].number=num;
        p->c[p->c_size].in_time=in;
        p->c[p->c_size].vehicle_in_parking=1;
        p->c_size++;
    }
    else printf("\n Parking full");
}
void exit_vehicle(struct parking* p, int num, float out)
{
    int i,flag=0;
    float time;
    for(i=0;i<p->c_size;i++)
    {
        if(p->c[i].number == num && p->c[i].vehicle_in_parking==1)
        {
            p->c[i].out_time=out;
            time = (p->c[i].out_time - p->c[i].in_time);
            if(p->c[i].vehicle_status ==0)
            {
                p->c[i].price=0;
            }
            else{
            if(time<=2)
            p->c[i].price=20;
            else
            p->c[i].price=((ceil(time-2))*10 + 20);

            }
            printf("The price for %f is %f\n", time, p->c[i].price);
            flag=1;
            p->c[i].vehicle_in_parking=0;
        }
    }
    if(flag==0)
    {
        printf("Vehicle not found\n");
    }
}
