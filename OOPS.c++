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

//ACCESS MODIFIERS:
//1.Public
//2.Private  (by default) :it can be accessed only inside class
//3.Protected

//GETTER/SETTER:
#include<bits/stdc++.h>
using namespace std;
class Hero{
  //properties
  private:
  int health;      //4 byte
  public:
  char level;      //1 byte

 //constructor
  Hero(){
    cout<<"Constructor called"<<endl;
  }

  //parametrised constructor
  Hero (int health){
    cout<<"this->"<<this<<endl;
   this->health = health;
  }
  
  Hero (int health, char level){
    this->level=level;
    this->health=health;
  }

    //once we create our own constructor, the default constructor will no longer exist.
  
  void print(){
    cout<<level<<endl;
  }

  int getHealth(){
    return health;
  }
  char getLevel(){
    return level;
  }
  void setHealth(int h){
    health=h;
  }
    
  void setLevel(char ch){
    level=ch;
  }
};
int main(){
   
   //creation of object
   //static allocation 
   Hero ramesh;

   cout<<"size of ramesh:"<<sizeof(ramesh)<<endl;       //8  (not 5) (4+1+3padding)
   //READ ABOUT PADDING AND GREEDY ALIGNMENT
   // Padding:
   //Padding refers to the extra bytes added by the compiler between the members of a class or structure to satisfy memory alignment requirements.
   //Why padding is needed:
   //It ensures data members are aligned for faster memory access by the processor.
   //Misaligned data can lead to performance penalties or even hardware exceptions on some systems.

   // Greedy Alignment:
   //Greedy alignment refers to the strategy of arranging members of a class or structure in a way that minimizes padding by grouping members of the same size together.
   //This is typically a manual optimization done by the programmer or automatically handled by some compilers.

    //we can access properties using "." operator 
   cout<<"Ramesh health is:"<<ramesh.getHealth()<<endl;
   ramesh.setHealth(70);
   //ramesh.health=70;
   ramesh.level='s';
   cout<<"health:"<<ramesh.getHealth()<<endl;
   cout<<"level:"<<ramesh.level<<endl;

 
   //static allocation
   Hero a;
   a.setHealth(80);
   a.setLevel('B');
   cout<<"level:"<<a.level<<endl;
   cout<<"health:"<<a.getHealth()<<endl;
   //dynamic allocation
   Hero *b = new Hero;
   b->setLevel('A');
   b->setHealth(70);
   cout<<"level:"<<(*b).level<<endl;
   cout<<"health:"<<(*b).getHealth()<<endl;
   cout<<"level:"<<b->level<<endl;
   cout<<"health:"<<b->getHealth()<<endl;

    //object created statically '
  cout<<"Hi"<<endl;
  Hero suresh;
  cout<<"hello"<<endl;
  //whenever an object is created its constructor is called first which has no return type and input parameter.

  cout<<"Address of suresh:"<<&suresh<<endl;

  suresh.print();


  //dynamically
  Hero *h = new Hero;
  h->print();

  Hero temp(22,'W');
  temp.print(); 
  
  return 0;
}




