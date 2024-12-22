                    //Recursion
//When a function calls itself until a specified condition is met.
// #include<bits/stdc++.h>
// using namespace std;
// void print(){
//     cout<<1<<endl;
//     print();
// }
// int main(){
    
//     print();
//     return 0;
// }
//this code will print infinite 1 => stack overflow.[segmentation fault will happen]
//numerous function calls waiting due to recursion.
//Base conditon: condition which is used to stop a function.
#include<bits/stdc++.h>
using namespace std;
void f(int count){
  if(count==3)
  return;
  cout<<count;
  count++;
  f(count);
}
int main(){
    f(0);
    return 0;
}

//when int reaches 3, function is stopped...this stop condition is called base condition.
