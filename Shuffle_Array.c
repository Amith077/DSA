#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int arr[], int n) {
    srand(time(NULL)); // seed the random number generator
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1); // generate a random index
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    shuffle(arr, n);
    printf("The shuffled array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
