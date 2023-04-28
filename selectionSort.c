#include<stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(int a[], int n){
    int minIdx = 0;
    for(int i=0; i<n; i++){
        minIdx = i;
        for(int j=i+1; j<n; j++){
            if(a[minIdx] > a[j]){
                minIdx = j;
            }
            if(minIdx != i){
                swap(&a[minIdx], &a[i]);
            }
        }
        
    }
}

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);

    int a[n];
    for(int i=0; i<n; i++){
        printf("Enter %d element:",i);
        scanf("%d",&a[i]);
    }

    sort(a,n);

    printf("Sorted array\n");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n\n");
    return 0;
}