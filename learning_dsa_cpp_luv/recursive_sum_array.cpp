#include <bits/stdc++.h>
using namespace std;
int sum(vector<int> arr,int i){
     //base case
     if(i == arr.size()-1) return arr[i];

     //recursive relation
     return arr[i] + sum(arr, i+1);
}
int main() {
vector<int> arr{3,4,98,23};
int ans = sum(arr,0);
cout<<ans<<endl;
return 0;
}