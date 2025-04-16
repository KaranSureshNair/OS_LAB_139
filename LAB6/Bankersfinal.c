#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int i,j,k, avail[10][10], safe[10], alloc[10][10], max[10][10], need[10][10], finish[10], n, m, count = 0, found;

void main(){
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[0][i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        finish[i] = 0;
        safe[i] = -1;
    }

    while (count < n) {
        found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[0][j]) {
                        break;
                    }
                }
                if (j == m) { 
                    for (k = 0; k < m; k++) {
                        avail[0][k] += alloc[i][k]; 
                    }
                    finish[i] = 1;
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is in a deadlock state.\n");
            return;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (i = 0; i < n ; i++){
        printf("%d ",safe[i]);
    }
    printf("\n");   
}
