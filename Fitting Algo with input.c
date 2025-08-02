#include <stdio.h>

void firstFit(int holes[], int n, int processSize) {
    for (int i = 0; i < n; i++) {
        if (holes[i] >= processSize) {
            printf("First Fit: Process of %dk allocated to hole %d (%dk)\n", processSize, i + 1, holes[i]);
            return;
        }
    }
    printf("First Fit: No suitable hole found.\n");
}

void bestFit(int holes[], int n, int processSize) {
    int bestIndex = -1;
    for (int i = 0; i < n; i++) {
        if (holes[i] >= processSize) {
            if (bestIndex == -1 || holes[i] < holes[bestIndex])
                bestIndex = i;
        }
    }
    if (bestIndex != -1)
        printf("Best Fit: Process of %dk allocated to hole %d (%dk)\n", processSize, bestIndex + 1, holes[bestIndex]);
    else
        printf("Best Fit: No suitable hole found.\n");
}

void worstFit(int holes[], int n, int processSize) {
    int worstIndex = -1;
    for (int i = 0; i < n; i++) {
        if (holes[i] >= processSize) {
            if (worstIndex == -1 || holes[i] > holes[worstIndex])
                worstIndex = i;
        }
    }
    if (worstIndex != -1)
        printf("Worst Fit: Process of %dk allocated to hole %d (%dk)\n", processSize, worstIndex + 1, holes[worstIndex]);
    else
        printf("Worst Fit: No suitable hole found.\n");
}

int main() {
    int n, processSize;

    printf("Enter number of memory holes: ");
    scanf("%d", &n);

    int holes[n];
    printf("Enter the size of each hole:\n");
    for (int i = 0; i < n; i++) {
        printf("Hole %d size (in k): ", i + 1);
        scanf("%d", &holes[i]);
    }

    printf("Enter process size to allocate (in k): ");
    scanf("%d", &processSize);

    printf("\n");
    firstFit(holes, n, processSize);
    bestFit(holes, n, processSize);
    worstFit(holes, n, processSize);

    return 0;
}
