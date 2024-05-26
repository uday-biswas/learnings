#include <bits/stdc++.h>
using namespace std;
void bubble_sort(vector<int> &arr, int n){
    //base condition
    if(n == 0 || n == 1) return;

    //processing
    bool swapped = false;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            swapped = true;
        }
    }
    if(swapped == false) return;

    //recurrence relation
    bubble_sort(arr, n-1);
}
int main() {
vector<int> arr{3, 56, 2 , 12 , 45};
bubble_sort(arr,arr.size());
for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
}
return 0;
}