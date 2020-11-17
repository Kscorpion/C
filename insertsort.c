#include<stdio.h>

void swap(int *arr,int a,int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

/**
*1.在执行过程中插入排序会将序列分为两部分,头部已经排好序,尾部是待排序的
*2.从头开始扫描每一个元素,每当扫描到一个元素，就将它插入到合适的位置,使得头部依然有序
*简单来说就是选择下标为1的位置和下标为0的位置元素进行比较,如果当前位置小于前面的元素就一直进行交换
*通过使用cur标识来进行交换,保证不与begin++冲突，同时也要保证cur是大于0的防止越界.
*/
void insertsortbak(int *arr,int count){
	int begin,cur;
	for(begin=1;begin<count;begin++){
		cur = begin;
		while(cur>0 && arr[cur]<arr[cur-1]){
			swap(arr,cur,cur-1);
			cur--;	
		}
	}
}

/*
*优化思路：
*1.先将待插入的元素备份
*2.头部有序数据中比待插入元素大的，都朝尾部方向挪动1个位置
*3.将待插入的元素放入最终合适位置
*/
void insertsort(int *arr,int count){
	int begin,cur,bak;
	for(begin=1;begin<count;begin++){
		cur = begin;
		bak = arr[cur];
		while(cur>0 && bak<arr[cur-1]){
			swap(arr,cur,cur-1);
			cur--;	
		}
		arr[cur]=bak;
	}
}

void main(){
	int arr[] = {4532,32,5,2,54,435,55,6,345,4,45};
	int count = sizeof(arr)/sizeof(int);
	insertsort(arr,count);
	int n;
	for(n=0;n<count;n++){
		printf("%d\t",arr[n]);
	}
}
