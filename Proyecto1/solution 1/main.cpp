//Carlos González Garita || Universidad Nacional || Ingeniería en Sistemas
//17/04/2022
//El objetivo del programa es pasar un número decimal a un número romano, para luego convertir este número romano en código morse, esto con el fin de hacerle sonar.
#include <iostream>
#include <windows.h>
using namespace std;

string decimalToRomano(int numero) {
    string romano = "";

//Se evaluan las principales unidades de la tabla de conversion
    while (numero) {         
        if (numero / 1000) {    //este if evalua si el numero es mayor a 1000
            romano += "M";      //se agrega el simbolo romano M
            numero -= 1000;     
        }else if (numero / 900) {
            romano += "CM";
            numero -= 900;
        }else if (numero / 500) {
            romano += "D";
            numero -= 500;
        }else if (numero / 400) {
            romano += "CD";
            numero -= 400;
        }else if (numero / 100) { 
            romano += "C";
            numero -= 100;
        }else if (numero / 90) {
            romano += "XC";
            numero -= 90;
        }else if (numero / 50) {
            romano += "L";
            numero -= 50;
        }else if (numero / 40) {
            romano += "XL";
            numero -= 40;
        }else if (numero / 10) {
            romano += "X";
            numero -= 10;
        }else if (numero / 9) {
            romano += "IX";
            numero -= 9;
        }else if (numero / 5) {
            romano += "V";
            numero -= 5;
        }else if (numero / 4) {
            romano += "IV";
            numero -= 4;
        }else if (numero / 1) {
            romano += "I";
            numero -= 1;
        }
                       
    }
    return romano;
}

string romanoToMorse(string romano) {
    string morse = "";
    int i = 0;                                   //Se encarga de reccore el string romano

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

void hacerloSonar(string morse) {
    int i = 0;
    while (morse[i]) {                 //Se evaluan las posibles letras morse, y se hace sonar el símbolo correspondiente
        if (morse[i] == '.') {
            Beep(1000, 200);           //Beep(Frecuencia, Duración)  
            Sleep(100);        
        } else if (morse[i] == '-') {
            Beep(1000, 400);
            Sleep(100);        
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