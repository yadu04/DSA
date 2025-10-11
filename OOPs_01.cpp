#include<iostream>
using namespace std;
class hero{
    private:
    int health;
    char level;
  

    public:
    static int time;
    // Default constructor
    // This constructor initializes health to 0 and level to 'A'
    hero(int h,char l){
        cout<< "this is :"<< this<<endl;


        this->health=h;
        this->level=l;
    }
    void gethealth(){
        cout<< "health is:"<< health<<endl;
    }
    void getlevel(){
        cout<< "level is:"<< level<<endl;
    }
    int sethealth(int h){
        this->health = h;
    }
    char setlevel(char l){
        this->level = l;
    }
};
int hero::time=1000;


int main(){
    cout<<hero::time <<endl;
    
     
    hero a(100, 'A');
    cout << "Address of object a: " << &a << endl; // Displaying the address of object a
    // Creating an object of hero with health 100 and level 'A'
    cout<< a.time <<endl; // Accessing static member variable
   
// Dynamically allocating memory for a hero object
    // hero *b=new hero(   100, 'B'); 
    // b->gethealth();     
    // b->getlevel();
    // delete b; // Free the dynamically allocated memory

//     hero  c(200,'m');
//     c.gethealth();
//     c.getlevel();
//     cout << "Address of object c: " << &c << endl; // Displaying the address of object c
//     return 0;
// }
}