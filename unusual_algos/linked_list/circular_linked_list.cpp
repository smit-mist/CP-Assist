#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vl vector<ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define clr(x) memset(x, 0, sizeof(x)) 
#define mll map<ll,ll>
#define mod 1000000007
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head,int val)
{
    node* n = new node(val);
    node* temp=head;
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* todelete=head;
    head=temp->next->next;
    temp->next=head;
    delete todelete;

}
void deletion(node* &head,int pos){
    node* temp=head;
    int count =1;
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    while(count!=pos-1){
        temp=temp->next;
        count++;

    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void display(node* head)
{
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    
   
    cout<<endl;
}
int main()
{
//   freopen('input.txt', 'r', stdin);
//   freopen('output.txt', 'w', stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,6);
    display(head);
    deletion(head,2);
    display(head);
   return 0;
}
