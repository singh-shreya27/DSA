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
//insert the value given at tail.
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

//whenever we see that temp->next=NULL , we will stop.
Node*insertTail(Node*head, int val){
   if(head==NULL){
      return new Node(val);  //single element is created
   }
   //what if it has ..take a temp
   Node*temp=head;
   while(temp->next!=NULL){
      temp=temp->next;
   }
   Node* newNode= new Node(val); //pointimg to null 
   temp->next=newNode;
   return head;
}
int main(){
   vector<int>arr={12,8,5,7};
   Node*head=convertArr2LL(arr);
   head=insertTail(head,100);
   print(head);
   return 0;
}

//insert the value(el) given at kth element.
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

Node*insertPosition(Node*head, int el, int k){
   if(head==NULL){
      if(k==1)  return new Node(el);
      else  return head;   
   }
   if(k==1){
      Node*newHead= new Node(el, head); //pointing to head
      return newHead;
   }
  int cnt=0;
  Node*temp=head;
  while(temp!=NULL){
   cnt++;
   if(cnt==k-1){
     Node*x=new Node(el);
     x->next=temp->next;
     temp->next=x;
     break;
   }
   temp=temp->next;
  }
  return head;
}

int main(){
   vector<int>arr={12,8,5,7};
   Node*head=convertArr2LL(arr);
   head=insertPosition(head,100,2);
   print(head);
   return 0;
}

//Insert el before x.
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

Node*insertBeforeValue(Node*head, int el, int val){
   if(head==NULL){
     return NULL;
   }
   if(head->data==val){
      return new Node(el,head);
   }
  Node*temp=head;
  while(temp->next!=NULL){
   if(temp->next->data==val){
     Node*x=new Node(el);
     x->next=temp->next;
     temp->next=x;
     break;
   }
   temp=temp->next;
  }
  return head;
}

int main(){
   vector<int>arr={12,8,5,7};
   Node*head=convertArr2LL(arr);
   head=insertBeforeValue(head,100,12);
   print(head);
   return 0;
}






