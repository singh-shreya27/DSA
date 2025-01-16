                                            //OOPS:
            //What is OOPS?
//It is a type of programming style in which things revolve around objects that increases manageability,extensiability,readability etc.
//It is a programming paradigm(style or approach) based on the concept of "objects." 
            //What is objects?
//It is a type of entity(instance of class) which have two things :
//1.State or property.
//2.Behaviour.
            //What is class?
//It is a user defined data-type.

#include<bits/stdc++.h>
using namespace std;
class Hero{
  //properties
  int health;
};
int main(){
   
   //creation of object
   Hero h1;
   
   cout<<"size: "<<sizeof(h1) <<endl;   //4(integer:4 byte) size of properties
  //in case of empty class..object is allocated 1 byte memory for its indentification.

  return 0;
}

