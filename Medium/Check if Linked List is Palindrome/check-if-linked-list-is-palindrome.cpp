//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    private:
    Node *getMiddle(Node *head) {//finding the middle of the linked list 
  Node *slow = head;
  Node *fast = head->next;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}
Node* reverse(Node* head1) {  //reversing linked list from middle->next
  if (head1->next == NULL || head1 == NULL) {
    return head1;
  }
  Node *prev = NULL;
  Node *curr = head1;
  Node *next = NULL;
  while (curr != NULL) {
  next=curr->next;
  curr->next=prev;
  prev=curr;
  curr=next;
  }
  return prev;
}

  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
         if (head->next == NULL) 
  {
    return true;
  }
  Node *temp1 = head;
  Node *middle = getMiddle(head);
  Node *temp2 = reverse(middle->next);
  while(temp2!=NULL)
  {
    if(temp1->data==temp2->data){
      temp1=temp1->next;
      temp2=temp2->next;
    }
    else{
      return false;
    }
  }
  return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends