#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n){
        
        // Your code here
        vector<int> sum;
        int s=0;
        
        for(int i=0; i<n; i++){
            s=0;
          for(int j=i; j<n; j++){
              s = s + arr[j];
              sum.push_back(s);
          }
        }
        int max = sum[0];
        for (int i=1; i<sum.size(); i++){
            if(sum[i] > max) max = sum[i];
        }
        return max;
    }
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
vector<long long> sum;
        long long s;
        
        for(int i=0; i<n; i++){
            s=0;
          for(int j=i; j<n; j++){
              s = s + arr[j];
              sum.push_back(s);
          }
        }
        long long max = sum[0];
        for (int i=1; i<sum.size(); i++){
            if(sum[i] > max) max = sum[i];
        }
cout<<max;
return 0;
}