//Q.1.Print name N times using recursion.
#include<bits/stdc++.h>
using namespace std;
void printName(int i,int n){
  if(i>n){
    return;     //base case
  }
  cout<<"shreya"<<endl;
  printName(i+1,n);
}
int main(){
  int n;
  cout<<"n:";
  cin>>n;
  printName(1,n);
  return 0;
}

//T.C: O(n) 
//S.C: O(n)  f(1,3),f(2,3),f(3,3) called stack space

//Q.2.Print linearly from 1 to N.
#include<bits/stdc++.h>
using namespace std;

 void print(int count,int n){
    if(count>n){
      return;
    }
    cout<<count<<" ";
    count++;
    print(count,n);
 }

int main(){
  int n;
  cout<<"n:";
  cin>>n;
  print(1,n);
  return 0;
}

//T.C:O(n)
//S.C:O(n)

//Q.3.Print in terms of 1 to N.
#include<bits/stdc++.h>
using namespace std;
  void print(int i,int n){
    if(i<1){
      return;
    }
    cout<<i<<" ";
    i--;
    print(i,n);
  }
int main(){
  int n;
  cout<<"n:";
  cin>>n;
  print(n,n);
  return 0;
}

 //[important]
//Q.4.Print linearly from 1 to N (but by backtracking)
   //f(i+1,n) +is not allowed , do with -
  #include<bits/stdc++.h>
  using namespace std;
  void func(int i,int n){
     if(i<1){
      return;
     }
     func(i-1,n);
     cout<<i<<" ";    //print line after recursion call
       }
  int main(){
    int n;
    cout<<"n:";
    cin>>n;
   func(n,n);
    return 0;
  }

//Q.5 Print from n to 1(by Backtracking)
//- is not allowed.
#include<bits/stdc++.h>
using namespace std;

void func(int i,int n){
  if(i>n){
    return;
  }
  func(i+1,n);
  cout<<i<<" ";
}
int main(){
  int n;
  cout<<"n:";
  cin>>n;
  func(1,n);
  return 0;
}


