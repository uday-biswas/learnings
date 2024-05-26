#include <bits/stdc++.h>
using namespace std;
void explainPair(){
    pair<int, char> p1 = {1,'a'};
    cout<<p1.first<<" "<<p1.second<<endl;  //prints 1 a
    
    pair<int, pair<int,int>> p = {1, {3,4}};
    cout<<p.first<<" "<<p.second.second << " "<<p.second.first<<endl; //prints 1 4 3

    pair<int,int> arr[] = { {1,2}, {2,5}, {5,1}};
    cout<<arr[2].second<<endl;                    //prints 1
}
void explainVector(){
    vector<int> v1;    //declaration of a vector
    v1.push_back(1);   //pushes the element in the last
    v1.emplace_back(2);   //similar to push_back() but faster
    for(int i=3; i<6; i++){
        v1.push_back(i);
    }                              //v1 = {1, 2, 3, 4, 5}
    cout<<v1[0]<<" "<<v1[1]<<endl;  //giving output is similar to normal array , prints 1 2
    
    vector<pair<int, int>> v2;
    v2.push_back({5,2});
    v2.emplace_back(1,2);      //v2 = { {5,2} , {1,2}}
    cout<<v2[0].first<<endl;   //prints 5

    vector<int> v3(5, 100);  //it initiliazes the vector with 5 elements each with value as 100
    for (int i=0; i<5; i++) cout<<v3[i]<<" ";        //prints 100 100 100 100 100
    cout<<endl;

    vector<int> v4(5);    //it initializes the vector with 5 elements each with 0
    for (int i=0; i<5; i++) cout<<v4[i]<<" ";     //prints 0 0 0 0 0 
    cout<<endl;

    vector<int> v5(5,30);
    vector<int> v6(v5);    //it copies the element from v5 to v6
    cout<<v6[3]<<endl;     //prints 30

    int a = *(v1.begin());  //begin() function refers to the address of the beginning element of the vector
    int b = *(v1.end()-1);  //end() function refers to the address after the last element.
    cout<<a<<" "<<b<<endl;   //prints 1 5

    for(auto it = v1.begin(); it != v1.end(); it++) cout<< *(it) << " ";  //used to print the whole array , prints 1 2 3 4 5
    cout<<endl;

    //important
    v1.erase(v1.begin()+2);  //erase( element_address ) function deletes the element at the given address
                             //v1 = {1 2 4 5}
    for(auto it = v1.begin(); it != v1.end(); it++) cout<< *(it) << " ";   //prints 1 2 4 5
    cout<<endl;

    for(int i=0; i<v1.size(); i++) cout<< v1[i] << " ";  //prints 1 2 4 5 
    cout<<endl;
    v1.erase(v1.begin()+1, v1.end()-1);  //erase(initial_address , final_address) function deletes the element from the initial address to the final address excluding the element at final address
    for(auto it = v1.begin(); it != v1.end(); it++) cout<< *(it) << " ";   //prints 1 5    
    cout<<endl;
    
    //insert function
    vector<int> v7(2,100);
    v7.insert(v7.begin(), 300);  //insert function inserts the element at the given address
    v7.insert(v7.begin()+2, 2,10);  //it inserts 2 elements in the given address
    for(auto it = v7.begin(); it != v7.end(); it++) cout<< *(it) << " ";    //prints 300 100 10 10 100
    cout<<endl;

    vector<int> copy(2, 50);
    v7.insert(v7.begin(), copy.begin(), copy.end()); //it copies the elements of vector copy to the given address of vector v7
    for (int i=0; i<v7.size(); i++) cout<<v7[i]<<" ";   //prints 50 50 300 100 10 10 100
    cout<<endl;

    cout<<v7.size()<<endl;  //size() function gives the size of the vector , prints 7

    v7.clear();  //erases the entire vector
    cout<<*(v7.begin()+2)<<endl;  //but it can be accessed through address , prints 300
    cout<<v7.size()<<endl;        //size shown will be 0                   , prints 0

    for (int x : v7) cout<<x<<" ";  //output will be none according to this
    cout<<endl;
    cout<<v7.empty();  //returns 1 if the vector is empty else 0  , prints 1
}

void explainList() {
    list<int> ls;
    ls.push_back(2);   //adds a new element at the end of the list
    ls.emplace_back(4); //similar to push_back()

    ls.push_front(6);  //adds a new element at the beginning 
    ls.emplace_front();  //similar to push_front() 
    //if nothing is given in argument of emplace_front() then, it inserts 0
    //ls = {0 , 6, 2, 4}
    int l = ls.front(); cout<<l<<endl;  //front() returns the value of the first element in the list. prints 0
    int r = ls.back(); cout<<r<<endl;  //back() returns the value of the last element in the list.    prints 4

    ls.pop_back();  //pop_back() removes the last element of the list        
    ls.pop_front();  //pop_front() removes the first element of the list
    //ls = {6, 2}
    for(auto it = ls.begin(); it != ls.end(); it++) cout<<*(it)<<" ";  //prints 6 2
    cout<<endl;
    cout<<*(ls.begin())<<endl;    //prints 6

    //traversing the list 
    ls.insert(ls.begin(), 5 , 20);     //ls = {20 20 20 20 20 6}
    auto it = ls.begin();
    for(; it != ls.end(); it++){
        if(*(it) == 6){
            cout<<"found"<<endl;
            break;
        }                             //prints 20 20 20 20 20 found
        cout<<*(it)<<" ";

    }

    //insert() , size() , begin() , end() function are similar to as in vector.
}

void explainDeque(){
    deque<int> dq;
    // the push_back() , emplace_back(), push_front(), emplace_front(), pop_back(), pop_front(), back(), front() , insert() are all similar to list;
}

// -> queue  and stack has no begin() or end()
void explainStack(){
    //stack is last in first out (LIFO)
     stack<int> st;
     st.push(1);    //pushes an element into the stack
     st.push(2);
     st.push(3);
     st.push(4);
     st.emplace(5);
                      //top -> 5 4 3 2 1 
     cout<<st.top()<<endl;  //returns the top element in the stack . prints 5

     st.pop();   //pops the top element  . top -> 4 3 2 1
     cout<<st.top()<<endl;      //prints 4
     cout<<st.size()<<endl;   //returns the size of the stack . prints 4
     cout<<st.empty()<<endl;  //checks whether the stack is empty or not . prints 0

     stack<int> st1, st2;
     st1.swap(st2);         //swaps the stacks
}

void explainQueue(){
    //queue is first in first out (FIFO)
     queue<int> q;
     q.push(1);    // R -> 1 <- F
     q.push(2);    // R -> 2 , 1 <- F
     q.emplace(4); // R -> 4 , 2 , 1 <- F

     q.back() += 5;   // R -> 9 , 2 , 1 <- F
     cout<< q.back()<<endl;   // prints 9
     cout<< q.front()<<endl;  // prints 1

     q.pop();    //pops element from front i.e. 1  
     // R -> 9 , 2 <- F

     cout<<q.front()<<endl;   // prints 2
}

void explainPriority_queue(){
    priority_queue<int> pq;
    // it is also similar to queue , but popping , pushing is done according to the ascending order of the element
    //its actually forming a max heap 
    pq.push(5); // R -> 5 <- F
    pq.push(2); // R -> 2 , 5 <- F
    pq.push(8); // R -> 2 , 5 , 8 <- F
    pq.emplace(10); //R -> 2 , 5 , 8 , 10 <- F

    cout<<pq.top()<<endl;  //prints 10
    pq.pop();              //deletes 10
    cout<<pq.top()<<endl;  //prints 8

    //priority queue with elements in descending order
    //basically it is forming a min heap
    priority_queue<int , vector<int> , greater<int>> pq1;
    pq1.push(5);  //R ->  5 <- F
    pq1.push(2);  //R -> 5 , 2 <- F
    pq1.push(8);  //R -> 8 , 5 , 2 <- F
    pq1.emplace(10);  //R -> 10 , 8 , 5 , 2 <- F

    cout<<pq1.top()<<endl;  //prints 2
}
void explainSet(){
    //set is a container that stores unique elements following a specific order
    set<int> st;
    st.insert(1);  //inserts 1 in the set
    st.insert(2);  //inserts 2 in the set
    st.emplace(2);  //doesnt insert 2 as it is already present in the set
    st.insert(4);  //inserts 4 in the set
    st.insert(3);  //inserts 3 in the set
                                          //st = {1, 2, 3, 4}
    //begin() , end() , size() , empty() , swap() , are same as above
    auto it = st.find(2);  //finds the element 2 in the set and returns the address of it
    cout<<*(it)<<endl;  //prints 2
    it = st.find(5);  //as there is no element 5 in the set , it returns the address of the last element in the set
    cout<<*(it)<<endl;  //prints 4

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1 , it2);  //erases the elements from it1 to it2-1
    for (auto it = st.begin(); it != st.end(); it++) cout<<*(it)<<" ";  //prints 1 4
    cout<<endl;

    int cnt = st.count(2);  //returns 1 if 2 is present in the set , else returns 0
    cout<<cnt<<endl;        //prints 0

    it = st.lower_bound(2);  //returns the address of the element which is equal to or greater than 2
    cout<<*(it)<<endl;  //prints 4
    
    it = st.upper_bound(2);  //returns the address of the element which is greater than 2
    cout<<*(it)<<endl;  //prints 4

}

void explainMultiSet(){
    multiset<int> ms;
    ms.insert(1);  //inserts 1 in the multiset  { 1 }
    ms.insert(1);  //inserts 1 in the multiset  { 1 , 1 }
    ms.insert(1);  //inserts 2 in the multiset  { 1 , 1 , 1 }
    ms.insert(2);  //inserts 2 in the multiset  { 1 , 1 , 1 , 2 }
    for(auto it=ms.begin(); it!=ms.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //begin() , end() , size() , empty() , swap() , are same as above
    int cnt = ms.count(1);  //returns the number of 1's in the multiset , prints 3
    cout<<cnt<<endl;

    ms.erase(ms.find(1)); //erases the first 1 from the multiset {1, 1, 2}
    for(auto it=ms.begin(); it!=ms.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    ms.erase(1);  //erases all the 1's from the multiset  { 2 }
    for(auto it=ms.begin(); it!=ms.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void explainUSet(){
    unordered_set<int> ust;
    //unordered set is same as set , but it is unordered and it stores same element multiple times
    

}
void explainMap(){
    //first parameter is the key and second is value 
    map<int, int> mp1;
    map<int, pair<int, int>> mp2;
    map<pair<int,int> , int> mp3;

    mp1[1] = 2;  // it stores {1,2}
    mp1.insert({3,1});
    
    for(auto it : mp1){
        cout<< it.first<<" "<<it.second<<endl;    //prints 1 2 
    }                                             //       3 1
    cout<<mp1[1]<<endl;        //prints 2
    cout<<mp1[5]<<endl;        //prints 0

    //begin() , end()
    for (auto it = mp1.begin(); it != mp1.end(); ++it) {
       cout << it->first << ", " << it->second << '\n';    //prints 1, 2
     }                                                     //       3, 1    
                                                           //       5, 0
    
    cout<<mp1.size()<<endl;   //prints 3
    cout<<mp1.empty()<<endl;  //prints 0 
    
    auto it = mp1.end();
    mp1.erase(mp1.find(3),--it); 
    for (auto it = mp1.begin(); it != mp1.end(); ++it) {
       cout << it->first << ", " << it->second << '\n';    //prints 1, 2
     }                                                     //prints 5, 0                                      

    cout<<mp1.count(1)<<endl; //returns whether the key value is present in the map or not , 1 for true and 0 for false 
    
    map<int,int> mp4{{7,8}, {4,7}};
    mp1.swap(mp4);
    for (auto it = mp1.begin(); it != mp1.end(); ++it) {
       cout << it->first << ", " << it->second << '\n';    //prints 4, 7
     }                                                     //       7, 8

    mp1.clear(); //clears the map mp1
}
void explainAlgorithms(){
    vector<int> v{5, 7, 3, 10, 0, 1, 2, 2, 7, 4};
    //sort
    sort(v.begin(), v.end());  //v = {0, 1, 2, 2, 3, 4, 5, 7, 7, 10}

    //rotate  -> syntax rotate(first, middle, end) 
    //first	- the beginning of the original range
    //middle - the element that should appear at the beginning of the rotated range
    //last - the end of the original range
    rotate(v.begin(), v.begin()+2, v.end()); //left rotating twice;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";             //prints 2, 2, 3, 4, 5, 7, 7, 10, 0, 1
    }
    cout<<endl;

    rotate(v.rbegin(), v.rbegin()+1, v.rend()); //right rotating once
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";             //prints 1, 2, 2, 3, 4, 5, 7, 7, 10, 0
    }
    cout<<endl;

    //reverse
    reverse(v.begin(), v.end()-3);    //v = {7, 5, 4, 3, 2, 2, 1, 7, 10, 0}

    //swap
    swap(v[4],v[3]);                  //v = {7, 5, 4, 2, 3, 2, 1, 7, 10, 0}
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //max
    int maxi = max(v[2], v[4]);    
    cout<<maxi<<endl;           //prints 4

    //min
    int mini = min(v[2], v[4]);
    cout<<mini<<endl;           //prints 3

    //is_permutation - syntax (first1, last1, first2, last2)
    //returns 1 if the second array could be the next permutation of the first array

    vector<int> v1{1,2 ,3, 4,5};
    vector<int> v2{3, 5, 4, 1, 2};
    vector<int> v3{3, 5, 4, 1, 1};
    cout<<is_permutation(v1.begin(), v1.end(), v2.begin(), v2.end())<<endl;  //prints 1
    cout<<is_permutation(v1.begin(), v1.end(), v3.begin(), v3.end())<<endl;  //prints 0

    //next_permutation - syntax (first, last)
    //it converts the array to its next permutation, and makes it null if there doesn't exists next permutation
    string s1 = "aba";
    sort(s1.begin(), s1.end());   //s1 = "aab"

    do cout << s1 << '\n';
    while (next_permutation(s1.begin(), s1.end()));
    cout<<endl;                                         //prints aab aba baa

    //prev_permutation - syntax (first, last)
    //it converts the array to its previous permutation , and makes it null if there doesn't exists previous permutation
    string s2 = "abc";
    sort(s2.rbegin(), s2.rend());       //s2 = "cba"
 
    do cout << s2 << ' ';                            //prints cba cab bca bac acb abc
    while (prev_permutation(s2.begin(), s2.end()));
    cout << '\n';                                   

    //merge - syntax(begin1 , end1 , begin2, end2, destination_vector)
    //it merges the two sorted arrays and stores it in the destination vector
    vector<int> v5{0, 2 ,2, 2, 4, 5, 6 ,6, 7, 7};
    vector<int> v4{0, 0, 1, 2 ,3 ,5 ,5, 6, 8, 9};
    vector<int> dst;
    merge(v5.begin(), v5.end(), v4.begin(), v4.end(), back_inserter(dst));
    for(int i=0; i<dst.size(); i++){
        cout<<dst[i]<<" ";           //prints 0 0 0 1 2 2 2 2 3 4 5 5 5 6 6 6 7 7 8 9
    }
    cout<<endl;

    //includes - syntax (begin1, end1, begin2, end2) 
    //it returns true if second sequence is the part of the first sequence otherwise false
    vector<int> v6 = {'a', 'b', 'c', 'f', 'h', 'x'},
        v7 = {'a', 'b', 'c'},
        v8 = {'a', 'c'},
        v9 = {'a', 'a', 'b'},
        v10 = {'g'},
        v11 = {'a', 'c', 'g'};
 
    cout<< "v6" << "\nincludes:\n";
    cout<<"v7" << ": " << includes(v6.begin(), v6.end(), v7.begin(), v7.end()) << '\n'  //prints 1
    << "v8" << ": " << includes(v6.begin(), v6.end(), v8.begin(), v8.end()) << '\n'     //prints 1
    << "v9" << ": " << includes(v6.begin(), v6.end(), v9.begin(), v9.end()) << '\n'     //prints 0
    << "v10" << ": " << includes(v6.begin(), v6.end(), v10.begin(), v10.end()) << '\n'  //prints 0
    << "v11" << ": " << includes(v6.begin(), v6.end(), v11.begin(), v11.end()) << '\n'; //prints 0

    //lower_bound - syntax(begin, end , value)
    //it returns the iterator to the first element greater than equal to the value
    vector<int> data {1, 2, 4, 5, 5, 6};
 
    for (int i = 0; i < 8; ++i)
    {
        // Search for first element x such that i ≤ x
        auto lower = lower_bound(data.begin(), data.end(), i);
 
        cout << i << " <= ";
        lower != data.end() ? cout << *lower << " at index " << lower - data.begin()
            : cout << "not found";
        cout << '\n';
    }

    //upper_bound - syntax(begin, end, value)
    //it returns the iterator to the first element greater than value
    vector<int> data2 {1, 2, 4, 5, 5, 6};
 
    for (int i = 0; i < 7; ++i)
    {
        // Search first element that is greater than i
        auto upper = upper_bound(data2.begin(), data2.end(), i);
 
        cout << i << " < ";
        upper != data2.end()
            ? cout << *upper << " at index " << upper - data2.begin()
            : cout << "not found";
        cout << '\n';
    }
}
int main() {
 //explainPair();
 //explainVector();
 //explainList();
 //explainDeque();
 //explainStack();
 //explainQueue();
 //explainPriority_queue();
 //explainSet();
 //explainMultiSet();
 //explainUSet();
 //explainMap();
 explainAlgorithms();
 
return 0;
}