#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = (array1.size() + array2.size());
        int i=0,j=0,k=0;
        int y=array1.size() , z = array2.size();
        // if(y==0) {
        //     if(n %2 == 1){
        //         return array2[n/2];
        //     }
        //     else{
        //         return (array2[n/2 -1] + array2[n/2])/2.0;
        //     }
        // }
        // if(z==0) {
        //     if(n %2 == 1){
        //         return array1[n/2];
        //     }
        //     else{
        //         return (array1[n/2 -1] + array1[n/2])/2.0;
        //     }
        // }
        int m = y - z ;
        if(m>0){
            for(int q=0; q<m; q++){
                array2.push_back(INT_MAX);
            }
        }
        else if(m<0){
            for(int q=0; q<-m; q++){
                array1.push_back(INT_MAX);
            }
        }
        array1.push_back(INT_MAX);
        array2.push_back(INT_MAX);
        if(n%2 == 1) {
            while(i!= n/2){
                if(array1[j] <= array2[k]) j++;
                else k++;
                i++;
            }
            if(array1[j] <= array2[k]) return array1[j];
            else return array2[k];
        }
        else{
            while(i != (n/2) - 1){
                if(array1[j] <= array2[k]) j++;
                else k++;
                i++;
            }
            if(j==y) return (array2[k] + array2[k+1])/2.0;
            else if(k==z) return (array1[j] + array1[j+1])/2.0;
            else {
                if(array1[j+1] < array2[k]) return (array1[j] + array1[j+1])/2.0;
                else if(array2[k+1] < array1[j]) return (array2[k] + array2[k+1])/2.0;
                else return ( array1[j] + array2[k])/2.0 ;
                
            }
        }
    }
int main() {
vector<int> arr1{48425, 53237 ,53652, 83052 ,96283}, arr2{};
double ans = MedianOfArrays(arr1,arr2);
cout<<ans;
return 0;
}
