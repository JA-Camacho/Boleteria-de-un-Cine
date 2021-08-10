/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "sala.h"

Sala::Sala()
{
    this->fcol=0;
    this->fnum=0;
    this->fila='\0';
    this->col='\0';
    this->crearSala();
}

bool Sala::crearSala()
{
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]='0';
        }
    }
    return true;
}

bool Sala::asignarSala(char fila, int col)
{
    if(fila=='A'|| fila=='a'){
        fnum=0;
    }else if(fila=='B'|| fila=='b'){
        fnum=1;
    }else if(fila=='C' || fila=='c'){
        fnum=2;
    }else if(fila=='D' || fila == 'd'){
        fnum=3;
    }else if(fila=='E' || fila=='e'){
        fnum=4;
    }
    if(col==1){
        fcol=0;
    }else if(col==2){
        fcol=1;
    }else if(col==3){
        fcol=2;
    }else if(col==4){
        fcol=3;
    }else if(col==5){
        fcol=4;
    }

    if(arr[fnum][fcol]=='X'){
        cout << "El Asiento esta OCUPADO. Escoja otro asiento"<<endl;
        return false;
    }else{
        arr[fnum][fcol]='X';
    }
    return true;
}

void Sala::sala()
{
    //cout << setw(3)<< " ";
    for(int k=1;k<6;k++){
        cout << setw(2) <<" "<< k  << " ";
    }
    cout << endl;
    for(int i=0;i<5;i++){
        if(i==0){
            cout <<"A ";
        }else if(i==1){
            cout << "B ";
        }else if(i==2){
            cout << "C ";
        }else if(i==3){
            cout << "D ";
        }else if(i==4){
            cout << "E ";
        }
        for(int j=0;j<5;j++){
            cout <<arr[i][j]<<"   ";
        }
        cout << endl;
    }
    cout << endl;
}
int Sala::numAsientos()
{
    int contador=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(arr[i][j]=='0'){
                contador++;
            }
        }
    }
    return contador;
}
