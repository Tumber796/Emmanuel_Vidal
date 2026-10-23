#include <iostream>
using namespace std;

int main() {
    int A, B, C;

    cout << "Ingresa el valor de A: ";
    cin >> A;

    cout << "Ingresa el valor de B: ";
    cin >> B;

    cout << "Ingresa el valor de C: ";
    cin >> C;

    if (A == 0 && B == 0 && C == 0) {
        cout << "Los valores no indican figura";

    } else if (A > 0 && B == 0 && C == 0) {
        cout << "La figura es un circulo";

    } else if (A > 0 && A == B && C == 0) {
        cout << "La figura es un cuadrado";

    } else if (A > 0 && B > 0 && A != B && C == 0) {
        cout << "La figura es un rectangulo";

    } else if (A > 0 && B > 0 && C > 0) {

        if (A + B > C && A + C > B && B + C > A) {

            if (A == B && B == C) {
                cout << "La figura es un triangulo equilatero";

            } else if (A != B && A != C && B != C) {
                cout << "La figura es un triangulo escaleno";

            } else {
                cout << "La figura es un triangulo isosceles";
            }

        } else {
            cout << "Los valores no indican figura";
        }

    } else {
        cout << "Los valores no indican figura";
    }

    return 0;
}
