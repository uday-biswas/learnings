#include <bits/stdc++.h>
using namespace std;
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    //base condition
   if(myStack.empty()) {
       myStack.push(x);
       return myStack;
   }

   //recurrence relation and processing
   int popped = myStack.top();
   myStack.pop();
   pushAtBottom(myStack,x);
   myStack.push(popped);
    return myStack;
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    //base condition
    if(stack.empty()) return;
    if(stack.size() == 1) return;

    //recurrence relation and processing
    int popped = stack.top();
    stack.pop();
    reverseStack(stack);
    stack = pushAtBottom(stack, popped);

}
int main() {
stack<int> s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
reverseStack(s);
while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}
return 0;
}