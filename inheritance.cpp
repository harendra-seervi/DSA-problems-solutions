

//////////////////////////////////////////////////TYPES OF INHERITANCE//////////////////////////////////


// #include<iostream>
// using namespace std;
// //-------------------single inheritance---------------
// class a{             //parent class 
//     public:               
//     void fuca(){
//         cout<<"Funa"<<endl;
//     }
// };
// class b:public a{   //derived class    (a class ki public or protected elements b me aa jayenge )

// };
// int main(){
//     b t;
//     t.fuca();
//     return 0;
// }


//*********************************************************************************


// #include<iostream>
// using namespace std;
// //-------------------multiple inheritance---------------

// class c{
//     public:
//     void func(){
//         cout<<"This is  a function c"<<endl;
//     }
// };
// class a{             //parent class 
//     public:               
//     void fuca(){
//         cout<<"Funa"<<endl;
//     }
// };
// class b:public a,public c{   //derived class    (a class ki public or protected elements b me aa jayenge )

// };
// int main(){
//     b t;
//     t.fuca();
//     t.func();
//     return 0;
// }



//****************************************************************************************************


#include<iostream>
using namespace std;
//-------------------multilevel inheritance---------------

class c{
    public:
    void func(){
        cout<<"This is  a function c"<<endl;
    }
};
class a:public c{             //parent class 
    public:               
    void fuca(){
        cout<<"Funa"<<endl;
    }
};
class b:public a{   //derived class    (a,c class ki public or protected elements b me aa jayenge )

};
int main(){
    b t;
    t.fuca();
    t.func();
    return 0;
}


