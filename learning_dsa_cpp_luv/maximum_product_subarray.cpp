#include <bits/stdc++.h>
using namespace std;
long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long max= INT_MIN;
	    long long prod = 1,prodn=1;
	    long long lo;
	    for( int i=0; i<arr.size(); i++){   //3 12 15 23 33 -35 30 -40 -30 -30 -30 26 28
	        if(arr[i]<0){
	            prodn *= arr[i];
	            if(prodn>0) {
                    prod *= prodn * lo;
                    prodn =1;
                    }
	            else{
                    lo = prod;
                    prod = 0;
                    }
	        }
	        else if(arr[i] > 0) prod *= arr[i];
	        else {
	            prodn = 1;
	            prod =0;
	        }
	        
	        if(max < prod) max = prod;
	        if(arr[i] ==0 || prod==0) {
	            prod =1 ;
	        }
	    }
        prod=1; prodn=1;
        long long max1 = INT_MIN;
        for( int i=arr.size()-1; i>=0; i--){   //3 12 15 23 33 -35 30 -40 -30 -30 -30 26 28
	        if(arr[i]<0){
	            prodn *= arr[i];
	            if(prodn>0) {
                    prod *= prodn * lo;
                    prodn =1;
                    }
	            else{
                    lo = prod;
                    prod = 0;
                    }
	        }
	        else if(arr[i] > 0) prod *= arr[i];
	        else {
	            prodn = 1;
	            prod =0;
	        }
	        
	        if(max1 < prod) max1 = prod;
	        if(arr[i] ==0 || prod==0) {
	            prod =1 ;
	        }
	    }
        if(max1 > max ) max = max1;
	    if(arr.size()==1 && arr[0]<0) max = arr[0];
	    return max;
	}

int main() {
int n = 13;
vector<int> arr{3 ,12, 15, 23, 33, -35, 30, -40, -30, -30, -30, 26, 28};
long long ans = maxProduct(arr,n);
cout<<ans;
return 0;
}