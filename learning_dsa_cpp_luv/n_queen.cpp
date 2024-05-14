#include <bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<int>> board, int row, int col){
        int n = board.size();
        int i=row,j=col;
        while(j>=0){
            if(board[i][j] == 1) return false;
            j--;
        }
        j = col;
        while(i>=0 && j>=0){
            if(board[i][j] == 1) return false;
            i--; j--;
        }
        i=row; j=col;
        while(i<n && j>=0){
            if(board[i][j] == 1) return false;
            i++; j--;
        }
        return true;
    }

    void change(vector<vector<int>> &board, int row , int col){
        int n = board.size();
        for(int k=0; k<n; k++){
            if(board[row][k] == 0) board[row][k] = col+1;  //straight top to bottom
            if(board[k][col] == 0) board[k][col] = col+1;  //straight left to right
        }
        int i,j;
        //diagonally right down
        for(i=row,j=col; i<n && j<n; i++,j++)
            if(board[i][j] == 0) board[i][j] = col + 1;
        
        //diagonally left up
        for(i=row,j=col; i>=0 && j>=0; i--,j--)
            if(board[i][j] == 0) board[i][j] = col + 1;
        
        //diagonally left down
        for(i=row,j=col; i<n && j>=0; i++,j--)
            if(board[i][j] == 0) board[i][j] = col + 1;
        
        //diagonally right up
        for(i=row,j=col; i>=0 && j<n; i--,j++)
            if(board[i][j] == 0) board[i][j] = col + 1;
    }
    
    void undo(vector<vector<int>> &board, int row , int col){
        int n = board.size();
        for(int k=0; k<n; k++){
            if(board[row][k] == col+1) board[row][k] = 0;  //straight top to bottom
            if(board[k][col] == col+1) board[k][col] = 0;  //straight left to right
        }
        int i,j;
        //diagonally right down
        for(i=row,j=col; i<n && j<n; i++,j++)
            if(board[i][j] == col+1) board[i][j] = 0;
        
        //diagonally left up
        for(i=row,j=col; i>=0 && j>=0; i--,j--)
            if(board[i][j] == col+1) board[i][j] = 0;
        
        //diagonally left down
        for(i=row,j=col; i<n && j>=0; i++,j--)
            if(board[i][j] == col+1) board[i][j] = 0;
        
        //diagonally right up
        for(i=row,j=col; i>=0 && j<n; i--,j++)
            if(board[i][j] == col+1) board[i][j] = 0;
    }

    void solve(vector<vector<int>> &ans, vector<int> ans_part,vector<vector<int>> board,int col){
        bool status;
        if(col == board.size()){
            ans.push_back(ans_part);
            return;
        }
        for(int row=0; row<board.size(); row++){
            status = isvalid(board,row,col);
            if(status){
                ans_part.push_back(row+1);
                board[row][col] = 1;
                solve(ans, ans_part, board, col+1);
                board[row][col] = 0;
                ans_part.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> ans_part;
        vector<vector<int>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));
        // for(int i=0; i<n; i++){
        //     ans_part.push_back(i+1);
        //     ans_part.pop_back();
        // }
            solve(ans,ans_part, board, 0);
        return ans;
    }
int main() {
int n=4;
vector<vector<int>> ans = nQueen(n);
for(int i=0; i<ans.size(); i++){
  for(int j=0; j<n; j++){
     cout<<ans[i][j]<<" ";
  }
  cout<<endl;
}
return 0;
}