//USER INPUT/OUTPUT
#include<bits/stdc++.h>
using namespace std;
int main(){
    //TAKING INPUT
    int x,y;
      cout<<"Input:";
      cin>>x>>y;
      cout<<"The value of x :"<<x<<" and y:"<<y;

   //DATA TYPES:
    //int
    int x=10;
    //long
    long y=15;
    //long long
    long long z=190000000;

    //STRING AND GETLINE
    string s1,s2; 
     cout<<"Input string:";     //Hey striver //s1=Hey //" " breaks the string
    cin>>s1>>s2;
    cout<<"string:"<<s1<<" "<<s2;

   //In order to get "Hey striver I am cool" (means complete sentence) all in one string // use getline.

   string str;
   getline(cin, str);
   cout<<"string:"<<str;

   //char (can store all 256 characters of english dictionary)
   char ch='i';   (using single quotes)
   cout<<"character:"<<ch; 

  //STORING CAPACITY:
  //integer approx -10^9 TO 10^9.
  // long : -10^12 to 10^12.
  //long long : -10^18 to 10^18.

  //IF ELSE STATEMENTS:
//Write a program which takes input of age and prints if you are an adult or not.
//>=18, yes
//<18,no 
  int age;
   cout<<"age:";
   cin>>age;
    if(age>=18) {
    cout<<"you are an adult.";
   } 
    else{
      cout<<"you are not an adult.";
    }

//A School has following rules for garding system.
// a. Below 25-F
// b. 25 to 44-E
// c. 45 to 49-D
// d. 50 to 59-C
// e. 60 to 79-B
// f. 80 to 100-A
// Ask user to enter marks and print the corresponding grade.

int marks;
  cout<<"marks:";
  cin>>marks;
  if(marks<25){
    cout<<"F";
  }
  else if(marks<=44){
    cout<<"E";
  }
  else if(marks<=49){
    cout<<"D";
  }
  else if(marks<=59){
    cout<<"C";
  }
  else if(marks<=79){
    cout<<"B";
  }
  else if(marks<=100){
    cout<<"A";
  }

//Take the age from the user and then decide accordingly
//1.If age<18,
//print->"not eligible for job"
//2.If age >=18,
//print->"eligible for job"
//3.If age >=55 and age <= 57,
//print->"eligible for job, but retirement soon."
//4.If age >57
print ->"retirement time.

//NESTED IF-ELSE STATEMENTS.
  int age;
  cout<<"age:";
  cin>>age;
  if(age<18){
    cout<<"not eligible for job";
  }
  else if(age<=57){
    cout<<"eligible for job";
    if(age>=55){
      cout<<", but retirement soon";
    }
  }
  else{
    cout<<"retirement time.";
  }

//SWITCH STATEMENT.
//Take the day no. and print the corresponding day.
  //for 1 print Monday,
  //for 2 print Tuesday and so on for 7 print Sunday.
int day;
cout<<"day:";
cin>>day;
switch(day){
  case 1:
  {
    cout<<"Monday";
    break;
  }
  case 2:{
    cout<<"Tuesday";
    break;
  }
  case 3:{
    cout<<"Wednesday";
    break;
  }
  case 4:{
    cout<<"Thursday";
    break;
  }
  case 5:{
    cout<<"Friday";
    break;
  }
  case 6:{
    cout<<"Saturday";
    break;
  }
  case 7:{
    cout<<"Sunday";
    break;
  }
  default:
  {
    cout<<"Invalid";
  }
}
cout<<endl<<"Check";

//2D ARRAY.
int arr[3][5];
arr[3][5]=78;
cout<<arr[3][5];

//DO WHILE
int i=2;
do{
  cout<<"Striver"<<i<<endl;
  i++;
}while(i<=1);
cout<<i<<endl;

return 0;
}

#include<bits/stdc++.h>
using namespace std;
//FUNCTIONS
//Functions are set of code which performs something for you.
//Functions are used to modularise code.
//Functions are used to increase readaility.
//Functions are used to use same code multiple times.
//void ->which does not return anything
//return
//parametrised
//non parametrised
//1.void printName(){
  cout<<"Hey striver";
}
//2.void printName(string name){
  cout<<"Hey "<<name;
}
int main(){
//1.printName();
//2. string name;
  cout<<"name:";
  cin>>name;
  printName(name);
//inbuilt max and min functions exist.

//PASS BY VALUE
//copy goes
//PASS BY REFERENCE
(&)
//Arrays always goes by reference.
return 0;
}
