#include <bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int ans=1, max= INT_MIN;
      sort(arr, arr+N);
      for(int i=1; i<N; i++){
          if(arr[i] - arr[i-1] == 1){
              ans++;
          }
          else{
              if(ans > max ) max = ans;
              ans =1;
          }
      }
      if(ans > max) max = ans;
      if(N==1) max=1;
      return max;
    }
   // 2 4 5 6 7 8 10 11 12 13 14 15 16 17 18 19 21 22 23 24 25 26 27 29 30 31 32 33 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
int main() {
int N = 43;
int arr[] = {19, 38, 21, 46 ,25 ,40, 44, 7 ,48 ,42, 11, 13, 12, 47, 43 ,14 ,37 ,8 ,41, 31, 2, 5, 16, 45, 49, 33, 4 ,39, 10, 26, 6, 35, 23, 17, 30, 36, 27, 32, 22, 29, 18 ,15 ,24};
int ans = findLongestConseqSubseq(arr,N);
cout<<ans;
return 0;
}