                            //Flatten a LL

//brute force approach:

//initialise an array to store the data extracted during traversal.
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* child;
    
    public:
    Node(){
        data=0;
        next=nullptr;
        child=nullptr;
    }

    Node(int x){
        data=x;
        next=nullptr;
        child=nullptr;
    }
    Node(int x, Node* nextNode, Node*childNode){
        data=x;
        next=nextNode;
        child=childNode;
    }

};

Node* convertArr2LL(vector<int>& arr){
    Node* dummyNode= new Node(-1);
    Node* temp=dummyNode;

    for(int i=0;i<arr.size();i++){
        temp->child = new Node(arr[i]);
        temp=temp-> child;
    }
    return dummyNode->child;
}


Node* flattenLL(Node*head){
    vector<int> arr;
    while(head!=NULL){
        Node*t2=head;
        while(t2!=NULL){
            arr.push_back(t2->data);
            t2=t2->child;
        }
        head=head->next;
    }
    //sort the array containing node values in ascending order
    sort(arr.begin(), arr.end());

    //convert the sorted array back to a LL
    return convertArr2LL(arr);
}

//print the LL by traversing through child pointers
void printLL(Node* head){
    while(head!=NULL){
        cout<< head->data<<" ";
        head=head->child;
    }
    cout<<endl;
}

//print the LL in a grid like structure
void printOriginalLL(Node* head, int depth){
    while(head!=NULL){
        cout<<head->data;
        
        if(head->child){
            cout<<"->";
            printOriginalLL(head->child, depth+1);
        }

        //add vertical bars
        //for each level in the grid
        if(head->next){
            cout<<endl;
            for(int i=0;i<depth;i++){
                cout<<"|";
            }
        }
        head=head->next;
    }
}
int main(){
    // Create a linked list with child pointers
    Node* head = new Node(5);
    head->child = new Node(14);
    
    head->next = new Node(10);
    head->next->child = new Node(4);
    
    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);
    
    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);
    
    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLL(head, 0);

     // Flatten the linked list
    // and print the flattened list
    Node* flattened = flattenLL(head);
    cout << "\nFlattened linked list: ";
    printLL(flattened);
    
    return 0;
}

//T.C:O(n*m)+O(n*m log(n*m) +O(n*m)
//S.C:O(2n*m)


//optimise:
Node*merge(Node* list1, Node* list2){
  Node* dummyNode= new Node(-1);
  Node* res= dummyNode;
  while(list1!=NULL && list2!=NULL){
    if(list1->data < list2->data){
      res->child=list1;
      res=list1;
      list1=list1->child;
    }
    else{
      res->child=list2;
      res=list2;
      list2=list2->child;
    }
    res->next=NULL;
  }
  if(list1) res->child=list1;
  else res->child=list2;
  if(dummyNode->child) dummyNode->child->next=NULL;
  return dummyNode->child;
}
Node* flattenLL(Node* head){
  if(head==NULL || head->next==NULL) return head;
  Node* mergedHead= flattenLL(head->next);
  head=merge(head,mergedHead);
  return head;
}

//T.C:O(N*O(2m)) ~ O(2nm)
//S.C:O(n) //recursive stack space.
