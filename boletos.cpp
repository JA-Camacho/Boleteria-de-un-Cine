/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include "boletos.h"
Boletos::Boletos()
{
    this->boleto = 0;
    this->sala = 0;
    this->fila = ' ';
    this->columna = 0;
}

Boletos::Boletos(int sala, char fila, int columna, Pelicula pelicula)
{
    this->sala = sala;
    this->fila = toupper(fila);
    this->columna = columna;
    this->pelicula = pelicula;
    this->separacion -= pelicula.getTitulo().length();
}

string Boletos::mostrarPlano()
{
    char a = -70, b = -55, c = -56, d = -51, e = -69, f = -68;
    string str;
    str = b;
    for (int i =0; i <50; i++)
        str += d;
    str += e;
    str += "\n";
    str += a;
    str += "Sala: " + to_string(sala);
    str += "\t\t\t\t\t   ";
    str += a;
    str += "\n";
    str += a;
    str += "Hora: " + pelicula.getHora();
    str += "\t\t\t\t\t   ";
    str += a;
    str += "\n";
    str += a;
    str += "Asiento: ";
    str += this->fila;
    str += to_string(this->columna);
    str += "\t\t\t\t\t   ";
    str += a;
    str += "\n";
    str += a;
    str += "Pelicula: " + pelicula.getTitulo();
    for(int i = 0; i < separacion; i++)
        str += " ";
    str += a;
    str += "\n";
    str += c;
    for (int i =0; i <50; i++)
        str += d;
    str += f;
    str += "\n";

    return str;
}

int Boletos::getSala() const{
    return sala;
}
void Boletos::setSala(int value){
    sala = value;
}
char Boletos::getFila() const{
    return fila;
}
void Boletos::setFila(char value){
    fila = value;
}
int Boletos::getColumna() const{
    return columna;
}
void Boletos::setColumna(int value){
    columna = value;
}
