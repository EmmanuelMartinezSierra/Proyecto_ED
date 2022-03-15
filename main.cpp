#include "SECCION.cpp"
#include "PRODUCTO.cpp"
#include "TIENDA.cpp"

main(){
    TIENDA *Tienda = new TIENDA();
    SECCION *Alimentos = new SECCION(15, "Alimentos");

    /*Alimentos->insertarProducto("Arroz lb", 2354, 2000, 50);
    Alimentos->insertarProducto("Aceite 500ml", 6849, 8000, 70);
    Alimentos->insertarProducto("Papa lb", 1346, 3000, 45);
    Alimentos->insertarProducto("Jamon lb", 4532, 3000, 15);
    Alimentos->insertarProducto("Queso lb", 7654, 8000, 10);
    Alimentos->insertarProducto("Lentejas lb", 0154, 4500, 20);
    Alimentos->insertarProducto("Frijoles lb", 0164, 4500, 20);
    Alimentos->insertarProducto("Garbanzos lb", 0174, 4500, 20);
    Alimentos->Imprimir();*/

    Tienda->insertarSeccion(1, "Alimentos");
    Tienda->insertarSeccion(2, "Bebidas");
    Tienda->insertarSeccion(3, "Aseo");
    Tienda->insertarSeccion(4, "Dulces");
   // Tienda->imprimir(Tienda->getCabecera());


    cout<<endl<<endl;

    Tienda->insertarProducto(1,"Arroz lb", 2354, 2000, 50);
    Tienda->insertarProducto(1, "Aceite 500ml", 6849, 8000, 70);
    Tienda->insertarProducto(1, "Papa lb", 1346, 3000, 45);
    Tienda->insertarProducto(1, "Jamon lb", 4532, 3000, 15);
    Tienda->insertarProducto(1, "Queso lb", 7654, 8000, 10);
    Tienda->insertarProducto(1, "Lentejas lb", 0154, 4500, 20);
    Tienda->insertarProducto(1, "Frijoles lb", 0164, 4500, 20);
    Tienda->insertarProducto(1, "Garbanzos lb", 0174, 4500, 20);
    Tienda->insertarProducto(3, "Clorox 250ml", 4573, 5000, 20);

    Tienda->imprimir(Tienda->getCabecera());
}
