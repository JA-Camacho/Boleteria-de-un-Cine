/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#ifndef PELICULA_H
#define PELICULA_H
#include <string>

using namespace std;

class Pelicula
{
private:
    int id;
    string titulo;
    float duracion;
    bool estreno;
    string hora;
    bool comprado;
    int cantidad;
    static int totalPeliculas;
public:
    Pelicula();
    Pelicula(string titulo, float duracion, bool estreno, string hora);
    string toStringEstreno();
    int getId() const;
    string getHora() const;
    string getTitulo() const;
    string getDuracion() const;
    string getDatos();
    void setComprado(bool value);
    bool getComprado() const;
    int getCantidad() const;
    void setCantidad(int value);
    void setEstreno(bool value);
    void setDuracion(float value);
    void setHora(const string &value);
    void setTitulo(const string &value);
};

#endif // PELICULA_H
