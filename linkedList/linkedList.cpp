#include<bits/stdc++.h>

using namespace std;

class Node{
  public:
    int data;
    Node *next;
};

Node *head = NULL;

void print(){
  Node *ptr = head;
  while(ptr!= NULL){
    cout<<ptr->data<<"\t";
    ptr = ptr->next;
  }
  cout<<"\n";
}

void insertAtStart(){
  Node *ptr = new Node();
  cout<<"\n enter the data to be inserted";
  cin>>ptr->data;
  ptr->next = head;
  head = ptr;
}

void insertAtEnd(){
  Node *ptr = new Node();
  cout<<"\n enter the data to be inserted";
  cin>>ptr->data;

  Node *p = head;
  if(p==NULL){
    head = ptr;
    return;
  }
  while(p->next != NULL){
    p=p->next;
  }
  p->next = ptr;
}
void deleteAtStart(){
  if(!head){
    cout<<"Underflow";
    return;
  }

  Node * ptr = head;
  head = head->next;
  delete ptr;
}

void deleteAtEnd(){
  if(!head){
    cout<<"Underflow";
    return;
  }
  Node * ptr= head->next
  ,*prev=head;
  while(ptr!=NULL && ptr->next!=NULL){
      prev=ptr;
      ptr=ptr->next;
  }
  prev->next = NULL;
  delete ptr;

}

int main(){

  int n=1;
  while (n) {
    cout<<"Enter the choice of \n1. Insertion at start \n2. Insertion at end \n3. Deletion at start \n4. Deletion at end \n0 to exit\n";
    cin>>n;

    switch (n) {
      case 1:
        insertAtStart();
        print();
        break;
      case 2:
        insertAtEnd();
        print();
        break;
      case 3:
        deleteAtStart();
        print();
        break;
      case 4:
        deleteAtEnd();
        print();
        break;
      case 0:
        exit(0);
        break;
    }
  }

  return 0;
}
