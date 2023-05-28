#include <stdio.h>

int binary_search(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int nu;
    printf("Enter any number from the given array:\n");
    printf("{2, 5, 8, 12, 16, 23, 38, 56, 72, 91}\n");
    scanf("%d",&nu);
    int key = nu;
    int index = binary_search(arr, n, key);
    if (index == -1) {
        printf("%d not found in the array\n", key);
    } else {
        printf("%d found at index %d in the array\n", key, index);
    }
    return 0;
}
