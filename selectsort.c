#include<stdio.h>

void selectsort(int *arr,int count){ //这里第一个参数是通过指针传递的,count一定要从外部传进来,否则计算的应该是指针的count
	int end ;
	int begin ;
	for(end=count-1;end>0;end--){
		int maxIndex = 0;
		for(begin = 0;begin<=end;begin++){
			if(arr[maxIndex]<=arr[begin]){
				maxIndex = begin;
			}
		}
		int temp = arr[maxIndex];
		arr[maxIndex] = arr[end];
		arr[end] = temp;
	}
}

void main(){
	int arr[] = {5,3,65,423,7,34,56,5,899,5};
	int n;
	int count = sizeof(arr)/sizeof(int);
	selectsort(arr,count);
	for(n=0;n<count;n++){
		printf("%d\n",arr[n]);
	}
}
