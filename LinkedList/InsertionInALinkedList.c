          //Insertion: 
//1.head
//2.position
//3.value
//4.last


               //INSERTION.
//Insert at head.
//Insert 5 at the start of the linked list.

//insert the value given at head
#include<bits/stdc++.h>
using namespace std;
class Node{
 public:
 int data;
 Node*next;

 public:
 Node(int data1, Node*next1){
   data=data1;
   next=next1;
 }

 public:
 Node(int data1){
   data=data1;
   next=nullptr;
 }
};

Node*convertArr2LL(vector<int>&arr){
   Node*head=new Node(arr[0]);
   Node*mover=head;
   for(int i=1;i<arr.size();i++){
      Node*temp=new Node(arr[i]);
      mover->next=temp;
      mover=temp;
   }
   return head;
}

void print(Node*head){
   while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
   }
   cout<<endl;
}

Node* insertHead(Node*head,int val){
   Node*temp=new Node(val,head);  //next is head..so pointing to head
   return temp;
}
int main(){
   vector<int>arr={12,8,5,7};
   Node*head=convertArr2LL(arr);
   head=insertHead(head,100);
   print(head);
   return 0;
}

//T.C:O(1)

//Insert at the last.


