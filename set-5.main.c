#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct kid{
    char name[10];
    char hobbie1[50];
    char hobbie2[50];
    char attribute1[50];
    char attribute2[50];
    char interest1[50];
    char interest2[50];
};

struct all{
struct kid* k;
int c_size;
int t_size;
};

struct all* init(int size)
{
    struct all* p;
    p=(struct all*)malloc(sizeof(struct all));
    p->k=(struct kid*)malloc(sizeof(struct kid)*size);
    p->c_size=0;
    p->t_size=size;
};
void store(struct all* gender, char ch1[],char ch2[],char ch3[],char ch4[],char ch5[],char ch6[], char ch7[])
{
    strcpy(gender->k[gender->c_size].name,ch1);
    strcpy(gender->k[gender->c_size].attribute1,ch4);
    strcpy(gender->k[gender->c_size].attribute2,ch5);
    strcpy(gender->k[gender->c_size].hobbie1,ch2);
    strcpy(gender->k[gender->c_size].hobbie2,ch3);
    strcpy(gender->k[gender->c_size].interest1,ch6);
    strcpy(gender->k[gender->c_size].interest2,ch7);

    gender->c_size++;

};

void match_hobbie(struct all* boy, struct all* girl)
{
    int i,j;
    for(i=0;i<boy->c_size;i++)
    {
        for(j=0;j<girl->c_size;j++)
        {
            if((!strcmp(boy->k[i].hobbie1,girl->k[j].hobbie1) || !strcmp(boy->k[i].hobbie1,girl->k[j].hobbie2))&&(!strcmp(boy->k[i].hobbie2,girl->k[j].hobbie1) || !strcmp(boy->k[i].hobbie2,girl->k[j].hobbie2)))
                printf("Match found - hobbies : %s, %s\n", boy->k[i].name, girl->k[j].name);
        }
    }
}

void match_expectations(struct all* boy, struct all* girl)
{
    int i,j;
    for(i=0;i<boy->c_size;i++)
    {
        for(j=0;j<girl->c_size;j++)
        {
            if((!strcmp(boy->k[i].hobbie1,girl->k[j].hobbie1) || !strcmp(boy->k[i].hobbie1,girl->k[j].hobbie2))&&(!strcmp(boy->k[i].hobbie2,girl->k[j].hobbie1) || !strcmp(boy->k[i].hobbie2,girl->k[j].hobbie2)))
                if((!strcmp(boy->k[i].attribute1,girl->k[j].interest1) || !strcmp(boy->k[i].attribute1,girl->k[j].interest2)) && (!strcmp(boy->k[i].attribute2,girl->k[j].interest1) || !strcmp(boy->k[i].attribute2,girl->k[j].interest2)))
                    if((!strcmp(boy->k[i].interest1,girl->k[j].attribute1) || !strcmp(boy->k[i].interest1,girl->k[j].attribute2)) && (!strcmp(boy->k[i].interest2,girl->k[j].attribute1) || !strcmp(boy->k[i].interest2,girl->k[j].attribute2)))
                        printf("\nMatch found - hobbies and Expectations : %s, %s\n", boy->k[i].name, girl->k[j].name);

        }
    }
}
main()
{
    struct all *boy,*girl;

    boy = init(20);
    girl = init(20);
    store(boy,"tom","playing","dancing","tall","kind","tall","blonde"); // name, hobbies[2], attribute[2], expectations [2]
    store(girl,"jennifer","dancing","playing","tall","blonde","tall","kind");
    store(girl,"ellen","listening","movie","short","blonde","tall","kind");
    store(boy,"john","movie","listening","short","humorous","blonde","short");

    match_hobbie(boy,girl);
    match_expectations(boy,girl);

}
