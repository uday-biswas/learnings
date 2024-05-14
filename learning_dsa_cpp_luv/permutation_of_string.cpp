#include <bits/stdc++.h>
using namespace std;
 int factorial(int n){
	        if(n==1) return 1;
	        int prod = 1;
	        for(int i=2; i<=n; i++){
	            prod *= i;
	        }
	        return prod;
	    }
		vector<string> find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    vector<char> ch;
		    for(int j=0; j<S.size(); j++){
		        ch.push_back(S[j]);
		    }
		    sort(ch.begin(), ch.end());
		    S.clear();
		    for(int j=0; j<ch.size(); j++){
		        S.push_back(ch[j]);
		    }
		    ans.push_back(S);
		    int fac = factorial(S.size()),pivot=-1;
		    for(int i=1; i<fac; i++){
                pivot=-1;
		        for(int j=S.size()-2; j>=0; j--){
		            if(S[j] < S[j+1]){
		                pivot = j;
		                break;
		            }
		        }
                if(pivot==-1) break;
		        int min = pivot + 1;
		        for(int k=pivot+1; k<S.size(); k++){
		            if(S[k] > S[pivot] && S[min] >= S[k]) min = k;
		        }
		        swap(S[pivot],S[min]);
		        reverse(S.begin()+pivot+1, S.end());
		        ans.push_back(S);
		    }
		    return ans;
		}
int main() {
vector<string> ans = find_permutation("ABB");
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}