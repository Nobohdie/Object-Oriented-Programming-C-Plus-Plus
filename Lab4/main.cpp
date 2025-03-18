//main
#include "RPG.h"
#include <iostream>
#include <string>
using namespace std;

void displayStats(RPG play1, RPG play2) {
    printf("%s health: %i      %s health: %i", play1.getName().c_str(), play1.getHealth(), play2.getName().c_str(), play2.getHealth());
}
void displayEnd(RPG play1, RPG play2) {
    if(play1.isAlive()) printf("%s defeated %s! Good game!\n", play1.getName().c_str(), play2.getName().c_str());
    else printf("%s defeated %s! Good game!\n", play2.getName().c_str(), play1.getName().c_str());
}
void gameLoop(RPG * p1, RPG * p2) {
    while((*p1).isAlive() && (*p2).isAlive()) {
        printf("%s's turn: \n", ((*p1).getName().c_str()));
        (*p1).useSkill(p2);
        printf("------------------------------------\n");
        printf("%s's turn: \n", ((*p2).getName().c_str()));
        (*p2).useSkill(p1);
        printf("------------------------------------\n");
    }
}

int main() {
    RPG p1 = RPG();
    RPG p2 = RPG("stebe", 12, 16, 14, "thief");

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;
}