#include <bits/stdc++.h>
using namespace std;
int distinctElements(int N, int K, vector<int> A){
        // code here
        sort(A.begin(),A.end());
        map<int, int> mp;
        for(int i=0; i<N; i++){
            if(mp[A[i]] == 0) {
                if(mp[A[i]-K] == 0){
                    A[i] = A[i] - K;
                    mp[A[i]]++;
                }
                else mp[A[i]]++;
            }
            else{
                if(mp[A[i]-K] == 0) {
                    A[i] = A[i] - K;
                    mp[A[i]]++;
                }
                else if(mp[A[i]+K] == 0){
                    A[i] = A[i] + K;
                    mp[A[i]]++;
                }
            }
        }
        return mp.size();
    }
int main() {
vector<int> arr{1,2,2,2,3,4};
int ans = distinctElements(6,2,arr);
cout<<ans;
return 0;
}