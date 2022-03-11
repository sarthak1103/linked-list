#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
    // constructor
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    // cout << endl;
}
//length of linked list
int len(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
//insert node in begining 
Node *insertAtbegin(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;

    head->prev = temp;
    head = temp;
    return head;
}
//insert node in last
Node *insertAtend(Node *&head, int d)
{
    Node *end = new Node(d);
    if(head==NULL){
        head=end;
        return head;
    }
    Node *curr=head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    
    curr->next = end;
    end->prev = curr;
    return head;
}
//insert node in ith position 
Node *insertAtpos(Node *&head, int position, int d)
{
    Node *insertnewnode = new Node(d);
    if (head == NULL)
    {
        return NULL;
    }
    if (position == 1)
    {
        insertnewnode->next = head;
        head->prev = insertnewnode;
        head=insertnewnode;
        return head;
    }
    if (position > len(head) || position < 0)
    {
        cout << "aap ne postion aukaat se jyada daali hai" << endl;
        return head;
    }
    int cnt = 1;
    Node *curr=head;
    while (cnt <position-1 &&curr!=NULL)
    {
        curr=curr->next;
        cnt++;
        
    }
        Node *temp = curr;
        insertnewnode->next = temp->next;
        temp->next->prev = insertnewnode;
        temp->next = insertnewnode;
        insertnewnode->prev = temp;
    return head;
}
//delete node from begining 
Node *deleteAtbegin(Node *&head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    
    Node *curr=head;
    curr=curr->next;
    delete( curr->prev);
    head=curr;
    return head;
}
//deletion from end
Node *deleteAtend(Node *&head)
{
    if(head==NULL)
    {
        return NULL;

    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next->next!=NULL)
    {
        curr=curr->next; 
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}
//deletion at ith position
Node *deleteAtpos(Node *&head,int position)
{

   int cnt=1;
   Node *curr=head;
   while(cnt<position && curr->next!=NULL)
   {
       curr=curr->next;
       cnt++;
   }
   curr->next->prev=curr->prev;
   curr->prev->next=curr->next;
   delete(curr);
   return head;

}
int main()
{
    Node *head = NULL;
    int position;
    int size, newnode;
    // Node *node1 = new Node(10);
    // Node *head = node1;
    // Node *end = node1;

    cout << "enter the size of linked list" << endl;
    cin >> size;
    // print(head);
    // insertAtbegin(head, 5);
    // print(head);
    cout << "enter the values of linked list" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> newnode;
        insertAtend(head, newnode);
    }
    cout << "eneter the position where you want to delete  node" << endl;
    cin >> position;

    // // insertAtend(head, 15);
    // // print(head);
    // insertAtpos(head,position,20);
    //deleteAtbegin(head);
    // deleteAtend(head);
    // print(head);
    deleteAtpos(head,position);
    print(head);

    // insertAtbegin(head, 4);
    // print(head);
    // insertAtbegin(head, 3);
    // print(head);
    // cout<<len(head)<<endl;
}