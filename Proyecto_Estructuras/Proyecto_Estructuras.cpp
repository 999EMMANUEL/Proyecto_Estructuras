#include <iostream>
#include <string>
using namespace std;

//estructura nodo
struct Nodo
{
	int dato;
	Nodo* siguiente;
};

Nodo* Lista = NULL;

//funciones
void insertarLista(Nodo*&, int);
void mostrarLista(Nodo*);
void buscarLista(Nodo*, int);
void eliminarLista(Nodo*&, int);


int main()
{
	int numero;
	int opcion;
	insertarLista(Lista, 5);
	insertarLista(Lista, 10);
	insertarLista(Lista, 15);
	do {
		cout << "Practica de Nodos" << endl;
		cout << "Seleccione una opcion." << endl;
		cout << "1-Insertar" << endl;
		cout << "2-Mostrar." << endl;
		cout << "3-Buscar." << endl;
		cout << "4-Eliminar." << endl;
		cout << "0-Salir" << endl;
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			cout << "Ingrese un digito" << endl;
			cin >> numero;
			insertarLista(Lista, numero);
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Mostrar." << endl;
			mostrarLista(Lista);
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Ingrese el numero a buscar: ";
			cin >> numero;
			buscarLista(Lista, numero);
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "Ingrese el numero que desea eliminar: ";
			cin >> numero;
			eliminarLista(Lista, numero);
			system("pause");
			system("cls");
			break;
		default:
			cout << "Opcion no valida" << endl;
			break;
		}
	} while (opcion != 0);
	return 0;
}

void insertarLista(Nodo*& Lista, int d)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = d;
	nuevoNodo->siguiente = Lista;
	Lista = nuevoNodo;

}

void mostrarLista(Nodo* Lista)
{
	Nodo* actual = new Nodo;
	actual = Lista;

	while (actual != NULL) {
		cout << actual->dato << " -> ";
		actual = actual->siguiente;
	}
}

void buscarLista(Nodo* Lista, int d)
{
	Nodo* actual = new Nodo;
	actual = Lista;
	while (actual != NULL) {
		if (actual->dato == d) {
			cout << "Lista encontrada: " << actual->dato << endl;
			return;
		}
		actual = actual->siguiente;
	}
	cout << "Lista no encontrada." << endl;
}

void eliminarLista(Nodo*& Lista, int d) {
	if (Lista == NULL) {
		cout << "La lista está vacía." << endl;
		return;
	}

	if (Lista->dato == d) {
		Nodo* temp = Lista;
		Lista = Lista->siguiente;
		delete temp;
		cout << "Nodo con el numero " << d << " eliminado." << endl;
		return;
	}

	Nodo* actual = Lista;
	while (actual->siguiente != NULL && actual->siguiente->dato != d) {
		actual = actual->siguiente;
	}

	if (actual->siguiente == NULL) {
		cout << "Nodo con valor " << d << " no encontrado." << endl;
		return;
	}

	Nodo* temp = actual->siguiente;
	actual->siguiente = temp->siguiente;
	delete temp;
	cout << "Nodo con valor " << d << " eliminado." << endl;
}
