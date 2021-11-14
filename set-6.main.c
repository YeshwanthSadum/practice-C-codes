#include "set-6.h"
main()
{
    struct parking* p;
    int vehicle_st;
    int num;
    float in;
    float out;
    int i;
    p=init(200);

    while(1)
    {

        printf("Enter 1 to enter vehicle or 0 to exit vehicle:");
        scanf("%d",&i);
        if(i==1)
        {
        printf("\nPlease enter the vehicle status(1 for customer vehicle and 0 for shop vehicle) , vehicle number(int) and in_time(ex. 12.24, 13.20, 15.00)\n");
        scanf("%d %d %f", &vehicle_st, &num, &in);
        enter_vehicle(p,vehicle_st,num,in);
        }
        else if(i==0)
        {
            printf("\nPlease enter the vehicle number and exit time\n");
            scanf("%d %f",&num, &out);
            exit_vehicle(p,num, out);
        }
        printf("\n%d\n",p->c[0].number);
    }
}
