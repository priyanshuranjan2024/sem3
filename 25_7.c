#include<stdio.h>


// write a program to create n number of array and find the following operations
// 1.reverse the array
// 2.find the duplicate element and its frequency
// 3.replace the array using another array



void reverse(int arr[], int start, int end){
    
    if(start >= end){
        return;
    }
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse(arr, start+1, end-1);

}



void replace(int arr1[], int n, int i, int arr2[], int j){
    if(i == n){
        return;
    }
    arr1[i] = arr2[j];
    replace(arr1, n, i+1, arr2, j+1);
}


void countFrequency(int arr[], int freq[], int index, int n) {
    if (index == n) {
        return;
    }
    freq[arr[index]]++;
    countFrequency(arr, freq, index + 1, n);
}

void printDuplicates(int arr[], int freq[], int index, int n) {
    if (index == n) {
        return;
    }
    if (freq[arr[index]] > 1) {
        printf("%d occurs %d times\n", arr[index], freq[arr[index]]);
        freq[arr[index]] = 0;  
    }
    printDuplicates(arr, freq, index + 1, n);
}



int main(){

    //array 1
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    reverse(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    int freq[100] = {0}; 

    countFrequency(arr, freq, 0, n);

    printDuplicates(arr, freq, 0, n);



    
    int arr2[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &arr2[i]);
    }

    replace(arr, n, 0, arr2, 0);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }


    return 0;


}
