#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


int modificarCordura(int cordura, int cambio) {
    cordura += cambio;
    if (cordura > 100) cordura = 100;
    if (cordura < 0) cordura = 0;
    return cordura;
}

bool ataqueMonstruo(int cordura) {
    int prob = rand() % 100; 

    if (cordura > 40) {
        return false;
    } 
    else if (cordura > 20) {
        return (prob < 20);
    } 
    else {
        return (prob < 50);
    }
}


void avanzarTiempo(int &hora, int &minuto) {
    minuto += 30;
    if (minuto >= 60) {
        minuto = 0;
        hora++;
    }
}


string formatoHora(int hora, int minuto) {
    int h = hora;
    string sufijo = "AM";

    if (h >= 12) sufijo = "PM";
    if (h > 12) h -= 12;
    if (h == 0) h = 12;

    string m = (minuto == 0 ? "00" : "30");

    return to_string(h) + ":" + m + " " + sufijo;
}


int main() {
    srand(time(NULL));

    int cordura = 100;
    int hora = 0;
    int minuto = 0;

    cout << "=========================================" <<endl;
    cout << "        EL JUEGO DE LA VENTANA" <<endl;
    cout << "=========================================" <<endl;
    cout << "Sobrevive hasta las 6:00 AM." <<endl;
    cout << "Tu cordura bajara o subira dependiendo de tus acciones." <<endl;

    while (true) {
        cout << "-----------------------------------------" <<endl;
        cout << "Hora actual: " << formatoHora(hora, minuto)  <<endl;
        cout << "Cordura: " << cordura <<endl;
        cout << "-----------------------------------------" <<endl;

        if (hora == 6) {
            cout << "¡Has sobrevivido!" <<endl;
            cout << "GANASTE EL JUEGO." <<endl;
            break;
        }

        cout << "Que deseas hacer?" <<endl;
        cout << "1. Mirar por la ventana (-15 cordura)" <<endl;
        cout << "2. Encender/apagar la luz (+5 o -10 cordura)" <<endl;
        cout << "3. Esconderte bajo la cama (+10 cordura)" <<endl;
        cout << "4. Quedarte quieto (-5 cordura)" <<endl;
        cout << "5. Cerrar los ojos (cordura aleatoria)" <<endl;
        cout << "Opcion: ";

        int opcion;
        cin >> opcion;

        switch(opcion) {
            case 1:
                cordura = modificarCordura(cordura, -15);
                cout << "Sientes que algo te observa..." <<endl;
                break;

            case 2: {
                int r = rand() % 2;
                if (r == 0) {
                    cordura = modificarCordura(cordura, +5);
                    cout << "La luz te hace sentir mas seguro." <<endl;
                } else {
                    cordura = modificarCordura(cordura, -10);
                    cout << "La habitacion se vuelve mas oscura..." <<endl;
                }
                break;
            }

            case 3:
                cordura = modificarCordura(cordura, +10);
                cout << "Te escondes y respiras profundo..." <<endl;
                break;

            case 4:
                cordura = modificarCordura(cordura, -5);
                cout << "El Eco de los alaridos recorren tu espina dorsal..." <<endl;
                break;

            case 5: {
                int cambio = (rand() % 21) - 10;
                cordura = modificarCordura(cordura, cambio);
                cout << "Tus pensamientos divagan..." <<endl;
                break;
            }

            default:
                cout << "Opcion no valida." <<endl;
                continue;
        }

        if (ataqueMonstruo(cordura)) {
            cout << "Algo abre la ventana lentamente..." <<endl;
            cout << "El monstruo te atrapa." <<endl;
            cout << "GAME OVER." <<endl;
            break;
        }

        avanzarTiempo(hora, minuto);
    }

    return 0;
}
