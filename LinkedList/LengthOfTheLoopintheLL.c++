//LENGTH OF A LOOP IN THE LL

//Brute force:
//using hashing
//take a temp and a timer.

map<node,int> mpp ;
temp=head;
timer=1;
while(temp!=NULL){
  if(mpp.find(temp)==tick){
     value=mpp[temp];
    return (timer-value);                 //T.C:O(n*2logn) to traverse the enitre LL:O(n) 
  }                                       //S.C:O(n) : optimise
  mpp[temp]=timer;
  timer++;
  temp=temp->next;
}
return 0;
}

//OPTIMAL APPROACH:
//TORTOISE AND HARE APPROACH:

int findlength(Node*slow,Node*fast){
  int cnt=1;
  fast=fast->next; //one step
  while(slow!=fast){
    cnt++;
    fast=fast->next;
  }
  return cnt;
}
int lengthOfLoop(Node*head){
Node*slow=head;
Node*fast=head;
while(fast!=NULL && fast->next!=NULL){
  slow=slow->next;
  fast=fast->next->next;
  if(slow==fast)
    return findlength(slow,fast);
}
 return 0; //no loop
}
