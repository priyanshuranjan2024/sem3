//selection sort

#include<stdio.h>

void selectionSortAscending(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++) if(arr[j]<arr[min_idx]) min_idx=j;
        int temp=arr[min_idx];
        arr[min_idx]=arr[i];
        arr[i]=temp;
    }
}

void selectionSortDescending(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int max_idx=i;
        for(int j=i+1;j<n;j++) if(arr[j]>arr[max_idx]) max_idx=j;
        int temp=arr[max_idx];
        arr[max_idx]=arr[i];
        arr[i]=temp;
    }
}

int printArray(int arr[],int n){
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
}


int main(){
    int arr[]={22,55,33,88,44};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original Array\n");
    printArray(arr,n);

    // Sort in ascending order
    selectionSortAscending(arr, n);
    printArray(arr,n);

    //sort in descending order
    selectionSortDescending(arr,n);
    printArray(arr,n);

    return 0;


}