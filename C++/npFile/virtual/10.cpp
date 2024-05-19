// 10. Write a C++ program to crplaye an abstract class Instrument with abstract methods play() and tune(). Crplaye derived classes for Glockenspiel and Violin that extend the Instrument class and implement the respective methods to play and tune each instrument.
#include <iostream>
using namespace std;
class Instrument{
    public:
        virtual void play() = 0;
        virtual void tune() = 0;
};
class Glockenspiel : public Instrument{
    public:
    void play() override{
        cout<<"GLOCKENSPIEL PLAYS"<<endl;
    }
    void tune() override{
        cout<<"GLOCKENSPIEL TUNES"<<endl;
    }
};
class Violin : public Instrument{
    public:
    void play() override{
        cout<<"VIOLIN PLAY"<<endl;
    }
    void tune() override{
        cout<<"VIOLIN TUNES"<<endl;
    }
};
int main() {
    Instrument* ptr1; 
    Glockenspiel glockenspiel;
    Violin violin;
    ptr1 = &glockenspiel;
    ptr1->play();
    ptr1->tune();
    ptr1 = &violin;
    ptr1->play();
    ptr1->tune();
    return 0;
}