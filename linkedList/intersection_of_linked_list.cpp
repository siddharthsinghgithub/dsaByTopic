#include<iostream>

using namespace std;

class Node{
  public:
    int data;
    Node * next;
}

int insert(int data, Node *head1, Node *head2 = NULL){

  Node *ptr = new Node();
  ptr->data = data;
  ptr->next = head;
  head = ptr;

  cout<<"inserted"<<data<<"\n";

  return ptr;
}

int main(){
  Node * head1 = NULL;

  insert(&head1, 1);
  insert(&head1, 2);
  insert(&head1, 3);

  Node * head2 = NULL;

  insert(&head2, 5);
  insert(&head2, 6);


  Node * head3 = NULL;

  insert(&head3, 7);
  insert(&head3, 8);
  insert(&head3, 9);

}
