#include <bits/stdc++.h>
using namespace std;
int main() {
int a = 10;
int *p = &a;  // declaring a pointer and assigning the address of a to it
cout << "a = " << a << endl;
cout << "p = " << p << endl;     // accessing the address of "a" using pointer
cout << "*p = " << *p << endl;   // accessing the value of "a" using pointer
cout << "&a = " << &a << endl;   // address of "a"
cout << "&p = " << &p << endl;   // address of "p"

//array and pointers
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;  // assigning the base address of the array to the pointer
cout << "arr = " << arr << endl; // base address of the array
cout << "&arr[0] = " << &arr[0] << endl; // base address of the array
cout << "*arr = " << *arr << endl; // accessing the value of the first element of the array
cout << "*(arr + 1) = " << *(ptr + 1) << endl; // accessing the value of the second element of the array
cout << "&arr[1]: "<< &arr[1] << endl; // address of the second element of the array
cout << "*(arr + 1): "<< *(arr + 1) << endl; // accessing the value of the second element of the array
return 0;
}