#include <bits/stdc++.h>
using namespace std;
void increment(int &a, int b) {    //a is passed by reference and b is passed by value
    a = a + 1;                      //hence a got incremented and b didn't
    b = b + 1;
}
int main() {
    int a = 10, b = 20;
increment(a,b);
cout<< a << " " << b << endl;
return 0;
}