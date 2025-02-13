#include "combate.h"
#include <iostream>
using namespace std;

int playerOneHP = PLAYER_ONE_HP_START;
int playerTwoHP = PLAYER_TWO_HP_START;

// STATS

int pwr = 8;
int def = 4;
int dmg = 50;
int dmg2 = 12;

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
        ganador = true;
    }
    if (playerTwoHP <= MIN_HP) {
        ganador = true;
    }
    return ganador;
}

void mostrarGanador(int playerOneHP, int playerTwoHP, string ganadorP1, string ganadorP2) {
    if (playerOneHP <= MIN_HP && playerTwoHP <= MIN_HP) {
        cout << "¡Empataron los giles!" << endl;
    }
    else if (playerOneHP <= MIN_HP) {
        cout << "¡Ganó " << ganadorP2 << "!" << endl;
    }
    else if (playerTwoHP <= MIN_HP) {
        cout << "¡Ganó " << ganadorP1 << "!" << endl;
    }
}