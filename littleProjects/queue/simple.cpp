/*
I am doing this simple queue manupulation so that i can understand that i am doing it correctly. if i am doing it correctly i know what i will have to do to make it work in my battleship
*/

#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue <int> numbers;
    cout << "Push 5" << endl;
    numbers.push(5);
    cout << "push 4" << endl;
    numbers.push(4);
    cout << "push 4" << endl;
    numbers.push(4);
    cout <<"numbers in the queue "<< numbers.size() << endl;
    cout << "Popped " << numbers.front() << endl;
    numbers.pop();
    cout <<"numbers in the queue "<< numbers.size() << endl;
    return 0;
}