#include<stdio.h>

int binarysearch(int *arr,int count,int tag){
	int l = 0;
	int r = count-1;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(arr[mid]== tag)return mid;
		if(tag<arr[mid])r = mid -1;
		else l = mid+1;
	}
	return -1;
}

void main(){
int arr[] = {1,2,3,4,5,6,7,8,9};
int count = sizeof(arr)/sizeof(int);
int res = binarysearch(arr,count,6);
printf("%d\n",res);
}

