#include <bits/stdc++.h>
using namespace std;
pair<int, int> mountain_binary_search(int arr[], int n) {
int start=0, end=n-1;
while(start<=end) {
int mid= start+(end-start)/2;
if(mid==0 || mid==n-1) return {arr[mid], mid};
else if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]) {
    return {arr[mid], mid}; }
else if(arr[mid]>arr[mid+1] && arr[mid]<arr[mid-1]) {
    end=mid-1; }
else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1]) {
    start = mid+1; }
else {
    return {-1, -1}; }

}
return {-1, -1};

}
int main() {
int odd[7]= {1,2,4,5,6,3,1};
int even[6]= {1,2,6,5,4,3};
int arr[6] = {1,2,3,4,5,6};
pair<int, int> p= mountain_binary_search(arr, 6);
cout<<p.first<<" "<<p.second<<endl;
return 0;
}