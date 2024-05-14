#include <bits/stdc++.h>
using namespace std;
vector<string> letterCombinations(string digits) {
        //base condition
        if(digits.empty()){
            vector<string> emp;
            return emp;
        }

        //recurrence relation and processing
        char last = digits[digits.size()-1];
        digits.pop_back();
        vector<string> ans = letterCombinations(digits);
        if(ans.empty()) ans.push_back("");
        vector<char> keys;
        switch(last){
            case '2' : keys.push_back('a'); keys.push_back('b'); keys.push_back('c');
                       break;
            case '3' : keys.push_back('d'); keys.push_back('e'); keys.push_back('f');
                       break;
            case '4' : keys.push_back('g'); keys.push_back('h'); keys.push_back('i');
                       break;
            case '5' : keys.push_back('j'); keys.push_back('k'); keys.push_back('l');
                       break;
            case '6' : keys.push_back('m'); keys.push_back('n'); keys.push_back('o');
                       break;
            case '7' : keys.push_back('p'); keys.push_back('q'); keys.push_back('r'); keys.push_back('s');
                       break;
            case '8' : keys.push_back('t'); keys.push_back('u'); keys.push_back('v');
                       break;
            case '9' : keys.push_back('w'); keys.push_back('x'); keys.push_back('y'); keys.push_back('z');
                       break;
            default :  cout<<"wrong input";
                       break;
        }
        
        vector<string> ans1;
        int size = ans.size(); 
        for(int i=0; i<size; i++){
            for(int j=0; j<keys.size(); j++){
                string temp = ans[i];
                temp.push_back(keys[j]);
                ans1.push_back(temp);
            }
        }
        return ans1;
    }
int main() {
string str = "234";
vector<string> ans = letterCombinations(str);
for(int i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
}
return 0;
}