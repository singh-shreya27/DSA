                                //Linked List
//Arrays are of fixed size and are in contiguous memory location.
//so we can neither increase nor decrease the size of the array[n].
//so linkedlist comes in.
//It is a data structure which helps to increase as well as decrease the size.
//Linkedlist is not in contiguous memory location.
//Starting point of the linked list is called HEAD of the linked list.

#include<bits/stdc++.h>
using namespace std;
struct Node{
        public:
        int data;
        Node* next;

        //constructor
        public:
        Node(int data1,Node* next1){
            data = data1;
            next=next1;
        }
    };

int main(){
    vector<int> arr={2,5,8,7};
    Node* y=new Node{arr[0], nullptr};
    cout<<y->data;
    return 0;
}
