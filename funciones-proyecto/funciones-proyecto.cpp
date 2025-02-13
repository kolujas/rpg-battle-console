/*
Calculadora de daño:


Qué hace: Recibe como entrada las estadísticas de un personaje (ataque, defensa, etc.) y las estadísticas de un enemigo, y calcula el daño que el personaje le hace al enemigo.

Funciones:

    calcularDaño(int ataque, int defensa): Calcula el daño base.

    aplicarCritico(int daño, float probabilidadCritico): Aplica un golpe crítico con una cierta probabilidad.

    aplicarDebilidad(int daño, string tipoAtaque, string tipoDebilidad): Aplica una bonificación de daño si el enemigo es débil al tipo de ataque.
*/

#include <iostream>
#include <string>
#include "combate.h"
#include <windows.h>
#include <locale>

using namespace std;

void turnoCombate(bool turno);
void ejecucionCombate();
void mostrarMenu(int eleccion);
void menuCombate(int eleccion);

string playerOne;
string playerTwo;


int main() {
    locale::global(std::locale(""));

    bool turno = false;    

    cout << "Ingresa el nombre del jugador 1: " << endl;
    cin >> playerOne;
    cout << "Ingresa el nombre del jugador 2: " << endl;
    cin >> playerTwo;

    cout << playerOne << " VS " << playerTwo << endl;    

    int eleccion = 0;

    do {
        turnoCombate(turno);
        ejecucionCombate();
        turno = !turno;
    } while(!showResults());

    return 0;
}

void turnoCombate(bool turno) {
    if (turno == true) {
        cout << "Turno del jugador 1..." << endl;
        turno = false;
    }

    if (turno == false) {
        cout << "Turno del jugador 2..." << endl;
        turno = true;
    }
}

void ejecucionCombate() {
    while (!showResults()){
        calculateDamage(dmg, def, "P1");
        calculateDamage(dmg2, def, "P2");
        Sleep(1000);

        cout << "Jugador 1: " << playerOneHP << endl;
        cout << "Jugador 2: " << playerTwoHP << endl;
        cout << endl;
    } 
}

void mostrarMenu(int eleccion) {
    

    std::cout << "1. Atacar" << std::endl;
    std::cout << "2. Defender" << std::endl;
    std::cout << "3. Usar pocion" << std::endl;
    std::cout << "4. Escapar" << std::endl;

    std::cout << "Hace tu movimiento... elegi uno de los siguientes numeros 1, 2, 3 o 4: " << std::endl;
    std::cin >> eleccion;

    while (eleccion != 1 && eleccion != 2 && eleccion != 3 && eleccion != 4) {
        std::cout << "No le pifies zapallo, hace tu movimiento bien... elegi uno de los siguientes numeros 1, 2, 3 o 4: " << std::endl;
        std::cin >> eleccion;
    }
}

void menuCombate(int eleccion) {

    switch (eleccion) {
    case 1:
        std::cout << "Fajar" << std::endl;
        break;
    case 2:
        std::cout << "Aguantar los trapos" << std::endl;
        break;
    case 3:
        std::cout << "Te clavas un mate curativo" << std::endl;
        break;
    case 4:
        std::cout << "Rajas como una rata apestosa" << std::endl;
        break;
    default:
        std::cout << "Que mierda elegiste gil?" << std::endl;
    }
}
