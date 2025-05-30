  //Remove duplicates from sorted DLL

//sorted: so duplicates will always be in contiguous manner.

Node* removeDuplicates(Node* head){
 Node*temp=head;
while(temp!=NULL && temp->next!=NULL){
  Node*nextNode=temp->next;
  while(nextNode!=NULL && nextNode->data == temp->data){
    Node* duplicate=nextNode;
    nextNode=nextNode->next;   
    free(duplicate);
  }
  temp->next=nextNode;
  if(nextNode!=NULL) nextNode->prev=temp;
  temp=temp->next;
}
return head; 
}


//T.C:O(n) 
//IMPORTANT: temp skipped the duplicates which were traversed by the inner loop. so overall n=length of the LL.
//S.C:O(1)
