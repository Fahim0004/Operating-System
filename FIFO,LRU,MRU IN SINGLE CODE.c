#include <stdio.h>

#define SIZE 4
int ref[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3,3,0};
int n = sizeof(ref)/sizeof(ref[0]);

int isIn(int frames[], int x) {
    for (int i = 0; i < SIZE; i++)
        if (frames[i] == x) return 1;
    return 0;
}

int FIFO() {
    int frames[SIZE], front = 0, faults = 0;
    for (int i = 0; i < SIZE; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        if (!isIn(frames, ref[i])) {
            frames[front] = ref[i];
            front = (front + 1) % SIZE;
            faults++;
        }
    }
    return faults;
}

int LRU() {
    int frames[SIZE], time[SIZE], faults = 0;
    for (int i = 0; i < SIZE; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < SIZE; j++) {
            if (frames[j] == ref[i]) {
                time[j] = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            int lru = 0;
            for (int j = 1; j < SIZE; j++)
                if (time[j] < time[lru]) lru = j;
            frames[lru] = ref[i];
            time[lru] = i;
            faults++;
        }
    }
    return faults;
}

int MRU() {
    int frames[SIZE], time[SIZE], faults = 0;
    for (int i = 0; i < SIZE; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < SIZE; j++) {
            if (frames[j] == ref[i]) {
                time[j] = i;
                found = 1;
                break;
            }
        }
        if (!found) {
            int mru = 0;
            for (int j = 1; j < SIZE; j++)
                if (time[j] > time[mru]) mru = j;
            frames[mru] = ref[i];
            time[mru] = i;
            faults++;
        }
    }
    return faults;
}

int main() {
    printf("FIFO: %d\n", FIFO());
    printf("LRU : %d\n", LRU());
    printf("MRU : %d\n", MRU());
    return 0;
}
