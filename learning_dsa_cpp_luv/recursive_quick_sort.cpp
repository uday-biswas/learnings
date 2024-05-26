#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int s, int e){
     int pivot = arr[s], count=0;
     for(int i=s+1; i<=e; i++){
         if(arr[i] < pivot) count++;
     }
     swap(arr[s], arr[s+count]);
     int i=s, j=e;
     while(i<j){
        if(arr[i] >= pivot && arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        if(arr[i] < pivot) i++;
        if(arr[j] >= pivot) j--;
     }
     return (s+count);
}

void quick_sort(vector<int> &arr, int s, int e){
    //base condition
    if(s >= e) return;

    //processing and recurrence relation 
    int p = partition(arr, s,e);
    quick_sort(arr, s, p-1);
    quick_sort(arr, p+1, e);
}
int main() {
vector<int> arr{87, 56, 2 , 12 , 45, 4, 67, 2, 2};
quick_sort(arr, 0 , arr.size()-1);
for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
}
return 0;
}