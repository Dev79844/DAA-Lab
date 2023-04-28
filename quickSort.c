#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int par(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i = i + 1;

            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

void sort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = par(arr, p, r);
        sort(arr, p, q - 1);
        sort(arr, q + 1, r);
    }
}

int main()
{
    int size;
    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &size);

    int nums[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter The Number: ");
        scanf("%d", &nums[i]);
    }

    sort(&nums[0], 0, size);

    printf("Sorted Array:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
        
    }
    return 0;
}


