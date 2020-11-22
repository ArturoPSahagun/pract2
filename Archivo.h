#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "Registro.h"

class Archivo{
    private:
        std::string nombreArchivo;
    public:
        Archivo(std::string);
        void nuevoRegistro(registro nuevoReg, string&);
        void mostrarTodos();
        void avanzarCampo(fstream&);
        void avanzarRegistro(fstream&);
        string leerCampo(fstream&, int);
        string leerCampo(fstream&);

};
using namespace std;

Archivo::Archivo(std::string A)
{//Inicializador del Archivo
    nombreArchivo=A;
    string init(" ");
    ofstream B(A);
    char num[3];//Llenamos el archivo con las 100 direcciones
    for(int i(0);i<100;i++)
    {
        sprintf(num,"%d",i);
        if(num[1]=='\0')
        {
         num[1]=num[0];
         num[0]='0';
         num[2]='\0';
        }
        B<<num<<" "<<init<<" \n";
    }

}

void Archivo::nuevoRegistro(registro nuevoReg,string& dirBase)
{
    fstream newIn(nombreArchivo);//Abrimos un archivo de entrada y salida
    string temp;

    for(;!newIn.eof();avanzarRegistro(newIn))//Ciclo para recorrer el archivo
    {
        temp=leerCampo(newIn,2);//Leer el campo direccion en el que nos encontramos
    if(temp==dirBase)//Comparar con la direccion base que se nos masndo
    {

       avanzarCampo(newIn);//Avanzamos al campo donde se ingresa el registro
       //newIn.seekp(-1,ios_base::cur);
      ///newIn.write(nuevoReg.Archivo().c_str(),nuevoReg.Archivo().size());
        //Escribimos el registro en el archivo, con el comando "write"
        newIn<<nuevoReg.Archivo();
    }

    }
    newIn.close();
}
void Archivo::avanzarCampo(fstream& nuevoR)
{
    for(char c; c != ' ' && !nuevoR.eof(); c = nuevoR.get());
}


void Archivo::avanzarRegistro(fstream& nuevoR)
{
    string s;
    getline(nuevoR,s);
}
string Archivo::leerCampo(fstream& nuevoR, int totalCaracteres)
{
    string s;
    for(int i = 0; i < totalCaracteres; i++)
    {
        s += nuevoR.get();
    }
    return s;
}

string Archivo::leerCampo(fstream& nuevoR){
    //leemos caracter a caracter y lo vamos depositando en una string hasta encontrar un espacio
    string s;
    for(char c; c != ' ' && !nuevoR.eof(); c = nuevoR.get())
        s += c;
    //se borra el primer caracter que es algo especial y causa problemas
    s.erase(0, 1);
    return s;
}

#endif // ARCHIVO_H_INCLUDED
