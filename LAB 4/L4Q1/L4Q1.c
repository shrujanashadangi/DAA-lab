// Q1: given n (number, colour) pairs sorted by number, group them by
// colour (red, blue, yellow) while keeping numbers sorted within a colour.
// Idea: 3 buckets, one pass to fill them, then join red+blue+yellow. O(n).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    char colour[10];
} Item;

int isValidColour(char *c) {
    return strcmp(c, "red") == 0 || strcmp(c, "blue") == 0 || strcmp(c, "yellow") == 0;
}

int main(void) {
    int n;
    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input: n must be a positive integer.\n");
        return 1;
    }

    Item *items = malloc(n * sizeof(Item));
    printf("Enter %d items as: number colour(red/blue/yellow), sorted by number\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d %9s", &items[i].num, items[i].colour) != 2 || !isValidColour(items[i].colour)) {
            printf("Invalid input: colour must be red, blue or yellow.\n");
            free(items);
            return 1;
        }
    }
    for (int i = 1; i < n; i++) {
        if (items[i].num < items[i - 1].num) {
            printf("Invalid input: numbers must be entered in sorted order.\n");
            free(items);
            return 1;
        }
    }

    Item *red = malloc(n * sizeof(Item));
    Item *blue = malloc(n * sizeof(Item));
    Item *yellow = malloc(n * sizeof(Item));
    int rc = 0, bc = 0, yc = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(items[i].colour, "red") == 0)
            red[rc++] = items[i];
        else if (strcmp(items[i].colour, "blue") == 0)
            blue[bc++] = items[i];
        else
            yellow[yc++] = items[i];
    }

    printf("\nGrouped by colour:\n");
    for (int i = 0; i < rc; i++) printf("(%d, red)\n", red[i].num);
    for (int i = 0; i < bc; i++) printf("(%d, blue)\n", blue[i].num);
    for (int i = 0; i < yc; i++) printf("(%d, yellow)\n", yellow[i].num);

    free(items); free(red); free(blue); free(yellow);
    return 0;
}
