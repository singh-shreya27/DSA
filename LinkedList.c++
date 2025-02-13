                                //Linked List
//Arrays are of fixed size like arr[4] and are in contiguous memory location.
//so we can neither increase nor decrease the size of the array[n].
//so linkedlist comes in.
//WHAT IS A LINKED LIST?
//It is a data structure which helps to increase as well as decrease the size.
//Linkedlist is not in contiguous memory location.
//Starting point of the linked list is called HEAD of the linked list.

#include<bits/stdc++.h>
using namespace std;
//define a self defined data type.
class Node{                 //storing 2 things:
        public:
        int data;           //data itself
        Node* next;         //and pointer to the next

        //constructor
        public:
        Node(int data1,Node* next1){
            data = data1;
            next=next1;
        }
    };

int main(){
    vector<int> arr={2,5,8,7};             //suppose we are given to add a value 2 , how can we initialise that.
    Node* y=new Node{arr[0], nullptr}; //(this automatically stores pointer to the memory location)      //1st method:       //Node x= Node(2,nullptr)
    cout<<y->data;                                                                                                           //Node* y=&x; 
    return 0;             //here we are using new variable.
}

//WHERE IS LINKED LIST USED?
//In data structures, it is used in stack/queue.
//In real life: Used in a browser.

//What is the data structure that we will be using?
//struct/class in c++ and java.

int x=2;
int* y=&x;      //pointer to its memory location.
cout<<y;   

//struct does not offers OPPS concepts , so we use class.

//Memory space used?
//data
//*       
//32-bit system:              //64-bit system:
//int : 4 bytes               //int : 4 bytes
//*: 4 bytes                  // *  : 8 bytes
// 8 bytes                    // 12 bytes
//depending on the system, moemory space used might be different.

//HOW TO CONVERT AN ARRAY TO LINKED LIST.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }
 
    public:
    Node(int data1){            //if we don't want to pass nullptr ,                             
      data = data1;             // then make multiple constructor.
      next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){ 
    Node* head= new Node(arr[0]);          //we cannot return the entire linkedlist, so we need a head.
    Node* mover = head;    
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }  
      return head;
}
int main(){
    vector<int> arr ={2,5,8,7}; 
    Node* head=convertArr2LL(arr);
    cout<<head->data;
}

//T.C:O(n) simply traversing through every element

//TRAVERSAL IN A LINKED LIST.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }
 
    public:
    Node(int data1){            //if we don't want to pass nullptr ,                             
      data = data1;             // then make multiple constructor.
      next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){ 
    Node* head= new Node(arr[0]);          //we cannot return the entire linkedlist, so we need a head.
    Node* mover = head;    
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }  
    return head;
}
int main(){
    vector<int> arr ={2,5,8,7}; 
    Node* head=convertArr2LL(arr);
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//T.C:O(n) simply traversing through every element

//LENGTH OF A LINKED LIST
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }
 
    public:
    Node(int data1){            //if we don't want to pass nullptr ,                             
      data = data1;             // then make multiple constructor.
      next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){ 
    Node* head= new Node(arr[0]);          //we cannot return the entire linkedlist, so we need a head.
    Node* mover = head;    
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }  
    return head;
}
int lengthOfLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}
int main(){
    vector<int> arr ={2,5,8,7}; 
    Node* head=convertArr2LL(arr);
    cout<<lengthOfLL(head);
}
//T.C:O(n)

//Search in a linked list
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data =data1;
        next =next1;
    }
 
    public:
    Node(int data1){            //if we don't want to pass nullptr ,                             
      data = data1;             // then make multiple constructor.
      next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){ 
    Node* head= new Node(arr[0]);          //we cannot return the entire linkedlist, so we need a head.
    Node* mover = head;    
    for(int i=1;i<arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }  
    return head;
}
int lengthOfLL(Node* head){
    int count=0;
  //copy paste the traversal
    Node* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
}

int checkIfPresent(Node*head,int val){
  //copy paste the traversal
  Node* temp=head;
  while(temp){
    if(temp->data == val) return 1;
      temp=temp->next;
  }
  return 0;
}
int main(){
    vector<int> arr ={2,5,8,7}; 
    Node* head=convertArr2LL(arr);
    cout<<checkIfPresent(head,15);
 }

//T.C:O(n) in case the element is not found
//O(1) in case the element is the head itself.
//O(n/2) in between
