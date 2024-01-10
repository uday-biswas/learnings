#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        int k ;
        map<int, int> mp;
        for ( int i=0; i<n; i++){
           k = X - A[i];
           mp.clear();
           for(int j=0; j<n; j++){
               if(i==j) continue;
               if(mp[A[j]] >= 1) return true; 
               mp[k - A[j]]++;
           }
        }
        return false;
    }
int main() {
int n=4,x=3;
int arr[] = {1,2,2,1};
bool t = find3Numbers(arr,n,x);
cout<<t;
return 0;
}