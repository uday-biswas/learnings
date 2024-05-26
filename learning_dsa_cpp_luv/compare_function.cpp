#include <bits/stdc++.h>
using namespace std;
bool compare1(int a, int b){       //compare1 for sorting the elements in decreasing order.
    return a>b;
}
class student{
    public:
    string name;
    int roll;
    int marks;
    student(string name, int roll, int marks){
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};
bool compare2(student obj1, student obj2){     //compare2 for sorting the students class objects based on their marks in decreasing order
    return (obj1.marks > obj2.marks);
}
class compare{                                //class compare for the priority queue to store the student objects decreasing order of their marks
  public:                                     // and if any two students have same marks , then it will sort according to their roll in increasing order
    bool operator()(student obj1, student obj2){      //syntax is very strict
       if(obj1.marks < obj2.marks) return true;
       else if(obj1.marks == obj2.marks){
          if(obj1.roll > obj2.roll) return true;
          else return false;
       }
       else return false;
    }
};
int main() {
  vector<int> arr1{8,34,9,2,98};
  vector<student> arr2{student("uday",45,98), student("amlan",69,23)};
  sort(arr1.begin(), arr1.end(), compare1);
  sort(arr2.begin(),arr2.end(),compare2);
  for(int i=0; i<arr2.size(); i++){
    cout<<arr2[i].name<<" ";
  }
  cout<<endl;

  cout<<endl<<"roll "<<"name "<<"marks"<<endl;
  priority_queue<student, vector<student>, compare> pq;
  pq.push(student("uday",45,98));
  pq.push(student("amlan",69,34));
  pq.push(student("isan",23,95));
  pq.push(student("aman",67,98));
  pq.push(student("ankit",56,98));
  int n = pq.size();
  while(!pq.empty()){
     cout<<pq.top().roll<<" "<<pq.top().name<<" "<<pq.top().marks<<endl;
     pq.pop();
  }
return 0;
}