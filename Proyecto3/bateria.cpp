#define maximoFilasBateria 25
#define maximoColumnasBateria 25
#define maximoVoltaje 12
#define maximoAmperaje 12
#include <iostream>
#include <sstream>
using namespace std;

class Celda {
private:
    int condicion; //-1=deshabilitada 0=mal estado, 1=buen estado
    float voltaje;
    float amperaje;
public:
    Celda() {
        condicion = 1;
        voltaje = 12;
        amperaje = 12;
    }
    Celda(int condicion, float voltaje, float amperaje) {
        this->condicion = condicion;
        this->voltaje = voltaje;
        this->amperaje = amperaje;
    }
    //destructor
    ~Celda() {}
    //setters
    void setCondicion(int condicion) {
        this->condicion = condicion;
    }
    void setVoltaje(float voltaje) {
        this->voltaje = voltaje;
    }
    void setAmperaje(float amperaje) {
        this->amperaje = amperaje;
    }
    //getters
    int getCondicion() {
        return condicion;
    }
    float getVoltaje() {
        return voltaje;
    }
    float getAmperaje() {
        return amperaje;
    }
    //toString
    string detallesDeLaCelda() {
        stringstream ss;
        ss << "CondiciÛn: " << condicion << endl;
        ss << "Voltaje: " << voltaje << endl;
        ss << "Amperaje: " << amperaje;
        return ss.str();
    }
};
class Bateria {
private:
    Celda bateria[maximoFilasBateria][maximoColumnasBateria];
    string codigo;
    string tipo;
    string modelo;
    int anno;
    float costoDeProduccion;
    int filas;
    int columnas;

public:
    //constructores
    Bateria() {
        codigo = "Default";
        tipo = "Default";
        modelo = "Default";
        anno = 0;
        costoDeProduccion = 0;
        filas = 25;
        columnas = 25;
    }
    Bateria(string codigo, string tipo, string modelo, int anno, float costoDeProduccion, int filas, int columnas) {
        this->codigo = codigo;
        this->tipo = tipo;
        this->modelo = modelo;
        this->anno = anno;
        this->costoDeProduccion = costoDeProduccion;
        this->filas = filas;
        this->columnas = columnas;
    }
    //destructor
    ~Bateria() {}
    //setters
    void setFilas(int filas) {
        this->filas = filas;
    }
    void setColumnas(int columnas) {
        this->columnas = columnas;
    }
    void setCelda(int x, int y, Celda celda) {
        bateria[x][y] = celda;
    }
    void setCodigo(string codigo) {
        this->codigo = codigo;
    }
    void setTipo(string tipo) {
        this->tipo = tipo;
    }
    void setModelo(string modelo) {
        this->modelo = modelo;
    }
    void setAnno(int anno) {
        this->anno = anno;
    }
    void setCostoDeProduccion(float costoDeProduccion) {
        this->costoDeProduccion = costoDeProduccion;
    }
    //getters
    int getFilas() {
        return filas;
    }
    int getColumnas() {
        return columnas;
    }
    string getCodigo() {
        return codigo;
    }
    string getTipo() {
        return tipo;
    }
    string getModelo() {
        return modelo;
    }
    int getAnno() {
        return anno;
    }
    float getCostoDeProduccion() {
        return costoDeProduccion;
    }
    Celda getCelda(int x, int y) {
        return bateria[x][y];
    }
    Bateria getBateria() {
        return *this;
    }
//metodos
/**
 * 
 * Establece la condicion de cada celda cuya condicion sea -1 y que este antes de @param filas y @param columnas
 * 
 * @param filas numero de filas
 * @param columnas numero de columnas
 */
    int totalDeAmperios() { //7
        int total = 0;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                total += bateria[i][j].getAmperaje();
            }
        }
        return total;
    }
    int totalDeVoltios() { //8
        int total = 0;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                total += bateria[i][j].getVoltaje();
            }
        }
        return total;
    }
    string dibujarCeldas() {
        stringstream ss;
        //enumerar las columnas
        ss << "   ";
        for (int i = 0; i < maximoColumnasBateria; i++) {
            if (i < 9) {
                ss << i <<"     ";
            } else {
                ss << i <<"    ";
            }
        }
        
        ss << endl;
        for (int i = 0; i < 151; i++) {
            ss << "_";
        }
        ss << endl;
        for (int i = 0; i <= 152; i++) {
            if (i % 6 == 0){
                ss << "|";
            } else {
                ss << " ";
            }
        }
		ss << endl;
        for (int i = 0; i < maximoFilasBateria; i++) {
            //crea el cuadro con la condicion
            ss << "| ";
            for (int j = 0; j < maximoColumnasBateria; j++) {
                if (bateria[i][j].getCondicion() == -1) {
                    ss << "-1  | ";
                } else if (bateria[i][j].getCondicion() == 0) {
                    ss << " 0  | ";
                } else {
                    ss << " 1  | ";
                }
            }
            //enumerar las filas
            ss << " " << i;
            ss << endl;
            for (int k = 0; k < 151 / 6; k++) {
                ss << "|_____";
            }
			ss << "|" ;
            ss << endl;
            if (i != filas - 1) {
                for (int k = 0; k <= 151 / 6; k++) {
                    ss << "|     ";
                }
                ss << endl;
            }
        }
        return ss.str();
    }
    string datosDeLaBateria() { //1
        deshabilitarCeldas();
        stringstream ss;
        //datos de la bateria
        ss << "Codigo de la baterÌa: " << codigo << endl;
        ss << "Tipo: " << tipo << endl;
        ss << "Modelo: " << modelo << endl;
        ss << "AÒo: " << anno << endl;
        ss << "Costo de producciÛn: " << costoDeProduccion << endl;
        ss << "Total de amperajes: " << totalDeAmperios() << endl;
        ss << "Total de voltajes: " << totalDeVoltios() << endl;
        ss << endl << endl;
        ss << "Filas habilitadas: " << filas << endl;
        ss << "Columnas habilitadas: " << columnas << endl << endl;
        
        ss << dibujarCeldas();
        return ss.str();
    }
    string informacionCelda(int x, int y) {  //2
        stringstream ss;
        ss << "BaterÌa: " << modelo << endl;
        ss << "Celda: " << x << "," << y << endl;
        ss << bateria[x][y].detallesDeLaCelda();
        return ss.str();
    }
    void modificarAleatoriamente() { //3
        string tipos[6] = {"PB-acido", "NiCd", "NiMH", "LiCoO2", "LiFePO4", "LiPo"};
        stringstream codeGen;
        setTipo(tipos[rand() % 6]);
        setModelo("Modelo " + to_string(rand() % 100));
        setAnno(rand() % 2023);
        setCostoDeProduccion(rand() % 1000);
        //crear cadena de caracteres con el codigo
        codeGen << "B" << rand() % 100 << "-" << tipos[rand() % 6] << "-" << rand() % 100;
        setCodigo(codeGen.str());

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                bateria[i][j].setCondicion(rand() % 2);  //genera un numero aleatorio entre 0 y 1
                bateria[i][j].setVoltaje(rand() % 13);   //genera un numero aleatorio entre 0 y 12
                bateria[i][j].setAmperaje(rand() % 13);
            }
        }
    }
    //recibe la posicion de una celda y verifica si esta habilitada

/**
 * Devuele true si la en la posicion x, y esta habilitada (condicion igual a 1 o 0), y falso de cualquier otra manera
 * 
 * @param x la fila de la bateria
 * @param y la columna de la bateria
 * 
 * @return false si la condicion en la poscion x, y es -1, true de cualquier otra manera
 */
    bool estaHabilitada(int x, int y) {
        if (bateria[x][y].getCondicion() == -1) {
            return false;
        } else {
            return true;
        }
    }
/**
 * Modifica la celda en la posicion x, y
 * 
 * @param x la fila de la bateria
 * @param y la columna de la bateria
 * 
 * @param celda la celda que se colocar√° en la bater√≠a en la posicion x, y
 */
    void modificarCelda(int x, int y, Celda celda) {
            bateria[x][y] = celda;
    }
    string estadoDeLaBateria() { //5
        float contadorBuenEstado = 0;
        float contadorMalEstado = 0;
        float contadorDeshabilitadas = 0;
        float porcentajeEnBuenEstado = 0;
        float porcentajeEnMalEstado = 0;
        float porcentajeDeshabilitadas = 0;
        stringstream ss;
        ss << "Estado de la baterÔøΩa " << getModelo() << " : " << endl << endl;
        for (int i = 0; i < maximoFilasBateria; i++) {
            for (int j = 0; j < maximoColumnasBateria; j++) {
                if (bateria[i][j].getCondicion() == -1) {
                    contadorDeshabilitadas += 1;
                } else if (bateria[i][j].getCondicion() == 0) {
                    contadorMalEstado += 1;
                } else {
                    contadorBuenEstado += 1;
                }
            }
        }
        porcentajeEnBuenEstado = (contadorBuenEstado * 100) / (maximoFilasBateria * maximoColumnasBateria);
        porcentajeEnMalEstado = (contadorMalEstado * 100) / (maximoFilasBateria * maximoColumnasBateria);
        porcentajeDeshabilitadas = (contadorDeshabilitadas * 100) / (maximoFilasBateria * maximoColumnasBateria);
        ss << "Celdas en buen estado: " << contadorBuenEstado << endl;
        ss << "Celdas en mal estado: " << contadorMalEstado << endl;
        ss << "Celdas deshabilitadas: " << contadorDeshabilitadas << endl;
        ss << "Porcentaje de celdas en buen estado: " << porcentajeEnBuenEstado << "%" << endl;
        ss << "Porcentaje de celdas en mal estado: " << porcentajeEnMalEstado << "%" << endl;
        ss << "Porcentaje de celdas deshabilitadas: " << porcentajeDeshabilitadas << "%" << endl;
        return ss.str();
    }
//Establece la condici√≥n de las celdas que est√°n fuera del rango de la bater√≠a a -1
    void deshabilitarCeldas() {
        for (int i = 0; i < maximoFilasBateria; i++) {
            for (int j = 0; j < maximoColumnasBateria; j++) {
                if (i > filas - 1 || j > columnas - 1) {
                    bateria[i][j].setCondicion(-1);
                }
            }
        }
    }
/**
*Establece el voltaje y amperaje de las nuevas celdas (celdas cuya condicion es -1)
* 
* @param voltaje el voltaje de las nuevas celdas
* @param amperaje el amperaje de las nuevas celdas
* @param filas la cantidad de filas nuevas que va a tener la bateria
* @param columnas la cantidad de columnas nuevas que va a tener la bateria
*/
//En lugar de empezar desde 0 se podria empezar desde la fila y columna actual
    void establecerAmperioYVoltajeDeLasCeldasNuevas (int voltaje, int amperaje, int filas, int columnas){
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (bateria[i][j].getCondicion() == -1) {
                    bateria[i][j].setVoltaje(voltaje);
                    bateria[i][j].setAmperaje(amperaje);
                }
            }
        }
    }
/**
* Establece la condiciÛn de cada celda a 1 si su condiciÛn es -1
* 
* @param filas nuevo numero de filas
* @param columnas nuevo numero de columnas
*/
    void habilitarCeldas(int filas, int columnas) {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (bateria[i][j].getCondicion() == -1) {
                    bateria[i][j].setCondicion(1);
                }
            }
        }
    }
/**
* Modifica el tamaÒo de la baterÌa, y si el nuevo tamaÒo es mayor que el anterior, se
* habilita las nuevas celdas y establece su voltaje y amperaje
* 
* En caso de que el nuevo tamaÒo sea menor que el anterior, se deshabilitan las celdas que sobran
* 
* @param nuevasFilas nuevo numero de filas
* @param nuevasColumnas nuevo numero de columnas
* @param voltaje voltage of the battery
* @param amperaje the amperage of the battery
*/
    void modificarTamanoBateria(int nuevasFilas, int nuevasColumnas, int voltaje, int amperaje) { //6
        if (nuevasFilas < getFilas() || nuevasColumnas < getColumnas()){
            this->filas = nuevasFilas;
            this->columnas = nuevasColumnas;
            deshabilitarCeldas();
        } else if(nuevasFilas > getFilas() || nuevasColumnas > getColumnas()){
            this->filas = nuevasFilas;
            this->columnas = nuevasColumnas;
            establecerAmperioYVoltajeDeLasCeldasNuevas(voltaje, amperaje, nuevasFilas, nuevasColumnas);
            habilitarCeldas(nuevasFilas, nuevasColumnas);
        }
    }
/**
 * Intercambia el contenido del objeto que llama a la funci√≥n con el contenido del objeto que se
 * pasa como argumento
 * 
 * @param bateria La bater√≠a que se intercambiar√° con la actual.
 */
    void cambiarBateria(Bateria &bateria) {
        Bateria aux;
        aux = bateria;
        bateria = *this;
        *this = aux;
    }
    //Devuelve el amperaje medio de la bateria
    float promedioAmperaje() {
        float contador = 0;
        float promedio = 0;
        for (int i = 0; i < maximoFilasBateria; i++) {
            for (int j = 0; j < maximoColumnasBateria; j++) {
                contador += bateria[i][j].getAmperaje();
            }
        }
        promedio = contador / (maximoFilasBateria * maximoColumnasBateria);
        return promedio;
    }
/**
* 
* Compara el amperaje promedio de la baterÌa con el amperaje medio de la baterÌa pasado como par·metro.
* 
* @param bateriaParametro el objeto que va a ser comparado con el objeto que llama la funcion
* @param promedioAmperajeBateriaParametro el amperaje promedio de la baterÌa pasada como par·metro
* 
* @return el amperaje promedio de la bateria que llama a la funcion
*/
    float compararBateria(Bateria bateriaParametro, float &promedioAmperajeBateriaParametro) {
        float promedioAmperajeBateriaPropia = promedioAmperaje();
        promedioAmperajeBateriaParametro = bateriaParametro.promedioAmperaje();

        return promedioAmperajeBateriaPropia;
    }
};
string resultadoDeCompararLasBaterias(Bateria bateria, Bateria bateria2){
    stringstream ss;
    float promedioAmperajeBateriaParametro = 0;
    float promedioAmperajeBateriaPropia = bateria.compararBateria(bateria2, promedioAmperajeBateriaParametro);
    ss << "ComparaciÛn de la bateria " << bateria.getModelo() << " con la baterÌa " << bateria2.getModelo() << endl << endl;
    ss << "Promedio de amperaje de la baterÌa " << bateria.getModelo() << ": " << promedioAmperajeBateriaPropia << endl;
    ss << "Promedio de amperaje de la baterÌa " << bateria2.getModelo() << ": " << promedioAmperajeBateriaParametro << endl << endl;
    
    if (promedioAmperajeBateriaPropia > promedioAmperajeBateriaParametro) {
        ss << "La baterÌa " << bateria.getModelo() << " es m·s eficiente que la baterÔøΩa " << bateria2.getModelo() << endl; 
    } else if(promedioAmperajeBateriaPropia < promedioAmperajeBateriaParametro){
        ss << "La baterÌa " << bateria2.getModelo() << " es m·s eficiente que la baterÔøΩa " << bateria.getModelo() << endl;
    } else {
        ss << "Las baterÌas " << bateria.getModelo() << " y " << bateria2.getModelo() << " son iguales" << endl;
    }
    return ss.str();
}
string menu() {
    stringstream ss;
    ss << endl;
    ss << "Men˙: " << endl;
    ss << "1. InformaciÛn de la baterÌa" << endl;
    ss << "2. InformaciÛn de una celda" << endl;
    ss << "3. Llenar aleatoriamente las celdas de una baterÌa" << endl;
    ss << "4. Modificar una celda" << endl;
    ss << "5. Estado de la baterÌa" << endl;
    ss << "6. Modificar la capacidad de la baterÌa" << endl;
    ss << "7. Intercambiar baterÌa" << endl;
    ss << "8. Comparar baterÌas" << endl;
    ss << "0. Salir" << endl;
    ss << "Ingrese una opciÛn: ";
    return ss.str();
}
bool validarAmperaje(int amperios) {
    bool valido = true;
    if (amperios < 0 || amperios > maximoAmperaje) {
        valido = false;
    }
    return valido;
}
bool validarVoltaje(int voltaje) {
    bool valido = true;
    if (voltaje < 0 || voltaje > maximoVoltaje) {
        valido = false;
    }
    return valido;
}
bool validarCelda(int fila, int columna) {
    bool valido = true;
    if (fila < 0 || fila > maximoFilasBateria - 1 || columna < 0 || columna > maximoColumnasBateria - 1) {
        valido = false;
    }
    return valido;
}
bool validarOpcion(int opcion) {
    bool valido = true;
    if (opcion != 1 && opcion != 2) {
        valido = false;
    }
    return valido;
}
string mensajeDeErrorCelda() {
    stringstream ss;
    ss << "Ingrese una celda v·lida" << endl;
    ss << "El n˙mero de filas y columnas debe de ser mayor o igual 0 y menor a " << maximoFilasBateria << endl;
    return ss.str();
}
string averiguarElTipoDeBateria(int opcion, string &tipo) {
    if (opcion == 1) {
        tipo = "PB-acido";
    } else if (opcion == 2) {
        tipo = "NiCd";
    } else if(opcion == 3) {
        tipo = "NiMh";
    } else if(opcion == 4) {
        tipo = "LiCoO2";
    } else if(opcion == 5) {
        tipo = "LiFePO4";
    } else if(opcion == 6) {
        tipo = "LiPo";
    }
	return tipo;
}
void eligeOpcion(Bateria &bateria, Bateria &bateria2,  int opcionMenu, bool &repetir){
    int fila;
    int columna;
    int nuevasFilas;
    int nuevasColumnas;
    int opcion;
    int condicion;
    int voltaje;
    int amperaje;
    switch (opcionMenu) {
        case 0:
            repetir = false;
            break;
        case 1:
            do {
                cout << "øCu·l baterÌa desea ver (1 o 2)?: ";
                cin >> opcion;
                if (validarOpcion(opcion)) {
                    cout << "Ingrese una opciÛn valida" << endl;
                }
            } while (validarOpcion(opcion) == false);
            if (opcion == 1) {
                cout << endl << bateria.datosDeLaBateria();
            } else if (opcion == 2) {
                cout << endl << bateria2.datosDeLaBateria();
            }
            break;
        case 2:
            do {
                cout << "øLa celda de cu·l baterÌa desea ver (1 o 2)?: ";
                cin >> opcion;
                if (validarOpcion(opcion) == false) {
                    cout << "Ingrese una opciÛn valida" << endl;
                }
                cout << endl;
            } while (validarOpcion(opcion) == false);
            if (opcion == 1) {
                do {
                    cout << bateria.dibujarCeldas() << endl;
                    cout << "Ingrese la fila: ";
                    cin >> fila;
                    cout << "Ingrese la columna: ";
                    cin >> columna;
                    if (validarCelda(fila, columna) == false) {
                        cout << mensajeDeErrorCelda() << endl;
                    }
                    cout << endl;
                } while (validarCelda(fila, columna) == false); //Validaci√≥n de que la celda exista (las celdad inhabilitadas tambien se toman en cuenta)
                cout << bateria.informacionCelda(fila, columna) << endl;
            } else if (opcion == 2) {
                    do {
                    cout << bateria2.dibujarCeldas() << endl;
                    cout << "Ingrese la fila: ";
                    cin >> fila;
                    cout << "Ingrese la columna: ";
                    cin >> columna;
                    if (validarCelda(fila, columna) == false) {
                        cout << mensajeDeErrorCelda() << endl;
                    }
                    cout << endl;
                } while (validarCelda(fila, columna) == false); //Validaci√≥n de que la celda exista (las celdad inhabilitadas tambien se toman en cuenta)
                cout << bateria2.informacionCelda(fila, columna) << endl;
            }
            break;
        case 3:
            do {
                cout << "Cual baterÌa desea llenar aleatoriamente (1 o 2): ";
                cin >> opcion;
                if (validarOpcion(opcion) == false) {
                    cout << "Ingrese una opciÛn valida" << endl;
                }
            } while (validarOpcion(opcion) == false);  
            if (opcion == 1) {
                bateria.modificarAleatoriamente();
                cout << "La baterÌa " << bateria.getModelo() << " se lleno aleatoriamente" << endl;
            } else if (opcion == 2) {
                bateria2.modificarAleatoriamente();
                cout << "La baterÌa " << bateria2.getModelo() << " se lleno aleatoriamente" << endl;
            }
            break;
        case 4:
            do {
                cout << "Cual baterÌa desea ver (1 o 2): ";
                cin >> opcion;
                if (validarOpcion(opcion) == false) {
                    cout << "Ingrese una opciÛn v·lida" << endl;
                }
                cout << endl;
            } while (validarOpcion(opcion) == false);

            if (opcion == 1) {
                cout << bateria.dibujarCeldas() << endl;
                do {
                    cout << "Ingrese la fila: ";
                    cin >> fila;
                    cout << "Ingrese la columna: ";
                    cin >> columna;
                    //Validaci√≥n de que la celda exista y que no se modifique una celda inhabilitada
                    if (validarCelda(fila, columna) == false) {
                        cout << mensajeDeErrorCelda() << endl;
                    } else if(bateria.estaHabilitada(fila, columna) == false){
                        cout << "La celda seleccionada no esta habilitada" << endl;
                    }
                    cout << endl;
                } while (validarCelda(fila, columna) == false || bateria.estaHabilitada(fila, columna) == false);
            } else if (opcion == 2) {
                cout << bateria2.dibujarCeldas() << endl;
                do {
                    cout << "Ingrese la fila: ";
                    cin >> fila;
                    cout << "Ingrese la columna: ";
                    cin >> columna;
                    //Validaci√≥n de que la celda exista y que no se modifique una celda inhabilitada
                    if (validarCelda(fila, columna) == false) {
                        cout << mensajeDeErrorCelda() << endl;
                    } else if(bateria2.estaHabilitada(fila, columna) == false){
                        cout << "La celda seleccionada no esta habilitada" << endl;
                    }
                    cout << endl;
                } while (validarCelda(fila, columna) == false || bateria2.estaHabilitada(fila, columna) == false);
            }
            do {
                cout << "Ingrese la condiciÔøΩn de la celda (0 o 1): ";
                cin >> condicion;
                if (condicion != 0 && condicion != 1) {
                    cout << "Ingrese una condiciÛn v·lida" << endl;
                    cout << "La condiciÛn debe de ser 0 o 1" << endl << endl;
                }
            } while (condicion != 0 && condicion != 1);
            do {
                cout << "Ingrese el voltaje: ";
                cin >> voltaje;
                if (validarVoltaje(voltaje) == false) {
                    cout << "Ingrese un voltaje v·lido" << endl;
                    cout << "El voltaje debe de ser mayor o igual 0 y menor o igual a  " << maximoVoltaje << endl << endl;
                }
            } while (validarVoltaje(voltaje)  == false);
            do {
                cout << "Ingrese el amperaje: ";
                cin >> amperaje;
                if (validarAmperaje(amperaje) == false) {
                    cout << "Ingrese un amperaje v·lido" << endl;
                    cout << "El amperaje debe de ser mayor o igual 0 y menor o igual a " << maximoAmperaje << endl;
                }
                cout << endl;
            } while (validarAmperaje(amperaje) == false);

            if (opcion == 1) {
                bateria.modificarCelda(fila, columna, Celda(condicion, voltaje, amperaje));
            } else if (opcion == 2) {
                bateria2.modificarCelda(fila, columna, Celda(condicion, voltaje, amperaje));
            }
            break;
        case 5:
            do {
                cout << "De cual baterÌa desea ver el estado (1 o 2): ";
                cin >> opcion;
                if (validarOpcion(opcion) == false) {
                    cout << "Ingrese una opciÛn v·lida" << endl;
                }
                cout << endl;
            } while (validarOpcion(opcion) == false);
            if (opcion == 1) {
                cout << bateria.estadoDeLaBateria() << endl;
            } else if (opcion == 2) {
                cout << bateria2.estadoDeLaBateria() << endl;
            }
            break;
        case 6:
            do {
                cout << "Cual baterÌa desea editar (1 o 2): ";
                cin >> opcion;
                if (validarOpcion(opcion) == false) {
                    cout << "Ingrese una opciÛn valida" << endl;
                }
                cout << endl;
            } while (validarOpcion(opcion) == false);
            do {
                cout << "Ingrese el n˙mero de filas: ";
                cin >> nuevasFilas;
                cout << "Ingrese el n˙mero de columnas: ";
                cin >> nuevasColumnas;
                if (nuevasFilas > maximoFilasBateria || nuevasFilas < 0 || nuevasColumnas > maximoColumnasBateria || nuevasColumnas < 0) {
                    cout << endl << "No se puede crear la baterÌa con esas dimensiones" << endl;
                    cout << "El numero de filas y columnas debe de ser mayor o igual 0 y menor o igual a " << maximoFilasBateria << endl << endl;
                }
                cout << endl;
            } while (nuevasFilas > maximoFilasBateria || nuevasColumnas > maximoColumnasBateria);
            if (opcion == 1) {
                if (nuevasFilas < bateria.getFilas() || nuevasColumnas < bateria.getColumnas()) {
                    bateria.modificarTamanoBateria(nuevasFilas, nuevasColumnas, voltaje, amperaje);
                } else if (nuevasFilas > bateria.getFilas() || nuevasColumnas > bateria.getColumnas()) {
                    do{
                        cout << "Digite el voltaje de las nuevas celdas: " << endl;
                        cin >> voltaje;
                        if (validarVoltaje(voltaje) == false) {
                            cout << "El voltaje debe de ser mayor o igual 0 y menor o igual a " << maximoVoltaje << endl;
                        }
                    } while (validarVoltaje(voltaje) == false);
                    do{
                        cout << "Digite el amperaje de las nuevas celdas: " << endl;
                        cin >> amperaje;
                        if(validarAmperaje(amperaje) == false) {
                            cout << "El amperaje debe de ser mayor o igual 0 y menor o igual a " << maximoAmperaje << endl;
                        }
                    } while (validarAmperaje(amperaje) == false);
                    bateria.modificarTamanoBateria(nuevasFilas, nuevasColumnas, voltaje, amperaje);
                }
                cout << "Nuevo estado de la baterÌa:" << endl;
                cout << bateria.dibujarCeldas() << endl;
            } else if (opcion == 2) {
                if (nuevasFilas < bateria2.getFilas() || nuevasColumnas < bateria2.getColumnas()) {
                    bateria2.modificarTamanoBateria(nuevasFilas, nuevasColumnas, voltaje, amperaje);
                } else if (nuevasFilas > bateria2.getFilas() || nuevasColumnas > bateria2.getColumnas()) {
                    do{
                        cout << "Digite el voltaje de las nuevas celdas: " << endl;
                        cin >> voltaje;
                        if (validarVoltaje(voltaje) == false) {
                            cout << "El voltaje debe de ser mayor o igual 0 y menor o igual a " << maximoVoltaje << endl;
                        }
                    } while (validarVoltaje(voltaje) == false);
                    do{
                        cout << "Digite el amperaje de las nuevas celdas: " << endl;
                        cin >> amperaje;
                        if(validarAmperaje(amperaje) == false) {
                            cout << "El amperaje debe de ser mayor o igual 0 y menor o igual a " << maximoAmperaje << endl;
                        }
                    } while (validarAmperaje(amperaje) == false);
                    bateria2.modificarTamanoBateria(nuevasFilas, nuevasColumnas, voltaje, amperaje);
                }
                cout << "Nuevo estado de la baterÌa:" << endl;
                cout << bateria2.dibujarCeldas() << endl;
            }
            break;
        case 7:
            bateria.cambiarBateria(bateria2);
            cout << "Se han intercambiado los valores de las baterÌas" << endl;
            break;
        case 8:
            cout << resultadoDeCompararLasBaterias(bateria, bateria2);
            break;    
        default:
            cout << "OpciÔøΩn no valida" << endl << endl;
            break;
    }
}
string valoresIniciales(int &anno, string &codigo, string &modelo, string &tipo, int &costoDeProduccion, int &filas, int &columnas) {
    int opcion;
    do {
        cout << "Ingrese cantidad de filas: ";
        cin >> filas;
        cout << "Ingrese la cantidad de columnas: ";
        cin >> columnas;
        //Validaci√≥n de que la celda exista y que no se modifique una celda inhabilitada
        if (validarCelda(filas, columnas) == false) {
            cout << mensajeDeErrorCelda() << endl;
        }
    } while (validarCelda(filas, columnas) == false);
    do {
        cout << "Ingrese el aÒo de fabricaciÛn: ";
        cin >> anno;
        if (anno > 2022) {
            cout << "Digite un aÒo v·lido" << endl;
        }
    } while(anno > 2022);
    cout << "Ingrese el codigo: ";
    cin >> codigo;
    cout << "Ingrese el modelo: ";
    cin >> modelo;
    do{
        cout << "Seleccione uno de los siguientes tipos de baterÌa" << endl;
        cout << "1. PB-acido" << endl;
        cout << "2. NiCd" << endl;
        cout << "3. NiMh" << endl;
        cout << "4. LiCoO2" << endl;
        cout << "5. LiFePO4" << endl;
        cout << "6. LiPo" << endl;
        cin >> opcion;
        if (opcion < 1 || opcion > 6 ) {
            cout << "Ingrese una opciÛn v·lida" << endl;
        }
    } while (opcion < 1 || opcion > 6);
    averiguarElTipoDeBateria(opcion, tipo);
    cout << "Ingrese el costo de producciÛn: ";
    cin >> costoDeProduccion;
    return "Se han ingresado los valores iniciales";
}
int main() {
    int anno;
    string codigo;
    string modelo;
    string tipo;
    int costoDeProduccion;
    int filas;
    int columnas;
    //Datos bateria 1
    cout << "Valores iniciales de la baterÌa 1" << endl;
    cout << valoresIniciales(anno, codigo, modelo, tipo, costoDeProduccion, filas, columnas);
	system("pause"); system("cls");
    Bateria bateria(codigo, tipo, modelo, anno, costoDeProduccion, filas, columnas);
    //Datos bateria 2
    cout << "Valores iniciales de la baterÌa 2" << endl;
    cout << valoresIniciales(anno, codigo, modelo, tipo, costoDeProduccion, filas, columnas);
    Bateria bateria2(codigo, tipo, modelo, anno, costoDeProduccion, filas, columnas); 
	system("pause"); system("cls");
    //Menu de opciones
    bool repetir = true;
    int opcionMenu = 0;
    while (repetir) {
        cout << menu();
        cin >> opcionMenu;
        cout << endl;
        eligeOpcion(bateria, bateria2, opcionMenu, repetir);
		system("pause"); system("cls");
    }
    cout << "Gracias por usar el programa" << endl;    
    return 0;
}
