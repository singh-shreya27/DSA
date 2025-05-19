//REVERSE A DLL:

//USING STACK:
Node*temp=head;
stack<int>st;
//step1: push everything into stack
while(temp!=NULL){
  st.push(temp->data);                   //T.C:O(n)
  temp=temp->next;
}
//step2:get everything out of that stack
temp=head;
while(temp!=NULL){
  temp->data=st.top();                        //T.C:O(n)
  st.pop();
  temp=temp->next;
}
//now we have DLL reversed only in terms of data
//T.C:O(2n)
//S.C:O(n)  using external stack to store all the elements.
  
//optimise this because this is 2 pass solution...optimise this to 1 pass solution.
//first solve it for one node.
last=NULL, current=head;
while(current!=NULL){
//swap the links.
last=current->back;
current->back=current->next;
current->next=last;
//links swapped ...now move current to next node.
current=current->back;
}
new head:last->back;

//REVERSE A DLL
Node* reverseDLL(Node* head){

  //single element
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node*prev=NULL;
  Node*current=head;

  while(current!=NULL){
    prev=current->prev;
    current->prev=current->next;
    current->next=prev;
    current=current->prev;
  }
  return prev->prev;
}

//solved in single pass.
//T.C:O(n)
//S.C:O(1) just changing the links ..not using any extra space
//MOST OPTIMAL SOLUTION.
