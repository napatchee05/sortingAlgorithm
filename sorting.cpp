#include <iostream>
#include <queue>


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

bool isSorted(int arr[],int n) {
    for (int i = 0 ; i < n-1 ; i++) {
        if (arr[i] > arr[i+1]) {
            return false ;
        }
    }
    return true ;
}

int power(int base,int power) {
    int result = 1 ;
    for (int i = 0 ; i < power ; i++) {
        result *= base ;
    }
    return result ;
}

int getDigitFL(int n , int digit) {
    return (n/power(10,digit))%10 ;
}

int lengthOfInt(int n) {
    int length = 0 ;
    while (n) {
        length += 1 ;
        n /= 10 ;
    }
    return length ;
}

void radixSort(int arr[],int n) {
    std::queue<int> qs[10] ;
    int maxLength = lengthOfInt(arr[0]) ;
    for (int i = 1 ; i < n ; i++) {
        maxLength = lengthOfInt(arr[i]) > maxLength ? lengthOfInt(arr[i]) : maxLength ;
    }
    for (int i = 0 ; i < maxLength ; i++) {
        int e = 0 ;
        for (int j = 0 ; j < n ; j++) {
            qs[getDigitFL(arr[j],i)].push(arr[j]) ;
        }
        for (int k = 0 ; k < 10 ; k++) {
            while(!qs[k].empty()) {
                arr[e++] = qs[k].front() ;
                qs[k].pop() ;
            }
        }
        printArray(arr,n) ;
    }
}

int main() {
    int arr[] = {5,1,4,28,10,1,0} ;
    int n = sizeof(arr)/sizeof(int) ;
    printArray(arr,n) ;
    radixSort(arr,n) ;
    std::cout << getDigitFL(28,1) ;
}


