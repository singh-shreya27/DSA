                  //Deletion and insertion : 
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





































