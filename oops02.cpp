#include<iostream>
using namespace std;
class base{
    public:
    int age;
    int a;
    int b;
   
    void operator() (base &b) {
        cout << "Base class operator() called." << endl;
    
    }
    int operator+(base &b){
       int val1=this->a;
        int val2=b.b;
        return val1 - val2;
    }
};
//  class child:public base{
//     public:
//     int name;
//     child(): base(0) { // Calling base class constructor with default value
//         cout << "Child class constructor called." << endl;
//         age = 0; // Initialize inherited member variable
//     }
//  };
//  class child2:public child{
//     public:
//     int height;
//     child2(): child() {} // Calling child class constructor

//  };
 int main(){
    // child a;
    // a.age = 10; // Accessing the inherited member vari able
    // cout << "Child class age: " << a.age << endl; // Output the age
    // return 0;
    // child2 b;
    // b.age=20;
    base a,b;
    a.a=10;
    b.b=20;

    int result = a + b; // Using operator+ to add values
    cout<< result << endl; // Output the result
   // Calling operator() on base class

 }