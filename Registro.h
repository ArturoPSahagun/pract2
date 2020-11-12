#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class registro{
private:
public:
    char placa[12],
        nombre[30],
        domicilio[20],
        provincia[20];

    void leerRegistro(ifstream&);
    int obtenerDireccionBase();
};

void registro::leerRegistro(ifstream& file){
    file.getline(placa, 12, '|');
    file.getline(nombre, 30, '|');
    file.getline(domicilio, 20, '|');
    file.getline(provincia, 20);
}

int registro::obtenerDireccionBase(){
    int formaNumerica[8];
    for(int i = 0; i < 8; i++)
        formaNumerica[i] = placa[i];

    int numerosConcatenados[4];
    for(int i = 0; i < 4; i++)
        numerosConcatenados[i] = stoi( to_string(formaNumerica[i*2]) + to_string(formaNumerica[(i*2) + 1]));

    int s=numerosConcatenados[0];

    for(int i = 1; i < 4; i++){
        s+=numerosConcatenados[i];
        s = s%20000;
    }

    return s%101;
}
