
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

