#include "computer.h"
#include "player.h"
/*
    making the first turn true so in the turn function it can randomly pick one spot the first time it is run
*/
Computer::Computer(){
    first_ = true;
}
/*
    returns the front of the queue attackNums
*/
int Computer::getAttackNum_(){
    return attackNums_.front();
}
/*
    @param vector char
    sets the board with an imported file, to allow the computer to have a board
*/

void Computer::setBoardC(vector <char> c){
    Player_Board.setBoard1(c);
}
/*
    @param int 
    takes in the integer and compairs it to positions on the set board, if the position passed in has an 'S' it will run the hit function
    if the passed number is an 'o' it will clal the miss function.
*/
void Computer::attack(int num){
    if(Player_Board.getPosition(num) == 'S'){
        track_Board_C.hit(num);
        cout<<"The Computer attacked position: " << num << endl;
        track_Board_C.displayBoard1();
    }
    else{
        track_Board_C.miss(num);
        cout<<"The Computer attacked position: " << num << endl;
        track_Board_C.displayBoard1();
    }
    
}
/*
    this function will randomly generate a number between 0 and 100  if its the first turn, otherwise it will take the number it made and test each of its neighbors if any of its neighbors are a ship it will
    move its number to that and repeat the process otherwise if each neighbor surrounding a position is an 'o' it will pick a new random number between 0 and 100.
*/
void Computer::turn(){
     if(first_){
        attackNums_.push(rand() % 100);
     }
  
    if(first_){
        cout <<"im in the first turn!" << endl;
        //track_Board_C.displayBoard1();
        attackNums_.push(rand() % 100);
        first_ = false;
    }
    
    else if(attackNums_.size() >= 1){
        cout << "im in the first if" << endl;
        bool newArea = false;
        int testAttack = rand() % 100;
        cout<< testAttack << "im the test attack" << endl;
        while(newArea == (false)){
            if(track_Board_C.getPosition(testAttack) == 'S' || track_Board_C.getPosition(testAttack) == 'o'){
                cout << "turning new area true" << endl;
                newArea = true;
            }
        
            else{
                 cout<<"making a random test attack"<< endl;
                testAttack = rand() % 100;
             }
        }
        
        attackNums_.pop();
        cout <<"attack nums popped" << endl;
        attackNums_.push(testAttack);
        cout <<"attack nums pushed" << endl;
    }
    
    else{
        if(track_Board_C.getPosition(attackNums_.front()) == 'o'){
            bool newArea = false;
            int testAttack = rand() % 100;
            while(newArea = false){
                if(track_Board_C.getPosition(testAttack) == 'S' || track_Board_C.getPosition(testAttack) == 'o'){
                    newArea = true;
                }
                else{
                    testAttack = rand() % 100;
                }
            }
            attackNums_.pop();
            attackNums_.push(testAttack);
        }
        else if(track_Board_C.getPosition(attackNums_.front()) == 'S'){
         //	checks for top
        //	 makes sure it is not on the edge
        if(attackNums_.front() > 0) { 
          //  Ensure it has not already been attacked
            if(track_Board_C.getPosition(attackNums_.front() - 1) == 'S' || track_Board_C.getPosition(attackNums_.front() - 1) == 'o' ) {
                attackNums_.push(attackNums_.front() - 1);
            }
        }
    	//checks for right neighbor
        //makes sure it is not on the edge
        if(attackNums_.front() < 100) {
            //Ensure it has not already been attacked
    	    if(track_Board_C.getPosition(attackNums_.front() - 1) == 'S' || track_Board_C.getPosition(attackNums_.front() - 1) == 'o' ) {
                attackNums_.push(attackNums_.front() + 1);
    	    }
        }
    	//checks for bottom neighbor
    	//makes sure it is not on the edge
        if(attackNums_.front() < 100) {
            //Ensure it has not already been attacked
        	if(track_Board_C.getPosition(attackNums_.front() - 1) == 'S' || track_Board_C.getPosition(attackNums_.front() - 1) == 'o' ) {
                attackNums_.push(attackNums_.front() + 10);
        	}
        }
        //checks for left neighbor
        //makes sure it is not on the edge
        if(attackNums_.front() > 0) {
            if(track_Board_C.getPosition(attackNums_.front() - 1) == 'S' || track_Board_C.getPosition(attackNums_.front() - 1) == 'o' ) {
                attackNums_.push(attackNums_.front() - 1);
            }
        }
        attackNums_.pop();
    }
        attackNum_ = attackNums_.front();
    }
}