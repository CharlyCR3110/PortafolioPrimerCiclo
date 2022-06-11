//Carlos González Garita || Universidad Nacional || Ingeniería en Sistemas
//17/04/2022
//El objetivo del programa es pasar un número decimal a un número romano, para luego convertir este número romano en código morse, esto con el fin de hacerle sonar.
#include <iostream>
#include <windows.h>
using namespace std;

string decimalToRomano(int numero) {
    string romano = "";
    /*Se crea un array para los valores basicos y otro para los romanos. El elemento en la posicion 0 de el array decimal 
    tiene el mismo valor que el elemento en la posicion 0 del array romano y asi sucesivamente.*/
    int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; 
    string romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
    int recorredorDeArrays = 0;   

    while (numero) {                        
        while (numero / decimal[recorredorDeArrays]) {       //el primer valor basico que divide a n es el mayor valor basico
            romano += romanos[recorredorDeArrays];           //Se agrega el simbolo romano equivalente
            numero -= decimal[recorredorDeArrays];           //Se resta el valor mayor de n, o sea, si n es 1100 se resta 1000
        }
        recorredorDeArrays++;                           
    }
    return romano;
}

/**
 * It takes a string of Roman numerals as input, and returns a string of Morse code
 * 
 * @param romano The string that contains the roman letters.
 * 
 * @return the string 'morse' which contains the morse code of the string 'romano'
 */
string romanoToMorse(string romano) {
    string morse = "";
    int i = 0;

    while (romano[i]) {                          //int i se encarga de reccorer cada letra del string almacenado en la variable 'romano'
        if (romano[i] == 'M') {                  //Se evaluan las posibles letras romanas, y se agrega la clave morse correspondiente
            morse += "-- ";                      
        } else if (romano[i] == 'D') {           
            morse += "-.. ";
        } else if (romano[i] == 'C') {
            morse += "-.-. ";
        } else if (romano[i] == 'L') {
            morse += ".-.. ";
        } else if (romano[i] == 'X') {
            morse += "-..- ";
        } else if (romano[i] == 'V') {
            morse += "...- ";
        } else if (romano[i] == 'I') {
            morse += ".. ";
        }
        i++;
    }
    return morse;
}

/**
 * It takes a string of morse code and plays it through the computer's speaker
 * 
 * @param morse The morse code to be played.
 */
void hacerloSonar(string morse) {
    int i = 0;
    while (morse[i]) {
        if (morse[i] == '.') {
            Beep(1000, 200);
        } else if (morse[i] == '-') {
            Beep(1000, 400);
        }
        i++;
    }
}

int main() {
    int inputNumero;
    cout << "Digite un numero entre 1 y 3000: ";
    cin >> inputNumero;

    //Evita que el usuario introduzca un numero mayor a 3000 o menor a 1
    while (inputNumero > 3000 || inputNumero < 1) {
        cout << "El numero no esta en el rango, intente de nuevo: ";
        cin >> inputNumero;
    }

    cout << inputNumero << " en romano es: " << decimalToRomano(inputNumero) << endl;
    cout << romanoToMorse(decimalToRomano(inputNumero)) << endl;
    hacerloSonar(romanoToMorse(decimalToRomano(inputNumero)));

    return 0;
}