// Online C compiler to run C program online
#include <stdio.h>
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int qsort(int *a,int max){
    int l,r,l_switch=0,r_switch=0,key=a[max-1],l_index=0,r_index=max-1;
    swap(&a[0],&a[max-1]);
    while(l_index<r_index){
        if(key<a[l_index]){
        l=a[l_index];
        l_switch=1;
        
        }
        else{
        ++l_index;
        printf("%d\n",l_index);
        }
        
        if(key>a[r_index]){
            r=a[r_index];
            r_switch=1;
        }
        else
        --r_index;
        
        if(l_switch==r_switch==1){
            swap(&a[l_index],&a[r_index]);
            l_switch=0;
            r_switch=0;
        }
    }
    return l_index;
}
//5,1,9,6,0,7
int main() {
    // Write C code here
    int a[]={7,1,9,6,0,5},max=sizeof(a)/sizeof(a[0]),index;
    index=qsort(a,max);
    printf("%d\n",index);
    return 0;
}