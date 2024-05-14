#include <bits/stdc++.h>
using namespace std;
long long trappingWater(int arr[], int n){
        // code here
        long long ans=0,i=0;
        vector<int> left, right;
            left.push_back(arr[0]);
            right.push_back(arr[n-1]);
            for(int j=1; j<n; j++){
                left.push_back(max(arr[j-1], left[j-1]));
            }
            for(int k=n-2; k>0; k--){
                right.push_back(max(arr[k+1], right[i]));
                i++;
            }
            right.push_back(0);
            reverse(right.begin(), right.end());
            for(int m=1; m<n-1; m++){
                int val = min(left[m], right[m]);
                if(val - arr[m] <=0) ans += 0;
                else ans += val - arr[m];
            }
        return ans;
    }
int main() {
int n = 4;
int arr[] = { 7,4,0,9};
long long ans = trappingWater(arr, n);
cout<<ans;
return 0;
}