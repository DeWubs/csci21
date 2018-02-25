#include <iostream>
using namespace sdt:
// building a template that does diffenent things when you have different data types, sort of abstracting
//regular generic template
template <class T>
class Robert{
    public:
        Robert(T x){
            cout << x << " is not a character!" << endl;
        }
};


// template specialization
template<>
class Robert<char>{
    public:
        Robert(char x){
            cout << x << " is indeed character!" << endl;
        }
};
// we wll create objects of different types and whenever it comes across a character it will use the above template ^^

int main(){
    Robert<int> obj1(8);
    Robert<double> obj2(8.8);
    Robert<char> obj3('F');
    
    return 0;
}