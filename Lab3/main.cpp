//main
#include "RPG.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    RPG p1 = RPG();
    RPG p2 = RPG("stebe", 12, 16, 14, "thief");

    cout << p1.getName() << " Is alive: " << p1.isAlive() << endl;
    cout << p2.getName() << " Is alive: " << p2.isAlive() << endl;
    p1.updateHealth(-5);
    cout << p1.getName() << " Is alive: " << p1.isAlive() << endl;
}