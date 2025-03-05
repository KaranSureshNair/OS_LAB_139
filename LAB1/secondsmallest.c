#include <stdio.h>

int main() {
    int n, i, first, second;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    first = second = 1000;

    for (i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == 1000) {
        printf("There is no second smallest element.\n");
    } else {
        printf("The second smallest element is: %d\n", second);
    }

    return 0;
}
