#include <vector>
#include <iostream>
void swap(int* a, int* b){
    if(a!=nullptr & b!=nullptr & a!=b){
        int p = *a;
        *a=*b;
        *b=p;
    }
}
void sort(std::vector<int>& arr){
    for ( int i=0; i+1<arr.size(); i++){
        for (int j=i+1; j<arr.size(); j++){
            if (arr[i]>arr[j]){
                // std::swap(arr[i],arr[j]);
                swap(&arr[i],&arr[j]);
        }
    }
    
}
}
void bubblesort(std::vector<int>& arr){
    for (int i = 0; i < arr.size() - 1; i++) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
            swap(&arr[j], &arr[j + 1]);
        }
    }
}
}
