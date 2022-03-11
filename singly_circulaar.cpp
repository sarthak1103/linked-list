#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *next;
    //constructure 
    node(int d){
        data=d;
        next=NULL;
    }
};
//insertion in circular
node  *insertNode(node *&tail,int element ,int d )
{
    //empty list
    //assuming that element is present in the list
    if(tail==NULL)
    {
        node *newNode =new node(d);
        tail=newNode;
        newNode->next=newNode;
        return tail;
    }
    else{
        //non empty list
        //assuming that element is present in the list
        node *curr=tail;
        while(curr->data!=element)
        {
            curr=curr->next;
        }
        //element found 
        node *temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;
        
    }
    return tail;
}
node *deletenodes(node *&tail, int value)
{
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return NULL;
    }

    else {
        //non-empty
        node *prev=tail;
        node *curr=prev->next;
        while(curr->data!=value)
        {
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //for deletion of 1 node link list
        
        if(tail==curr)
        {
            tail=prev;
        }
        else if(curr=prev)
        {
           tail=NULL;
        }
        curr->next=NULL;
        delete curr;


    }
    return tail;
}
void print(node *tail)
{
    node *temp=tail;
    if(tail==NULL)
    {
        cout<<"list is empty"<<endl;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}
int main()
{
    node *tail= NULL;
    //inserting in empty node
    insertNode(tail,5,1);
    
    insertNode(tail,1,2);
    
    insertNode(tail,2,3);
    
    insertNode(tail,3,4);
    
    insertNode(tail,4,5);
    //print(tail);
    deletenodes(tail,1);
    print(tail);
}

