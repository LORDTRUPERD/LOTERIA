#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;



void guardarganadores(int numero_ganador){
    auto ahora = chrono::system_clock::now();
    time_t tiempo = chrono::system_clock::to_time_t(ahora);
    string fecha = ctime(&tiempo);
    ofstream archivo;
    archivo.open("ganadores.txt", ios::app);
    if (archivo.is_open()) {
        archivo<<"EL NUMERO GANADOR DEL DIA "<<fecha<< " FUE: "<<numero_ganador<<endl;
    }
    archivo.close();
}

int main() {


    cout << "SISTEMA DE LOTERIA!" << endl;
    cout << "Seleccione un numero para ganar un premio, los numeros disponibles son:" << endl;

    int numeros[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int datos = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < datos; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    int seleccion;
    cout << "Seleccione un numero de los anteriores: ";
    cin >> seleccion;

    if (seleccion <= 0 || seleccion > 10) {
        cout << "LA SELECCION NO ES VALIDA!" << endl;
    } else {
        // Inicializar semilla aleatoria
        srand(time(0));

        // Generar número ganador
        int numero_ganador = rand() % 10 + 1;
        /*
                cout << "Numeros generados: ";
                for (int i = 0; i < 3; i++) {
                    cout << (rand() % 10 + 1) << " ";
                }
        */
        cout << endl;

        if (seleccion == numero_ganador) {
            cout << "HAS SIDO EL GANADOR, FELICIDADES!!" << endl;
            cout << "El numero ganador fue: " << numero_ganador << endl;
            guardarganadores(numero_ganador);
        } else {
            cout << "Lo siento, no has ganado." << endl;
            cout << "El numero ganador fue: " << numero_ganador << endl;
            guardarganadores(numero_ganador);
        }
    }

    return 0;
}