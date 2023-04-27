#include<stdio.h>

int binarySearch(int a[],int n,int key,int low,int high){
    while(low<=high){
        int mid = (high+low)/2;
        if(a[mid] == key) return mid;
        else if(a[mid] > key){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);

    int a[n];
    printf("Enter the elements in sorted manner:\n");
    for(int i=0; i<n; i++){
        printf("Enter %d element:",i);
        scanf("%d",&a[i]);
    }

    int key;
    printf("Enter the element to be searched:");
    scanf("%d",&key);

    int low = 0; 
    int high = n-1;

    int index = binarySearch(a,n,key,low,high);

    if(index >= 0){
        printf("Element found at index %d\n",index);
    }else{
        printf("Element not found");
    }

}