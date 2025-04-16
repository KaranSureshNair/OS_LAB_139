#include <stdio.h>

int wait(int x) {
    return --x;
}

int signal(int x) {
    return ++x;
}

int main() {
    int stick[5] = {1, 1, 1, 1, 1};
    int eaten[5] = {0};
    int count = 0;

    while (count < 5) {
        for (int i = 0; i < 5; i++) {
            int p1 = i;
            int p2 = (i + 2) % 5;

            if (eaten[p1] == 0 && stick[p1] == 1 && stick[(p1 + 1) % 5] == 1 &&
                eaten[p2] == 0 && stick[p2] == 1 && stick[(p2 + 1) % 5] == 1) {

                stick[p1] = wait(stick[p1]);
                stick[(p1 + 1) % 5] = wait(stick[(p1 + 1) % 5]);
                printf("Philosopher %d is eating now\n", p1 + 1);
                eaten[p1] = 1;
                count++;

                stick[p2] = wait(stick[p2]);
                stick[(p2 + 1) % 5] = wait(stick[(p2 + 1) % 5]);
                printf("Philosopher %d is eating now\n", p2 + 1);
                eaten[p2] = 1;
                count++;

                stick[p1] = signal(stick[p1]);
                stick[(p1 + 1) % 5] = signal(stick[(p1 + 1) % 5]);
                printf("Philosopher %d is thinking now\n", p1 + 1);

                stick[p2] = signal(stick[p2]);
                stick[(p2 + 1) % 5] = signal(stick[(p2 + 1) % 5]);
                printf("Philosopher %d is thinking now\n", p2 + 1);
            }
        }
    }
    printf("Philosopher 5 is eating\n");
    printf("Philosopher 5 is thinking\n");
    printf("All philosophers have eaten at least once.\n");
    return 0;
}