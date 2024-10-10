// quick sort
#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int arr[], int m, int p) {
    int i = m + 1; 
    int j = p;
    
    do {
        while (i <= p && arr[i] < arr[m]) { i++; }
        while (j > m && arr[j] > arr[m]) {  j--; }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    
    swap(arr[m], arr[j]);
    return j;
}


void QuickSort(int arr[], int low, int high) {
    if(low < high) {
        
        int j_ki_value = Partition(arr, low, high);
        
        // sorting the left (small elements) side
        QuickSort(arr, low, j_ki_value - 1);
        
        // sorting the right (large elements) side
        QuickSort(arr, j_ki_value + 1, high);
    }
}

int main() {
    int arr[] = {7, 2, 3, 4, 6, 1, 12, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    QuickSort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;    
}