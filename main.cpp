/*
  Archivo: Main.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/
#include <stdio.h>
#include <iostream>
#include "ListaCircular.h"
using namespace std;

int main()
{
    Lista *listacircular = new Lista();
    listacircular->insertarUltimo(100);
    listacircular->insertarUltimo(45);
   listacircular->insertarUltimo(12);
    listacircular->insertarUltimo(300);
    listacircular->insertarUltimo(4);
    listacircular->insertarUltimo(200);

  //  listacircular->insertarUltimo(500);
//    listacircular->imprimir();
//    cout << endl << listacircular->cantidad();
//    listacircular->borrarUltimo();
//    listacircular->borrarMayor();
    listacircular->imprimir();
//    listacircular->borrar(3);
    listacircular->borrarMayor();
    listacircular->imprimir();
    return 0;
}