#include <iostream>
#include <string>
#include <cmath>
using namespace std;

constexpr double PI = 3.14159265358979323846;

void mostrarMenu(){
	cout << "1. Determine Figura" << endl;
	cout << "2. Calcule Area" << endl;
	cout << "3. Salir" << endl;
	cout << "> "; 
}

string tipoFigura(int A, int B, int C){
	if (A == 0 && B == 0 && C == 0) {
        return "Los valores no indican figura";

    } else if ((A > 0 && B == 0 && C == 0) || (A == 0 && B > 0 && C == 0)
				|| (A == 0 && B == 0 && C > 0)) {
        return "La figura es un circulo";

    } else if ((A > 0 && A == B && C == 0) || (A > 0 && B == 0 && A == C) 
				|| (A == 0 && B > 0 && B == C)) {
        return "La figura es un cuadrado";

    } else if ((A > 0 && B > 0 && A != B && C == 0) || (A > 0 && B == 0 && C > 0 && A != C)
				|| (A == 0 && B > 0 && B != C && C > 0)) {
        return "La figura es un rectangulo";

    } else if (A > 0 && B > 0 && C > 0) {

        if (A + B > C && A + C > B && B + C > A) {

            if (A == B && B == C) {
                return "La figura es un triangulo equilatero";

            } else if (A != B && A != C && B != C) {
                return "La figura es un triangulo escaleno";

            } else {
                return "La figura es un triangulo isosceles";
            }

        } else {
            return "Los valores no indican figura";
        }

    } else {
        return "Los valores no indican figura";
    }
}

void calcularArea(int A, int B, int C){
	
	string figura;
	figura = tipoFigura(A, B, C);
	double semiper, area;
	
	//Condiciones para obtener el area de un Circulo
	if (A > 0 && B == 0 && C == 0) {
		cout << "Circulo; area = " << PI * A * A;
		return;
	}
	if (B > 0 && C == 0 && A == 0) {
		cout << "Circulo; area = " << PI * B * B;
		return;
	}
	if (C > 0 && A == 0 && B == 0) {
		cout << "Circulo; area = " << PI * C * C;
		return;
	}
	
	//Condiciones para obtener el area de un Cuadrado
	if (A > 0 && A == B && C == 0) {
		cout << "Cuadrado; area = " << A * B;
		return;
	}
	if (A > 0 && B == 0 && A == C) {
		cout << "Cuadrado; area = " << A * C;
		return;
	}
	if (A == 0 && B > 0 && C == B) {
		cout << "Cuadrado; area = " << B * C;
		return;
	}
	
	//Condiciones para obtener el area de un Rectangulo
	if (A > 0 && B > 0 && A != B && C == 0) {
		cout << "Rectangulo; area = " << A * B;
		return;
	}
	if (A > 0 && B == 0 && C > 0 && A != C) {
		cout << "Rectangulo; area = " << A * C;
		return;
	}
	if (A == 0 && B > 0 && B != C && C > 0) {
		cout << "Rectangulo; area = " << B * C;
		return;
	}
	
	//Condicion para obtener el area de un Triangulo equilatero
	if (tipoFigura(A, B ,C) == "La figura es un triangulo equilatero"){
		 area = (A * A * sqrt(3)) /4;
		 cout << "Triangulo equilatero; area = " << area << endl;
		 return;
	}
	
	//Condicion para obtener el area de un Triangulo isosceles
	if (figura == "La figura es un triangulo isosceles") {
	    if (A == B) {
	        area = (C / 4.0) * sqrt(4.0 * A * A - C * C);
	    }
	    else if (A == C) {
	        area = (B / 4.0) * sqrt(4.0 * A * A - B * B);
	    }
	    else {
	        area = (A / 4.0) * sqrt(4.0 * B * B - A * A);
	    }
    cout << "Triangulo isosceles; area = " << area;
    return;
}
	
	//Condicion para obtener el area de un Triangulo escaleno
	if (tipoFigura(A, B ,C) == "La figura es un triangulo escaleno") {	
		semiper = (A + B + C) / 2.0;
		area = sqrt(semiper * (semiper - A) * (semiper - B) * (semiper - C));
		cout << "Triangulo escaleno; area = " << area;
		return;
	}
}

int main() {
    int A, B, C, opcion;
    bool figuraIdentificada; //Ayudara a saber si ya se identifico una figura o no//
    figuraIdentificada = false;
	 do{
    	mostrarMenu();
    	cin >> opcion;
    	switch(opcion){
    		case 1: 
    		    cout << endl << "Ingresa el valor de A: ";
    			cin >> A;
			    cout << "Ingresa el valor de B: ";
			    cin >> B;
			    cout << "Ingresa el valor de C: ";
			    cin >> C;
			    cout << tipoFigura(A, B, C) << endl << endl;
			    if (tipoFigura(A, B, C) == "Los valores no indican figura"){
			    	figuraIdentificada = false;	 
			    } else {
			    	figuraIdentificada = true;
			    }
			    break;
			case 2:
				if(!figuraIdentificada){
					cout << "Los valores no indican figura, determine la figura en la opcion 1"
						 << endl << endl;
				} else {
					calcularArea(A ,B ,C);
					cout << endl;
				}
				break;
			case 3:
				cout << "Hasta la proxima." << endl;
				break;
			default:
				cout << "Opcion no valida" << endl;
    	}
    	cout << endl;
    } while (opcion != 3);
    return 0;
}
