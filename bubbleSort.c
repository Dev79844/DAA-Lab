#include<stdio.h>

void sort(int arr[], int n){
    for(int i = 0;i<n;i++)
	{
		int swap = 0;
		for(int j = 0;j<n-1;j++)
		{
			
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;	
				swap++;
				
				
			}
		
		}
		if(swap==0) break;
		
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

    sort(arr,n);

    printf("Sorted array\n");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
    return 0;
}