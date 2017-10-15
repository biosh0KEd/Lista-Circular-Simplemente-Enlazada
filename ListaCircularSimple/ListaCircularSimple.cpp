// Efraín Girón Romero 15300102 5G1
#include "stdafx.h"
#include <iostream>

using namespace std;

struct Nodo
{
	int dato;
	Nodo *sig;
}*inicio, *aux, *aux2, *nodo;

void inicializar();
void imprime();
void limpia();
bool vacia();
bool buscar(int dato);
void insertar(int dato);
void eliminar(int dato);

int main()
{
	int R = 0;
	inicializar();
	do
	{
		int r;
		system("cls");
		cout << "                    Lista Enlazada                    " << endl;
		cout << "¿Que accion decea realizar?\nSeleccione el numero\n1: Ingresar dato\n2: Eliminar dato\n3: Mostrar todos los datos\n4: Eliminar todos los datos\n5: Salir" << endl;
		cin >> r;
		system("cls");
		switch (r)
		{
		case 1: //insertar()
			cout << "                    Lista Enlazada                    " << endl;
			cout << "Ingresa el numero a la lista" << endl;
			int x;
			cin >> x;
			insertar(x);
			system("cls");
			break;
		case 2: //eliminar()
			cout << "                    Lista Enlazada                    " << endl;
			cout << "Ingresa el numero que decea eliminar de la lista" << endl;
			int y;
			cin >> y;
			eliminar(y);
			system("cls");
			break;
		case 3: //imprime()
			cout << "                    Lista Enlazada                    " << endl;
			imprime();
			system("cls");
			break;
		case 4: //limpia()
			cout << "                    Lista Enlazada                    " << endl;
			limpia();
			system("cls");
			break;
		case 5: //Salir
			R = 1;
			break;
		}
	} while (R != 1);
	return 0;
}

void inicializar()
{
	inicio = NULL;
}

bool vacia()
{
	if (inicio == NULL)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void insertar(int dato)
{
	nodo = new Nodo;
	nodo->dato = dato;
	nodo->sig = NULL;
	int temp;
	if (vacia()) {
		inicio = nodo;
	}
	else {
		aux = inicio;
		aux2 = inicio->sig;

		do {
			if (aux->dato == nodo->dato) {
				cout << "Ya existe ese numero en la lista\nIngrese uno nuevo" << endl;
				delete nodo;
				return;
			}
			aux = aux->sig;
		} while (aux != NULL);
		aux = inicio;
		do {
			if (nodo->dato < inicio->dato) {
				temp = inicio->dato;
				inicio->dato = nodo->dato;
				nodo->dato = temp;
				nodo->sig = inicio->sig;
				inicio->sig = nodo;
				break;
			}
			if (aux->sig == NULL) {
				aux->sig = nodo;
				break;
			}
			else if (nodo->dato < aux2->dato) {
				aux->sig = nodo;
				nodo->sig = aux2;
				break;
			}
			else {
				aux = aux->sig;
				aux2 = aux2->sig;
			}
		} while (1);
	}


	system("Pause");
}

void eliminar(int dato)
{
	Nodo *borrar;
	if (vacia()) {
		cout << "La lista esta vacia" << endl;
	}
	else {
		if (inicio->sig == NULL) {
			if (inicio->dato == dato) {
				delete inicio;
				inicio = NULL;
				return;
			}
			cout << "No se ha encontrado el numero \"" << dato << "\" en la lista" << endl;
			return;
		}
		aux = inicio;
		aux2 = inicio->sig;
		while (aux2->sig != NULL) {
			if (aux2->dato == dato) {
				borrar = aux2;
				aux->sig = aux2->sig;
				delete borrar;
				return;
			}
			else {
				aux = aux->sig;
				aux2 = aux2->sig;
			}
		}

		cout << "No se ha encontrado el numero \"" << dato << "\" en la lista" << endl;

	}
}

void imprime()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		aux = inicio;
		while (aux != NULL)
		{
			cout << aux->dato << " - ";
			aux = aux->sig;
		}
		cout << endl;
	}
	system("Pause");
}

void limpia()
{
	if (vacia())
	{
		cout << "La lista ya se encuentra vacia" << endl;
	}
	else
	{
		aux = inicio;
		while (inicio != NULL)
		{
			inicio = inicio->sig;
			delete aux;
			aux = inicio;
		}
	}
}

bool buscar(int dato)
{
	if (vacia())
	{
		return(false);
	}
	else
	{
		aux = inicio;
		while (aux != NULL)
		{
			if (aux->dato == dato)
			{
				return(true);
			}
			else
			{
				aux = aux->sig;
			}
		}
		if (aux == NULL)
		{
			return(false);
		}
	}
}
