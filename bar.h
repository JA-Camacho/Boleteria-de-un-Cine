/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef BAR_H
#define BAR_H
#include <string>
#include "correccion.h"
using namespace std;
class Bar
{
private:
    int id;
    string nombre;
    float precio;
    bool comprado;
    int cantidad;
public:
    Bar();
    Bar(string nombre, float precio);
    static int totalProductos;
    string getDatos();
    float comprar();
    bool getComprado() const;
    string getNombre() const;
    float getPrecio() const;
    int getCantidad() const;
    float totalProducto();
    void setCantidad(int value);
    void setComprado(bool value);
};

#endif // BAR_H
