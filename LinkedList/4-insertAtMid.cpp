#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

/*
	Let's assume that we have the position where we want to insert the node. Now, follow the steps given below
	- Make a new node
	- then, we have to traverse the list until we reach the node that has reference to the node at given position
	  e.g. If we are inserting at position 3 then we need to go to position 2 first
	- Connect the new node to the node at position 3 by using next of node at position 2.
	- Disconnect the node 2 from the older node at position 3 and connect it to new node 
	- we have successfully inserted our node :)
*/

void insertAtMid(Node **head, int position, int data) {
	Node *newNode, *current_node;
	// Variable to keep a track of position	
	int i = 1; 
	
	newNode = new Node();
	newNode -> data = data;
	newNode -> next = NULL;
	// keep a track of current node
	current_node = *head;

	// Traverse the list until the position is reached
	while((current_node != NULL) && (i < position))  {
		i++;
		
		if(i == position) {
			// connect new node to the node at 'position'
			newNode -> next = current_node -> next;
			// connect the current node to new node
			current_node -> next = newNode;
		}
		
		current_node = current_node -> next;
		
	}
	// Point to head again	
	current_node = *head;
	// Travese and print the list	
	while(current_node != NULL) {
		cout << current_node -> data << endl;
		current_node = current_node -> next;
	}
}

int main()
{
	Node *head, *second, *end;
  
	head = new Node();
	second = new Node();
	end = new Node();

	head -> data = 1;
	head -> next = second;

	second -> data = 2;
	second -> next = end;

	end -> data = 3;
	end -> next = NULL;

	insertAtMid(&head, 3, 25);

	return 0;
}
