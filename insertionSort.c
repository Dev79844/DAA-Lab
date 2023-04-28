#include<stdio.h>

void sort(int a[],int n){
    for(int i=1; i<n; i++){
        int min = a[i];
        int j = i-1;

        while(j>=0 && a[j] > min){
            a[j+1] = a[j];
            j -= 1;
        }
        a[j+1] = min;
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