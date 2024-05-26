#include <bits/stdc++.h>
using namespace std;
#define auto vector<int>::iterator

vector<int> merge_two(auto it1s, auto it1e, auto it2s, auto it2e){
    vector<int> arr;
    int ans;
     while(it1s != it1e && it2s != it2e){
        if(*it1s < *it2s) {
            ans = *it1s;
            it1s++;
        }
        else {
            ans = *it2s;
            it2s++;
        }
        arr.push_back(ans);
     }
     while(it1s != it1e){
        arr.push_back(*it1s);
        it1s++;
     }
     while(it2s != it2e){
        arr.push_back(*it2s);
        it2s++;
     }
     return arr;
}

void merge_sort(vector<int> &arr, int s, int e){
    //base condition
    if(s == e) return;

    //processing and recurrence relation
    int mid = s + (e-s)/2;
    merge_sort(arr, s, mid);          //sorted first half
    merge_sort(arr, mid+1, e);        //sorted second half
    arr = merge_two(arr.begin(),arr.begin()+mid+1, arr.begin()+mid+1, arr.end());    //merged both the sorted halves
}
int main() {
vector<int> arr{3, 56, 2 , 12 , 45, 4, 67};
merge_sort(arr, 0 , arr.size()-1);
for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<" ";
}
return 0;
}