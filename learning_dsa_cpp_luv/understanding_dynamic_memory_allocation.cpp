#include <bits/stdc++.h>
using namespace std;
int main() {
//understanding dynamic memory allocation 
//static memory is stored in stack, and the variable size must be defined at the compile time 
//whereas dynamic memory is stored in heap , and the variable size may be defined at the run time as well as compile time
int n;
cout<<"enter the number of rows : ";
cin>>n;
int *arr= new int[n];   //dynamically allocating the array with variable size , cant be done with static memory

cout<<"enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>arr[i];
}
cout<<"the array elements are : "<<endl;
for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;


int *i = new int;
char *ch = new char;


//we have to manually delete the dynamically allocated variable, using 'delete' keyword , unlike static variables.
delete i;
delete ch;
delete []arr;

//we can create 2D array dynamically
    int row;
    cout<<"enter the rows : ";
    cin >> row;

    int col;
    cout<<endl<<"enter the columns : ";
    cin >> col;

    //creating a 2D array
    int** arr2 = new int*[row];
    for(int i=0; i<row; i++) {
        arr2[i] = new int[col];
    }

    //taking input
    cout<<endl<<"enter the elements of the 2D array : "<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr2[i][j];
        }
    }

    //giving output
    cout << "the elements are : "<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr2[i][j] << " ";
        } 
        cout << endl;
    }


    //releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr2[i];
    }   

    delete []arr2;

return 0;
}