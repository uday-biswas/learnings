#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> heights){
        int n = heights.size();
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

    vector<int> prevSmallerElement(vector<int> heights){
        int n = heights.size();
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


    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        left = prevSmallerElement(heights);
        right = nextSmallerElement(heights);
        int max_area = 0, area;
        int width , height;
        for(int i=0; i<heights.size(); i++){
            width = right[i] - left[i] - 1;
            height = heights[i];
            area = width * height;
            max_area = max(area, max_area);
        }
        return max_area;
    }
int main() {
vector<int> heights{4,2,0,3,2,4,3,4};
int area = largestRectangleArea(heights);
cout << area << endl;
return 0;
}