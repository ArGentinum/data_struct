// Online C compiler to run C program online
#include <stdio.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void revarr(int *ptr,int max){
    int start=0,end=max-1,temp;
    while(start<end){
        swap(&ptr[start],&ptr[end]);
        ++start;
        --end;
    }
}

int main() {
    // Write C code here
    int a[]={2,4,9,3,0,1},size=sizeof(a)/sizeof(a[0]),i;
    printf("original array")
    revarr(a,size);
    for(i=0;i<size;++i){
        printf("%d",a[i]);
        if(i<size-1)
        printf(",");
    }
    

    return 0;
}