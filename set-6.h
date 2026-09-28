#ifndef SET_6_H
#define SET_6_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct car {
    int vehicle_status;
    int number;
    float in_time;
    float out_time;
    float price;
    int vehicle_in_parking;
};

struct parking {
    struct car* c;
    int c_size;
    int t_size;
};

struct parking* init(int size);

void enter_vehicle(struct parking* p, int vehicle_st, int num, float in);
void exit_vehicle(struct parking* p, int num, float out);

#endif /* SET_6_H */
