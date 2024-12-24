                   //Parametrised and Functional Recursion.
                //Parametrised recursion:
                       //Sum of first N numbers.
#include<bits/stdc++.h>
using namespace std;
 void func(int i, int sum){
        if(i<1){
            cout<<sum;
            return;
        }
     func(i-1,sum+i);
    }
int main(){
   int n;
   cout<<"n:";
   cin>>n;
   cout<<"sum:";
   func(n,0);
    return 0;

}
                     //Functional recursion:
//eg: f(3)=3+f(2)=3+2+f(1)=3+2+1+f(0)

#include<bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }
   
   return n+sum(n-1);
}
int main(){
    int n;
    cout<<"n:";
    cin>>n;
    cout<<"sum:";
   cout<< sum(n);
    return 0;
}

              //Factorial of N.
#include<bits/stdc++.h>
using namespace std;
int  factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
   int n;
   cout<<"n:";
   cin>>n;
   cout<<"factorial of n :";
  cout<<factorial(n);
    return 0;
}
//T.C:O(N);
//S.C:O(N);   N functions will be awaiting to be completed, stack space will be taken.
