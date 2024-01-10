#include <bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int i=0,j=0,p=1,k=0;
        int row=r, col=c;
        vector<int> ans;
        while(true){
            if(p==1){
                i=k;
            for( ;i<col+k;i++){
                ans.push_back(matrix[j][i]);
            }
            if(i==col+k){
                i--; k++; j=k; row--;
            }
            
            if(i>=c && j>=r) return ans;
            for(;j<=(r+row)/2;j++){
                ans.push_back(matrix[j][i]);
            }
            if(j==(r+row)/2 + 1) {
                j--; col--;}
            p=0;
        }
        else{
            i--;
            for(;i>=(c-col)/2;i--){
                ans.push_back(matrix[j][i]);
            }
            i++;j--; row--;
            for(;j>=(r-row)/2; j--){
                ans.push_back(matrix[j][i]);
            }
            j++;
            p=1;
            col--;
         }
         if(row==0 && col==0 && r==c) return ans;
         else if(r>c && row==r-c && col==0) return ans;
         else if(r<c && row==0 && col==c-r) return ans;
        }
    }
int main() {
int r=2, c=3;
vector<vector<int>> mat{{5,11,30}, {5,19,19}};
vector<int> ans = spirallyTraverse(mat,r,c);
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}