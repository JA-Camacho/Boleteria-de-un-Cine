/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef FACTURA_H
#define FACTURA_H
#include <vector>
#include "cliente.h"
class Factura : public Cliente
{
private:
    string nombreCine;
    string ruc;
    int espaciado1 = 70;
    int espaciado2 = 73;
public:
    Factura();
    Factura(string cedula, string nombre, string direccion, string telefono);
    string imprimirDatos();
};

#endif // FACTURA_H
