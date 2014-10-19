#include <stdio.h>
#define MAX 1000

int sum (int arr[], int n ){
	int sum = 0;
	int i;
for (i =0 ; i < n; i++ )
	sum += arr[i];
	
	return sum;

}


int main(){
	int arr[MAX];
	int n,i;
	printf("enter the array's size");
	scanf("%d",&n);
	printf("enter the array's element");
 	for (i=0; i<n ;i++){
	scanf("%d",&arr[i]);
	}
	printf("the Sum is:%d\n",sum(arr,n));
}	
