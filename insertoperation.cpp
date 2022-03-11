#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
int sizeoflink(node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
// iterative approach
void print(node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// recursive approach
void recursive(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << "  ";
    recursive(head->next);
}
node *insertAtbegin(node *&head, int x)
{
    node *n1 = new node(x);
    n1->next = head;
    head = n1;
    return head;
}
node *insertAtend(node *&head, int y)
{
    node *end = new node(y);
    if (head == NULL)
    {
        head = end;
        return head;
    }
    node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = end;
    return head;
}

node *insertAtposition(node *&head, int pos, int z)
{
    node *insertnewnode = new node(z);
    if (pos == 1)
    {
        insertnewnode->next = head;
        head = insertnewnode;
        return head;
    }
    if (pos > sizeoflink(head) || pos < 0)
    {
        cout << "position is out of bound" << endl;
        return head;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    insertnewnode->next = temp->next;
    temp->next = insertnewnode;
    return head;
}
node *deleteAtpos(int position,node *&head){
    //deleting first or start node
    if(position==1)
    {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
     if (position > sizeoflink(head) || position < 0)
    {
        cout << "position is out of bound" << endl;
        return head;
    }
    //deleting last or middle 
    else{
        node *curr=head;
        node *prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
           curr=curr->next;
           cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

    int main()
{
    node *head = NULL;
    int size, value;
    int newnode;
    int position;
    cout << "enter the size of linked list " << endl;
    cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> value;
    //     insertAtbegin(head, value);
    // }
    cout << "enter the value of new nodes" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> newnode;
        insertAtend(head, newnode);
    }
    cout << "insert the position of  node to be deleted";

    cin >> position;
    // insertAtposition(head, pos, 1);
    deleteAtpos(position,head);
    recursive(head);
    // cout<<sizeoflink(head);
}
