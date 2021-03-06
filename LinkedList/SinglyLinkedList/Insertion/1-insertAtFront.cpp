#include <bits/stdc++.h>

using namespace std;
// Type Declaration
struct Node {
  int data;
  Node *next;
};

void traverse(Node *head) {
	Node *current_node = head;

	while(current_node != NULL) {
		cout << current_node -> data << endl;
		current_node = current_node -> next;
	}
}
/*
  To insert a node at front of the list :
  - Create a new node
  - Make the new node point the head of list
  - Update head pointer to point the new node
*/
// Let's make a function that takes 'head' and 'data' as arguments. Since we need to modify the head after we have connected our 'newNode'
// to our list we need to pass double pointer for 'head'.

void insertAtFront(Node **head, int data) {
  Node *newNode, *current_node;
  
  newNode = new Node();
  newNode -> data = data; // Insert data into 'newNode'
  newNode -> next = *head; // Tell 'newNode' to point to current head
  
  // Update head pointer to point to 'newNode'  
  *head = newNode;
  
  // traverse the list
  traverse(*head);
}

int main() {
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
  // Pass reference of head
  insertAtFront(&head, 0);
  
}
