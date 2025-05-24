                  //SORT A LL OF 0's , 1's and 2's.

 temp=head, cnt0=0,cnt1=0,cnt2=0;
while(temp!=NULL){
  if(temp->data==0) cnt0++;
  else if(temp->data==1) cnt1++;
  else cnt2++;

temp=temp->next;  
}

temp=head;
while(temp!=NULL){
  if(cnt0)
    temp->data=0;
  cnt--;
  else if(cnt1)
    temp->data=1;
  cnt1--;
  else
   temp->data=2;
  cnt2--;
  
  temp=temp->next;
}

//T.C:O(2n)  2 pass
//S.C:O(1)

//1 pass solution:
//change the given links.
//In one traversal, I need three segregated lists of 0's, 1's and 2's.
//take three dummy head as zeroHead, oneHead and twoHead , assign all of them as -1;
//also take three pointers zero, one and two pointing at their heads.

if (head==NULL || head->next==NULL) return NULL;
Node*zeroHead=new Node(-1), Node*zero=zeroHead;
Node*oneHead=new Node(-1);  Node*one=oneHead;
Node*twoHead=new Node(-1);  Node*two=twoHead;

temp=head;
while(temp!=NULL){
  if(temp->data==0){
    zero->next=temp;
    zero=temp;
  }
  else if(temp->data==1){
    one->next=temp;
    one=temp;
  }
  else{
    two->next=temp;
    two=temp;
  }
  temp=temp->next;
}

zero->next=(oneHead->next) ? oneHead->next: twoHead->next;
one->next=(twoHead->next);
two->next=NULL;
Node*newHead=zeroHead->next;
delete zeroHead;
delete oneHead;
delete twoHead;
return newHead;

//T.C:~O(n)
//S.C:O(1)
