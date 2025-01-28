#include <stdio.h>

void swap(int *a, int *b){
 int tmp=*a;
 *a=*b;
 *b=tmp;
}

void QSORT(int *nums, int left, int right){  
    if(left>=right) return;
    
    int l=left+1;
    int r=right;
    int key=nums[left];
    
    while(1){
        while(l<=right){
            if(nums[l]>key) break;
            l++;
        }
        while(r>left){
            if(nums[r]<key) break;
            r--;
        }
        if(l>r) break;
        swap(&nums[l],&nums[r]); 
    }
    
    swap(&nums[left],&nums[r]);
    
    QSORT(nums,left,r-1);
    QSORT(nums,r+1,right);
}

int main(void){
    
    int array[10];
    int len = sizeof(array) / sizeof(int);
    
    for(int i = 0; i < len; i++){
        scanf("%d",&array[i]);
    }
    
    QSORT(array,0,9);

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
}