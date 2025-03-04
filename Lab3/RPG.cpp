#include "RPG.h"
#include <iostream>
#include <string>
using namespace std;

//constructors
RPG::RPG(){
    name = "NPC";
    health = 100;
    strength = 10;
    defense = 10;
    type = "warrior";
    skills[0] = "slash";
    skills[1] = "parry";
}

RPG::RPG(string name, int health, int strength, int defense, string type) {
    this -> name = name;
    this -> health = health;
    this -> strength = strength;
    this -> defense = defense;
    this -> type = type;
    setSkills();
}

//Accessors
const string RPG::getName(){
    return name;
}
const int RPG::getHealth() {
    return health;
}
const int RPG::getStrength() {
    return strength;
}
const int RPG::getDefense() {
    return defense;
}

//other
void RPG::setSkills() {
    if(type == "mage") {
        skills[0] = "fire";
        skills[1] = "thunder";
    }
    else if (type == "thief") {
        skills[0] = "pilfer";
        skills[1] = "jab";
    }
    else if (type == "archer") {
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    }
    else {
        skills[0] = "slash";
        skills[1] = "parry";
    }
}
void RPG::printAction(string skill, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

//mutators
void RPG::updateHealth(int newHealth) {
    health = newHealth;
}
const bool RPG::isAlive() {
    if(health > 0) return true;
    else return false;
}
