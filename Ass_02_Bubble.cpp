
#include <iostream>
#include <stdlib.h>
#include <omp.h>

using namespace std;

void bubble(int arr[], int n){
    int i, j;
    #pragma opm parallel for shared(i, j)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int *arr, n;
    cout<<"Enter the number of elements :  "<<endl;
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements : ";
    for(int i = 0; i<n; i++){
        cin>> arr[i];
    }

    bubble(arr, n);
    
    cout<<"Sorted Array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i] <<endl;
    }
}