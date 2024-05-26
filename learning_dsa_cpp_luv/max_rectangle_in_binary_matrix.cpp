#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(int heights[], int n){
        stack<int> s;
        s.push(n);
        vector<int> ans(n);
       for(int i= n-1; i>=0; i--){
        while( s.top() != n && heights[s.top()] >= heights[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
       }
       return ans;
    }

    vector<int> prevSmallerElement(int heights[], int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
       for(int i= 0; i<n; i++){
        while( s.top() != -1 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
       }
       return ans;
    }


    vector<int> largestRectangleArea(int heights[], int m) {
        vector<int> left;
        vector<int> right;
        int start=0, end=0;
        vector<int> ans;
        left = prevSmallerElement(heights, m);
        right = nextSmallerElement(heights, m);
        int max_area = 0, area;
        int width , height;
        for(int i=0; i<m; i++){
            width = right[i] - left[i] - 1;
            height = heights[i];
            area = width * height;
            if(area > max_area){
                max_area = area;
                start = left[i] +1;
                end = right[i] -1;
            }
        }
        ans.push_back(start);
        ans.push_back(end);
        ans.push_back(max_area);
        return ans;
    }
    int maxArea(int M[1000][1000], int n, int m) {
        // Your code here
        vector<int> ans;
        int area,max_area =0;
        for(int i=0; i<n; i++){
            ans = largestRectangleArea(M[i], m);
            if(ans[2] > max_area) max_area = ans[2];
            if(i != n-1){
                for(int j=ans[0]; j<ans[1] + 1; j++){
                    if(M[i+1][j] == 0){
                        continue;
                    }
                    M[i+1][j] = M[i+1][j] + M[i][j];
                }
            }
            
        }
        return max_area;
    }
int main() {
int n=5,m=12;
int M[1000][1000] ;
// {{0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0},
//                      {0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
//                      {1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1},
//                      {0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
//                      {1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1}};
for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        cin>>M[i][j];
    }
}
int ans = maxArea(M, n, m);
cout<<ans<<endl;
return 0;
}