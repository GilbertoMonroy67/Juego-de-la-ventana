#include <iostream>
#include <string>
using namespace std;

void mostrarIntroduccion() {
    cout << "La noche ha caiddo. Son las 11:00 p.m. y estas en tu habitacion.\n";
    cout << "Debes resistir hasta las 5:00 a.m. para sobrevivir.\n\n";
}

// -------------------------------------
// Escenas
// -------------------------------------
void escena1() {
    int op;
    cout << "11:00 p.m. - Escena 1\n";
    cout << "El silencio es perturbador. A las 11:30 p.m., escuchas un rasgu�o en la ventana.\n\n";

    cout << "Opciones:\n";
    cout << "1. Mantenerte inmovil.\n";
    cout << "2. Taparte los oidos.\n";
    cout << "3. Gritar o reaccionar con miedo.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "Permanece en silencio. El rasgu�o se detiene...\n\n"; break;
        case 2: cout << "Te tapas los oidos. Aun asi sientes el rasgu�o...\n\n"; break;
        case 3: cout << "Gritas. El rasgu�o se detiene por un momento...\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void escena2() {
    int op;
    cout << "12:00 a.m. - Escena 2\n";
    cout << "Sientes un aliento frio en tu rostro, un susurro helado te eriza la piel.\n\n";

    cout << "Opciones:\n";
    cout << "1. Respirar lentamente y mantener la calma.\n";
    cout << "2. Taparte la cara con las manos.\n";
    cout << "3. Abrir los ojos y mirar al ente.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "Respiras lento... el frio se aleja unos centimetros.\n\n"; break;
        case 2: cout << "Te tapas la cara, pero el frio se intensifica.\n\n"; break;
        case 3: cout << "Abres los ojos. Una sombra se mueve frente a ti...\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void escena3() {
    int op;
    cout << "1:00 a.m. - Escena 3\n";
    cout << "Un golpe fuerte sacude la ventana. La habitacion vibra.\n\n";

    cout << "Opciones:\n";
    cout << "1. Ignorar el golpe y permanecer inmovil.\n";
    cout << "2. Mirar hacia la ventana con cautela.\n";
    cout << "3. Intentar abrir la ventana.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "Permaneces inmovil... el golpe no se repite.\n\n"; break;
        case 2: cout << "Miras la ventana. Algo se movio...\n\n"; break;
        case 3: cout << "Intentas abrirla, pero esta trabada.\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void escenaEspecial() {
    int op;
    cout << "2:30 a.m. - Escena Especial\n";
    cout << "Silencio absoluto. El ente parece haberse retirado, pero no confies.\n\n";

    cout << "Opciones:\n";
    cout << "1. Mantenerte inmovil y esperar.\n";
    cout << "2. Mirar alrededor con cautela.\n";
    cout << "3. Intentar moverte lentamente.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "No te mueves... el silencio permanece.\n\n"; break;
        case 2: cout << "Miras alrededor, pero no ves nada.\n\n"; break;
        case 3: cout << "Te mueves un poco... el piso cruje.\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void escena4() {
    int op;
    cout << "3:00 a.m. - Escena 4\n";
    cout << "El aliento frio vuelve. Lo sientes detras de ti.\n\n";

    cout << "Opciones:\n";
    cout << "1. Respirar lentamente y mantener la calma.\n";
    cout << "2. Taparte la cara con las manos.\n";
    cout << "3. Abrir los ojos y mirar al ente.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "Controlas tu respiracion. El frio se aleja...\n\n"; break;
        case 2: cout << "Te cubres, pero el ente se acerca mas.\n\n"; break;
        case 3: cout << "Lo miras. Una sombra enorme se inclina hacia ti...\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void escena5() {
    int op;
    cout << "4:00 a.m. - Escena 5\n";
    cout << "Un golpe final sacude la ventana. La habitacio tiembla.\n\n";

    cout << "Opciones:\n";
    cout << "1. Ignorar el golpe y permanecer inmovil.\n";
    cout << "2. Mirar hacia la ventana con cautela.\n";
    cout << "3. Intentar abrir la ventana.\n";
    cout << "Elige una opcion: ";
    cin >> op;

    switch(op) {
        case 1: cout << "Te mantienes inmovil... el golpe cesa.\n\n"; break;
        case 2: cout << "Observas la ventana... una figura se aleja.\n\n"; break;
        case 3: cout << "Intentas abrirla nuevamente, pero sigue cerrada.\n\n"; break;
        default: cout << "Opcion no valida.\n\n"; break;
    }
}

void finalJuego() {
    cout << "5:00 a.m. - Amanecer\n";
    cout << "La luz del sol entra por la ventana.\n";
    cout << "Has sobrevivido a la noche! El ente desaparece.\n";
}

int main() {
    mostrarIntroduccion();

    escena1();
    escena2();
    escena3();
    escenaEspecial();
    escena4();
    escena5();

    finalJuego();

    return 0;
}

