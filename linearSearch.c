#include<stdio.h>

int linearSearch(int a[],int n,int key){
    for(int i=0; i<n; i++){
        if(a[i] == key) return i;
    }
    return -1;
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

    int key;
    printf("Enter the element to be searched:");
    scanf("%d",&key);

    int index = linearSearch(a,n,key);

    if(index >= 0){
        printf("Element is on index %d",index);
    }else{
        printf("Element not found!");
    }

    return 0;
}