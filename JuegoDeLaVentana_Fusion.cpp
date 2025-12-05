#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <string>

using namespace std;


void dramaticPause(int seconds);

struct Scene {
    int hour;
    int minute;
    string description;
    vector<string> options;
    vector<int> corduraChanges;
};

bool ataqueMonstruo(int cordura) {
    int prob = rand() % 100;
    
    if (cordura > 60) {
        return (prob < 5);
    } 
    else if (cordura > 40) {
        return (prob < 20); 
    } 
    else if (cordura > 20) {
        return (prob < 40);  
    } 
    else {
        return (prob < 60); 
    }
}

void eventoAleatorio(int& cordura, int currentHour) {
    int random = rand() % 100;
    
    if (random < 30) {  
        cout << "\nEVENTO ALEATORIO\n";
        int evento = rand() % 3;
        
        if (evento == 0) {
            cout << "Escuchas pasos en el pasillo fuera de tu habitacion...\n";
            cordura -= 5;
            cout << "Cordura: -5\n";
        } else if (evento == 1) {
            cout << "Un trueno retumba en la distancia. La tormenta se acerca.\n";
            cordura -= 8;
            cout << "Cordura: -8\n";
        } else {
            cout << "Tu telefono vibra misteriosamente en la oscuridad.\n";
            cordura -= 3;
            cout << "Cordura: -3\n";
        }
        dramaticPause(2);
    }
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int showMainMenu() {
    clearScreen();
    cout << "\n";
    cout << "     JUEGO DE LA VENTANA - EL ENTE        \n";
    cout << "\n\n";
    cout << "1. Iniciar juego\n";
    cout << "2. Instrucciones\n";
    cout << "3. Salir\n\n";
    cout << "Selecciona una Opcion: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    return choice;
}

void showInstructions() {
    clearScreen();
    cout << "\n";
    cout << "            INSTRUCCIONES                  \n";
    cout << "\n\n";
    cout << "Objetivo:\n";
    cout << "Debes mantener tu cordura y sobrevivir hasta las 5:00 a.m.,\n";
    cout << "momento en el cual el sol saldra y el ente desaparecera.\n\n";
    
    cout << "Mecanicas:\n";
    cout << "- Tu cordura comienza en 100.\n";
    cout << "- Si la cordura llega a 0, pierdes.\n";
    cout << "- Cada accion tiene consecuencias diferentes.\n";
    cout << "- El ente atacara en momentos especificos.\n";
    cout << "- Tu cordura baja determina la probabilidad de ataque.\n\n";
    
    cout << "Eventos del Ente:\n";
    cout << "- Rasgunia \n";
    cout << "- Respira en tu cara \n";
    cout << "- Golpea la ventana \n";
    cout << "- Silencio absoluto\n\n";
    
    cout << "Presiona Enter para continuar...";
    cin.ignore();
    cin.get();
}

void displayStatus(int currentHour, int currentMinute, int cordura) {
    cout << "Hora: " << (currentHour < 10 ? "0" : "") << currentHour 
         << ":" << (currentMinute < 10 ? "0" : "") << currentMinute;
    
    // Barra visual de cordura
    cout << "\nCordura: [";
    int barLength = cordura / 10;
    for (int i = 0; i < 10; i++) {
        if (i < barLength) {
            cout << "|";
        } else {
            cout << "-";
        }
    }
    cout << "] " << cordura << "/100\n";
}

void dramaticPause(int seconds) {
    Sleep(seconds * 1000);  // Usar Sleep de windows.h en lugar de this_thread
}

void startGame() {
    clearScreen();
    int cordura = 100;
    int currentHour = 23; 
    int currentMinute = 0;
    
    clearScreen();
    cout << "\n";
    cout << "                   INTRODUCCIoN                      \n";
    cout << "\n\n";
    cout << "La noche ha caido. Son las 11:00 p.m. y te encuentras\n";
    cout << "en tu habitacion con la ventana cerrada y las cortinas\n";
    cout << "echadas. Debes mantener tu cordura y resistir hasta las\n";
    cout << "5:00 a.m., cuando el sol saldra y el ente desaparecera.\n\n";
    cout << "Tu ventana empieza a hacer ruidos extranios...\n\n";
    cout << "Presiona Enter para continuar...";
    cin.get();
    
    clearScreen();
    displayStatus(23, 30, cordura);
    cout << "\nESCENA 1 - 11:30 p.m.\n";
    cout << "El silencio es perturbador. De repente, a las 11:30 p.m.,\n";
    cout << "escuchas un RASGUniO en la ventana. CRRRRASH!\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Mantenerte inmovil \n";
    cout << "2. Taparte los oidos \n";
    cout << "3. Gritar o reaccionar con miedo \n";
    cout << "\nTu Opcion: ";
    int choice;
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 5);
        cout << "\nMantienes la calma relativa.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 10);
        cout << "\nTe tapas los oidos pero el sonido sigue resonando en tu mente.\n";
    } else {
        cordura = max(0, cordura - 15);
        cout << "\nGritas de miedo! El ente parece alimentarse de tu terror.\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nEL ENTE INTENTA ENTRAR!\n";
        cordura = max(0, cordura - 20);
        cout << "Logras cerrar la ventana. Cordura: -20\n";
    }
    
    eventoAleatorio(cordura, 23);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "No aguantas mas. Tu mente colapsa.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    displayStatus(0, 0, cordura);
    cout << "\nESCENA 2 - 12:00 a.m. (Medianoche)\n";
    cout << "A la medianoche, sientes un aliento frio en tu rostro.\n";
    cout << "Un susurro helado te eriza la piel. El ente esta aqui.\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Respirar lentamente y mantener la calma \n";
    cout << "2. Taparte la cara con las manos \n";
    cout << "3. Abrir los ojos y mirar al ente \n";
    cout << "\nTu Opcion: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 8);
        cout << "\nRespiras profundamente. Es desagradable pero manejable.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 12);
        cout << "\nEl aliento se siente aun mas cerca.\n";
    } else {
        cordura = max(0, cordura - 30);
        cout << "\nABRISTE LOS OJOS! Ve algo imposible de describir.\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nEL ENTE TE AGARRA!\n";
        cordura = max(0, cordura - 25);
        cout << "Logras escapar! Cordura: -25\n";
    }
    
    eventoAleatorio(cordura, 0);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "Ya no puedes mas. El ente gana.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    displayStatus(1, 0, cordura);
    cout << "\nESCENA 3 - 1:00 a.m.\n";
    cout << "A la 1:00 a.m., un GOLPE FUERTE sacude la ventana.\n";
    cout << "CRASH! La habitacion vibra violentamente.\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Ignorar el golpe y permanecer inmovil\n";
    cout << "2. Mirar hacia la ventana con cautela \n";
    cout << "3. Intentar abrir la ventana \n";
    cout << "\nTu Opcion: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 10);
        cout << "\nIgnoras el golpe. Tu corazon late a mil por hora.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 18);
        cout << "\nMiras cautelosamente. Ves una sombra moverse en la ventana.\n";
    } else {
        cordura = max(0, cordura - 35);
        cout << "\nAbres la ventana! El ente intenta entrar.\n";
        cout << "LA CIERRAS RaPIDO!\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nGOLPES MaS FUERTES!\n";
        cordura = max(0, cordura - 15);
        cout << "El cristal casi se rompe. Cordura: -15\n";
    }
    
    eventoAleatorio(cordura, 1);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "No soportas mas. Tu mente se rinde.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    displayStatus(2, 30, cordura);
    cout << "\nESCENA 4 - 2:30 a.m. [SILENCIO MORTAL]\n";
    cout << "A las 2:30 a.m., de repente, el silencio inunda la habitacion.\n";
    cout << "No escuchas nada. El ente parece haberse retirado.\n";
    cout << "Pero... es realmente seguro?\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Mantenerte inmovil y esperar \n";
    cout << "2. Mirar alrededor con cautela \n";
    cout << "3. Intentar moverte lentamente \n";
    cout << "\nTu Opcion: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 5);
        cout << "\nEsperas. El silencio es ensordecedor.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 8);
        cout << "\nMiras alrededor lentamente. Todo parece normal.\n";
        cout << "Demasiado normal.\n";
    } else {
        cordura = max(0, cordura - 20);
        cout << "\nAl moverte, escuchas un GRUniIDO INHUMANO.\n";
        cout << "EL ENTE ESTABA ESPERANDO!\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nPRESENCIA ATERRADORA!\n";
        cordura = max(0, cordura - 18);
        cout << "Sientes como si algo invisiblemente te tocara. Cordura: -18\n";
    }
    
    eventoAleatorio(cordura, 2);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "La presencia invisible te consume.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    displayStatus(3, 0, cordura);
    cout << "\nESCENA 5 - 3:00 a.m.\n";
    cout << "A las 3:00 a.m., el aliento frio vuelve a acercarse a ti.\n";
    cout << "Helando tu piel. El ente sigue aqui.\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Respirar lentamente y mantener la calma \n";
    cout << "2. Taparte la cara con las manos \n";
    cout << "3. Abrir los ojos y mirar al ente \n";
    cout << "\nTu Opcion: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 6);
        cout << "\nRespiras lentamente. Casi logras tranquilizarte.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 14);
        cout << "\nTe tapas nuevamente. El aliento se intensifica.\n";
    } else {
        cordura = max(0, cordura - 25);
        cout << "\nAbres los ojos. Ves la sombra mas cerca.\n";
        cout << "ESTa ADENTRO!\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nuLTIMO INTENTO DEL ENTE!\n";
        cordura = max(0, cordura - 22);
        cout << "Da todo lo que tiene para asustarte. Cordura: -22\n";
    }
    
    eventoAleatorio(cordura, 3);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "El ataque final te destruye mentalmente.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    displayStatus(4, 0, cordura);
    cout << "\nESCENA 6 - 4:00 a.m.\n";
    cout << "A las 4:00 a.m., un GOLPE FINAL sacude la ventana.\n";
    cout << "CRASH! Haciendo que la habitacion tiemble violentamente.\n";
    cout << "Parece el ultimo ataque del ente.\n";
    dramaticPause(3);
    
    cout << "\nQue haces?\n";
    cout << "1. Ignorar el golpe y permanecer inmovil \n";
    cout << "2. Mirar hacia la ventana con cautela \n";
    cout << "3. Intentar abrir la ventana \n";
    cout << "\nTu Opcion: ";
    cin >> choice;
    cin.ignore();
    
    if (choice == 1) {
        cordura = max(0, cordura - 8);
        cout << "\nResistes el ultimo ataque. Casi estas libre.\n";
    } else if (choice == 2) {
        cordura = max(0, cordura - 16);
        cout << "\nMiras. El ente esta furioso.\n";
    } else {
        cordura = max(0, cordura - 28);
        cout << "\nLo intentaste de nuevo! El ente casi te arrastra.\n";
        cout << "Cierras rapido.\n";
    }
    
    if (ataqueMonstruo(cordura)) {
        cout << "\nuLTIMO ASALTO!\n";
        cordura = max(0, cordura - 20);
        cout << "El ente da todo. Cordura: -20\n";
    }
    
    eventoAleatorio(cordura, 4);
    dramaticPause(2);
    
    if (cordura <= 0) {
        clearScreen();
        cout << "TU CORDURA SE QUIEBRA\n\n";
        cout << "Tu mente no aguanta mas.\n";
        cout << "GAME OVER - DERROTA\n";
        cout << "Cordura Final: 0/100\n";
        cout << "\nPresiona Enter para volver al menu...";
        cin.get();
        return;
    }
    
    clearScreen();
    cout << "\n";
    cout << "              AMANECER - 5:00 a.m.                 \n";
    cout << "\n\n";
    
    cout << "LA LUZ DEL SOL COMIENZA A FILTRARSE POR LA VENTANA\n\n";
    cout << "Has resistido hasta las 5:00 a.m.\n";
    cout << "El ente se desvanece con los primeros rayos del sol.\n";
    cout << "Has ganado.\n\n";
    cout << "VICTORIA!!!!!\n";
    cout << "Cordura Final: " << cordura << "/100\n\n";
    
    if (cordura >= 80) {
        cout << "Casi sin danio mental! Eres muy valiente.\n";
    } else if (cordura >= 50) {
        cout << "Has sobrevivido, pero el trauma esta ahi.\n";
    } else if (cordura > 0) {
        cout << "Apenas sobreviviste. Necesitaras terapia...\n";
    }
    
    cout << "\nPresiona Enter para volver al menu...";
    cin.get();
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int menuChoice;
    
    do {
        menuChoice = showMainMenu();
        
        switch (menuChoice) {
            case 1:
                startGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                cout << "\nHasta luego!\n";
                return 0;
            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
                cin.ignore();
                cin.get();
        }
    } while (true);
    
    return 0;
}