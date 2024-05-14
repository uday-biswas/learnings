#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};
Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	Node* temp = head;
	while(temp != NULL){
		Node* after = temp->next;
		while(temp->child != NULL){
			temp->next = temp->child;
			temp = temp->child;
		}
		temp->next = after;
		temp = after;
	}
	return head;
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
int main() {
Node* head = NULL;
Node* tail = NULL;
vector<int> data{1,4,7,9,20};

for(int i=0; i<data.size(); i++){
    new_node_back(data[i],head, tail);
}
head->child = new Node(2);
head->child->child = new Node(3);
head->next->child = new Node(5);
head = flattenLinkedList(head);
while(head != NULL){
    cout<<head->data<<" ";
    head = head->next;
}
return 0;
}