#include <bits/stdc++.h>
using namespace std;
void print1(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print2(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
void print3(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}
void print4(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<n-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print5(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<n-i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
}
void print6(int n){
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n-i;j++){
            cout<<"  ";
        }
        for ( int k=1; k<=2*i-1;k++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print7(int n){
    for(int i=1; i<=n; i++){    //rows
       //numbers
        for (int j=1; j<=i;j++){  
            cout<<j<<" ";
        }
        //spaces
        for ( int k=1; k<=2*(n-i);k++){
            cout<<"  ";
        }
        //numbers
        for (int l=i; l>=1; l--){
            cout<<l<<" ";
        }
        cout<<endl;
    }
}
void print8(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<n-i;j++){
            cout<<char(j+'A')<<" ";
        }
        cout<<endl;
    }
}
void print9(int n){
    for (int i=1; i<=n; i++){
        int k=(n-i);
        for(int j=1; j<=i; j++){
            cout<<char('A' + k++)<<" ";
        }
        cout<<endl;
    }
}

int main() {
print1(5); cout<<endl;
print2(5); cout<<endl;
print3(5); cout<<endl;
print4(5); cout<<endl;
print5(5); cout<<endl;
print6(5); cout<<endl;
print1(5);print4(5); cout<<endl;
print7(4); cout<<endl;
print8(5); cout<<endl;
print9(5); cout<<endl;
return 0;
}