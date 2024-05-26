#include <bits/stdc++.h>
using namespace std;
void update(int& n){     //using reference variable as function parameter instead of pointers.
    n = n * 3;
}
int main() {
//reference variable understanding
int i=5;
int& j = i;  //declaring a reference variable for i , its just the other name , both i and j are pointing to the same 
             //memory address 
j++;         //j = i = 6;
cout<<"i = "<<i<<endl; 
update(i);
cout<<"after update i = "<<i<<endl;
return 0;
}