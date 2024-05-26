#include <bits/stdc++.h>
using namespace std;
class node{          //declaring the structure of the node
    public:
    int data;       //data part in the node 
    node* next;     //pointer pointing to the next node
    
    node(){}        
    node(int data){         //parametrized constructor for entering data at the time of declaration of node
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<endl<<"memory for node with data "<<value<<" is deleted."<<endl;
    }
};

void print_ll(node* &head){                  //function for printing all the nodes of the linked list
    cout<<endl<<"the current linked list is : "<<endl;
    node* temp = head;                          //putting the address of the head of the temporary node to traverse the linked list
    cout<<"head->";
    while(temp != NULL){                  //traversing the linked list until the last node
        cout<<temp->data<<"->";       //printing the data of the node
        temp = temp->next;           //moving to the next node
    }
    cout<<"tail";
}

void new_node_front(int data, node* &head, node* &tail){      //function for entering the node from front
if(head == NULL){                     //if the linked list is empty , enter the first node
    head = new node(data);
    tail = head;
    return;
}
node* temp = new node(data);        //make a new node with storing the data
temp->next = head;              //making the new node pointing to head
head = temp;            //then make the new node as head , and finally a new node is entered at front
print_ll(head);
}

void new_node_back(int data, node* &head, node* &tail){      //function for entering the node from back
    if(head == NULL){                           //if the linked list is empty, enter the first node
        head = new node(data);
        tail = head;
        return;
    }
    node* temp1 = tail;              //putting the address of the tail
    node* temp2 = new node(data);    //creating another temporary node and storing the data into it
    temp1->next = temp2;             //now putting the second temporary node to the last of the linked list
    tail = temp2;
}


void new_node_insert(node* &head, node* &tail){           //function to insert new node at any postition
    int pos,data;
    cout<<endl<<"enter the position : ";
    cin>>pos;
    cout<<"enter the data : ";
    cin>>data;
   if(pos==1) {
    new_node_front(data, head, tail);
    return;
   }
   node* temp1 = new node(data);          //creating new node and storing the data
   node* temp2 = head;                    //creating another temporary node and putting the address of the head into it to traverse the linked list
   for(int i=0; i<pos-2; i++){         //it goes to the node just before the position 'pos' 
    if(temp2->next==NULL){              //if the position is greater than the size of the linked list then, it stops
        cout<<"size exceeded"<<endl;
        return;
    }
    temp2 = temp2->next;
   }
   temp1->next = temp2->next;         //inserting the node to the correct position
   temp2->next = temp1;
   if(temp1->next==NULL) tail = temp1;   //updating the tail if the new node is the last node
   print_ll(head);
}


void delete_node(node* &head, node* &tail){                  //function to delete a node in the given position
    if(head == NULL) {
        cout<<"the linked list is empty"<<endl;
        return;
    }
    int pos;
    cout<<"enter the position to be deleted : ";
    cin>>pos;
    if(pos==1) {
        node* curr = head;
        head = head->next;  //removing the first node from the linked list
        
        curr->next = NULL;    //freeing up the memory 
        delete curr;
        print_ll(head);
        return;    
    }
    node* temp = head;
    for(int i=0; i<pos-2; i++){         //reaching to the node preceding to the pos
       if(temp->next == tail){
        cout<<"size exceeded";
        return;
       }
       temp = temp->next;
    }
    node* curr = temp->next;   //the 'curr' node has to be deleted
    temp->next = curr->next;       //deleting the node
    
    curr->next = NULL;
    delete curr;                  //freeing up the memory
    
    if(temp->next == NULL) tail = temp;   //updating tail if the deleted node is the last node
    print_ll(head);
}

void replace_node(node* &head){              //function to replace the data in the given position node of the linked list
    int pos,data;
    cout<<endl<<"enter the position : ";
    cin>>pos;
    cout<<"enter the data : ";
    cin>>data;
    node* temp = head;
    for(int i=0; i<pos-1; i++){               //reaching to the target node
        if(temp->next == NULL){
            cout<<"size exceeded ";
            return;
        }
        temp = temp->next;
    }
    temp->data = data;                   //replacing the data
    print_ll(head);
}

void reverse_ll(node* &head, node* &tail){ 
    if(head == NULL) {
        cout<<"the linked list is empty"<<endl;
        return;
    }
    node* before = NULL;
    node* curr = head;
    node* after = curr->next;
    if(after == NULL) {
        cout<<endl<<"reversed"<<endl;
        print_ll(head);
        return;
        }
    while(curr != NULL){
        curr->next = before;
        before = curr;
        curr = after;
        if(after != NULL) after = after->next;
    }
    tail = head;
    head = before;
    cout<<endl<<"reversed"<<endl;
    print_ll(head);
}
void reverse_s(node* &prev, node* &curr){
    //base condition
    if(prev == curr) return;

    //recurrence relation and processing
    node* check = curr->next;
    node* before = NULL;
    node* now = prev;
    node* after = now->next;
    while(now != check){
        now->next = before;
        before = now;
        now = after;
        if(after != check) after = after->next;
    }

    
}
node* kReverse(node* head, int k) {
    // Write your code here.
    if(head == NULL) {
        return head;
    }
    //recurrence relation and processing
    node* curr = head;
    node* prev = head;
    for(int i=0; i<k-1; i++){
        if(curr->next != NULL) curr = curr->next;
        else {
            return kReverse(prev, i+1);
        }
    }
    node* head1 = kReverse(curr->next,k);
    reverse_s(prev, curr);
    prev->next = head1;
    return curr;
}

bool isCircular(node* head){
    // Write your code here.

    //brute force method 

    //node* temp = head;
    //if(temp == NULL) return true;
    // map<node* , int> mp;

    // while(temp != NULL ){
    //     if(mp[temp] >= 1 && temp!= head) return false;
    //     else if(mp[temp] >= 1 && temp==head) return true;
    //     mp[temp]++;
    //     temp = temp->next;
    // }
    // return false;


    //optimised code 

    if(head == NULL) return true;
    node* slow = head;
    node* fast = head;
    while(1){
        slow = slow->next;
        if(fast->next != NULL) fast = fast->next->next;    //moving two nodes at a time, that's why fast 
        if(slow == NULL || fast == NULL) return false;     //if any one of the two pointers becomes null , then it is a linear linked list
        if(slow == fast && slow == head) return true;      //if its looping at the head , then slow and fast pointers both will meet at head always
        else if(slow == fast && slow != head) return false;   //if not meeting at head , then there's a loop , not a circular linked list
    }
}

node* looping_node(node* &head){
    
    //returning null means the linked list is either empty or circular or linear, but not looping
    if(head == NULL) return NULL;
    node* prev = NULL;
    node* slow = head;
    node* fast = head;
    while(1){
        slow = slow->next;
        if(fast->next != NULL) fast = fast->next->next;    //moving two nodes at a time, that's why fast 
        if(slow == NULL || fast == NULL) return NULL;     //if any one of the two pointers becomes null , then it is a linear linked list
        if(slow == fast && slow == head) return NULL;      //if its looping at the head , then slow and fast pointers both will meet at head always
        else if(slow == fast && slow != head) break;   //if not meeting at head , then there's a loop , not a circular linked list
    }
    //we have detected a loop , now to determine the starting node
    // the node where the slow and fast are equal for the first time , lets say that node as meet node .
    // now the distance between the meet node and starting node is equal to the distance between the head and the starting node
    // so if we traverse nodes one by one from meet node and head node , then we will intersect at the starting node only
    slow = head;
    while(1){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
        if(slow == fast ){
            prev->next = NULL;     //removing the loop in the linked list 
            return slow;
        }
    }
}


int main() {
node* head = NULL;
node* tail = NULL;
char ch= 'y';
vector<int> data{7,6,3,87,56,45,67};

for(int i=0; i<data.size(); i++){
    new_node_back(data[i],head, tail);
}
print_ll(head);
tail->next = head->next->next->next;
// while(1){
//   cout<<endl<<"want to enter new(n)/ delete(d)/ replace(r)/ reverse(v)/ exit(e) : ";
//   cin>>ch;
//   if(ch=='n') new_node_insert(head, tail);
//   else if(ch=='d') delete_node(head, tail);
//   else if(ch=='r') replace_node(head);
//   else if(ch=='v') reverse_ll(head, tail);
//   else break;
// }
bool state = isCircular(head);
cout<<endl<<state;
node* loop = looping_node(head);
if(loop == NULL) cout<<endl<<"there is no loop";
else {
    cout<<endl<<"the loop starts from : "<<loop->data;
}
print_ll(head);
return 0;
}