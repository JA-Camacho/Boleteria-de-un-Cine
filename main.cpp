/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include <iostream>
#include "cine.h"
#include <vector>
int Pelicula::totalPeliculas = 1;
int Bar::totalProductos = 1;
using namespace std;
int main()
{
    system("color 0E");
    int opc;
    cout << "\t\t- - M I  C I N E - -\n";
    Cine controlador;
    do
    {
        cout << "+ + MENU PRINCIPAL + +"
                "\n1. Salir"
                "\n2. Mostrar Cartelera"
                "\n3. Mostrar Sala"
                "\n4. Comprar Boletos"
                "\n5. Bar"
                "\n6. Factura"
                "\n7. Administrador"
                "\nIngrese su opcion: ";
        if (!(cin >> opc))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nERROR: No reconozco esa opcion\n"
                    "Vuelva a intentarlo\n\n";
            continue;
        }
        switch (opc)
        {
        case 1:
            cout << "\n--Gracias por utilizar el programa!--"
                    "\n\t==Hasta Pronto==\n";
            break;
        case 2:
            cout << controlador.mostrarCartelera();
            break;
        case 3:
            cout << controlador.mostrarSala();
            break;
        case 4:
            controlador.comprarBoletos();
            break;
        case 5:
            cout << controlador.comprarComida();
            break;
        case 6:
            cout << controlador.factura();
            break;
        case 7:
            controlador.InterfazAdmin();
            break;
        default:
            cout << "\nERROR: Comando Desconocido\n"
                    "Vuelva a intentarlo\n\n";
            break;
        }
    }while (opc != 1);
    return 0;
}
