#include<iostream.h>
using namespace std;

class Node {
  int data;
  Node *next;
}

Node * top = NULL;

int push(int n){

  Node * ptr = new Node();
  if(!ptr){
    cout<<"Stack overflow";
    return 0;
  }

  ptr->data = n;
  ptr->next = NULL;
  top = ptr;
}

int pop(){

  if(!top){
    cout<<"Stack Underflow";
    return 0;
  }

  Node * ptr = top;
  top = top->next;
  delete ptr;

}

int get top(){
  cout<<top->data;
  return 0;
}

int main(){




  return 0;
}
