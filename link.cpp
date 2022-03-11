#include<bits/stdc++.h>
using namespace std;
struct Node{
 int data ;
 Node *next;
 Node(int x)
 {
     data=x;
     next=NULL;
 }
 
};
//iterative aproach
void print(Node *head)
{
   while(head!=NULL)
   {
       cout<<head->data<<" ";
       head=head->next;
   } 
}
//recursive aproach
void recursive_print(Node *head)
{
    if(head==NULL)
    {
        return ;
    }
    cout<<head->data<<" ";
    recursive_print(head->next);
}
//insertion at begining 
Node *insert_begin(Node * &head,int x)
{
    Node *n1=new Node(x);
    n1->next=head;
    head=n1;
    return head;
    
}
//insertion at end
Node *insert_end(Node* &head,int y)
{
    Node *end=new Node(y);
    if(head==NULL)
    {
        head=end;
        return head;
    }
    while(head->next!=NULL)
    {
        head=head->next;
        

    }
    head->next=end;
    return head;
}
//delete a node from begining
Node *delete_begin(Node * &head)
{
 if(head==NULL)
 {
     return NULL;
 }
 else{
     Node *temp=head->next;
     delete head;
     head=temp;
     return head;
 }

}
int main()
{
    int x=13,y=9;
    Node *head=new Node(10);
    // insert_end(head,y);
    // insert_begin(head,x);
    // delete_begin(head);
    // recursive_print(head);
    print(head);
}