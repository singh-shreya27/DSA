//ENCAPSULATION:
//wrapping up data members(properties/state) and functions(methods/behaviour).

//Fully encapsulated class: All data members are marked private.
//Advantage:
//It is a synonym for information/data hiding. security increases.
// If we want e can make class-"Read Only".
//It  helps in unit testing.

#include<bits/stdc++.h>
using namespace std;

class Student{
  private:
  string name;
  int age;
  int height;
  
  public:
  int getAge(){
    return this->age;
  }
};
int main(){
   
   Student first;
   cout<<"Sab sahi chal rha hai"<<endl;


  return 0;
}
