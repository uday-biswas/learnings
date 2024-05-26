#include <bits/stdc++.h>
using namespace std;
int main() {
int sum =0,count=1,b,a,n,v;
        double group,c,d;
        // cin>>n;
        n=89988062;
        v=n;
        while(v!=0){
            count++;
            v= v>>1;
        }
        for (int i=0; i<count; i++){
          group = ((n+1.0)/pow(2,i));
          a = group;
          if(a%2 == 0) c= a/2;
          else{
              d = group;
              float f = group - a;
              if(f==0) d+= 0.5;
              b= ceil(d);
              c= group - b/2;
          }
          sum += c * pow(2,i);
        }
        cout<<sum;
return 0;
}