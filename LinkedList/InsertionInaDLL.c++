         //Insertion:
//1. Head(before)
//2.Before Tail                      //ALL BEFORE QUESTION HERE
//3.Before Kth node            
//4.Before given node.

//INSERT BEFORE THE HEAD OF THE DLL.
#include<bits/stdc++.h>
using namespace std;
class Node{
       public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1,Node*next1, Node*back1){
          data=data1;
          next=next1;
          back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
  }
};
  Node* convertArr2DLL(vector<int>&arr){
  Node*head= new Node(arr[0]);
  Node*prev=head;
  for(int i=1;i<arr.size();i++){
    Node*temp=new Node(arr[i],nullptr, prev);
    prev->next=temp;
    prev=temp;
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
Node*insertBeforeHead(Node*head, int val){
  Node*newHead=new Node(val, head, nullptr);
  head->back= newHead;

  return newHead;
}
int main(){
      vector<int>arr={12,8,5,7};
      Node*head=convertArr2DLL(arr);
      head=insertBeforeHead(head,10);
      print(head);
    return 0;
}

                 //INSERT BEFORE THE TAIL OF DLL
#include<bits/stdc++.h>
using namespace std;
class Node{
       public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1,Node*next1, Node*back1){
          data=data1;
          next=next1;
          back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
  }
};
  Node* convertArr2DLL(vector<int>&arr){
  Node*head= new Node(arr[0]);
  Node*prev=head;
  for(int i=1;i<arr.size();i++){
    Node*temp=new Node(arr[i],nullptr, prev);
    prev->next=temp;
    prev=temp;
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
Node*insertBeforeHead(Node*head, int val){
  Node*newHead=new Node(val, head, nullptr);
  head->back= newHead;

  return newHead;
}
Node*insertBeforeTail(Node*head, int val){
  //single element
  if(head->next==NULL){
    return insertBeforeHead(head,val);
  }
  Node*tail=head;
  while(tail->next!=NULL){
    tail=tail->next;
  }

  Node*prev=tail->back;
  Node*newNode= new Node(val, tail, prev);
  prev->next=newNode;
  tail->back=newNode;
  return head;
}
int main(){
      vector<int>arr={12,8,5,7};
      Node*head=convertArr2DLL(arr);
      head=insertBeforeTail(head,10);
      print(head);
    return 0;
}

                                //INSERT BEFORE Kth NODE OF DLL
#include<bits/stdc++.h>
using namespace std;
class Node{
       public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1,Node*next1, Node*back1){
          data=data1;
          next=next1;
          back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
  }
};
  Node* convertArr2DLL(vector<int>&arr){
  Node*head= new Node(arr[0]);
  Node*prev=head;
  for(int i=1;i<arr.size();i++){
    Node*temp=new Node(arr[i],nullptr, prev);
    prev->next=temp;
    prev=temp;
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
Node*insertBeforeHead(Node*head, int val){
  Node*newHead=new Node(val, head, nullptr);
  head->back= newHead;

  return newHead;
}
Node*insertBeforeTail(Node*head, int val){
  //single element
  if(head->next==NULL){
    return insertBeforeHead(head,val);
  }
  Node*tail=head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
}
//first go to kth node
Node* insertBeforeKthElement(Node*head, int k,int val){
    if(k==1){
      return insertBeforeHead(head,val);
    }
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
      cnt++;
      if(cnt==k) break;
      temp=temp->next;
    }
    Node*prev=temp->back;
    Node* newNode= new Node(val, temp, prev);
    prev->next=newNode;
    temp->back= newNode;
    return head;
}
int main(){
      vector<int>arr={12,8,5,7};
      Node*head=convertArr2DLL(arr);
      head=insertBeforeKthElement(head,4,10);
      print(head);
    return 0;
}


//INSERT BEFORE A GIVEN NODE(NODE!=HEAD)
#include<bits/stdc++.h>
using namespace std;
class Node{
       public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1,Node*next1, Node*back1){
          data=data1;
          next=next1;
          back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
  }
};
  Node* convertArr2DLL(vector<int>&arr){
  Node*head= new Node(arr[0]);
  Node*prev=head;
  for(int i=1;i<arr.size();i++){
    Node*temp=new Node(arr[i],nullptr, prev);
    prev->next=temp;
    prev=temp;
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
 void insertBeforeNode(Node*node, int val){
  Node*prev=node->back;
  Node* newNode= new Node(val, node, prev);
  prev->next=newNode;
  node->back=newNode;
 }

int main(){
    vector<int>arr={12,8,5,7};
      Node*head=convertArr2DLL(arr);
      insertBeforeNode(head->next->next,100);
      print(head);
  return 0;
}
