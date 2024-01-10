#include <bits/stdc++.h>
using namespace std;
struct Node  {
    int data;
    Node* next;
    Node* arb;
    Node(int x){
       data = x;
       next = NULL;
       arb = NULL;
    }
};

void print_ll(Node* &head){                  //function for printing all the nodes of the linked list
    cout<<endl<<"the current linked list is : "<<endl;
    Node* temp = head;                          //putting the address of the head of the temporary node to traverse the linked list
    cout<<"head->";
    while(temp != NULL){                  //traversing the linked list until the last node
        cout<<temp->data<<"->";       //printing the data of the node
        temp = temp->next;           //moving to the next node
    }
    cout<<"tail";
    temp = head;
    cout<<endl<<"random : ";
    while(temp != NULL){
       if(temp->arb != NULL) cout<<temp->data<<"->"<<temp->arb->data<<" ";
       temp = temp->next;
    }
}

void new_node_back(int data, Node* &head, Node* &tail){      //function for entering the node from back
    if(head == NULL){                           //if the linked list is empty, enter the first node
        head = new Node(data);
        tail = head;
        return;
    }
    Node* temp1 = tail;              //putting the address of the tail
    Node* temp2 = new Node(data);    //creating another temporary node and storing the data into it
    temp1->next = temp2;             //now putting the second temporary node to the last of the linked list
    tail = temp2;
}
    void push_backe(Node* &head, Node* &tail, Node* temp){
        if(head == NULL){
            head = temp;
            tail = head;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* chead = NULL;
        Node* ctail = NULL;
        Node* temp = head;
        map<Node*, Node*> mp;
        while(temp != NULL){
            Node* ctemp = new Node(temp->data);
            mp[temp] = ctemp;
            push_backe(chead, ctail, ctemp);
            temp = temp->next;
        }
        mp[NULL] = NULL;
        temp = head;
        Node* temp2 = chead;
        while(temp != NULL){
            temp2->arb = mp[temp->arb];
            temp2 = temp2->next;
            temp = temp->next;
        }
        return chead;
    }
int main() {
    Node* head = NULL;
    Node* tail = NULL;
vector<int> data{1,2,3,4};

for(int i=0; i<data.size(); i++){
    new_node_back(data[i],head, tail);
}
head->arb = head->next->next;
head->next->arb = head;
print_ll(head);
Node* chead = copyList(head);
print_ll(chead);
return 0;
}