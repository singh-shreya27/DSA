             //Add 1 to Linked List.
function(head){
    Node* head=reverse(head); //O(n)
    Node*temp=head;
    int carry=1;
    while(temp!=NULL){         //O(n)
      temp->data=temp->data+carry;
      if(temp->data<10){
        carry=0;
        break;
      }
      else{
        temp->data=0;
        carry=1;
      }
      temp=temp->next;
    }
  if(carry==1){
    Node newNode= new Node(1);
    head= reverse(head);
    newNode->next=head;
    return newNode;
  }
  head= reverse(head);    //O(n)
  return head;
}
//T.C: O(3n)   //do it without reversal 
//S.C:O(1)


//DO IT USING RECURSION
//if we do no reverse we cannot go back ...so in recursion we have something called back tracking

int addHelper(Node*temp){
  if(temp==NULL)
    return 1;
  carry=addHelper(temp->next);
  //backtracking
  temp->data=temp->data+carry;

  if(temp->data<10)
    return 0;
  temp->data=0;
  return 1;
}

Node* addOne(Node*head){
  int carry=addHelper(head);
  if(carry=1){
    Node*newNode= new Node(1);
    newNode->next=head;
    head=newNode;
  }
  return head;
}
//T.C:O(n)
//S.C:O(n)

//ITERATIVE SOLUTION:
//PROS: No space 
//CONS: Tampering data and more time taken.

//RECUSRIVE SOLUTION:
//PROS: No tampering of data, addition done in place and in fatser time.
//CONS: Extra space.
