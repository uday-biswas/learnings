#include <bits/stdc++.h>
using namespace std;
long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(), a.end());
        long long p, min=INT_MAX;
        for(int i=0; i+m-1<n; i++){
            p = a[i+m-1] - a[i];
            if(p < min) min = p;
        }
        return min;
    }  
int main() {
int n=8,m=5;
vector<long long> arr{3, 4 ,1 ,9 ,56 ,7 ,9 ,12};
long long ans = findMinDiff(arr, n, m);
cout<<ans;
return 0;
}