/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef SALA_H
#define SALA_H
#include <string>
using namespace std;

class Sala
{
private:
    char arr[5][5];
    int fnum;
    int fcol;
    char fila;
    int col;
    bool crearSala();
public:
    Sala();
    bool asignarSala(char,int);
    void sala();
    int numAsientos();
};

#endif // SALA_H
