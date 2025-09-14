#include <iostream>
using namespace std;

// Strategy Interface for walk
class WalkRobot{
    public :
    virtual void walk () = 0;
    virtual ~WalkRobot() {}

};
class NormalWalk : public WalkRobot{
    public:
    void walk() override {
        cout<<"Normal Walk"<<endl;
    }
};
class FastWalk : public WalkRobot{
    public:
    void walk() override {
        cout<<"Fast Walk"<<endl;
    }
};
class SlowWalk : public WalkRobot{
    public:
    void walk() override {
        cout<<"Slow Walk"<<endl;
    }
};
class TalkRobot{
    public:
    virtual void talk() =0;
    virtual ~TalkRobot() {};
};
class NormalTalk : public TalkRobot{
    public:
    void talk() override {
        cout<<"Normal Talk"<<endl;
    }
};
class FastTalk : public TalkRobot{
    public:
    void talk() override {
        cout<<"Fast Talk"<<endl;
    }
};
class SlowTalk : public TalkRobot{
    public:
    void talk() override {
        cout<<"Slow Talk"<<endl;
    }
};
class FlyRobot{
    public:
    virtual void fly() =0;
    virtual ~FlyRobot() {};

};
class NormalFly : public FlyRobot{
    public:
    void fly() override {
        cout<<"Normal Fly"<<endl;
    }
};

class FastFly : public FlyRobot{
    public:
    void fly() override {
        cout<<"Fast Fly"<<endl;
    }
};
class SlowFly : public FlyRobot{
    public:
    void fly() override {
        cout<<"Slow Fly"<<endl;
    }
};
class Robot{
    private:
    WalkRobot* walkBehavior;
    TalkRobot* talkBehavior;
    FlyRobot* flyBehavior;
    public:
    Robot(WalkRobot* walk, TalkRobot* talk, FlyRobot* fly)
        : walkBehavior(walk), talkBehavior(talk), flyBehavior(fly) {}
    void performWalk() {
        if(walkBehavior) walkBehavior->walk();
        else cout << "No walk behavior set." << endl;
    }
    void performTalk() {
        if(talkBehavior) talkBehavior->talk();
        else cout << "No talk behavior set." << endl;
    }
    void performFly() {
        if(flyBehavior) flyBehavior->fly();
        else cout << "No fly behavior set." << endl;
    }
    void setWalkBehavior(WalkRobot* walk) {
        delete walkBehavior;
        walkBehavior = walk;
    }
    void setTalkBehavior(TalkRobot* talk) {
        delete talkBehavior;
        talkBehavior = talk;
    }
    void setFlyBehavior(FlyRobot* fly) {
        delete flyBehavior;
        flyBehavior = fly;
    }
    ~Robot() {
        delete walkBehavior;
        delete talkBehavior;
        delete flyBehavior;
    }
};
int main() {
    Robot* robot = new Robot(new NormalWalk(), new FastTalk(), new SlowFly());
    robot->performWalk(); // Outputs: Normal Walk
    robot->performTalk(); // Outputs: Fast Talk
    robot->performFly();  // Outputs: Slow Fly

    // Change behavior at runtime
    robot->setWalkBehavior(new FastWalk());
    robot->performWalk(); // Outputs: Fast Walk

    delete robot;
    return 0;
}