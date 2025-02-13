// combate.h

#ifndef COMBATE_H // Previene la inclusi�n m�ltiple
#define COMBATE_H

#include <string>

const int PLAYER_ONE_HP_START = 100;
const int PLAYER_TWO_HP_START = 100;
const int MIN_HP = 0;

extern int playerOneHP; 
extern int playerTwoHP;

extern int pwr;
extern int def;
extern int dmg;
extern int dmg2;

void calculateDamage(int attackerAttack, int defenderDefense, std::string attacker);
bool showResults();

#endif