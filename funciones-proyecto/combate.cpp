#include "combate.h" 
#include <iostream>
using namespace std;

int playerOneHP = PLAYER_ONE_HP_START;
int playerTwoHP = PLAYER_TWO_HP_START;

// STATS

int pwr = 8;
int def = 4;
int dmg = 30;
int dmg2 = 20;


void calculateDamage(int attackerAttack, int defenderDefense, string attacker) {

    if (attacker == "P1") {
        playerTwoHP -= attackerAttack - defenderDefense;
    }
    else if (attacker == "P2") {
        playerOneHP -= attackerAttack - defenderDefense;
    }

    if (playerOneHP <= MIN_HP) {
        playerOneHP = MIN_HP;
    }
    if (playerTwoHP <= MIN_HP) {
        playerTwoHP = MIN_HP;
    }
}

bool showResults() {
    bool ganador = false;

    if (playerOneHP <= MIN_HP) {
        playerOneHP = MIN_HP;
        cout << "Jugador 1 le rompió la cabeza al jugador 2" << endl;
        ganador = true;
    }
    if (playerTwoHP <= MIN_HP) {
        playerTwoHP = MIN_HP;
        cout << "Jugador 2 le rompió la cabeza al jugador 1" << endl;
        ganador = true;
    }
    return ganador;
}