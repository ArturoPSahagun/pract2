#include <iostream>
#include <fstream>
#include "Registro.h"
#include "Archivo.h"
#include <sstream>
using namespace std;

int main(){
    //se declara un objeto para ayudarnos a manejar la informacion
    registro buffer;
    //se abre el archivo del cual tomaremos la informacion
    ifstream file("AUTOS_PRO.txt");
    //Variables auxiliares para depositar datos relevantes
    int direccionBase, opc;
    string temp,s;
    stringstream ss;

    //inicio:
    do
    {
    cout << "\n \n ---Menu principal---" << endl << "\n 1- Ejecutar la funcion de dispersion\n 2- Mostrar los resultados de la funcion\n 3- Mostrar numero de frecuencias\n 0- Salir" <<"\n >> ";
    cin >> opc;
    switch(opc){
        case 1:
            {
            Archivo Admin("autoReg.txt");
            for(int i = 0; i < 30; i++){//hacer el siguiente proceso 30 veces
                //Llena el buffer con los datos correspondientes a un registro
                buffer.leerRegistro(file);
                direccionBase=buffer.obtenerDireccionBase();
                ss<<direccionBase;
                ss>>s;
                //Regresa la direccion base generada usando el campo placa del registro que este actualmente en el buffer
                Admin.nuevoRegistro(buffer,s);//Mandamos a c¿guardad el registro mandando como parametros el buffer y la direccion
                ss.str("");
                ss.clear();
                        }
                ifstream Arch("autoReg.txt");
                while(Arch.good())
                        cout << (char)Arch.get();
                Arch.close();

            } break;
        case 0: cout<<"\n Hasta Pronto..."<<endl;
                break;
        default: cout << "Opcion invalida" << endl;
    }

    }while(opc!=0);
    file.close();
    return 0;
}
