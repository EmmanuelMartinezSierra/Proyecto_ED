#ifndef TIENDA_H
#define TIENDA_H
#include "SECCION.h"
#include "PRODUCTO.h"

class TIENDA{
    private:
        SECCION *Cabecera;
    public:
        TIENDA();
        virtual ~TIENDA();
        void setCabecera(SECCION *);
        SECCION *getCabecera();
        bool estaVacio();
        void insertarSeccion(int, string);
        void insertarProducto(int, string, int, int, int);
        void imprimir(SECCION *);
};

#endif // TIENDA_H
