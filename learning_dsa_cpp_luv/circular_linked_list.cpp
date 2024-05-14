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

void print_ll(node* &tail){                  //function for printing all the nodes of the linked list
    cout<<endl<<"the current linked list is : "<<endl;
    node* temp = tail->next;                          //putting the address of the head of the temporary node to traverse the linked list
    cout<<"head->";
    while(temp != tail){                  //traversing the linked list until the last node
        cout<<temp->data<<"->";       //printing the data of the node
        temp = temp->next;           //moving to the next node
    }
    cout<<temp->data<<"->";
    cout<<"tail";
}

void new_node_front(int data, node* &tail){      //function for entering the node from front
if(tail == NULL){                     //if the linked list is empty , enter the first node
    tail = new node(data);
    tail->next = tail;
    return;
}
node* temp = new node(data);        //make a new node with storing the data
temp->next = tail->next;              //making the new node pointing to head
tail->next = temp;            //then make the tail point to the temp , and finally a new node is entered at front
print_ll(tail);
}

void new_node_back(int data, node* &tail){      //function for entering the node from back
    if(tail == NULL){                           //if the linked list is empty, enter the first node
        tail = new node(data);
        tail->next = tail;
        return;
    }
    node* temp1 = tail;              //putting the address of the tail
    node* head = tail->next;
    node* temp2 = new node(data);    //creating another temporary node and storing the data into it
    temp1->next = temp2;             //now putting the second temporary node to the last of the linked list
    temp2->next = head;
    tail = temp2;
}


void new_node_insert(node* &tail){           //function to insert new node at any postition
    int pos,data;
    cout<<endl<<"enter the position : ";
    cin>>pos;
    cout<<"enter the data : ";
    cin>>data;
   if(pos==1) {
    new_node_front(data, tail);
    return;
   }
   node* temp1 = new node(data);          //creating new node and storing the data
   node* temp2 = tail;                    //creating another temporary node and putting the address of the head into it to traverse the linked list
   for(int i=0; i<pos-1; i++){         //it goes to the node just before the position 'pos' 
    if(temp2->next== tail && i != pos-2){            //if the position is greater than the size of the linked list then, it stops
        cout<<"size exceeded"<<endl;
        return;
    }
    temp2 = temp2->next;
   }
   temp1->next = temp2->next;         //inserting the node to the correct position
   temp2->next = temp1;
   if(tail->next== temp1) tail = temp1;   //updating the tail if the new node is the last node
   print_ll(tail);
}


void delete_node(node* &tail){                  //function to delete a node in the given position
    int pos;
    cout<<"enter the position to be deleted : ";
    cin>>pos;
    if(pos==1) {
        node* curr = tail->next;
        tail->next = tail->next->next;  //removing the first node from the linked list
        
        curr->next = NULL;    //freeing up the memory 
        delete curr;
        print_ll(tail);
        return;    
    }
    node* temp = tail;
    node* head = tail->next;
    for(int i=0; i<pos-1; i++){         //reaching to the node preceding to the pos
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
    
    if(temp->next == head) tail = temp;   //updating tail if the deleted node is the last node
    print_ll(tail);
}

void replace_node(node* &tail){              //function to replace the data in the given position node of the linked list
    int pos,data,count=0;
    cout<<endl<<"enter the position : ";
    cin>>pos;
    cout<<"enter the data : ";
    cin>>data;
    node* temp = tail;
    for(int i=0; i<pos; i++){               //reaching to the target node
        if(temp == tail && count==1){
            cout<<"size exceeded";
            return;
        }
        temp = temp->next;
        count=1;
    }
    temp->data = data;                   //replacing the data
    print_ll(tail);
}

int main() {
node* tail = NULL;
char ch= 'y';
vector<int> data{7,6,3};

for(int i=0; i<data.size(); i++){
    new_node_back(data[i], tail);
}
print_ll(tail);
while(1){
  cout<<endl<<"want to enter new(n)/ delete(d)/ replace(r)/ exit(e) : ";
  cin>>ch;
  if(ch=='n') new_node_insert(tail);
  else if(ch=='d') delete_node(tail);
  else if(ch=='r') replace_node(tail);
  else break;
}
return 0;
}