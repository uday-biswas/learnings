#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> arr){
    //base condition
    if(arr.empty()){
        vector<vector<int>> emp2d;
        vector<int> emp;
        emp2d.push_back(emp);
        return emp2d;
    }

    int last = arr[arr.size()-1];
    arr.pop_back();
    vector<vector<int>> ans = subsets(arr);
    int size = ans.size();
    for(int i=0; i<size; i++){
        vector<int> temp = ans[i];
        temp.push_back(last);
        ans.push_back(temp);
    }
    return ans;
}
int main() {
vector<int> arr{1,2,3};
vector<vector<int>> ans1 = subsets(arr);
for(int i=0; i<ans1.size(); i++){
    for(int j=0; j<ans1[i].size(); j++){
        cout<<ans1[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}