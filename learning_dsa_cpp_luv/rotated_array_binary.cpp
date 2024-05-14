#include <bits/stdc++.h>
using namespace std;
int rotated_array_pivot(int arr[] , int n){
    int s =0, e=n-1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]> arr[0] && arr[mid] > arr[n-1]){
            s = mid +1;
        }
        else if(arr[mid] < arr[0] && arr[mid] < arr[n-1]){
            if(arr[mid] > arr[mid-1]){
                e = mid -1 ;
            }
            else return mid;
        }
    }
    return -1;
}
int rotated_array_binary_search(int arr[] , int n, int pivot, int key){
    int s=0, e=n-1;
    if(key > arr[pivot] && key < arr[n-1]){
        s=pivot;
    }
    else if(key > arr[0] && key < arr[pivot-1]) e = pivot -1;
    else return -1;
    while(s<=e){
        int mid = s + (e-s)/2;
       if(arr[mid]==key) return mid;
       else if(arr[mid] < key) s = mid +1;
       else e = mid -1;
    }
    return -1;
}
int main() {
int arr[] = {6, 7, 8, 10, 1, 2, 4, 5};
int r = rotated_array_pivot(arr, 8);
cout<<"the index of the pivot element is : "<< r<<endl;
int t = rotated_array_binary_search(arr, 8, r, 2);
cout<<"the index of the key element is : "<<t;
return 0;
}