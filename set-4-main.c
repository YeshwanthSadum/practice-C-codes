#include <stdio.h>

#define NUM_PLAYERS 10
#define NUM_TEAMS 3
#define TEAM_BUDGET 10.0f

int main(void)
{
    float sp[NUM_PLAYERS];
    char team[NUM_TEAMS] = {'a', 'b', 'c'};
    char player_status[NUM_PLAYERS];
    float amount_spent_by[NUM_TEAMS] = {0, 0, 0};
    float cost[NUM_PLAYERS] = {1.2f, 1.5f, 3.0f, 5.3f, 1.0f,
                               3.0f, 2.0f, 1.0f, 1.0f, 2.0f}; /* min price of each player */
    int i, j;

    for (i = 0; i < NUM_PLAYERS; i++) {
        sp[i] = cost[i];
        player_status[i] = 'n';
    }

    for (j = 0; j < NUM_PLAYERS; j++) { /* each player */
        int flag[NUM_TEAMS] = {0, 0, 0};
        int all_passed = 0;

        printf("\nPlayer %d\n", j + 1);
        while (!all_passed) {
            all_passed = 1;
            for (i = 0; i < NUM_TEAMS; i++) { /* each team */
                float bid;

                if (flag[i] == 1)
                    continue;

                printf("\nTeam %c : Enter a price higher than %f for the player %d else enter 0:",
                       team[i], sp[j], j + 1);
                if (scanf("%f", &bid) != 1)
                    return 1;

                if (bid <= sp[j]) {
                    flag[i] = 1;          /* team stopped bidding for this player */
                    continue;
                }
                if (bid >= cost[j] && (amount_spent_by[i] + bid) <= TEAM_BUDGET) {
                    sp[j] = bid;
                    player_status[j] = team[i];
                }
                all_passed = 0;
            }
        }
        /* charge the winning team once, after bidding for this player ends */
        if (player_status[j] != 'n') {
            for (i = 0; i < NUM_TEAMS; i++) {
                if (player_status[j] == team[i]) {
                    amount_spent_by[i] += sp[j];
                    break;
                }
            }
        }
    }

    for (i = 0; i < NUM_PLAYERS; i++) {
        if (player_status[i] != 'n')
            printf("Player %d sold to %c at %f\n", i + 1, player_status[i], sp[i]);
        else
            printf("Player %d not sold\n", i + 1);
    }

    return 0;
}
