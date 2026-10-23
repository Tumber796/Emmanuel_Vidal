#include <iostream>
using namespace std;

int main(){
	int a, b;
	do{
		cout<<"Ingresa el lado a del rectangulo: ";
		cin>>a;
		cout<<endl;
		cout<<"Ingresa el lado b del rectangulo: ";
		cin>>b;
		cout<<endl;
		if(a<1 || b<1){
			cout<<"Ninguno de los valores puede ser 0"<<endl;
		}
	} while (a<1 || b<1);
	if(b==a){
		cout<<"El resultado del area es: "<<a*b <<" y es un cuadrado.";
	}else {
		cout<<"El resultado del area es: "<<a*b<<endl;
	}
	return 0;
}
