// Online C compiler to run C program online
#include <stdio.h>
int linsearch(int *a,int max,int key){
    int i;
    for(i=0;i<max;++i){
        if(a[i]==key)
        return i;
    }
    return -1;
    
}

int main() {
int a[]={1,7,8,-9,9,6,10},size=sizeof(
    a)/sizeof(a[0]),key,i,index;
printf("array: ");
for(i=0;i<size;++i){
    printf("%d",a[i]);
    if(i<size-1)
        printf(",");
    }
printf("\nenter the element that is to be searched in the array:");
scanf("%d",&key);

index=linsearch(a,size,key);
if(index>=0)
printf("\nelement found at index:%d",index);
else
printf("\nelement not found");
    return 0;
}