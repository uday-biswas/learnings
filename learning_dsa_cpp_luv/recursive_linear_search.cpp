#include <bits/stdc++.h>
using namespace std;
int search(vector<int> arr, int i,int key){
    //base case
    if(i == arr.size()-1) return (arr[i] == key) ? i : -1;

    //head recursion is returning the last occurrence of the key
    int ans1 = search(arr, i+1, key);      //recurrence relation
    if(ans1 != -1) return ans1;
    
    int ans2 = (arr[i] == key) ? i : -1;   //processing
    if(ans2 != -1) return ans2;      

    //tail recursion is returning the first occurrence of the key
    // int ans2 = (arr[i] == key) ? i : -1;   //processing
    // if(ans2 != -1) return ans2;    

    // int ans1 = search(arr, i+1, key);      //recurrence relation
    // if(ans1 != -1) return ans1;

    return -1;
}
int main() {
vector<int> arr{3, 6, 45, 78, 34, 6,98};
int ans = search(arr,0,6);
cout<<ans;
return 0;
}