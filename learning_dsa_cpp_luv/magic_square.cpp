#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int main() {
int n =5, c=1, i=1, j=3;
while (c <= 25){
    i--; j--; 
   if ( i==-1) i = 4;
   if ( j== -1) j =4;
   if(a[i][j] == 0) {
    a[i][j] = c;
    c++;
   }
   else{
    if (i==4) i = -1;
    if (j==4) j = -1;
    i++;i++;j++;
    a[i][j] =c;
    c++;
   }
}
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}