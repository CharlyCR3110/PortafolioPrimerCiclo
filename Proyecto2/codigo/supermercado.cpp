//Carlos González Garita y Kristel Salazar Chinchilla || Universidad Nacional || Ingeniería en Sistemas
//17/04/2022
#include <iostream>
#include <sstream>
using namespace std;

class Producto {
private:
    string codigo;
    string nombre;
    int precioBase;
    float porcentajeDeGanancias; //entre 0 y 1
    int cantidadVendida;
    int existencia;
    float peso;
    int existenciaMinima;
    float precioDeVenta;
public:
    //constructors
    Producto(){
        codigo = "Default";
        nombre = "Default";
        precioBase = 0;
        porcentajeDeGanancias = 0;
        cantidadVendida = 0;
        existencia = 0;
        peso = 0;
        existenciaMinima = 0;
        precioDeVenta = precioBase + (precioBase * porcentajeDeGanancias);
    }
    Producto(string codigo, string nombre, int precioBase, float porcentajeDeGanancias, int cantidadVendida, int existencia, float peso, int existenciaMinima){
        this->codigo = codigo;
        this->nombre = nombre;
        this->precioBase = precioBase;
        this->porcentajeDeGanancias = porcentajeDeGanancias;
        this->cantidadVendida = cantidadVendida;
        this->existencia = existencia;
        this->peso = peso;
        this->existenciaMinima = existenciaMinima;
        this->precioDeVenta = precioBase + (precioBase * porcentajeDeGanancias);
    }
    //destructor
    ~Producto(){
    }
    //Setters
    void setCodigo(string codigo){
        this->codigo = codigo;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setPrecioBase(int precioBase){
        this->precioBase = precioBase;
    }
    void setPorcentajeDeGanancias(float porcentajeDeGanancias){
        this->porcentajeDeGanancias = porcentajeDeGanancias;
    }
    void setCantidadVendida(int cantidadVendida){
        this->cantidadVendida = cantidadVendida;
    }
    void setExistencia(int existencia){
        this->existencia = existencia;
    }
    void setPeso(float peso){
        this->peso = peso;
    }
    void setExistenciaMinima(int existenciaMinima){
        this->existenciaMinima = existenciaMinima;
    }
    //Getters
    string getCodigo(){
        return codigo;
    }
    string getNombre(){
        return nombre;
    }
    int getPrecioBase(){
        return precioBase;
    }
    float getPorcentajeDeGanancias(){
        return porcentajeDeGanancias;
    }
    int getCantidadVendida(){
        return cantidadVendida;
    }
    int getExistencia(){
        return existencia;
    }
    float getPeso(){
        return peso;
    }
    int getExistenciaMinima(){
        return existenciaMinima;
    }
    float getPrecioDeVenta(){
        return precioDeVenta;
    }
    //Metodos
    string mostrarDatosDelProducto() {
        stringstream ss;
        ss << "Codigo: " << codigo << endl;
        ss << "Nombre: " << nombre << endl;
        ss << "Precio base: " << precioBase << endl;
        ss << "Porcentaje de ganancias: " << porcentajeDeGanancias << endl;
        ss << "Cantidad vendida: " << cantidadVendida << endl;
        ss << "Existencia: " << existencia << endl;
        ss << "Peso: " << peso << endl;
        ss << "Existencia minima: " << existenciaMinima << endl;
        ss << "Precio de venta: " << precioDeVenta << endl;
        return ss.str();
    }
};
class Supermercado {
private:
    Producto productos[200];
    int tamano;
    int cantidad;
public:
    //constructors
    Supermercado(){
        tamano = 10;
        cantidad = 0;
    }
    Supermercado(int tamano){
        this->tamano = tamano;
        cantidad = 0;
    }
    //destructor
    ~Supermercado(){
    }
    //Setters
    void setTamano(int tamano){
        this->tamano = tamano;
    }
    void setCantidad(int cantidad){
        this->cantidad = cantidad;
    }
    //Getters
    int getTamano(){
        return tamano;
    }
    int getCantidad(){
        return cantidad;
    }
    //Devuelve un objeto de la clase producto
    Producto getProducto(int posicion){
        return productos[posicion];
    }
    //Metodos
    //1
    void ingresaProducto(int posicionProducto, Producto producto){
        productos[posicionProducto] = producto;
        cantidad ++;
    }
    //Elimina un producto en base a su codigo
    //2
    void eliminarProductoPorCodigo(string codigo) { //eliminarProductoPorSu
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getCodigo() == codigo) {
                for (int j = i; j < cantidad; j++) {
                    productos[j] = productos[j + 1];
                }
                cantidad--;
            }
        }
    }
    //3
    Producto productoDeMayorValor() { //obtenerProducDeMayorValor
        int posicion = 0;
        for(int i = 0; i < cantidad; i++){ 
            if(productos[i].getPrecioBase() > productos[posicion].getPrecioBase()){
                posicion = i;
            }
        }
        return productos[posicion];
    }
    //4
    Producto productoConMayorExistencia() { //obtenerProducConMayorExistencia
        int posicion = 0;
        for(int i = 0; i < cantidad; i++){ 
            if(productos[i].getExistencia() > productos[posicion].getExistencia()){
                posicion = i;
            }
        }
        return productos[posicion];
    }
    //5
    //Ordena los productos alfabatecamente en base a su codigo
    void ordenarProductosPorCodigo() { //ordenarProductPorCodigo  
        Producto aux;
        for(int i = 0; i < cantidad; i++){
            for(int j = i + 1; j < cantidad; j++){
                if(productos[i].getCodigo() > productos[j].getCodigo()){
                    aux = productos[i];
                    productos[i] = productos[j];
                    productos[j] = aux;
                }
            }
        }
    }
    //6
    string mostrarTodosLosProductos() { //imprimirTodosLosProductos
        stringstream ss;
        ss << endl << endl << "Todos los productos" << endl << endl;
        for (int i = 0; i < cantidad; i++) {
            ss << "Producto numero: " << i + 1 << endl;
            ss << productos[i].mostrarDatosDelProducto() << endl;
        }
        return ss.str();
    }
    //7
    int cantidadDeProductosBajosDeExistencia() { //cantDeProductosBajosDeExistencia
        int contador = 0;
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getExistencia() < productos[i].getExistenciaMinima()) {
                contador++;
            }
        }
        return contador;
    }
    //8
    string mostrarProductosBajosDeExistencia() { //imprimirProductosBajosDeExistencia
        stringstream ss;
        bool esVacio = true;
        ss << endl << endl << "Productos bajos de existencia" << endl << endl;
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getExistencia() < productos[i].getExistenciaMinima()) {
                ss << "Producto numero: " << i + 1 << endl;
                ss << "Codigo: " << productos[i].getCodigo() << endl;
                ss << "Nombre: " << productos[i].getNombre() << endl;
                ss << "Existencia: " << productos[i].getExistencia() << endl;
                ss << "Existencia minima: " << productos[i].getExistenciaMinima() << endl << endl;
                esVacio = false;
            }
        }
        //Se cambia el mensaje si no hay productos bajos de existencia
        if (esVacio) {
            ss.clear(); //Vacia el stringstream
            ss << "No hay productos bajos de existencia" << endl;
        }
        return ss.str();
    }
    //9

/**
 * Suma el peso de todos los productos vendidos
 * 
 * @return La suma del peso de los productos vendidos.
 */
    float kilogramosVendidos() { //cuantosKgsSeHanVendidoEnGeneral
        float suma = 0;
        for (int i = 0; i < cantidad; i++) {
            suma += productos[i].getPeso() * productos[i].getCantidadVendida();
        }
        return suma;
    }
    //10
/**
 * Devuelve la suma de los pesos de todos los productos vendidos con el codigo dado
 * 
 * @param codigo el codigo del producto
 * 
 * @return La suma del peso de los productos vendidos con ese codigo.
 */
    float kilogramosVendidosDeUnProducto(string codigo) { //cuantosKgsSeHanVendidoDelProducto
        float suma = 0;
        // bool esVacio = true; //se me olvido borrar
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getCodigo() == codigo) {
                suma += productos[i].getPeso() * productos[i].getCantidadVendida();
                // esVacio = false; //se me olvido borrar
            }
        }
        //se me olvido borrar
        // if (esVacio) {
        //     suma = 0.4124541245;
        // }
        // return suma;
    }
    //11
    string productosMasCostososQue(string codigo) { //imprimProductosQueSonMasCostososQue
        stringstream ss;
        int posicion;
        bool esVacio = true;
        //Busca la posicion del producto cuyo codigo es igual al argumento
        for (int i = 0; i < cantidad; i ++ ) {
            if (productos[i].getCodigo() == codigo) {
                posicion = i;
            }
        }
        ss << endl << endl << "Productos mas costosos que el producto codigo: " << codigo << endl << endl;
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getPrecioDeVenta() > productos[posicion].getPrecioDeVenta()) {
                ss << "Producto numero: " << i + 1 << endl;
                ss << "Codigo: " << productos[i].getCodigo() << endl;
                ss << "Nombre: " << productos[i].getNombre() << endl;
                ss << "Precio de venta: " << productos[i].getPrecioDeVenta() << endl << endl;
                esVacio = false;
            }
        }
        //Se cambia el mensaje si no hay productos mas costosos que el producto codigo
        if (esVacio) {
            ss.clear(); //Vacia el stringstream
            ss << "No se encontraron productos mas costosos que el producto codigo: " << codigo;
        }
        return ss.str();
    }
    //12
    int cantidadDeUnidadesVendidasDeUnProducto(string codigo) { //cuantasUnidadesSeHanVendidoDelProducto
        int unidades = 0;
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getCodigo() == codigo) {
                unidades = productos[i].getCantidadVendida();
            }
        }
        return unidades;
    }
    //13
    int costoDelInventario() {
        int costo = 0;
        for (int i = 0; i < cantidad; i++) {
            costo += productos[i].getPrecioBase() * productos[i].getExistencia();
        }
        return costo;
    }
    //14
    int costoDeLasVentas() {
        int costo = 0;
        for (int i = 0; i < cantidad; i++){
            costo += productos[i].getPrecioBase() * productos[i].getCantidadVendida();
        }
        return costo;
    }
    //15
    int valorDeLasVentas() {
        int costo = 0;
        for (int i = 0; i < cantidad; i++){
            costo += productos[i].getPrecioDeVenta() * productos[i].getCantidadVendida();
        }
        return costo;
    }
    //16
    int gananciaDelSupermecadoPorVentas() {
        int ganancia  = 0;
        for (int i = 0; i < cantidad; i++){
            ganancia += (productos[i].getPrecioDeVenta() * productos[i].getCantidadVendida()) - (productos[i].getPrecioBase() * productos[i].getCantidadVendida());
        }
        return ganancia;
    }
    /**
    * Crea un string que contiene una tabla con el nombre del producto y un gráfico hecho con asteriscos de la cantidad
    * del producto vendido, en una escala 10, o sea, un asterisco representa 10 unidades vendidas.
    */
    string tablaDeGraficos() {
        stringstream ss;
        for (int i = 0; i < 5; i++) {
            ss << productos[i].getNombre();
            if (productos[i].getNombre().length() < 15) {
                for (int j = 0; j < 15 - productos[i].getNombre().length(); j++) {
                    ss << " ";
                }
            }
            ss << " |";
            for (int j = 0; j < productos[i].getCantidadVendida() / 10; j++) {
                ss << "*";
            }
            ss << endl;
        }
        //genera los primeros 15 espacios
        for (int j = 0; j < 16; j++) {
            ss << " ";
        }
        //crea el borde de la tabla
        for (int i = 0; i <= 100; i++) {
            if(i % 10 == 0){
                ss << "|";
            } else {
                ss << "_";
            }
        }

        ss << endl;
        //genera los primeros 15 espacios
        for (int j = 0; j < 16; j++) {
            ss << " ";
        }
        ss<< "0        100       200       300       400       500       600       700       800       900       1000" << endl;

        return ss.str();
    }
    //17
    string graficoDeVentaDeLos5MasVendidos() {
        stringstream ss;
        //ordena de mayor a menor en base a su cantidad vendida
        Producto aux;
        for(int i = 0; i < cantidad; i++){
            for(int j = i + 1; j < cantidad; j++){
                if(productos[i].getCantidadVendida() < productos[j].getCantidadVendida()){
                    aux = productos[i];
                    productos[i] = productos[j];
                    productos[j] = aux;
                }
            }
        }
        ss << endl << endl << "Grafico de venta de los 5 mas vendidos" << endl << endl;
        ss << tablaDeGraficos();
         
        return ss.str();
    }
    //18
    string graficoDeVentaDeLos5MenosVendidos() {
        stringstream ss;
        //ordena de menor a mayor en base a su cantidad vendida
        Producto aux;
        for(int i = 0; i < cantidad; i++){
            for(int j = i + 1; j < cantidad; j++){
                if (productos[i].getCantidadVendida() > productos[j].getCantidadVendida()) {
                    aux = productos[i];
                    productos[i] = productos[j];
                    productos[j] = aux;
                }
            }
        }
        //imprime los 5 primeros
        ss << endl << endl << "Grafico de venta de los 5 menos vendidos" << endl << endl;
        ss << tablaDeGraficos();
        return ss.str();
    }
    //19
/**
 * Calcula el precio medio de todos los productos vendidos por la tienda
 * 
 * @return La media de los precios de los productos vendidos.
 */
    float promedioDeLosPreciosVentas() {
        int contador = 0;
        float promedio = 0;
        for (int i = 0; i < cantidad; i++) {
            promedio += productos[i].getPrecioDeVenta() * productos[i].getCantidadVendida();
            contador ++;
        }
        return promedio / contador;
    }
    bool existeProducto(string codigo) {
        bool existe = false;
        for (int i = 0; i < cantidad; i++) {
            if (productos[i].getCodigo() == codigo) {
                existe = true;
            }
        }
        return existe;
    }
};
// Devuelve un string que contiene el menu
string menu () {
    stringstream menu;
    menu << "- 1- Ingresar producto(s)." << endl;
    menu << "- 2- Eliminar producto" << endl;
    menu << "- 3- Desplegar el producto de mayor precio." << endl;
    menu << "- 4- Desplegar el producto con mayor existencia." << endl;
    menu << "- 5- Ordenar los productos por codigo" << endl;
    menu << "- 6- Desplegar todos los productos." << endl;
    menu << "- 7- Desplegar la cantidad de productos bajos de existencia." << endl;
    menu << "- 8- Desplegar los productos bajos de existencia." << endl;
    menu << "- 9- Desplegar el total de kilogramos de todos los productos vendidos." << endl;
    menu << "-10- Desplegar el total de Kilogramos vendidos de un producto." << endl;
    menu << "-11- Desplegar la lista de productos que son mas costosos que un producto dado" << endl;
    menu << "-12- Desplegar la cantidad de unidades vendidas de un producto en particular." << endl;
    menu << "-13- Desplegar el Costo del Inventario." << endl;
    menu << "-14- Desplegar el Costo de las Ventas." << endl;
    menu << "-15- Desplegar el Valor de las Ventas." << endl;
    menu << "-16- Desplegar la ganancia total del supermercado por concepto de ventas." << endl;
    menu << "-17- Desplegar el grafico de las ventas de los 5 productos mas vendidos." << endl;
    menu << "-18- Desplegar el grafico de las ventas de los 5 productos menos vendidos." << endl;
    menu << "-19- Desplegar el promedio de los precios de venta." << endl;
    menu << "-20- SALIR" << endl << endl;

    menu << "Digite una opcion: ";

    return menu.str();
}
/**
 * Es una  switch que llama a una función de la clase Supermercado dependiendo de la opción elegida por el usuario
 * 
 * @param supermercado objeto de la clase Supermercado
 * @param opcion La opcion que el usuario elige
 * @param repetir bool que indica si el programa sigue o no
 * @param i index del array
 */
void eligeOpcion(Supermercado &supermercado, int opcion, bool &repetir, int &i) {
    switch (opcion) {
            case 1: {
                bool continuar = true;
                while(continuar){
                    supermercado.setTamano(supermercado.getTamano() + 1);
                        string codigo;
                        string nombre;
                        int precioBase;
                        int cantidadVendida;
                        int existencia;
                        int existenciaMinima;
                        float porcentajeDeGanancias;
                        float peso;
                        cout << "Digite los datos del producto numero " << i + 1 << ": " << endl << endl;
                        cout << "Digite el codigo del producto: ";
                        cin >> codigo;
                        cout << "Digite el nombre del producto: ";
                        cin >> nombre;
                        cout << "Digite el precio base del producto: ";
                        cin >> precioBase;
                        cout << "Digite el porcentaje de ganancias del producto (Entre 0 y 1): ";
                        cin >> porcentajeDeGanancias;
                        cout << "Digite la cantidad vendida del producto: ";
                        cin >> cantidadVendida;
                        cout << "Digite la existencia del producto: ";
                        cin >> existencia;
                        cout << "Digite el peso del producto (En kilogramos): ";
                        cin >> peso;
                        cout << "Digite la existencia minima del producto: ";
                        cin >> existenciaMinima;
                        cout << endl;
                        Producto producto(codigo, nombre, precioBase, porcentajeDeGanancias, cantidadVendida, existencia, peso, existenciaMinima);
                        supermercado.ingresaProducto(i, producto);
                        i++;
                    do {
                        cout << "Desea ingresar otro producto? (1-Si, 2-No): ";
                        cin >> opcion;
                        if (opcion == 1) {
                            continuar = true;
                        } else if (opcion == 2) {
                            continuar = false;
                        } else {
                            cout << "Opcion invalida" << endl;
                        }
                    } while (opcion != 1 && opcion != 2);
                }

            }
                break;
            case 2: {                
                string codigo;
                cout << "Digite el codigo del producto a eliminar: ";
                cin >> codigo;
                if (supermercado.existeProducto(codigo)) {
                    supermercado.eliminarProductoPorCodigo(codigo);
                    cout << "Se elimino el producto con codigo " << codigo << endl;
                } else {
                    cout << "El producto no existe" << endl;
                }
                }
                break;
            case 3:{                
                cout << "El producto de mayor precio es: " << endl;
                cout << supermercado.productoDeMayorValor().mostrarDatosDelProducto() << endl;
                }
                break;
            case 4: {                
                cout << "El producto con mayor existencia es: " << endl;
                cout << supermercado.productoConMayorExistencia().mostrarDatosDelProducto() << endl;
                }
                break;
            case 5: {
                supermercado.ordenarProductosPorCodigo();
                }
                break;
            case 6: {
                cout << supermercado.mostrarTodosLosProductos() << endl;
                }
                break;
            case 7: {                
                cout << "Hay: " << supermercado.cantidadDeProductosBajosDeExistencia() << " productos bajos de existencia" << endl;
                }
                break;
            case 8: {
                cout << supermercado.mostrarProductosBajosDeExistencia() << endl;
                }
                break;
            case 9: {
                cout << "El total de kilogramos de todos los productos vendidos es: ";
                cout << supermercado.kilogramosVendidos() << endl;
                }
                break;
            case 10: {
                string codigo;
                cout << "Digite el codigo del producto: ";
                cin >> codigo;
                if (supermercado.existeProducto(codigo)) {
                    cout << "El total de kilogramos vendidos del producto " << codigo << " es: ";
                    cout << supermercado.kilogramosVendidosDeUnProducto(codigo) << endl;
                } else {
                    cout << "El producto no existe" << endl;
                }
                }
                break;
            case 11: {
                string codigo;
                cout << "Digite el codigo del producto: ";
                cin >> codigo;
                if (supermercado.existeProducto(codigo)) {
                    cout << supermercado.productosMasCostososQue(codigo) << endl;
                } else {
                    cout << "El producto no existe" << endl;
                }
                }
                break;
            case 12: {
                string codigo;
                cout << "Digite el codigo del producto: ";
                cin >> codigo;
                if (supermercado.existeProducto(codigo)) {
                    cout << "La cantidad de unidades vendidas del producto codigo " << codigo << " son: ";
                    cout << supermercado.cantidadDeUnidadesVendidasDeUnProducto(codigo) << endl;
                } else {
                    cout << "El producto no existe" << endl;
                }
                }
                break;
            case 13: {
                cout << "El costo de inventario es: " << supermercado.costoDelInventario() << endl;
                }
                break;
            case 14: {
                cout << "El costo de ventas es: " << supermercado.costoDeLasVentas() << endl;
                }
                break;
            case 15: {
                cout << "El valor de las ventas es: " << supermercado.valorDeLasVentas() << endl << endl;
                }
                break;
            case 16: {
                cout << "La ganancia total del Supermercado por concepto de ventas es: ";
                cout << supermercado.gananciaDelSupermecadoPorVentas() << endl << endl;
                }
                break;
            case 17: {
                cout << supermercado.graficoDeVentaDeLos5MasVendidos() << endl << endl;
                }
                break;
            case 18: {
                cout << supermercado.graficoDeVentaDeLos5MenosVendidos() << endl << endl;
                }
                break;
            case 19: {
                cout << "El promedio de precios de venta de los productos vendidos con ganancia es: ";
                cout << supermercado.promedioDeLosPreciosVentas() << endl << endl;
                }
                break;
            case 20: {
                repetir = false;
                }
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
}
int main() {
    int opcion;
    string codigo;
    bool repetir = true;
    Supermercado SuperContenedorV;
    while (repetir) {
        cout << menu();
        cin >> opcion;
        int i = 0;
        eligeOpcion(SuperContenedorV, opcion, repetir, i);
    }

    SuperContenedorV.~Supermercado();

    return 0;
}