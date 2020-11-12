#include <iostream>
#include <fstream>
#include "Registro.h"
using namespace std;

int main(){
    //se declara un objeto para ayudarnos a manejar la informacion
    registro buffer;
    //se abre el archivo del cual tomaremos la informacion
    ifstream file("AUTOS_PRO.txt");
    //Variables auxiliares para depositar datos relevantes
    int direccionBase, opc;

    inicio:
    cout << "---Menu principal---" << endl << "1- Ejecutar la funcion de dispersion\n2-Mostrar los resultados de la funcion\n3-Mostrar numero de frecuencias\n" << ">>";
    cin >> opc;
    switch(opc){
        case 1:
            for(int i = 0; i < 30; i++){//hacer el siguiente proceso 30 veces
                //Llena el buffer con los datos correspondientes a un registro
                buffer.leerRegistro(file);
                //Regresa la direccion base generada usando el campo placa del registro que este actualmente en el buffer
                direccionBase = buffer.obtenerDireccionBase();
                //hacer algo con la direccion obtenida
            }
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }

    file.close();
    return 0;
}
