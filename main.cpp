#include <iostream>
#include <fstream>
#include "Registro.h"
#define TAMREG 86
using namespace std;

int main(){
    //se declara un objeto para ayudarnos a manejar la informacion
    registro buffer;
    //se abre el archivo del cual tomaremos la informacion
    ifstream file("AUTOS_PRO.txt");
    //Variables auxiliares para depositar datos relevantes
    int direccionBase, opc, frecuencias[100];
    //se crean los archivos donde guardaremos
    //los datos y las frecuencias
    ofstream escrFrec("FRECUENCIAS.txt", ios::trunc);
    //cada registro tendra un tamaño de 82 caracteres + 3 de los delimitadores + 1 del salto de linea para un total de 86
    ofstream escrDB("AUTOS.txt", ios::trunc);
    //iteramos 100 veces, una para cada compartimiento
    for(int i = 0; i < 100; i++){
    //escribimos 85 espacios + un salto de linea en cada compartimiento, dandonos los 86
        for(int j = 0; j < TAMREG-1; j++)
            escrDB << " ";
        escrDB << endl;
        //de una vez también preparamos el archivo de las frecuencias, escribiendolas todas a 0
        escrFrec << "(0)" << endl;
    }
    //ahora creamos un objeto nos ayude a leer de estos archivos
    ifstream lectDB("AUTOS.txt");
    ifstream lectFrec("FRECUENCIAS.txt");
    inicio:
    cout << "---Menu principal---" << endl << "1-Ejecutar la funcion de dispersion\n2-Mostrar los resultados de la funcion\n3-Mostrar numero de frecuencias\n" << ">>";
    cin >> opc;
    switch(opc){
        case 1:
            while( ! file.eof()){//mientras no se llegue al final del archivo
                //Llena el buffer con los datos correspondientes a un registro
                buffer.leerRegistro(file);
                //Regresa la direccion base generada usando el campo placa del registro que este actualmente en el buffer
                direccionBase = buffer.obtenerDireccionBase();
                //se pone el indicador de escritura en la direcion base multiplicada por el tamaño del registro
                escrDB.seekp(direccionBase*TAMREG);
                //se hace lo mismo con un indicador de lectura
                lectDB.seekg(direccionBase*TAMREG);
                //se comprueba si el espacio esta vacio, osea, si empieza con un espacio
                if(lectDB.get() == 32)
                    escrDB << buffer.toString();//se escribe lo del buffer al archivo
                //ahora se registará la existencia de este campo en la tabla de frecuencias.
                //4 es el tamaño de cada registro porque (0) + salto de linea
                escrFrec.seekp((direccionBase*4) + 1);
                //se hace lo mismo para la escritura, adelantandonos uno para tomar el numero en vez del (
                lectFrec.seekg((direccionBase*4) + 1);
                //se aumenta en uno al valor que ya se tiene
                escrFrec << lectFrec.get() - '0' + 1;
            }
            break;
        case 2:{
            //ubicamos el indicador de lectura al inicio del archivo
            lectDB.seekg(0);
            //variable auxiliar que nos ayudara a leer desde la "base de datos"
            char aux[TAMREG+1];
            //iteramos a lo largo de los 100 compartimientos
            for(int i = 0; i < 100; i++){
                //Se lee un registro
                lectDB.getline(aux, TAMREG);
                //Se escribe en la consola
                cout << i << " " << aux << endl;
            }
            break;
        }
        case 3:{
            //ubicamos el indicador de lectura al inicio del archivo
            lectFrec.seekg(0);
            //variable auxiliar que nos ayudara a leer desde la lista de frecuencias
            char aux[4+1];
            //iteramos a lo largo de los 100 compartimientos
            for(int i = 0; i < 100; i++){
                //Se lee un registro
                lectFrec.getline(aux, 4);
                //Se escribe en la consola
                cout << i << " " << aux << endl;
            }
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
    if(opc) goto inicio;
    //Cerramos los archivos utilizados
    file.close();
    escrDB.close();
    lectDB.close();
    escrFrec.close();
    lectFrec.close();
    return 0;
}
