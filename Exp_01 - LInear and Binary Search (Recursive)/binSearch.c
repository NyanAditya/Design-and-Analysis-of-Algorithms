#include <stdio.h>

int binarySearch(int arr[], int left, int right, int x)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        return binarySearch(arr, mid + 1, right, x);
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40, 50, 70, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    return 0;
}