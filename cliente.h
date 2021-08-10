/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

class Cliente
{
private:
    string nombre;
    string ci;
    string direccion;
    string telefono;

public:
    Cliente();
    Cliente(string cedula, string nombre, string direccion, string telefono);
    string getNombre() const;
    string getCi() const;
    string getDireccion() const;
    void setDireccion(const string &value);
    string getTelefono() const;
};

#endif // CLIENTE_H
