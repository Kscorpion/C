#include<stdio.h>

void merge(int *arr,int L,int M,int R){
	int LEFT_SIZE = M-L;
	int RIGHT_SIZE = R-M+1;
	int left[LEFT_SIZE];
	int right[RIGHT_SIZE];
	int i,j,k;
	for(i=L;i<M;i++)
		left[i-L] = arr[i];
	for(i=M;i<=R;i++)
		right[i-M] = arr[i];
	i=0;j=0;k=L;
	while(i<LEFT_SIZE && j<RIGHT_SIZE){
		if(left[i]<right[j]){
			arr[k++] = left[i++];
		}else{
			arr[k++] = right[j++];
		}	
	}
	while(i<LEFT_SIZE){
		arr[k++] = left[i++];
	}
	while(j<RIGHT_SIZE){
		arr[k++] = right[j++];
	}
}

void mergeSort(int *arr,int L,int R){
	if(L==R)return;
	int M = L+((R-L)>>1);
	mergeSort(arr,L,M);
	mergeSort(arr,M+1,R);
	merge(arr,L,M+1,R);
}

void main(){
	int arr[] = {1,3,2,4,5,7,6,9,8};
	int L = 0;
	int R = sizeof(arr)/sizeof(int);
	mergeSort(arr,L,R);
	int n;
	for(n=0;n<R;n++){
		printf("%d\t",arr[n]);
	}
	printf("\n");
}
