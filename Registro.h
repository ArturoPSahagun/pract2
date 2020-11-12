#include <iostream>
#include <fstream>
using namespace std;

class registro{
private:
public:
    char placa[12],
        nombre[30],
        domicilio[20],
        provincia[20];

    void leerRegistro(ifstream&);
};

void registro::leerRegistro(ifstream& file){
    file.getline(placa, 12, '|');
    file.getline(nombre, 30, '|');
    file.getline(domicilio, 20, '|');
    file.getline(provincia, 20);
}
