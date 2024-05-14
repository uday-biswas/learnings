#include <bits/stdc++.h>
using namespace std;
class node{          //declaring the structure of the node
    public:
    int data;       //data part in the node 
    node* next;     //pointer pointing to the next node
    node* prev;     //pointer pointing to the previous node
    
    node(){}        
    node(int data){         //parametrized constructor for entering data at the time of declaration of node
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void print_ll_reverse(node* &tail){
    cout<<endl<<"the reverse linked list is : "<<endl;
    node* temp = tail;
    cout<<"tail->";
    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->prev;
    }
    cout<<"head";
}

void new_node_front(int data, node* &head, node* &tail){      //function for entering the node from front
if(head == NULL){                     //if the linked list is empty , enter the first node
    head = new node(data);
    tail = head;
    return;
}
node* temp = new node(data);        //make a new node with storing the data
temp->next = head;              //making the new node pointing to head
head->prev = temp;              //updating the prev pointer

head = temp;            //then make the new node as head , and finally a new node is entered at front
print_ll(head);
}

void new_node_back(int data, node* &head, node* &tail){      //function for entering the node from back
    if(head == NULL){                           //if the linked list is empty, enter the first node
        head = new node(data);
        tail = head;
        return;
    }
    node* temp2 = new node(data);    //creating another temporary node and storing the data into it
    tail->next = temp2;             //now putting the second temporary node to the last of the linked list
    temp2->prev = tail;
    
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
   if(temp2->next != NULL){
   temp1->next = temp2->next;         //inserting the node to the correct position
   temp2->next->prev = temp1;
   }
   temp2->next = temp1;
   temp1->prev = temp2;
   if(temp1->next==NULL) tail = temp1;   //updating the tail if the new node is the last node
   print_ll(head);
}


void delete_node(node* &head, node* &tail){                  //function to delete a node in the given position
    int pos;
    cout<<"enter the position to be deleted : ";
    cin>>pos;
    if(pos==1) {
        node* curr = head;
        head = head->next;  //removing the first node from the linked list
        
        curr->next = NULL;    //freeing up the memory 
        head->prev = NULL;
        delete curr;
        print_ll(head);
        return;    
    }
    node* temp = head;
    for(int i=0; i<pos-2; i++){         //reaching to the node preceding to the pos
       if(temp->next->next==NULL){
        cout<<"enter position within bound";
        return;
       }
       temp = temp->next;
    }
    node* curr = temp->next;   //the 'curr' node has to be deleted
    temp->next = curr->next;       //removing the node

    if(curr->next != NULL){
    curr->next->prev = temp;
    curr->next = NULL;
    }

    curr->prev = NULL;
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
        if(temp->next==NULL){
        cout<<"enter position within bound";
        return;
       }
        temp = temp->next;
    }
    temp->data = data;                   //replacing the data
    print_ll(head); 
}

int main() {
node* head = NULL;
node* tail = NULL;
char ch= 'y';
vector<int> data{7,6,3};

for(int i=0; i<data.size(); i++){
    new_node_back(data[i],head, tail);
}
print_ll(head);
while(1){
  cout<<endl<<"want to enter new(n)/ delete(d)/ replace(r)/ exit(e) : ";
  cin>>ch;
  if(ch=='n') new_node_insert(head, tail);
  else if(ch=='d') delete_node(head, tail);
  else if(ch=='r') replace_node(head);
  else break;
}
print_ll_reverse(tail);
return 0;
}