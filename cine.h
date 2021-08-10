/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef CINE_H
#define CINE_H
#include "pelicula.h"
#include "boletos.h"
#include "sala.h"
#include "bar.h"
#include "factura.h"
#include <string>
#include <stdlib.h>
class Cine
{
private:
    const int CONTRASENIA = 159951;
    int opc;
    int boletos;
    static const int numeroPeliculas = 5;
    const float PRECIO_BOLETO = 3.15;
    static const int totalProductos = 10;
    Pelicula *cartelera[numeroPeliculas];
    Sala *sala[numeroPeliculas];
    Bar *bar[totalProductos];
    Factura *fact;
public:
    Cine();
    string mostrarCartelera();
    string mostrarSala();
    string comprarBoletos();
    string comprarComida();
    bool filaColumna(char,int);
    string factura();
    string imprimirDescripcion();
    string InterfazAdmin();
    void modificarPelicula();
};

#endif // CINE_H
