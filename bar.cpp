/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include "bar.h"

bool Bar::getComprado() const
{
    return comprado;
}

string Bar::getNombre() const
{
    return nombre;
}

float Bar::getPrecio() const
{
    return precio;
}

int Bar::getCantidad() const
{
    return cantidad;
}

float Bar::totalProducto()
{
    return cantidad * precio;
}

void Bar::setCantidad(int value)
{
    cantidad = value;
}

void Bar::setComprado(bool value)
{
    comprado = value;
}

Bar::Bar()
{
    this->id = totalProductos;
    this->nombre = "\0";
    this->precio = 0.0;
    this->comprado = false;
    this->cantidad = 0;
}

Bar::Bar(string nombre, float precio)
{
    this->id = totalProductos;
    this->nombre = nombre;
    this->precio = precio;
    totalProductos++;
    this->comprado = false;
    this->cantidad = 0;
}

string Bar::getDatos()
{
    return  "[" + to_string(this->id) + "] " + this->nombre
            + "  $" + to_string_con_precision(this->precio, 2);
}

float Bar::comprar()
{
    this->comprado = true;
    this->cantidad++;
    return precio;
}
