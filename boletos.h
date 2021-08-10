/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef BOLETOS_H
#define BOLETOS_H
#include <iomanip>
#include "pelicula.h"
using namespace std;

class Boletos : public Pelicula
{
private:
    int sala;
    char fila;
    int columna;
    int boleto;
    Pelicula pelicula;
    int separacion = 40;
public:
    Boletos();
    Boletos(int sala, char fila, int columna, Pelicula);
    string mostrarPlano();
    char getFila() const;
    void setFila(char value);
    int getColumna() const;
    void setColumna(int value);
    int getSala() const;
    void setSala(int value);
};

#endif // BOLETOS_H

