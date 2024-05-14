#include <bits/stdc++.h>
using namespace std;
void merge(int l, int mid, int r, vector<int> &arr){
            // starting index of first positive element of left subarray
            int leftPos = l;
            while(leftPos<=mid && arr[leftPos]<0)
                leftPos++;
            // starting index of last negative element of left subarray
            int rightNeg = r;
            while(rightNeg>mid && arr[rightNeg]>=0)
                rightNeg--;
            //reverse left positive part
            reverse(arr.begin()+leftPos, arr.begin()+mid+1);
            //reverse right negative part
            reverse(arr.begin()+mid+1, arr.begin()+rightNeg+1);
            //reverse entire left positive and right negative part
            reverse(arr.begin()+leftPos, arr.begin()+rightNeg+1);
        }
        void mergeSort(int l, int r, vector<int> &arr){
            if(l==r)
                return;
           int mid = (l+r)/2;
           mergeSort(l, mid, arr);
           mergeSort(mid+1, r, arr);
           merge(l, mid, r, arr);
        }
        void Rearrange(vector<int> &arr, int n)
        {
            mergeSort(0, n-1, arr);
        }
int main() {
vector<int> arr{-5, 1, 1, 1,-3, -6};
Rearrange(arr,6);
for(int i=0;i<6; i++){
    cout<<arr[i]<<" ";
}
return 0;
}