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


int main() {
    locale::global(std::locale(""));

    string playerOne;
    string playerTwo;
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

        if (showResults()) {
            break;
        }

    } while (!showResults());

    mostrarGanador(playerOneHP, playerTwoHP, playerOne, playerTwo);

    return 0;
}

void turnoCombate(bool turno) {
    turno = !turno; // Cambiamos el turno *antes* de imprimir el mensaje
    if (turno == true) {
        cout << "Turno del jugador 1..." << endl;
    }
    else {
        cout << "Turno del jugador 2..." << endl;
    }
}

void ejecucionCombate() {
    while (!showResults()) {
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