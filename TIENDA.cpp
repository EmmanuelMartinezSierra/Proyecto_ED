#include "TIENDA.h"

TIENDA::TIENDA(){
    Cabecera = NULL;
}

TIENDA::~TIENDA(){
    while(Cabecera != NULL){
        SECCION *aux = Cabecera;
        Cabecera = Cabecera->getSig();
        aux->~SECCION();
    }
}

void TIENDA::setCabecera(SECCION *cabecera){
    Cabecera = cabecera;
}

SECCION *TIENDA::getCabecera(){
    return Cabecera;
}

bool TIENDA::estaVacio(){
    if(Cabecera == NULL){
        return true;
    }
    else{
        return false;
    }
}

void TIENDA::insertarSeccion(int seccion, string nombre){
    SECCION *nuevo = new SECCION(seccion, nombre);
    if(estaVacio()){
        Cabecera = nuevo;
    }
    else{
        SECCION *ant = NULL;
        SECCION *act = Cabecera;
        while((act->getSig() != NULL) && (act->getCodigo() > seccion)){
            ant = act;
            act = act->getSig();
        }
        if(act->getCodigo() != seccion){
            if(act == NULL){
                ant->setSig(nuevo);
            }
            else{
                if(ant == NULL){
                    nuevo->setSig(Cabecera);
                    Cabecera = nuevo;
                }
                else{
                    nuevo->setSig(act);
                    ant->setSig(nuevo);
                }
            }
        }
    }
}

void TIENDA::insertarProducto(int codS, string nombre, int codigo, int precio, int inventario){
    SECCION *aux = Cabecera;
    while((aux != NULL) && (aux->getCodigo() != codS)){
        aux = aux->getSig();
    }
    if(aux->getCodigo() == codS){
        aux->insertarProducto(nombre, codigo, precio, inventario);
    }
}

void TIENDA::imprimir(SECCION *aux){
    if(aux != NULL){
        imprimir(aux->getSig());
        aux->Imprimir();
    }
    
}
