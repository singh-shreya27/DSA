                  //Deletion: 
//1.head
//2.position
//3.value
//4.last


                          //DELETION OF HEAD:

//write function which will be returning the new head 
Node*deleteHead(Node*head){
   Node*temp=head;     //keep temp as head
   head=head->next;    //move head to next  but temp( pehle wala head) is still there 
   free(temp);   //or delete(temp);
  return head;  
}

//Complete code
#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* next;
   //constructor
   public:
   Node(int data1, Node* next1){
     data=data1;
     next=next1;
   }
   //multiple constructor
   public:
   Node(int data1){
    data=data1;
    next=nullptr;
   }
};
Node* convertArr2LL(vector<int>&arr){
   Node* head= new Node(arr[0]);
   Node*mover=head;
   for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    mover->next=temp;
    mover=temp;
   }
   return head;
}
//function to print LL
void print(Node*head){
    while(head !=NULL){
        cout<< head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node*removesHead(Node* head){
    //edge case
    if(head== NULL) return head;  //empty LL 
    Node* temp=head;  //take temp=head
    head=head->next;
    delete temp;
    return head;
}

int main(){  
    vector<int> arr={12,5,8,7};
    Node*head = convertArr2LL(arr);
    // cout<<head->data;
    head= removesHead(head);
    print(head);
    return 0;
}

//delete tail of LL:
Node* deleteTail(Node* head){
    if(head==null || head->next==null){
       //either LL empty or has only one element
      return null;
    }
  //when LL has 2 elements
  Node*temp=head;
  while(temp->next->next!=null){
    temp=temp->next;  //move temp to next  
  }
  free(temp->next)
    temp->next=nullptr;

  return head;
}


//complete code:
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    
};
Node*convertArr2LL(vector<int> & arr){
       Node* head=new Node(arr[0]);
       Node* mover=head;
        for(int i=1;i<arr.size();i++){
        Node*temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
       }
      return head;
    }

//function to print LL
void print(Node*head){
    while(head !=NULL){
        cout<< head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* removesTail(Node*head){
    if(head==NULL || head->next==NULL) return NULL;
     Node* temp=head;
     while(temp->next->next!=NULL){
       temp=temp->next; //keep on moving
     }
     //after this temp will be standing at second last
    delete temp->next;
    temp->next=nullptr;

    return head;
}
int main(){
    vector<int> arr={12,5,8,7};
    Node*head=convertArr2LL(arr);
    head=removesTail(head);
    print(head);

    return 0;
}


                                  //size of array=4(here)
                           //Delete kth element of the linked list.
Node*deletek(Node*head, int k){
   if(head==null) return head; //edge case : LL empty
   //Next edge case: k=1
   if(k==1){
     Node*temp=head;
     head= head->next;
     free(temp);
     return head;
   }
  //k=3
  cnt=0, Node*temp=head, prev=NULL;
  while(temp!=NULL){
    cnt++;
    if(cnt==k){
      prev->next=prev->next->next;
      free(temp);
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

//complete code:
//Delete kth element of the list.
#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   public:
   Node(int data1, Node* next1){
      data=data1;
      next=next1;
   }

   public:
   Node(int data1){
    data=data1;
    next=nullptr;
   }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node*temp= new Node(arr[i]);
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

Node* removek(Node*head,int k){
    if(head==NULL) return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    int cnt=0;
    Node*temp= head;
    Node*prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={12,5,8,7};
    Node*head=convertArr2LL(arr);
    head=removek(head,2);
    print(head);
}

//delete the value given:
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

Node* convertArr2LL(vector<int>&arr){
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
Node* removeEl(Node* head, int el){
    if(head ==NULL) return head;
    if(head->data==el){
       Node*temp=head;
       head=head->next;
       free(temp);
       return head;
    }
   Node*temp=head;
   Node*prev=NULL;
   while(temp!=NULL){
    //do a linear search
    if(temp->data==el){
        prev->next=prev->next->next;
        free(temp);
        break;
    }
    prev=temp;
    temp=temp->next;
   }
   return head;
}
int main(){
  vector<int> arr={12,5,8,7};
   Node*head=convertArr2LL(arr);
   head=removeEl(head,3);
   print(head);
}


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



































































