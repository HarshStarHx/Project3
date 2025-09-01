
#include<iostream>
#include<iomanip>
#include<stack>
#include<tuple>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Node 
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int val):data(val) , next(NULL) , prev(NULL)
    {}
};
class doubly_linked_list{
Node*head ;
Node*tail;
public:
doubly_linked_list():head(nullptr) , tail(nullptr){}
void push_front(int val)
{
    Node*newNode = new Node(val);
    if(head==NULL)
    {
        head=tail=newNode;
    }
    else  
    {
newNode->next = head;
head->prev = newNode;
head= newNode;

    }
    
}
void printdll()
{
    Node*temp = head;
    cout<<"<-Head<=>";
    while(temp!=nullptr)
    {
        cout<< temp->data<<"<=>";
        temp=temp->next;
        
    }
    cout<<"Tail<=>"<<"Nullptr";
}
void push_back(int val)
{
    Node*newNode = new Node(val);
    if(head==NULL)
    {
        head= tail = newNode;
    }
    else   
    {
         newNode->prev = tail;
        tail->next = newNode;
       
        tail = newNode;
    }
}
void pop_front()
{
    if(head==NULL)
    {  
        return ;
    }
    Node*temp = head;

    head = head->next;
    if(head!=NULL)
    {
        head->prev =NULL;
    }
    delete temp;
}
// void pop_back()
// {
//     if(head==NULL)
//     {
//     head->prev =NULL;
//     }
//     Node*temp = head;
//     while(temp!=tail)
//     {
//         temp = temp->next;
//     }
//     temp->next = NULL;
//     if(tail!=nullptr)
//     {
//         tail->prev = NULL;
//     }
//     delete tail;
//     tail = temp;
// }
void pop_back()
{
    if(tail==NULL)return ;
    Node*temp = tail;
    if(head==tail)
    {
        head=tail = NULL;
    }
    else  
    {
        tail = tail->prev;
        tail->next = NULL;
    }
}
void insert(int pos , int val)
{
    if(pos<0)
    {
        return ;
    }
    if(pos==0)
    {
        push_front(val);
        return;
    }
    Node*temp=head;
    Node*newNode= new Node(val);
    int i =0  ;
    while(i<(pos-1)&&(temp!=NULL))
    {
        temp = temp->next;
        i++;
    }
    if(temp==NULL)return ;
    newNode->next= temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    if(newNode->next==NULL)
    {
        tail = newNode;
    }

}
int search(int val)
{
    int Ind=0;
    Node*temp =head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
           
            return Ind;
        }
        Ind++;
        temp = temp->next;
    }
    return -1;
}
void deletebyval(int val)
{
 if(head==NULL)
{
     return ;
}   
Node*temp = head;
while(temp!=NULL)
{
if(temp->data==val)
{
temp->prev->next = temp->next;
delete temp;
break;
}
temp = temp->next;
}
}
};
int main()
{

doubly_linked_list ll;

for(auto i =0; i<6 ; i++)
{
    int x ;
    cin>>x;
    ll.push_back(x);
    ll.push_front(x);

}
ll.pop_front();
ll.pop_front();
ll.pop_front();
ll.pop_front();
ll.pop_front();
ll.pop_back();
ll.insert(0 , 3999);
ll.deletebyval(3);
cout<<"\n";
cout<<"index=="<<ll.search(3)<<endl;
//this is not good my boy 
//want to become waht is this okay to you
ll.printdll();
//this is not fare
//this is now fine by me
return 0;
// this is new in the rebase 
}
