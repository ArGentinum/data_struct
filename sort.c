#include <stdio.h>

// Bubble Sort
void bsort(int *ptr, int max) {
    int i, j, k;
    for (i = 0; i < max - 1; ++i) { // Loop through all elements
        for (j = 0; j < max - i - 1; ++j) { // Traverse unsorted part
            if (ptr[j] > ptr[j + 1]) {
                k = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = k;
            }
        }
    }
}

// Selection Sort
void ssort(int *a, int max) {
    int i, j, temp, swap;
    for (i = 0; i < max - 1; ++i) {
        temp = i; // Index of the smallest element
        for (j = i + 1; j < max; ++j) {
            if (a[temp] > a[j])
                temp = j;
        }
        if (temp != i) { // Swap if needed
            swap = a[i];
            a[i] = a[temp];
            a[temp] = swap;
        }
    }
}

// Insertion Sort
void insort(int *a, int max) {
    int i, j, temp;
    for (i = 1; i < max; ++i) { // Start from the second element
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp) { // Shift elements to the right
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp; // Insert element at correct position
    }
}

// Print Array
void print(int *p, int max) {
    int i;
    for (i = 0; i < max; ++i) {
        printf("%d", p[i]);
        if (i < max - 1) // Avoid trailing comma
            printf(",");
    }
    printf("\n");
}




int binsearch(int a[],int max,int key){
    int left,right,mid;
    left=0;
    right=max-1;

    while(left<=right){
        mid=(left+right)/2;
        if(a[mid]==key)
        return mid;
    else if(a[mid]<key){
        ++mid;
        left=mid;
    }
    else{
        --mid;
        right=mid;
    }
    }
    return -1;
} 

int main() {
    int a[40], max, i,element,index;
    printf("Enter the max array size: ");
    scanf("%d", &max);

    if (max > 40 || max <= 0) { // Validate array size
        printf("Invalid size! Must be between 1 and 40.\n");
        return 1;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < max; ++i) {
        scanf("%d", &a[i]);
    }

    // Uncomment the desired sorting algorithm
    // bsort(a, max);
    // ssort(a, max);
    insort(a, max);

    printf("Sorted array: ");
    print(a, max);
    printf("enter the element to be searched in the sorted array:");
    scanf("%d",&element);

    index=binsearch(a,max,element);
    if(index<0)
    printf("element not found");
else
printf("element found at index %d",index);
    return 0;
}
