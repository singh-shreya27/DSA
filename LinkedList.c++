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
