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
//T.C: O(3n)   //do it withour reversal 
//S.C:O(1)


//DO IT USING RECURSION

