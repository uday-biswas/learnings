#include <bits/stdc++.h>
using namespace std;
 int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        map<int, int> mp;
            int count =0, k, knows = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(M[i][j] == 1) mp[j]++;
            }
        }
        if(mp.size() == 0) return -1;
            for(auto it : mp){
                if(it.second == n-1) {
                    count++;
                    k = it.first;
                }
            }
            for(int i=0; i<n; i++){
                if(M[k][i] ==1) knows = 1;
            }
            if(count != 1 || knows ==1) return -1;
            return k;
    }
int main() {
vector<vector<int>> M{{0,0,0},{0,0,0},{0,0,0}};
int n = 3;
int ans = celebrity(M, n);
cout << ans << endl;
return 0;
}