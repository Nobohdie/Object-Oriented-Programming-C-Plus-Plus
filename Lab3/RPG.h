//RPG.h
#include <string>
using namespace std;
#ifndef RPG_H
#define RPG_H
const int SKILL_SIZE = 2;

class RPG {
    public:
        //constructor
        RPG();
        RPG(string name, int health, int strength, int defense, string type);

        //mutator
        void setSkills();
        void printAction(string action, RPG opponent);
        void updateHealth(int newHealth);
        //void attack(RPG * opponent);
        //void useSkill(RPG * entity);
        //accessor
        const bool isAlive();
        const string getName();
        const int getHealth();
        const int getStrength();
        const int getDefense();
    private:
        string name;
        int health;
        int strength;
        int defense;
        string type; // warrior, mage, thief, archer
        string skills[SKILL_SIZE];
};
#endif
