#include <iostream>

void printArray(int arr[],int n) {
    for (int i = 0 ; i < n ; i++) {
        std::cout << arr[i] << " " ;
    }
    std::cout << "\n" ;
}

void bubbleSort(int arr[],int n) {
    printArray(arr,n) ;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j],arr[j+1]) ;
                printArray(arr,n) ;
            }
        }
    }
}

void selectionSort(int arr[],int n) {
    printArray(arr,n) ;
    for (int k = n-1 ; k > -1 ; k--) {
        int maxIdx = 0 ;
        int maxValue = arr[0] ;
        for (int i = 0 ; i < k+1 ; i++) {
            if (arr[i] > maxValue) {
                maxValue = arr[i] ;
                maxIdx = i ;
            }
        }
        std::swap(arr[maxIdx],arr[k]) ;
        printArray(arr,n) ;
    }
}

void insertionSort(int arr[] , int n) {
    for (int k = n-2 ; k >= 0 ; k--) {
        for (int j = k ; j < n-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j],arr[j+1]) ;
                printArray(arr,n) ;
            } else {
                break ;
            }
        }
    }
}

int main() {
    int arr[] = {5,1,4,28,10,1,0} ;
    int n = sizeof(arr)/sizeof(int) ;
    printArray(arr,n) ;
    insertionSort(arr,n) ;
}


