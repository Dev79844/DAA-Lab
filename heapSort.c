#include<stdio.h>
#define N 10
int arr[N];
void max_heap(int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest;
	if(l<N && arr[l]>arr[i])
	largest = l;
	else 
	largest =i;
	if(r<N && arr[r]>arr[largest])
	largest = r;
	
	if(largest!=i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heap(largest);
	}


}
int main()
{	
	for(int i =0;i<N;i++)
	{
		printf("Enter the number: ");
		scanf("%d",&arr[i]);
	}
	for(int i =N/2-1;i>=0;i--)
	{
		max_heap(i);
	
	}
	for(int i =0;i<N;i++)
	{
		printf("%d ",arr[i]);
	
	}



	return 0;
}
