#include <iostream>
#include "Charmander.h"
using namespace std;
int main()
{
    vector<string> pokemonType;
    pokemonType.push_back("Fire");
    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "----------Constructor Created---------\n";
    Charmander chuck = Charmander("Chuck", 100, 4, 4, pokemonType, skills);

    cout << "\n------Direct Speak------\n";
    chuck.speak();

    Pokemon * p1 = &chuck;
    cout << "\n------ Speak called from Pokemon Pointer ------\n";
    (*p1).speak();

    Charmander * c1 = &chuck;
    cout << "\n------ Speak called from Charmander pointer -----\n";
    (*c1).speak();

    cout << "------ Print stats ------\n";
    chuck.printStats();
}