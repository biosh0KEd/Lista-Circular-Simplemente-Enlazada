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
		cout << "                    Lista Circular Simplemente Enlazada                    " << endl;
		cout << "¿Que accion decea realizar?\nSeleccione el numero\n1: Ingresar dato\n2: Eliminar dato\n3: Mostrar todos los datos\n4: Eliminar todos los datos\n5: Salir" << endl;
		cin >> r;
		system("cls");
		switch (r)
		{
		case 1: //insertar()
			cout << "                    Lista Circular Simplemente Enlazada                    " << endl;
			cout << "Ingresa el numero a la lista" << endl;
			int x;
			cin >> x;
			insertar(x);
			system("cls");
			break;
		case 2: //eliminar()
			cout << "                    Lista Circular Simplemente Enlazada                    " << endl;
			cout << "Ingresa el numero que decea eliminar de la lista" << endl;
			int y;
			cin >> y;
			eliminar(y);
			system("cls");
			break;
		case 3: //imprime()
			cout << "                    Lista Circular Simplemente Enlazada                    " << endl;
			imprime();
			system("cls");
			break;
		case 4: //limpia()
			cout << "                    Lista Circualr Simplemente Enlazada                    " << endl;
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
	if (vacia())
	{
		inicio = nodo;
		inicio->sig = inicio;
	}
	else 
	{
		if (buscar(dato))
		{
			cout << "El dato ya existe en la lista\nNo se pueden repetir los datos" << endl;
		}
		else
		{
			if (dato < inicio->dato)
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (aux->sig == inicio)
					{
						aux->sig = nodo;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
				nodo->sig = inicio;
				inicio = nodo;
			}
			else
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (nodo->dato < aux->sig->dato || aux ->sig == inicio)
					{
						nodo->sig = aux->sig;
						aux->sig = nodo;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
			}
		}
	}
	system("Pause");
}

void eliminar(int dato)
{
	if (vacia())
	{
		cout << "La lista ya esta vacia" << endl;
	}
	else
	{
		if (!buscar(dato))
		{
			cout << "El elemento que decea eliminar no esta en la fila" << endl;
		}
		else
		{
			if (dato == inicio->dato)
			{
				if (inicio->sig == inicio)
				{
					inicializar();
				}
				else 
				{
					aux = inicio;
					bool exit = true;
					while (exit == true)
					{
						if (aux->sig == inicio)
						{
							aux->sig = inicio->sig;
							delete inicio;
							inicio = aux->sig;
							exit = false;
						}
						else
						{
							aux = aux->sig;
						}
					}
				}
			}
			else
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (aux->sig->dato == dato)
					{
						aux2 = aux->sig;
						aux->sig = aux2->sig;
						delete aux2;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
			}
		}
	}
	system("Pause");
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
		do
		{
			cout << aux->dato << " - ";
			aux = aux->sig;
		} while (aux != inicio);
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
		bool exit = true;
		aux = inicio;
		while (exit)
		{
			if (aux->sig == inicio)
			{
				aux->sig = NULL;
				exit = false;
			}
			else
			{
				aux = aux->sig;
			}
		} 
		aux = inicio;
		while (inicio != NULL)
		{
			if (inicio->sig == inicio)
			{
				inicializar();
			}
			else
			{
				inicio = inicio->sig;
				delete aux;
				aux = inicio;
			}

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
		do
		{
			if (aux->dato == dato)
			{
				return(true);
			}
			else
			{
				aux = aux->sig;
			}
		} while (aux != inicio);
		if (aux == inicio)
		{
			return(false);
		}
	}
}
