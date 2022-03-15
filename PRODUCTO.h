#ifndef PRODUCTO_H
#define PRODUCTO_H
#include "string"
#include "iostream"
#include "iomanip"
#include <stdio.h>  
#include <windows.h>  
using namespace std;

//NODO
class PRODUCTO{
    private:
        string Nombre;
        int Codigo, Precio, Inventario;
        PRODUCTO *Izquierda;
        PRODUCTO *Derecha;
    public:
        PRODUCTO(string, int, int, int);
        virtual ~PRODUCTO();
        void setNombre(string);
        void setCodigo(int);
        void setPrecio(int);
        void setInventario(int);
        void setDer(PRODUCTO *);
        void setIzq(PRODUCTO *);
        string getNombre();
        int getCodigo();
        int getPrecio();
        int getInventario();
        PRODUCTO *getDer();
        PRODUCTO *getIzq();
};

#endif // PRODUCTO_H
