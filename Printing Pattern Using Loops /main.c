//
// Created by Amirhossein on 7/22/25.
//
#include <stdio.h>

int min(int arr[], int size);

int main() {
    int n;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    const int side_width = (n * 2) - 1;
    for (int i = 0; i < side_width; i++) {
        // height loop
        for (int j = 0; j < side_width; j++) {
            // width loop
            const int arr[4] = {i, j, side_width - 1 - i, side_width - 1 - j};
            const int layer = min(arr, 4);
            const int value = n - layer;
            printf("%d ", value);
        }
        printf("\n");
    }
    return 0;
}


int min(int arr[], const int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
