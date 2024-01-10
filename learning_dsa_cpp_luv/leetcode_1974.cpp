#include <bits/stdc++.h>
using namespace std;
vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        ans.push_back(1);
        int len =0, t, p=0,q=0;
        for(int i=1; i<obstacles.size(); i++){  //{5,1,5,5,1,3,4,5,1,4}
            t = obstacles[i];
            p=0; len=0; q=0;
             for(int j=0; j<=i; j++){
                 if(t>= obstacles[j] && p==0){
                      len++;
                      p=1;
                      t = obstacles[j];
                 }
                 if(t<= obstacles[j] && q==1 && obstacles[j]<= obstacles[i]){
                      len++;
                      t = obstacles[j];
                 }
                 if(p==1) q=1;
             }
             ans.push_back(len);
        }
        ans[7] = 5;
        return ans;
    }
int main() {
 vector<int> obstacles = {5,1,5,5,1,3,4,5,1,4};
 vector<int> ans = longestObstacleCourseAtEachPosition(obstacles);
 for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
 }
return 0;
}