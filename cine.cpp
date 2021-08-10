/*Gilmar Campoverde:
 gcampoverdea@est.ups.edu.ec
 *José Camacho:
 jcamachor1@est.ups.edu.ec
*Joel Corrales:
 jcorralesg@est.ups.edu.ec
 *Steven Borja:
 sborjac2@est.ups.edu.ec
*/
#include "cine.h"
#include <iostream>
#include "correccion.h"
Cine::Cine()
{
    //Quemado de pleiculas, salas y el bar
    cartelera[0] = new Pelicula("El Equipo Dinamita", 105, true, "11:00");
    cartelera[1] = new Pelicula("Relacion Mortal", 90, true, "12:45");
    cartelera[2] = new Pelicula("Tom y Jerry", 105, false, "14:00");
    cartelera[3] = new Pelicula("Contra el Demonio", 105, false, "16:00");
    cartelera[4] = new Pelicula("Mortal Kombat", 110, false, "17:45");
    for(int i = 0; i < numeroPeliculas; i++)
        sala[i] = new Sala;

    bar[0] = new Bar("Bebida Grande", 3.4);
    bar[1] = new Bar("Bebida Mediana", 3.15);
    bar[2] = new Bar("Agua sin gas", 1.85);
    bar[3] = new Bar("M&M", 2.5);
    bar[4] = new Bar("Twix", 2.5);
    bar[5] = new Bar("Snickers", 2.5);
    bar[6] = new Bar("Canguil Grande", 3.35);
    bar[7] = new Bar("Canguil Mediano", 2.85);
    bar[8] = new Bar("Nachos Queso", 4);
    bar[9] = new Bar("Nachos Chile", 4);
}

string Cine::mostrarCartelera()
{
    //Imprimir la cartelera
    string str;
    str = "\n\t- - C A R T E L E R A - -\n";
    for(int i = 0; i < numeroPeliculas; i++)
    {
        str += cartelera[i]->getDatos();
    }
    str += "\n";
    return str;
}

string Cine::mostrarSala()
{
    int id;
    cout << "\nIngrese el id de la pelicula: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nERROR. Ingrese una Sala entre 1 y 5: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "ERROR: La id debe ser entre 1 y " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        cin >> id;
    }
    cout << cartelera[id-1]->getDatos();
    cout << "- - A S I E N T O S - -\n";
    sala[id-1]->sala();
    return "\0";
}

string Cine::comprarBoletos()
{
    int id, columna;
    char fila;
    cout << "\nIngrese el id de la pelicula: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "\nERROR: La id debe ser entre 1 y " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        while (!(cin >> id))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }

    cout << "\nIngrese el numero de boletos: ";
    //MIENTRAS NO SE CUMPLA !-VA ANTES DEL CIN
    while (!(cin >> boletos))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }

    while(boletos < 0)
    {
        cout << "\nERROR: El numero de boletos debe ser mayor o igual a 1"
                "\nVuelva a intentarlo: ";
        cin >> boletos;
    }

    if(boletos == 0)
    {
        cout << "\n--No se ha realizado una compra--!" << "\n";
        return "\0";
    }

    while(boletos>sala[id-1]->numAsientos()){
        cout << "\nERROR: Numero de asientos excedido";
        cout << "\nVuelva a ingresar: ";
        while (!(cin >> boletos))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }
    Boletos *boleto[boletos];
    cartelera[id-1]->setCantidad(boletos);
    cartelera[id-1]->setComprado(true);
    cout << "\nSeleccione los asientos" << "\n";

    sala[id-1]->sala();

    for (int i = 0 ; i < boletos; i++){
        cout << "\nBoleto # " << i + 1 << "\n";
        cout << "Ingrese el asiento:";
        while (!(cin >> fila>>columna))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Vuelva a ingresar: ";
        }
        while(filaColumna(fila,columna)==false){
            cin.ignore(1000, '\n');
            cout << "ERROR. Asiento no existente"
                    "\nVuelva a ingresar el asiento: ";
            while (!(cin >> fila>>columna))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Vuelva a ingresar: ";
            }
        }

        while (sala[id-1]->asignarSala(fila, columna)==false) {
            cout << "Ingrese el asiento: ";
            cin >> fila >> columna;
        }
        boleto[i] = new Boletos(id, fila, columna, *cartelera[id-1]);
    }

    cout << "\nRESUMEN DE LA COMPRA\n";
    for(int i = 0; i < boletos; i++)
    {
        cout << "\nBoleto #" << i + 1 << "\n";
        cout << boleto[i]->mostrarPlano();
    }
    cout << "Total: $" << to_string_con_precision(PRECIO_BOLETO * boletos, 2) << "\n\n";
    return "\0";
}

string Cine::comprarComida()
{
    int opc;
    float total = 0;
    cout << "\n\t- - B A R - -\n";
    for (int i = 0; i < totalProductos; i++)
    {
        cout << bar[i]->getDatos() << endl;
    }
    do
    {
        cout << "Digite el ID del producto, si desea salir digite 0: ";
        while (!(cin >> opc))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error. Vuelve a ingresar el id: ";
        }
        if(opc >= 0 && opc <= totalProductos)
            total += bar[opc-1]->comprar();
        else
            cout << "ERROR: Producto inexistente"
                    "\nVuelva a intentarlo\n";
    }while (opc != 0);
    cout << "\n\t- - RESUMEN DE LA COMPRA - -\n";
    for(int i = 0; i < totalProductos; i++)
    {
        if(bar[i]->getComprado() == true)
        {
            cout << bar[i]->getNombre();
            if(bar[i]->getNombre().size() < 8)
                cout << "\t\t | $" << to_string_con_precision(bar[i]->getPrecio(),2)
                     << " *" << bar[i]->getCantidad()
                     << " | $" << to_string_con_precision(bar[i]->totalProducto(), 2) << endl;
            else
                cout << "\t | $" << to_string_con_precision(bar[i]->getPrecio(),2)
                     << " *" << bar[i]->getCantidad()
                     << " | $" << to_string_con_precision(bar[i]->totalProducto(), 2) << endl;
        }
    }
    cout << "\t- - - - - - - - - \n" <<
            "Su total es de:  $" << to_string_con_precision(total, 2) << endl;
    return "\n";
}

bool Cine::filaColumna(char fila, int columna)
{
    bool val;
    if(fila=='A' || fila=='a'|| fila=='B'|| fila=='b'|| fila=='C'|| fila=='c'|| fila=='D'|| fila=='d'|| fila=='E'|| fila=='e'){
        val=true;
    }else{
        return false;
    }
    if(columna>0 && columna<6){
        val=true;
    }else{
        return false;
    }
    return val;
}

string Cine::factura()
{
    cout << "Forma de pago?"
            "\n1. Efectivo"
            "\n2. Tarjeta";
    cout <<"\nOpcion: ";
    cin >> opc;
    string respuesta;
    if(opc == 1)
    {
        cout << "Desea con datos o consumidor final? \n";
        cin >> respuesta;
    }
    if(respuesta[0] == 'D' || respuesta[0] == 'd' || opc == 2)
    {
        //Si desea con datos, se pedira los datos del cliente
        string nombre , apellido, ci, num, dir;
        cout << "Cual es su nombre?\n";
        cin >> nombre >> apellido;
        //Se pondra con mayusculas
        //La primera letra del nombre y del apellido
        nombre[0] = toupper(nombre[0]);
        apellido[0] = toupper(apellido[0]);
        //Se concatenara el nombre y el apellido en un solo string
        nombre = nombre + " " + apellido;
        cout << "Cual es su Cedula: ";
        cin >> ci;
        while(ci.length() != 10  && ci.length() != 13)
        {
            cout << "ERROR: La cedula tiene 10 digitos"
                    "\nVuelva a ingresar la cedula: ";
            cin >> ci;
        }
        //Se ignora el buffer del cin
        cin.ignore();
        cout << "Cual es su direccion: ";
        getline(cin, dir);
        cout << "Cual es su numero: ";
        //Se limpia el cin para poder recibir el numero
        cin.clear();
        cin >> num;
        while(num.length() != 10)
        {
            cout << "ERROR: El numero celular tiene 10 digitos"
                    "\nVuelva a ingresar el numero: ";
            cin >> num;
        }
        //Se crea una factura con datos del cliente
        Factura fact(ci, nombre, dir, num);
        //Se imprime los datos de la factura
        cout << fact.imprimirDatos();
        //Se imprime la descripcion de lo que ha comprado
        cout << Cine::imprimirDescripcion();
    }
    else
    {
        //Se crea una factura como consumidor final
        Factura fact;
        //Se imrpime los datos de la factura
        cout << fact.imprimirDatos();
        //Se imprime la descripcion de lo que ha comprado
        cout << Cine::imprimirDescripcion();
    }
    return "\n";
}

string Cine::imprimirDescripcion()
{
    //crea una variable de tipo string en el cual se almacenaran mas datos
    string str = "\0";

    int espaciado;
    float subTotal = 0;
    //los caracteres char con numeros muestran caracteres especiales que no se pueden escribir desde el teclado
    char a = -38, b = -60, c = -65, d = -77, h = -64, i = -39;
    //Final
    for(int i = 0; i < numeroPeliculas; i++)
    {
        if(cartelera[i]->getComprado())
        {
            subTotal += PRECIO_BOLETO * cartelera[i]->getCantidad();
            str = str + "  " + to_string(cartelera[i]->getCantidad());
            str = str + "\t" + cartelera[i]->getTitulo();
            espaciado = 50 - cartelera[i]->getTitulo().length();
            for (int i = 0; i < espaciado; i++)
                str += " ";
            str = str + "$" + to_string_con_precision(PRECIO_BOLETO, 2) + "       $" + to_string_con_precision(PRECIO_BOLETO * cartelera[i]->getCantidad(), 2) + "\n";
        }
    }
    for(int i = 0; i < totalProductos; i++)
    {
        if(bar[i]->getComprado())
        {
            subTotal += bar[i]->totalProducto();
            str = str + "  " + to_string(bar[i]->getCantidad());
            str = str + "\t" + bar[i]->getNombre();
            espaciado = 50 - bar[i]->getNombre().length();
            for (int i = 0; i < espaciado; i++)
                str += " ";
            str = str + "$" + to_string_con_precision(bar[i]->getPrecio(), 2);
            str = str + "       $" + to_string_con_precision(bar[i]->totalProducto(), 2) + "\n";

        }
    }
    if(opc==1){
        float IVA = subTotal-(subTotal/1.12);
        str += a;
        for (int i = 0; i <= 78; i++)
            str += b;
        str += c;
        str = str + "\n" + d + "Subtotal: $" + to_string_con_precision(subTotal-IVA, 2);
        espaciado = 72 - to_string(subTotal).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;

        str = str + "\n" + d + "IVA: $" + to_string_con_precision(IVA, 2);
        espaciado = 77 - to_string(IVA).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;

        str = str + "\n" + d + "Total: $" + to_string_con_precision(subTotal, 2);
        espaciado = 75 - to_string(subTotal).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;
    }
    if(opc==2){
        float val,nSubtotal;
        val=subTotal*0.03;
        nSubtotal=subTotal+val;
        float IVA = nSubtotal-(nSubtotal/1.12);
        str += a;
        for (int i = 0; i <= 78; i++)
            str += b;
        str += c;
        str = str + "\n" + d + "Se incrementa un 3% por usar tarjeta";
        for (int i = 0; i < 43; i++)
            str += " ";
        str += d;
        str = str + "\n" + d + "Subtotal: $" + to_string_con_precision(nSubtotal-IVA, 2);
        espaciado = 72 - to_string(nSubtotal).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;

        str = str + "\n" + d + "IVA: $" + to_string_con_precision(IVA, 2);
        espaciado = 77 - to_string(IVA).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;

        str = str + "\n" + d + "Total: $" + to_string_con_precision(nSubtotal, 2);
        espaciado = 75 - to_string(nSubtotal).length();
        for (int i = 0; i < espaciado; i++)
            str += " ";
        str += d;
    }
    //Cierre de la factura
    str = str + "\n" + h;
    for (int i = 0; i <= 78; i++)
        str += b;
    str = str + i +"\n";
    //Se resetea la cantidad y el estado de compra de las peliculas
    for(int i = 0; i < numeroPeliculas; i ++)
    {
        cartelera[i]->setCantidad(0);
        cartelera[i]->setComprado(false);
    }
    //Se resetea la cantidad y el estado de compra del bar
    for (int i = 0; i < totalProductos; i++)
    {
        bar[i]->setCantidad(0);
        bar[i]->setComprado(false);
    }
    return str;
}

string Cine::InterfazAdmin()
{
    int contrasenia;
    int opc;
    cout << "\nIngrese la contrasenia: ";
    while (!(cin >> contrasenia))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nERROR. Ingrese  solo numeros!"
                "\nIngrese de nuevo: ";
    }
    while(contrasenia != CONTRASENIA){
        cout << "\nContrasenia invalida, intente de nuevo!" << endl;
        cin >> contrasenia;
    }
    if (contrasenia == CONTRASENIA){
        cout << " BIENVENIDO!! " << endl;
        do
        {
            cout << "\n+ + MENU DE ADMINISTRADOR + +"
                    "\n1. Modificar pelicula"
                    "\n2. Salir"
                    "\nIngrese su opcion: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                modificarPelicula();
                break;
            case 2:
                cout << "\n\t==Hasta Pronto==\n";
                break;
            default:
                cout << "\nERROR: No reconozco esa opcion\n"
                        "Vuelva a intentarlo\n\n";
                break;
            }
        }while (opc != 2);
    }
    return "\0";
}

void Cine::modificarPelicula()
{
    string nombre, hora, dato;
    char estreno;
    int id;
    float duracion;
    cout << "Ingrese el ID de la pelicula entre [1 y " << numeroPeliculas << "] que desea modificar: ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nError. Vuelve a ingresar: ";
    }
    while(id <= 0 || id > numeroPeliculas)
    {
        cout << "\nERROR: La id debe ser entre 1 y " << numeroPeliculas;
        cout << "\nVuelva a intentarlo: ";
        while (!(cin >> id))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError. Vuelve a ingresar: ";
        }
    }
    cout << "\nQue desea modificar? Nombre, Hora, Duracion o estreno? ";
    cin >> dato;
    cin.ignore();
    if(dato == "nombre" || dato == "Nombre"){
        cout << "\nIngrese el nuevo nombre de la pelicula: ";
        getline(cin, nombre);
        cartelera[id-1]->setTitulo(nombre);
        cout << mostrarCartelera();
    } else if(dato == "hora" || dato == "Hora"){
        cout << "\nIngrese la nueva hora de la pelicula: ";
        cin >> hora;
        cartelera[id-1]->setHora(hora);
        cout << mostrarCartelera();
    } else if(dato == "duracion" || dato == "Duracion"){
        cout << "\nIngrese la nueva duracion de la pelicula: ";
        cin >> duracion;
        cartelera[id-1]->setDuracion(duracion);
        cout << mostrarCartelera();
    } else if(dato == "estreno" || dato == "Estreno"){
        cout << "\n Ingrese (S) si esta de estreno o ingrese (N) si ya esta en cartelera: ";
        cin >> estreno;
        if (estreno == 'S' || estreno == 's'){
            cartelera[id-1]->setEstreno(true);
        } else if (estreno == 'N' || estreno == 'n'){
            cartelera[id-1]->setEstreno(false);
        }
        cout << mostrarCartelera();
    }
}
