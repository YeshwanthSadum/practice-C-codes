#include<stdio.h>

int main()
{

    float sp[10],bidding_price[3]={0,0,0};

            char team[] ={'a','b','c','\0'};

            char player_status[10] = "nnnnnnnnnn"; // 10 players init to 'n'

            float amount_spent_by[3];
            int i,j,p=0,n,flag[4];
            float q;

            float cost[10]={1.2,1.5,3,5.3,1,3,2,1,1,2}; // min price of each player
            for(i=0;i<10;i++)
            sp[i]=cost[i];



    for(j=0;j<3;j++) // 3 players
    {
        printf("\nPlayer %d\n", j+1);
        for(i=0;i<4;i++)
            flag[i]=0;

    do
    {
        for(i=0;i<3;i++) // 3 teams
        {
            if(flag[i]==1) continue;

            printf("\nTeam %c : Enter a price higher than %f for the player %d else enter 0:",team[i],sp[j],j+1);
            scanf("%f",&bidding_price[i]);
            if(bidding_price[i]<=sp[j])
            {
                flag[i] = 1;
                bidding_price[i] = 0;
            }


        if(bidding_price[i]>=cost[j] && bidding_price[i]>sp[j] && (amount_spent_by[i]+bidding_price[i])<=10)
            {
                sp[j]=bidding_price[i];
                player_status[j]=team[i];
                p=i;

            }

        }


    amount_spent_by[p]+=sp[j];
    }while(bidding_price[0]!=0 || bidding_price[1]!=0 || bidding_price[2]!=0);
    }
    for(i=0;i<3;i++)
    {
        if(player_status[i]!='n')
    printf("Player %d sold to %c at %f\n",i+1,player_status[i],sp[i]);
    else printf("player %d not sold\n", i+1);
    }

return 0;
}
