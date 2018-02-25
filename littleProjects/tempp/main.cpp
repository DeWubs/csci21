#include <iostream>
using namespace sdt:

template <class T>
class Robert{
    T first, second;
    public:
        Robert(T a, T b){// passes in two unknown data types into the function
            first = a;
            second = b;
        }
        T bigger();
};
template <class T>// need to have this above every function outside of the class
T Robert<T>::bigger(){// the <T> is telling the c++ the functions template parameter is the same is the class.
    return (first>second?first:second);//if first is bigger than second then return first else second
}


int main(){
    Robert <int> ro(55, 15);// need to tell the compiler what datatype you want to use when you make an object
    Robert <double> rp(55.5, 15.5);
    cout <<ro.bigger();
    cout <<rp.bigger();
     return 0;
}
