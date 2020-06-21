// C++ program to delete a given node
// in linked list under given constraints
#include <bits/stdc++.h>
using namespace std;

/* structure of a linked list node */
class Node
{
public:
	int data;
	Node *next;
};

void deleteNode(Node *head, Node *n)
{	
	if(!head)
		return;

	Node * ptr = head;
	Node * temp;
	
	// find the given node
	while(ptr && ptr != n){
		ptr = ptr->next;
	}

	// move the data in the nodes
	while(ptr->next){
		ptr->data = ptr->next->data;
		temp = ptr;
		ptr = ptr->next;
	}

	temp->next = NULL;
	//delete the last node
	delete ptr;
	return;
}

/* Utility function to insert a node at the beginning */
void push(Node **head_ref, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

/* Utility function to print a linked list */
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


bool checkListPalindrome(Node *P){

	if(!P) return true;

	stack<int> S;
	Node * s = P, *f = P;
	while(f && f->next){
		f=f->next->next;
		S.push(s->data);
		s= s->next;
	}

	if(f)
		s = s->next;
	
	while(s){
		if(S.top() != s->data)
			return false;
		S.pop();
		s= s->next;
	}
	return true;
}

/* Driver code */
int main()
{
	Node *head = NULL;

	/* Create following linked list 
	12->15->10->11->5->6->2->3 */
	push(&head, 3);
	push(&head, 2);
	push(&head, 6);
	push(&head, 5);
	push(&head, 9);
	push(&head, 5);
	push(&head, 6);
	push(&head, 2);
	push(&head, 3);

	cout << "Given Linked List: ";
	printList(head);

	cout<<" check palindrome "<<checkListPalindrome(head);

	// /* Let us delete the node with value 10 */
	// cout << "\nDeleting node " << head->next->next->data << " ";
	// deleteNode(head, head);

	// cout << "\nModified Linked List: ";
	// printList(head);

	// /* Let us delete the first node */
	// cout << "\nDeleting first node ";
	// deleteNode(head, head);

	// cout << "\nModified Linked List: ";
	// printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
