#include <stdio.h>

int linearSearch(int arr[], int size, int key, int index) {
    if (index >= size)
        return -1;
    
    if (arr[index] == key)
        return index;
    
    return linearSearch(arr, size, key, index + 1);
}

int main() {
    int n, key, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    result = linearSearch(arr, n, key, 0);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}