#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }

    printf("Total number of duplicate elements: %d\n", count);
    return 0;
}
