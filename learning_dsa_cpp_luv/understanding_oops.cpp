#include <bits/stdc++.h>
using namespace std;
class Hero{
    private:          //private: means accessible only within the class
    int mode;
    public:           //public: means accessible everywhere
    string name;
    int health;
    char level;

    static int time;  //static keyword is used to declare a global variable which is independent of the objects creation and whose value is same for all objects

    //constructors declaring
    Hero(string name,int health, char level){      //paramaterized constructor declaring
        cout<<"paramaterized constructor called"<<endl;
        this->name = name;
        this->health = health;        //'this' is a pointer storing current object's address
        this->level = level;          //and 'this' is also used to distinguish between object's variables and parameters
    }
    Hero(){                          //default constructor , if no parameter is passed during declaring of object
        cout<<"default constructor called"<<endl;
        mode=0;
    }
    Hero(Hero& copy,string name){     //there is a default copy constructor which copies all the variables , but we can define our own copy constructor to copy some variables and not all , or to modify something
     this->name = name;
     this->health = copy.health;
     this->level = copy.level;       
    }
    void print(){
        cout<<"for "<<name<<" : "<<endl;
        cout<<"[ ";
        cout<<"mode is : "<<this->get_mode()<<" , ";
        cout<<"health is : "<<this->health<<" , ";
        cout<<"level is : "<<this->level<<" ]"<<endl;
        cout<<endl;
    }
    int get_mode(){    //getter for private variable "mode"
        return mode;
    }
    void set_mode(int mode){  //setter for private variable "mode"
        this->mode = mode;
    }

    static int timer(){       //the static function too doesn't needs objects to be accessed , and can access only static variables
        return time;          //hence , static function cannot use 'this' keyword.
    }

    //Destructor 
    ~Hero(){
        cout<<"destructor called for : "<<this->name<<endl;
    }
};

int Hero::time = 5;  //giving the static variable a global value 

int main() {
    //static allocation of object
Hero ramesh;          //creating the object for the class Hero
ramesh.health = 70;   //accessing the variables by dot operator
ramesh.name = "ramesh";
ramesh.level = 'A';   
//ramesh.mode can't be accessed as it is private variable
//but can be accessed via getters and setters 
ramesh.set_mode(50);

ramesh.print();

//with paramatrized constructor 
Hero suresh("suresh",58, 'e');
suresh.set_mode(89);

suresh.print();

//static variable can be accessed through class as well as objects
cout<<"the time for the game is : "<< Hero::time<<endl;
cout<<"the time for suresh is : "<< suresh.time<<endl;
//accessing static function
cout<< Hero::timer()<<endl;
cout<< suresh.timer()<<endl;

   //dynamic allocation of object
Hero *b = new Hero;
(*b).health = 80;    // or b->health = 80;
b->name = "b";
(*b).level = 'B';
(*b).set_mode(90);

cout<<"for b"<<endl;
cout<<"[ ";
cout<<"mode is : "<<(*b).get_mode()<<" , ";
cout<<"health is : "<<(*b).health<<" , ";
cout<<"level is : "<<(*b).level<<" ]"<<endl;
cout<<endl;

delete b;  //we have to call the destructor manually for dynamically allocated objects.

//with parametrized constructor
Hero *star = new Hero("star", 89, 'y');
star->set_mode(78);

cout<<"for star"<<endl;
cout<<"[ ";
cout<<"mode is : "<<star->get_mode()<<" , ";
cout<<"health is : "<<star->health<<" , ";
cout<<"level is : "<<star->level<<" ]"<<endl;
cout<<endl;

delete star;

Hero ritesh(suresh,"ritesh");   //here we are using copy constructor to copy contents of suresh to ritesh
cout<<"for ritesh copied from suresh"<<endl;
ritesh.print();

return 0;
}