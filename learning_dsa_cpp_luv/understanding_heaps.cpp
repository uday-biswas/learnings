#include <bits/stdc++.h>
using namespace std;
class heaps{
    public:

    int arr[100];
    int size;
    public:
    heaps(){
        size = 0;
    }

    void insert(int val){
        int index = size++;
        arr[index] = val;       //firstly inserting the element at the last in the array.

        while(index >= 1){
            int parent;
            if(index % 2 == 0) parent = index/2 -1;    //if its a right child
            else parent = index/2;                     //if its a left child
            if(arr[parent] < arr[index]) {             //if the child value is greater than parent value, swap each other.
                swap(arr[parent], arr[index]);
                index = parent;                        //in the next iteration, compare the current parent with its parent.
            }
            else return;
        }
    }

    //function to print the current heap
    void print(){
        cout<<"the current heap is : ";
        if(size == 0) cout<<"empty";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
    //function to delete the maximum element(root) from the current heap and then heapify the remaining heap
    //approach - firstly we will swap the first element and the last element in the heap array , decrease the size by 1 ,so that
    // the last element that is the maximum element will get excluded from the heap.
    // now we will heapify the remaining array , starting from the 0th index till the first leaf node is arrived.
    // firstly the element at 0th index is heapified , then its child which got swapped until the leaf node appears.
    //heapifying - if the parent node is lesser than the child node , then swap them and repeat it with its child in the next
    // cycle unti the leaf node arrives.
    int delete_root(){
        if(size == 0) return -1;

        int deleted = arr[0];
        arr[0] = arr[size-1];
        size--;

        int index = 0;
        while(1){
           if(index*2 + 1 > size-1 && index*2+2 > size-1) return deleted;    //index*2 + 1 gives the left child of the index, and index*2 + 2 gives the right child
           else if(index * 2 + 1 <= size-1 && index*2 + 2 > size-1 && arr[index] <= arr[index * 2 + 1]) {
                swap(arr[index], arr[index*2 + 1]);
                index = index*2 + 1;
           }
           else if(index*2 +2 <= size){
                int maxi;
                if(arr[index*2 + 1] > arr[index*2 +2])
                    maxi = index*2 + 1;
                else 
                    maxi = index*2 + 2;
                swap(arr[index], arr[maxi]);
                index = maxi;
           }
           else return deleted;
        }
    }

};
//function to heapify a given array's element as root, it heapifies a subtree at a time.
void heapify(int arr[], int size, int i){
    //arr[] is the complete array , 'size' is the size of the array that has to be heapified, 'i' is the index of the element 
    // in the array which is the root of the subtree that has to be heapified.
    if(i > size/2 - 1) return ;   //elements whose index is greater than size/2 -1 are leaf nodes, that don't needs to be heapified
    int largest = i;
    int left = i*2 + 1;       //finding index of the left child
    int right = i*2 + 2;      //finding index of the right child
    if(left <= size-1 && arr[left] > arr[largest]) largest = left;      //if left child exists and is greater than parent , then update the 'largest' index.
    if(right <= size-1 && arr[right] > arr[largest]) largest = right;   //if right child also exists and is greater than the element at 'largest' , then update the 'largest' index

    if(largest != i) {         //if 'largest' is updated , then swap it with parent , heapify that largest child in the next cycle.
        swap(arr[i], arr[largest]);
        heapify(arr ,size, largest);
    }
}

//function to arrange the heap elements in increasing order in a array.
//approach - first element of a max heap is always the maximum element of the heap, so swap it with the last element of the heap, and decrease 
// the size of the array by 1, so that the current maximum element is excluded from the heap , and placed at the right place .
void heap_sort(int arr[], int n){
    int size = n;
    while(size != 1){
        swap(arr[0], arr[size-1]);
        size--;
        int j = size/2 - 1;        //heapifying the non leaf nodes
        for(int k=j; k>=0; k--){
           heapify(arr, size, k);
        }
    }
}

int main() {
    //example: 
    //        55
    //       /  \
    //      54   53      input : 55 54 53 50 52 -1
    //     /  \    
    //    50   52  
// heaps h;
// int data;
// cout<<"enter the data for the heap: ";
// cin>>data;
// while(data != -1){
//     h.insert(data);
//     cin>>data;
// }
// h.print();
// char ch = 'y';
// while(ch == 'y'){
//     cout<<"after deletion the element at root was : ";
//     cout<<h.delete_root()<<endl;
//     h.print();
//     if(h.size == 0) break;
//     cout<<"want to delete more(y/n) : ";
//     cin>>ch;
// }
int arr[] = {45, 3 , 38 , 82, 34};
int size = 5;

int j = size/2 - 1;
for(int k=j; k>=0; k--){
heapify(arr, size, k);
}
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

//heap_sort to sort the array in O(NlogN) T.C.
heap_sort(arr,size);
for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
return 0;
}