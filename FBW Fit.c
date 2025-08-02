#include <stdio.h>

void allocate(char *name, int holes[], int n, int size, int type) {
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (holes[i] >= size) {
            if (type == 0 && index == -1) index = i; // First Fit
            if (type == 1 && (index == -1 || holes[i] < holes[index])) index = i; // Best Fit
            if (type == 2 && (index == -1 || holes[i] > holes[index])) index = i; // Worst Fit
        }
    }

    printf("%s: ", name);
    if (index != -1) {
        printf("Allocated at Hole %d (%dk)\n", index+1, holes[index]);
        holes[index] -= size;
    } else {
        printf("No suitable hole found\n");
    }
}

int main() {
    int holes[] = {30, 50, 65, 40, 15, 45, 70, 60};
    int n = sizeof(holes)/sizeof(holes[0]);
    int size = 38;

    int first[n], best[n], worst[n];
    for (int i = 0; i < n; i++) {
        first[i] = best[i] = worst[i] = holes[i];
    }

    allocate("First Fit", first, n, size, 0);
    allocate("Best Fit", best, n, size, 1);
    allocate("Worst Fit", worst, n, size, 2);
    return 0;
}

