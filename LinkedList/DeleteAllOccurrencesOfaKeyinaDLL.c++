
   //Delete all occurrences of a key in DLL.

Node* deleteAllOccurreneces(Node* head, int k){
  Node*temp=head;
  while(temp!=NULL){
    if(temp->data==k){
      if(temp==head){
        head=temp->next;
      }
      Node* nextNode=temp->next;
      Node* prevNode=temp->prev;
      if(nextNode!=NULL) nextNode->prev=prevNode;
      if(prevNode!=NULL) prevNode->next=nextNode;

      free(temp);
      temp=nextNode;
    }
    else{
      temp=temp->next;
    }
  }
  return head;
}

//T.C:O(n)
//S.C:O(1)
