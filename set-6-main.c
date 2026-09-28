#include "set-6.h"

int main(void)
{
    struct parking* p;
    int vehicle_st;
    int num;
    float in;
    float out;
    int i;

    p = init(200);
    if (p == NULL)
        return 1;

    while (1) {
        printf("Enter 1 to enter vehicle or 0 to exit vehicle:");
        if (scanf("%d", &i) != 1)
            break;
        if (i == 1) {
            printf("\nPlease enter the vehicle status(1 for customer vehicle and 0 for shop vehicle), vehicle number(int) and in_time(ex. 12.24, 13.20, 15.00)\n");
            if (scanf("%d %d %f", &vehicle_st, &num, &in) != 3)
                break;
            enter_vehicle(p, vehicle_st, num, in);
        } else if (i == 0) {
            printf("\nPlease enter the vehicle number and exit time\n");
            if (scanf("%d %f", &num, &out) != 2)
                break;
            exit_vehicle(p, num, out);
        }
        printf("\n%d\n", p->c[0].number);
    }

    free(p->c);
    free(p);
    return 0;
}
