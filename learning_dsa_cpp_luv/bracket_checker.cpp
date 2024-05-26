#include <bits/stdc++.h>
using namespace std;
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for(int i=0; i<expression.size(); i++){
      if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(') {
        s.push(expression[i]);
      } 
      else if (expression[i] == '}') {
        if (s.top() == '{')
          s.pop();
        else return false;
      }

      else if(expression[i] == ']'){
        if(s.top() == '[') s.pop();
        else return false;
      }
      else if(expression[i] == ')'){
        if(s.top() == '(') s.pop();
        else return false;
      }
      else return false;
    }
    if(s.empty()) return true;
    else return false;
}
int main() {
string str = "";
stack<int> s;
cout<<s.top()<<endl;
bool ans = isValidParenthesis(str);
cout<<ans<<endl;
return 0;
}