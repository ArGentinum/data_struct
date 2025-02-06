#include <stdio.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int qsort(int *a,int max){
    int l,r,key=a[0],l_index=0,r_index=max-2;
    swap(&a[0],&a[max-1]);
    while(l_index<=r_index){
        while(key>a[l_index]){
            l_index++;
            printf("left index:%d\n",l_index);
        }

        while(key<a[r_index]&&r_index>=0){
            r_index--;
            printf("right index:%d\n",r_index);
        }
        if(l_index<=r_index)
        swap(&a[l_index],&a[r_index]);
        //l_index=0;
        //r_index=max-2;
        else
        return l_index;
    }
    return l_index;
}
int main() {
    // Write C code here
    int a[]={0,9,7,1,6,-1,2},max=sizeof(a)/sizeof(a[0]),index;
    index=qsort(a,max);
    printf("%d\n",index);
    return 0;
}