/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include "cliente.h"

string Cliente::getNombre() const
{
    return nombre;
}

string Cliente::getCi() const
{
    return ci;
}

string Cliente::getDireccion() const
{
    return direccion;
}

void Cliente::setDireccion(const string &value)
{
    direccion = value;
}

string Cliente::getTelefono() const
{
    return telefono;
}

Cliente::Cliente()
{
    this->ci = "9999999999";
    this->direccion = "N/A";
    this->nombre = "CONSUMIDOR FINAL";
    this->telefono = "9999999999";
}

Cliente::Cliente(string cedula, string nombre, string direccion, string telefono)
{
    this->ci = cedula;
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
}
