//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *uniqueSortedList(Node *head) {
  // Write your code here.
  if (head == NULL) {
    return NULL;
  }
  Node *curr = head;
  while (curr->next!= NULL) {
    if ((curr->data == curr->next->data) ) {
      Node *next_next = curr->next->next;
      Node *temp = curr->next;
      delete temp;
      curr->next = next_next;

    } else {
      curr = curr->next;
    }
  }
  return head;
}
Node *removeDuplicates(Node *head)
{
 return uniqueSortedList(head);
}