#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* head = new Node();

void append(int value){
 Node* newNode = new Node{value,NULL};
 if(head==NULL){
    head=newNode;
 }
    Node* temp=head;
 while (temp->next != NULL)
 {
    temp=temp->next;
 }
 temp->next=newNode;
}

void insertatbeg(int value){
  Node* newNode = new Node{value, NULL};
    newNode->next = head;
    head = newNode;
}
void search(int value){
    Node* temp = head;
    while(temp != NULL){
        if(temp->data == value){
            cout << "Element found." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Element not found." << endl;
}
void deletenode(int value){
    if(head == NULL) return;

    if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL && temp->next->data != value){
        temp = temp->next;
    }

    if(temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}
void reverse(){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){
    append(10);
    append(20);
    append(30);

    display();

    insertatbeg(5);
    display();

    search(10);

    deletenode(10);
    display();

    reverse();
    display();

   return 0;
}