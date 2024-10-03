// to sort the arr using insertion sort in ascending and descending order

#include<stdio.h>

void insertionSortAscending(int arr[],int n){

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

void insertionSortDescending(int arr[],int n){

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]<key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSortAscending(arr, n);
    printArray(arr,n);

    //sort in descending order
    insertionSortDescending(arr,n);
    printArray(arr,n);

    return 0;


}