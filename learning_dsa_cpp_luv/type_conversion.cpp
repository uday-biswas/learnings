#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 10;
    float b = 1.5;
    char c = 'a', d = '9';
    cout << a + b + c + d<< endl;       // 10 + 1.5 + 'a' + '9' = 10 + 1.5 + 97 + 57 = 10.0 + 1.5 + 97.0 + 57.0 = 165.5
    cout << a + (int)b + d<< endl;       // 10 + (int)1.5 + '9' = 10 + 1 + 57 = 11
    cout << (float)a + b + c << endl;   // (float)10 + 1.5 + 'a' = 10.0 + 1.5 + 97.0 = 108.5
return 0;
}