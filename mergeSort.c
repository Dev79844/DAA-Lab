#include<stdio.h>

void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }

    L[n1] = 100;
    R[n2] = 100;

    int i = 0, j = 0;

    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void sort(int arr[], int p, int r){
    if (p < r)
    {
        int q = (p + r) / 2;
        // printf("Q==%d\n", q);

        sort(arr, p, q);
        sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter %d element:",i);
        scanf("%d",&arr[i]);
    }

    sort(arr,0,n);

    printf("Sorted array\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    return 0;
}