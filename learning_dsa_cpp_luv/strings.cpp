#include <bits/stdc++.h>
using namespace std;
int main() {
// string str = "hello";
// string str2 = "world";
// cout<< str + " " + str2 << endl;  //concatenation of the strings
// cout<< str.length()<< " " <<str2.size() <<endl;       //length of the string using length() and size() functions
// cout<< (str == str2) << endl; // comparing strings for equality , 0 for false and 1 for true
// cout<< (str < str2) << endl;  // comparing strings for lexicographical order , 0 for false and 1 for true

// str[0] = 'H';  
// cout<< str[0] << endl; // accessing and assigning values of the string using index.

//use of getline() function
int t; string str3;
cin>>t;
cin.ignore(); // to ignore the newline character , so that getline() can take the input
while(t--){
getline(cin, str3); // taking a line as input
cout<< str3 << endl;
}

//reversing the string 
string str_rev1, str_rev2, str4 = "legendary";
//method 1
// reverse(str4.begin(), str4.end());          //reverse() function is used to reverse the string
// cout<< str4 << endl;

//method 2
// for (int i = str4.length(); i>=0; i--){
//     str_rev1.push_back(str4[i]);         //push_back() function is used to push a character at the end of the string
// }
// cout<<str_rev1 << endl;

// //method 3
// for (int i= str4.length(); i>=0; i--){
//     str_rev2 = str_rev2 + str4[i];           //but the pushback function is better in terms of time complexity
// }
// cout<<str_rev2 << endl;

// //handling the larger numbers greater than 10^18
// string str5 = "178743938756382284565748937";
// int n = (int)str5[str5.length()-1] - '0'; //converting the character of the string to integer
// cout<< n << endl;

return 0;
}