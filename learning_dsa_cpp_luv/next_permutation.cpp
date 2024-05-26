#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
        int p;
        for(int i=nums.size()-2; i>=0; i--){
               if(nums[i]< nums[i+1]){
                     p=i;
                     break;
               }
        }
        int min=p+1;
        for(int i=p+1; i<nums.size(); i++){
            if(nums[i] > nums[p] && nums[min] >= nums[i]){
                min = i; 
            }
        }
        swap(nums[p] , nums[min]);
        reverse(nums.begin()+p+1 ,  nums.end());
    }
int main() {
vector<int> nums{1,3,4,2};
nextPermutation(nums);
for(int i=0; i<nums.size(); i++){
    cout<<nums[i]<<" ";
}
return 0;
}