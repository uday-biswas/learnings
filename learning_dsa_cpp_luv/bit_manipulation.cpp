#include <bits/stdc++.h>
using namespace std;
int main() {
int a = 4 , b = 6;
cout<< " a & b = "<< (a&b) << endl; //100 & 110 = 100 = 4
cout<<"a | b = " << (a|b) << endl;  // 100 | 110 = 110 = 6
cout<<"~a = "<< ~a <<endl;          // ~ 0000...0100 = 1111...1011(2's complement) = -5
cout<<"a^b = "<<(a^b)<< endl;       // 100 ^ 110 = 010 = 2
cout<< "17 >> 1 = "<< (17>>1) <<endl; // 010001 >> 1 = 001000 = 8 (17 / 2 = 8)
cout<< "17 >> 2 = "<< (17>>2) <<endl; // 010001 >> 2 = 000100 = 4 (17 / 4 = 4)
cout<< "19 << 1 = "<< (19<<1) <<endl; // 010011 << 1 = 100110 = 38 (19 x 2 = 38)
cout<< "21 << 2 = "<< (21<<2) <<endl; // 0010101 << 2 = 1010100 = 84 (21 x 4 = 84)
return 0;
}