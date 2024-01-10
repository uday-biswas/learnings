#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        int k=0;
        vector<int> ans;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                ans.push_back(Mat[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                Mat[i][j] = ans[k];
                k++;
            }
        }
        return Mat;
    }
int main() {
vector<vector<int>> mat{{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
int n=4;
vector<vector<int>> ans = sortedMatrix(n,mat);
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}

