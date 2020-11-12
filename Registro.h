#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class registro{
private:
    //buffer en el cual caben los datos de un registro
    char placa[12],
        nombre[30],
        domicilio[20],
        provincia[20];
public:
    void leerRegistro(ifstream&);
    int obtenerDireccionBase();
};

void registro::leerRegistro(ifstream& file){
    //Se llenan una a una variables del buffer con el dato correspondiente delimitado adecuadamente
    file.getline(placa, 12, '|');
    file.getline(nombre, 30, '|');
    file.getline(domicilio, 20, '|');
    file.getline(provincia, 20);
}

int registro::obtenerDireccionBase(){
    //En un arreglo se depositan los numeros corresponidentes a los caracteres de la placa segun el codigo ascii
    int formaNumerica[8];
    for(int i = 0; i < 8; i++)
        formaNumerica[i] = placa[i];

    //Ahora en un arreglo diferente se depositan en parejas los numeros concatenados
    int numerosConcatenados[4];
    for(int i = 0; i < 4; i++)
        //para esto primero convertimos los valores de la pareja a strings y los unimos
        //luego la string resultante la convertimos a int y la depositamos en su respectiva posicion
        numerosConcatenados[i] = stoi( to_string(formaNumerica[i*2]) + to_string(formaNumerica[(i*2) + 1]));

    //Ahora usaremos una variable entero auxiliar, en la iremos depositando los totales, empezando por el primer elemento
    int s=numerosConcatenados[0];

    for(int i = 1; i < 4; i++){
        //al valor del entero auxiliar le iremos sumando los valores del arreglo de concatenados
        s+=numerosConcatenados[i];
        //antes de sumar el siguiente elemento sacamos modulo para evitar errores de desbordamiento
        s = s%20000;
    }
    //por ultimo regresaremos el modulo de este numero auxiliar entre el numero primo mas cercano
    //al total de posiciones compartimientos disponibles, en este caso 100.
    //de esta manera nos aseguramos que el numero generado este dentro los limites establecidos
    return s%101;
    //este entero corresponde a la direccion base del registro cargado en el buffer en este momento
}
