                             //Stack and Queue.

//Stack(LIFO)                                                    //Queue(FIFO)

                          //What is?
                //Implement using arrays
            //Implement using LinkedList
         //Implement using Queue/Implement using stack



                       //What is?
//STACK:
//It is a data structure which can hold a certain kind of data(int, pair,tuple,long,char,string , etc)
//Follows LIFO(Last in first out) mechanism.
//Operations:
//push(), pop(),top(),size().
//pop():deleting (takes out) the last element.
//top():gives you the last element.

//QUEUE:
//It is similar type of a data structure which can hold a certain kind of data(int, pair,tuple,long,char,string , etc)
//Follow FIFO(First in First out) mechanism.
//Operations:
//push(),pop(),top(),size().


stack<int>st 
//st:variable name
//st.push(),
//st.pop()
//st.top()
//st.size()
Queue<int>q;
//q.push()
//q.pop()
//q.top()
//q.size()

                 //Implement using arrays?

//STACK USING ARRAYS:
//ques:I need a 10 size data structure. size=10

int st[10]
int top=-1;  //top:index

class stImp{
top=-1,int st[10];
//functions
push(x){                        //O(1)
  if(top>=10) {   
    //print something         
  }
  top=top+1;
  st[top]=x;
 }

int top(){                            //O(1)
  if(top==-1){
    //print something                      
  }                               
  return st[top];
}

int pop(){                        //O(1)
  if(top==-1){
    //print something
  }
  top=top-1;
}

int size(){                       //O(1)
  return top+1;
}

  }
//T.C:O(1)
//S.C:O(10)


             //Queue using arrays:
//we are using arrays..so it cannot be dynamic in nature...it needs to have a fixed size.
//size=4
//int q[4]
