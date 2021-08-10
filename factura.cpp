/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include "factura.h"
#include <time.h>
Factura::Factura()
{
    this->ruc = "999999999001";
    this->nombreCine = "- - M I  C I N E - -";
    espaciado1 -= Cliente::getNombre().length();
    espaciado2 -= Cliente::getDireccion().length();
}

Factura::Factura(string cedula, string nombre, string direccion, string telefono) : Cliente(cedula, nombre, direccion, telefono)
{
    this->ruc = "999999999001";
    this->nombreCine = "- - M I  C I N E - -";
    espaciado1 -= Cliente::getNombre().length();
    espaciado2 -= Cliente::getDireccion().length();
}

string Factura::imprimirDatos()
{
    char a = -38, b = -60, c = -65, d = -77, e = -61, g = -76, h = -64, i = -39;
    string str;
    //Cabecera
    str = "\n- - FACTURA - -\n";
    str += a;
    for (int i = 0; i <=78; i++)
    {
        str += b;
    }
    str = str + c + "\n";
    //Datos del cine
    //Nombre cine
    str = str + d + "\t\t\t" + nombreCine;
    for (int i = 1; i < 37; i ++)
        str += " ";
    str += d;
    //RUC
    str = str + "\n" + d + "RUC " + ruc;
    for (int i = 0; i < 63; i++){
        str += " ";}
    str += d;
    //Direccion
    str = str + "\n" + d + "Dir: Rumichaca y Moran Valverde s/n";
    for(int i = 0; i < 44; i++)
        str += " ";
    str += d;
    //Telefono
    str = str + "\n" + d + "Telf: 0999999999";
    for (int i = 0; i < 63; i++)
        str += " ";
    str += d;
    //Obligado a llevar contabilidad
    str = str + "\n" + d + "OBLIGADO A LLEVAR CONTABILIDAD: Si";
    for (int i = 0; i < 45; i++)
        str += " ";
    str += d;

    str = str + "\n" + e ;
    for (int i = 0; i <=78; i++){
        str += b;}
    str += g;
    //Datos del cliente
    //Nombre
    str = str + "\n" + d + "Nombre: " + Cliente::getNombre();
    for (int i = 0; i <= espaciado1; i++){
        str += " ";}
    str += d;
    //Cedula/CI
    str = str + "\n" + d + "CI/RUC: " + Cliente::getCi();
    int saltos;
    if(Cliente::getCi().length() == 10)
        saltos = 61;  //CI
    else
        saltos = 58;  //RUC
    for (int i = 0; i < saltos; i ++)
        str += " ";
    str += d;

    //Direccion
    str = str + "\n" + d + "Dir: " + Cliente::getDireccion();
    for(int i = 0; i <= espaciado2; i++)
        str += " ";
    str += d;

    //Numero
    str = str + "\n" + d + "Telf: " + Cliente::getTelefono();
    for (int i = 0; i < 63; i++)
        str += " ";
    str += d;

    //Resumen de la compra
    str = str + "\n" + e ;
    for (int i = 0; i <=78; i++){
        str += b;}
    str += g;

    str = str + "\n" + d + " Cant " + d + "\t\tDescripcion\t\t\t" + d + " Precio U. " + d + " Precio T. " + d;

    str = str + "\n" + h;
    for (int i = 0; i <= 78; i++)
        str += b;
    str = str + i +"\n";
    return str;
}
