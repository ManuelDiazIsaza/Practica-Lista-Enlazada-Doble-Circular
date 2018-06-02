/*
  Archivo: Lista.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-31
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1
  Licencia: GPL
*/

#include "ListaCircular.h"
#include "Nodo.h"
#include <time.h>
#include <stdio.h>
#include <iostream>

Lista::Lista()
{
    cab = NULL;
}

//inserta un nuevo elemento al principio
//de la lista

void Lista::insertarPrimero(int info)
{
    Nodo *nuevo = new Nodo();
    nuevo->setInfo(info);
    if (cab == NULL)
    {
        nuevo->setSig(nuevo);
        nuevo->setAnt(nuevo);
        cab  = nuevo;
    }
    else
    {
        Nodo *ultimo = cab->getAnt();
        nuevo->setSig(cab);
        nuevo->setAnt(ultimo);
        cab->setAnt(nuevo);
        ultimo->setSig(nuevo);
        cab = nuevo;
    }
}

void Lista::insertarUltimo(int info)
{
    Nodo *nuevo = new Nodo();
    nuevo->setInfo(info);
    if (cab == NULL)
    {
        nuevo->setSig(nuevo);
        nuevo->setAnt(nuevo);
        cab  = nuevo;
    }
    else
    {
        Nodo *ultimo = cab->getAnt();
        ultimo->setSig(nuevo);
        nuevo->setSig(cab);
        nuevo->setAnt(ultimo);
        cab->setAnt(nuevo);
    }
}

void Lista::borrarSegundo()
{
    if(cantidad()<2)
    {
        cout << "No hay suficientes elementos." << endl;
    }
    else if(cantidad()==2)
    {
        Nodo *ultimo = cab->getAnt();
        cab->setSig(cab);
        cab->setAnt(cab);
        delete ultimo;
    }
    else
    {
        Nodo *pos1 = cab->getSig();
        cab->setSig(pos1->getSig());
        pos1->getSig()->setAnt(cab);
        delete pos1;
    }
}

void Lista::borrarUltimo()
{
    if(cantidad()==0)
    {
        cout << "No hay elementos que borrar." << endl;
    }
    else if(cantidad() == 1)
    {
        delete cab;
        cab = nullptr;
    }
    else
    {
        Nodo *ultimo = cab->getAnt();
        ultimo->getAnt()->setSig(cab);
        cab->setAnt(ultimo->getAnt());
        delete ultimo;
    }
}

void Lista::borrar(int pos)
{
    Nodo *pos1 = cab;
    if(pos<0)
    {
        cout << "La posicion no puede ser menor que 0." << endl;
    }
    else if(pos>cantidad()-1)
    {
        cout << "Esta posicion no esta en la lista" << endl;
    }
    else if(pos==0)
    {
        if(cantidad()==0)
        {
            cout << "No hay elementos suficientes." << endl;
        }
        else if(cantidad()==1)
        {
            delete cab;
            cab = nullptr;
        }
        else
        {
            Nodo *ultimo = cab->getAnt();
            ultimo->setSig(cab->getSig());
            cab->getSig()->setAnt(ultimo);
            cab = cab->getSig();
            delete pos1;
        }
    }
    else if(pos==cantidad()-1)
    {
        borrarUltimo();
    }
    else
    {
        Nodo *pos2;
        int i = 0;
        do
        {
            if(i==pos)
            {
                pos1->getAnt()->setSig(pos1->getSig());
                pos1->getSig()->setAnt(pos1->getAnt());
                pos2 = pos1;
                pos1 = pos1->getSig();
                i++;
                delete pos2;
            }
            else
            {
                pos1 = pos1->getSig();
                i++;
            }
        }while(pos1!=cab);
    }
}

void Lista::borrarMayor()
{
    if(cantidad()==0)
    {
        cout << "No hay elementos suficientes." << endl;
    }
    else if(cantidad()==1)
    {
        delete cab;
        cab = nullptr;
    }
    else
    {
        Nodo *desplaza = cab;
        Nodo *ultimo = cab->getAnt();
        int mayorTemp = 0;
        int pos = 0;
        int i = 0;
        do
        {
            if(mayorTemp<desplaza->getInfo())
            {
                mayorTemp = desplaza->getInfo();
                pos = i;
                desplaza = desplaza->getSig();
                i++;
            }
            else
            {
                desplaza = desplaza->getSig();
                i++;
            }
        }while(desplaza!=cab);
        cout << "El mayor elemento es: " << mayorTemp << " y la posicion es: " << pos << endl;
        borrar(pos);
    }
}

int Lista::cantidad()
{
    if(cab== nullptr)
    {
        return 0;
    }
    else
    {
        Nodo *pos1 = cab->getSig();
        int contador=1;
        while(pos1!=cab)
        {
            contador++;
            pos1 = pos1->getSig();
        }
        return contador;
    }
}

bool Lista::vacia()
{
    if (cab == NULL)
        return true;
    else
        return false;
}

void Lista::imprimir()
{
    if (!vacia()) {
        Nodo *desplaza = cab;
        do {
            cout<<desplaza->getInfo()  <<"-";
            desplaza = desplaza->getSig();
        } while (desplaza != cab);
        cout << endl;
    }
}


Lista::~Lista()
{
    if (cab != NULL) {
        Nodo *desplaza = cab->getSig();
        Nodo *borrar;
        while (desplaza != cab)
        {
            borrar = desplaza;
            desplaza = desplaza->getSig();
            delete borrar;
            borrar = NULL;
        }
        delete cab;
        cab = NULL;
    }
}






