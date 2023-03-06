//{ Driver Code Starts
//

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

// } Driver Code Ends
/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // a node is creatd using Dyanamic memory allocation 
        Node* temp=new Node(data);
        
        // only one node  is here 
        if(head->next==NULL)
        { if(temp->data<=head->data)
             {
              temp->next=head;
             head=temp;
             return head;
             }
          if(temp->data>=head->data)
          {
              head->next=temp;
              temp->next=NULL;
              return head;
          }
        
            
        }
        
        if(temp->data <= head->data) //agar element is less than head ->data 
        {
            temp->next=head;
            head=temp;
            return head;
        }
        
        // if element is greater than the last element
        Node*pointer=head;
        while(pointer->next!=NULL)
        {
            pointer =pointer ->next;
        }
        
        if(temp->data>= pointer->data)
        {
            pointer ->next=temp;
            temp->next=NULL;
            return head;
        }
        
        
        //Insert Between the two numbers 
        Node*prev=head;
        Node*curr=head->next;
        while(curr!=NULL)
        {
             if(temp->data <= curr->data && temp->data > prev->data )
             {
                temp->next=curr;
                prev->next=temp;
                return head;
             }
            
            prev=curr;
            curr=curr->next;
        }
        
        
       
       
    }
};


//{ Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 

// } Driver Code Ends