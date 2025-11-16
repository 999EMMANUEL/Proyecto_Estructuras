


//Jhon Alonso López Zúñiga
//Estefany Duran
//Paula Pérez
//Emmanuel Jimenez Jimenez

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Proyecto Final Estructuras de Datos///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <random>
#include <windows.h>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;


struct nodo {
	int dato;
	nodo* siguente;
	nodo* izq;
	nodo* der;
};

nodo* lista = NULL;
nodo* arbol = NULL;

// Declaraciones
nodo* crearNodo(int);
bool agregarNodoRecursivo(nodo*&, int);
void agregarNodo(nodo*&, int);
void menu();
void cantidadNodos(nodo*, int&);
void mostrarArbol(nodo*);
int calcularAltura(nodo*);
void preorden(nodo*);
void inorden(nodo*);
void postorden(nodo*);
void buscarNodo(nodo*, int);
nodo* eliminarNodo(nodo*, int);
void insertarLista(Nodo*&, int);

// Generadores corregidos (semilla única)
int generarTamanoAleatorio(int minimo, int maximo)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> distrib(minimo, maximo);
	return distrib(gen);
}

int generarValorAleatorio(int min, int max)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}

// MAIN
int main()
{
	int tamano = generarTamanoAleatorio(8, 14);

	cout << "Generando vector con " << tamano << " numeros aleatorios...\n";

	for (int i = 0; i < tamano; i++)

		cout << "Numeros generados: ";
	for (int n : numeros) cout << n << " ";
	cout << "\n\n";

	for (int n : numeros) agregarNodo(arbol, n);

	system("pause");
	system("cls");
	menu();
	getch();
	return 0;
}

// Crear nodo
nodo* crearNodo(int n)
{
	nodo* nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->der = NULL;
	return nuevo_nodo;
}

// Menú
void menu()
{
	int opcion, dato, contador = 0;
	do
	{
		cout << "-----MENU ARBOLES BINARIOS-----\n";
		cout << "1. Mostrar arbol\n";
		cout << "2. Cantidad Nodos\n";
		cout << "3. Buscar nodo\n";
		cout << "4. Recorrido PreOrden\n";
		cout << "5. Recorrido InOrden\n";
		cout << "6. Recorrido PostOrden\n";
		cout << "7. Eliminar Nodo\n";
		cout << "0. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;

		system("cls");

		switch (opcion)
		{
		case 1:
			cout << "\nMostrando arbol completo:\n\n";
			mostrarArbol(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 2:
			contador = 0;
			cantidadNodos(arbol, contador);
			cout << "La cantidad de nodos en el arbol es: " << contador << "\n\n";
			system("pause");
			break;
		case 3:
			cout << "Ingrese el número a buscar: ";
			cin >> dato;
			buscarNodo(arbol, dato);
			cout << "\n\n";
			system("pause");
			break;
		case 4:
			cout << "Recorrido PreOrden: ";
			preorden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 5:
			cout << "Recorrido InOrden: ";
			inorden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 6:
			cout << "Recorrido PostOrden: ";
			postorden(arbol);
			cout << "\n\n";
			system("pause");
			break;
		case 7:
			cout << "Ingrese el número a Eliminar: " << endl;
			cin >> dato;
			buscarNodo(arbol, dato);
			cout << endl << endl << "Procesando....\n";
			arbol = eliminarNodo(arbol, dato);
			cout << endl << endl << "Eliminando....\n";
			cout << "\n\n";
			system("pause");
			break;
		case 0:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion no valida, intente de nuevo.\n";
		}
		system("cls");
	} while (opcion != 0);
}

//Insertar datos en una lista simple
void insertarLista(Nodo*& Lista, int d)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = d;
	nuevoNodo->siguiente = Lista;
	Lista = nuevoNodo;

}

// Agregar nodo
bool agregarNodoRecursivo(nodo*& arbol, int n)
{
	if (arbol == NULL)
	{
		arbol = crearNodo(n);
		return true;
	}
	if (n == arbol->dato)
		return false;
	else if (n < arbol->dato)
		return agregarNodoRecursivo(arbol->izq, n);
	else
		return agregarNodoRecursivo(arbol->der, n);
}

void agregarNodo(nodo*& arbol, int n)
{
	if (!agregarNodoRecursivo(arbol, n))
		cout << "El nodo " << n << " ya existe en el arbol, no se puede agregar nodos repetidos\n";
	else
		cout << "Nodo " << n << " agregado al arbol correctamente\n";

	Sleep(200);
}

// Altura
int calcularAltura(nodo* arbol)
{
	if (arbol == NULL) return 0;
	int izq = calcularAltura(arbol->izq);
	int der = calcularAltura(arbol->der);
	return 1 + max(izq, der);
}

// *** NUEVA FUNCIÓN mostrarArbol() CORREGIDA Y CENTRADA ***
void mostrarArbol(nodo* raiz) {

	if (!raiz) {
		cout << "El arbol esta vacio.\n";
		return;
	}

	queue<nodo*> q;
	q.push(raiz);

	int altura = calcularAltura(raiz);
	int nivel = 0;

	while (nivel < altura) {
		int nodosNivel = pow(2, nivel);
		int espaciosInicio = pow(2, altura - nivel - 1) * 2;
		int espaciosEntre = pow(2, altura - nivel) * 2 - 2;

		for (int i = 0; i < espaciosInicio; i++) {
			cout << " ";
		}

		// Guardar nodos actuales para las conexiones
		vector<nodo*> nodosActuales;

		// Procesar nodos del nivel actual
		for (int i = 0; i < nodosNivel; i++) {
			if (q.empty()) break;

			nodo* temp = q.front();
			q.pop();
			nodosActuales.push_back(temp);

			if (temp) {
				cout << setw(2) << temp->dato;
				q.push(temp->izq);
				q.push(temp->der);
			}
			else {
				cout << "  ";
				q.push(nullptr);
				q.push(nullptr);
			}

			// Espacios entre nodos
			if (i < nodosNivel - 1) {
				for (int j = 0; j < espaciosEntre; j++) {
					cout << " ";
				}
			}
		}
		cout << "\n";

		// Imprimir conexiones (solo si no es el último nivel)
		if (nivel < altura - 1) {
			// Espacios antes de las conexiones
			for (int i = 0; i < espaciosInicio - 1; i++) {
				cout << " ";
			}

			for (int i = 0; i < nodosActuales.size(); i++) {
				nodo* temp = nodosActuales[i];

				if (temp && temp->izq) cout << "/";
				else cout << " ";

				for (int j = 0; j < 2; j++) {
					cout << " ";
				}

				if (temp && temp->der) cout << "\\";
				else cout << " ";

				if (i < nodosActuales.size() - 1) {
					for (int j = 0; j < espaciosEntre - 2; j++) {
						cout << " ";
					}
				}
			}
			cout << "\n";
		}

		nivel++;
	}
}

// Buscar nodo
void buscarNodo(nodo* arbol, int n)
{
	if (arbol == NULL)
	{
		cout << "El nodo no existe en el arbol\n";
		return;
	}
	else if (arbol->dato == n)
	{
		cout << "El nodo " << n << " existe y es ";
		if (arbol->izq == NULL && arbol->der == NULL)
			cout << "HOJA\n";
		else
			cout << "PADRE\n";
		return;
	}
	else if (n < arbol->dato)
		buscarNodo(arbol->izq, n);
	else
		buscarNodo(arbol->der, n);
}

// Contar nodos
void cantidadNodos(nodo* arbol, int& contador)
{
	if (!arbol) return;
	contador++;
	cantidadNodos(arbol->izq, contador);
	cantidadNodos(arbol->der, contador);
}

// Recorridos
void preorden(nodo* arbol)
{
	if (!arbol) return;
	cout << arbol->dato << " ";
	preorden(arbol->izq);
	preorden(arbol->der);
}

void inorden(nodo* arbol)
{
	if (!arbol) return;
	inorden(arbol->izq);
	cout << arbol->dato << " ";
	inorden(arbol->der);
}

void postorden(nodo* arbol)
{
	if (!arbol) return;
	postorden(arbol->izq);
	postorden(arbol->der);
	cout << arbol->dato << " ";
}
//Eliminar nodo
nodo* eliminarNodo(nodo* arbol, int n) {
	if (arbol == NULL) {
		return NULL;
	}
	else if (n < arbol->dato) {
		arbol->izq = eliminarNodo(arbol->izq, n);
	}
	else if (n > arbol->dato) {
		arbol->der = eliminarNodo(arbol->der, n);
	}
	else {//Nodo sin hijos o con 1 hijo
		if (arbol->izq == NULL) {
			nodo* aux = arbol->der;
			delete arbol;
			return aux;
		}
		else if (arbol->der == NULL) {
			nodo* aux = arbol->izq;
			delete arbol;
			return aux;
		}
		//nodo con 2 hijos, buscar el menor del subarbol derecho
		nodo* aux = arbol->der;
		while (aux->izq != NULL) {
			aux = aux->izq;
		}
		arbol->dato = aux->dato;
		arbol->der = eliminarNodo(arbol->der, aux->dato);
	}
	return arbol;
}
