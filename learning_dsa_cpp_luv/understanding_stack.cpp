#include <bits/stdc++.h>
using namespace std;

class Stack {
    //properties
    public:
        vector<int> arr;     //array to store the elements
        int top;             //index of the topmost element
        int size;            //size of the stack

    // behaviour
    Stack() {
        size = 0;
        top = -1;
    }

    void push( int element) {     //push operation to insert the element in top
        top++;
        arr.push_back(element);
        size++;
    }

    void pop() {                 //pop operation to delete the topmost element
        if(top >=0 ) {
            top--;
            arr.pop_back();
            size--;
        }
        else{
            cout << "Stack UnderFlow" << endl;
        }
    }

    int peek() {                  //peek operation to return the topmost element
        if(top >=0 )
            return arr[top];
        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {              //to check whether the stack is empty or not
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }

    int sizeofstack(){           //to return the size of the stack
        return size;
    }

};


int main() {
    Stack st;
    vector<int> arr{22,43,44,22,43,44};
    for(int i=0; i<arr.size(); i++){
        st.push(arr[i]);
    }

    cout<<"the size of the stack is: "<<st.sizeofstack()<<endl;

    cout << st.peek() << endl;
    st.pop();

    cout << st.peek() << endl;
    st.pop();

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }

    
    /*
    //creation of stack using stl
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    */

    return 0;
}