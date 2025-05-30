
 //Find pairs with given sum in a sorted DLL.

//Brute force solution:

//pseudo code.
temp1=head; ds=[]
while(temp!=NULL){
  temp2=temp1->next;
  while(temp2!=NULL && temp1->data+temp2->data <=sum){
    if(temp1->data+temp2->data==sum){
      ds.add({temp1->data, temp2->data});
    }
    temp2=temp2->next;
  }
  temp1=temp1->next;
}
//T.C:~O(n^2)
//S.C:O(1)

//Optimised approach:
//This is a DLL , so we can move backwards.
Node* findTail(Node* head){
 Node* tail=head;
 while(tail->next !=NULL) tail=tail->next;
 return tail;
}
vector<pair<int,int>> findPairs(Node*head, int k){
 vector<pair<int,int>> ans;
 if(head==NULL) return ans;
 Node*left=head;
 Node*right= findTail(head);  //O(n)

while(left->data < right->data){       //O(n)
  if(left->data+right->data==k){
   ans.push_back(left->data+right->data);
   left=left->next;
   right=right->prev;
  }
   else if(left->data+right->data<k){
    left=left->next;
   }
   else{
    right=right->prev;
   }
}
   return ans;
}

//T.C: O(2n)
//S.C:O(1)
