#include <bits/stdc++.h>
using namespace std;
void print(int* p){
    cout<< *p <<endl;
}
int main() {
    int num = 5;
int* ptr = &num;   //declaring the integer pointer and storing the address of the integer variable 'num'.
cout<<"value of num = "<<*ptr<<endl;      //accessing the value of num through the pointer via '*' operator.
                                          //'*' operator means 'value at'
cout<<"address of num = "<< &num<<endl;   //accessing the address of num via '&' operator.
                                          //'&' operator means 'address of'
//similarly we can declare pointers of all the other data types 
//whatever be the size of the variable datatype , the size of pointers is 8 byte.
char ch ='c';
char* pt1 = &ch;
cout<<sizeof(ch)<<" "<<sizeof(pt1)<<endl;   //prints 1 8

//types of pointers 
//1. null pointers
int* pt2 = NULL;   
cout<<"the value of null pointer is : "<<pt2<<endl;  //it prints nothing

//2. double pointers
int i = 33;
int* pt3 = &i;
int** pt4 = &pt3;
cout<<**pt4<<" "<<*pt4<<" "<<pt4<<endl;

//important
// arr[i] = *(arr + i)    => arr[0] = *(arr + 0) = *arr    => arr = &arr[0]
//i[arr] = *(arr + i);
int arr[5] = {1, 2, 3, 4, 5};
int n=2;
cout<<"third element of the array is : "<<n[arr]<<endl;  //n[arr] = *(n + arr) = *(2 + arr) = arr[2]

cout<<arr<<endl;   //it will print the address of first element 
// but cout<<ch<<endl; will print the whole array , as cout behaves differently with character arrays 
//its better to not use character arrays with pointers .
char cha[6] = "abcde";
cout<<cha<<endl;      // it will print the array instead of address

//pointers with functions 
int value = 5;
int *p = &value;
print(p);  //or print(&value);  for passing the address of the variable
return 0;
}