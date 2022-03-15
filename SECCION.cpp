#include "SECCION.h"

SECCION::SECCION(int codigo, string nombre){
    Nombre = nombre;
    Cabecera = NULL;
    Codigo = codigo;
    Siguiente = NULL;
}

SECCION::~SECCION(){
    destruirSeccion(Cabecera);
}

void SECCION::destruirSeccion(PRODUCTO *aux){
    if(aux!=nullptr){
        destruirSeccion(aux->getIzq());
        destruirSeccion(aux->getDer());
        aux->~PRODUCTO();
    }
    if(aux == Cabecera){
        setCabecera(NULL);
    }
    Nombre = "";
    Siguiente = NULL;
}

void SECCION::setNombre(string nombre){
    Nombre = nombre;
}

void SECCION::setCabecera(PRODUCTO *cabecera){
    Cabecera = cabecera;
}

void SECCION::setCodigo(int codigo){
    Codigo = codigo;
}

void SECCION::setSig(SECCION *siguiente){
    Siguiente = siguiente;
}

string SECCION::getNombre(){
    return Nombre;
}

PRODUCTO *SECCION::getCabecera(){
    return Cabecera;
}

int SECCION::getCodigo(){
    return Codigo;
}

SECCION *SECCION::getSig(){
    return Siguiente;
}

bool SECCION::estaVacio(){
    if(Cabecera == NULL){
        return true;
    }
    else{
        return false;
    }
}

void SECCION::insertarProducto(string nombre, int codigo, int precio, int inventario){
    PRODUCTO *nuevo = new PRODUCTO(nombre, codigo, precio, inventario);
    if(estaVacio()){
        Cabecera = nuevo;
    }
    else{
        PRODUCTO *ant = nullptr;
        PRODUCTO *act = Cabecera;
        while((act != nullptr) && (act->getNombre() != nombre) && (act->getCodigo() != codigo)){
            ant = act;
            if (act->getCodigo() < codigo){
        	    act = act->getDer();
            }
        	else{
                act = act->getIzq();
            }
        }
        if (act == nullptr)
               if (ant->getCodigo() < codigo){
                   ant->setDer(nuevo);
               }
               else{
                   ant->setIzq(nuevo);
               }
        else{
            cout<<".... Producto ya existe ...."<<endl;
        }
    }
    Balanceo(Cabecera);
    return;
}

int SECCION::Altura(PRODUCTO *aux){
    int altIZ, altDE;
    if(aux != nullptr){
        altIZ = Altura(aux->getIzq());
        altDE = Altura(aux->getDer());
        if(altIZ > altDE){
            return altIZ+1;
        }
        else{
            return altDE+1;
        }
    }
    else{
        return 0;
    }
}

PRODUCTO *SECCION::RD(PRODUCTO *p){
    PRODUCTO *q = p->getIzq();
    p->setIzq(q->getDer());
    q->setDer(p);
    return q;
}

PRODUCTO *SECCION::RI(PRODUCTO* p) {
    PRODUCTO *q = p->getDer();
    p->setDer(q->getIzq());
    q->setIzq(p);
    return q;
}

PRODUCTO *SECCION::DRD(PRODUCTO* p) {
    PRODUCTO *q = p->getIzq();
    p->setIzq(RI(q));
    return RD(p);
}

PRODUCTO *SECCION::DRI(PRODUCTO* p) {
    PRODUCTO *q = p->getDer();
    p->setDer(RD(q));
    return RI(p);
}

PRODUCTO *SECCION::Balanceo(PRODUCTO *p){
    if(p != nullptr){
        p->setIzq(Balanceo(p->getIzq()));
        p->setDer(Balanceo(p->getDer()));
        int dif = Altura(p->getIzq()) - Altura(p->getDer());
        if(abs(dif) > 1){
            if(dif > 0){
                PRODUCTO* q = p->getIzq();
                int difq = Altura(q->getIzq()) - Altura(q->getDer());
                if(difq >= 0){
                    return RD(p);
                }
                else{
                    return DRD(p);
                }
            }
            else{
                PRODUCTO* q = p->getDer();
                int difq = Altura(q->getIzq()) - Altura(q->getDer());
                if (difq < 0) {
                    return RI(p);
                }
                else {
                    return DRI(p);
                }
            }
        }
    }
    return p;
}

void SECCION::Imprimir(){
    cout<<endl<<"\t"<<Nombre<<endl;
    PRODUCTO *aux = Cabecera;
    if (aux == NULL){
            return;
    }
    cout <<" "<<aux->getNombre()<<endl;
    ImpTree(aux, "");
    cout << endl;
}

void SECCION::ImpTree(PRODUCTO* aux, const string& prefix){
    if (aux == NULL){
        return;
    }
    bool hasLeft = (aux->getIzq() != NULL);
    bool hasRight = (aux->getDer() != NULL);
    if (!hasLeft && !hasRight){
        return;
    }
    char m = 195, m3 = 196, m2 = 192, m1 = 179;
    cout << prefix;
    if(hasLeft  && hasRight){
            cout<<" "<<m<<m3<<m3<<"D"<<m3<<m3<<">";
    }
    else{
        cout<<"";
    }
    if(!hasLeft  && hasRight){
            cout<<" "<<m2<<m3<<m3<<"D"<<m3<<m3<<">";
    }
    else{
        cout<<"";
    }
    if (hasRight){
        bool printStrand = (hasLeft && hasRight && (aux->getDer()->getDer() != NULL || aux->getDer()->getIzq() != NULL));
        string newPrefix;
        if(printStrand){
            newPrefix = prefix + " " + m1 + "     ";
        }
        else{
            newPrefix = prefix + "       ";
        }
        cout << aux->getDer()->getNombre() << endl;
        ImpTree(aux->getDer(), newPrefix);
    }
    if (hasLeft){
        if(hasRight){
            cout<<prefix;
        }
        else{
            cout<<"";
        }
        cout<<" "<<m2<<m3<<m3<<"I"<<m3<<m3<<">"<<aux->getIzq()->getNombre() << endl;
        ImpTree(aux->getIzq(), prefix + "       ");
    }
}

PRODUCTO *SECCION::BuscarReemp(PRODUCTO *aux){
    switch(Grado(aux->getCodigo())){
        case 0:
            return nullptr;
        case 1:
            if(aux->getIzq() != nullptr){
                return aux->getIzq();
            }
            else{
                return aux->getDer();
            }
        case 2:
            PRODUCTO *ant = nullptr;
            PRODUCTO *act = aux->getIzq();
            while(act->getDer() != nullptr){
                ant = act;
                act = act->getDer();
            }
            if(ant != nullptr){
                ant->setDer(act->getIzq());
                act->setIzq(aux->getIzq());
            }
            act->setDer(aux->getDer());
            return act;
    }
}

PRODUCTO *SECCION::Eliminar(int dato){
    PRODUCTO *padre = nullptr;
    PRODUCTO *salir = Cabecera;
    while((salir != nullptr)&&(salir->getCodigo() != dato)){
        padre = salir;
        if(salir->getCodigo() > dato){
            salir = salir->getIzq();
        }
        else{
            salir = salir->getDer();
        }
    }
    if(salir != nullptr){
        PRODUCTO *reemp = BuscarReemp(salir);
        if(padre != nullptr){
            if(padre->getCodigo() > dato){
                padre->setIzq(reemp);
            }
            else{
                padre->setDer(reemp);
            }
        }
        else{
            Cabecera = reemp;
        }
    }
}

int SECCION::Grado(int dato){
    PRODUCTO *aux = Buscar(dato);
    if(aux != nullptr){
        int cont = 0;
        if(aux->getIzq() != nullptr){
            cont++;
        }
        if(aux->getDer() != nullptr){
            cont++;
        }
        return cont;
    }
    return -1;
}

PRODUCTO *SECCION::Buscar(int dato){
    PRODUCTO *aux = Cabecera;
    while((aux != nullptr)&&(aux->getCodigo() != dato)){
        if(aux->getCodigo() > dato){
            aux = aux->getIzq();
        }
        else{
            aux = aux->getDer();
        }
    }
    return aux;
}
