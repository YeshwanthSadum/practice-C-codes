#include <stdio.h>
#include <stdlib.h>

struct node {
    float x, y;
    float weight;
};

struct ptr {
    struct node* position;
    int c_size;
    int t_size;
    float max_weight;
};

struct ptr* init(int size)
{
    struct ptr* n = (struct ptr*)malloc(sizeof(struct ptr));
    if (n == NULL)
        return NULL;
    n->position = (struct node*)malloc(sizeof(struct node) * size);
    if (n->position == NULL) {
        free(n);
        return NULL;
    }
    n->c_size = 0;
    n->t_size = size;
    n->max_weight = 0;
    return n;
}

void store(struct ptr* n, float x1, float y1, float w)
{
    if (n->c_size == n->t_size) {
        printf("total size reached\n");
        return;
    }
    if (w > n->max_weight)
        n->max_weight = w;
    n->position[n->c_size].x = x1;
    n->position[n->c_size].y = y1;
    n->position[n->c_size].weight = w;
    n->c_size++;
}

/* count distinct x values (points sharing an x form a horizontal line) */
int horizontal(struct ptr* n)
{
    int count = 0;
    int i, j;
    int* arr = (int*)calloc(n->c_size, sizeof(int));
    if (arr == NULL)
        return -1;
    for (i = 0; i < n->c_size - 1; i++) {
        for (j = i + 1; j < n->c_size; j++) {
            if (arr[i] == 0 && n->position[i].x == n->position[j].x) {
                count++;
                arr[j] = -1;
                arr[i] = count;
            }
        }
    }
    count = 0;
    for (i = 0; i < n->c_size; i++) {
        if (arr[i] > 0)
            count++;
    }
    free(arr);
    return count;
}

/* count distinct y values (points sharing a y form a vertical line) */
int vertical(struct ptr* n)
{
    int count = 0;
    int i, j;
    int* arr = (int*)calloc(n->c_size, sizeof(int));
    if (arr == NULL)
        return -1;
    for (i = 0; i < n->c_size - 1; i++) {
        for (j = i + 1; j < n->c_size; j++) {
            if (arr[i] == 0 && n->position[i].y == n->position[j].y) {
                count++;
                arr[j] = -1;
                arr[i] = count;
            }
        }
    }
    count = 0;
    for (i = 0; i < n->c_size; i++) {
        if (arr[i] > 0)
            count++;
    }
    free(arr);
    return count;
}

int main(void)
{
    struct ptr* n;
    int h = 0, v = 0;

    n = init(5);
    if (n == NULL)
        return 1;
    store(n, 1, 3, 123);
    store(n, 1, 4, 1231);
    store(n, 5, 0, 11);
    store(n, 0, 1, 122);
    store(n, 5, 1, 111);

    printf("Maximum weight : %f\n", n->max_weight);

    h = horizontal(n);
    v = vertical(n);

    printf("Horizontal : %d, Vertical : %d\n", h, v);

    free(n->position);
    free(n);
    return 0;
}
