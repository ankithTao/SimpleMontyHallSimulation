#include <iostream>
#include <time.h>

using namespace std;

class DoorSet{
private:
    char doors[3];
    int carDoor;
    int choice;
public:
    DoorSet(){ for(int i=0;i<3;i++) doors[i]='g'; }
    void setChoice(int c){ choice=c; }
    int getChoice(){ return choice; }
    void setDoor(int door){
        doors[carDoor]='g';
        carDoor=door;
        doors[door] = 'c';
    }
    int getDoor(){ return carDoor; }
    int switchedChoice(){ return (doors[(choice+1)%3]=='c') ? (choice+1)%3 : (choice+2)%3; }
    int win(){ return doors[switchedChoice()]=='c'; }
};

int main()
{
    srand(time(NULL));
    int trials = 10000;
    cout<<"Please enter desired number of trials : ";
    cin>>trials;
    if(trials<0) return 0;
    int successes = 0;
    DoorSet sampleSet;
    for(int i=0;i<trials;i++){  
        sampleSet.setDoor(rand()%3);
        sampleSet.setChoice(rand()%3);
        successes += sampleSet.win();
    }
    cout<<"Proportion of Success : "<<successes*1.0/trials<<endl;
}
