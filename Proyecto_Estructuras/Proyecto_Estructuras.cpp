#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Estructura para nodo de lista enlazada
struct NodoLista {
    int dato;
    NodoLista* siguiente;
};

// Estructura para nodo de árbol binario
struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
};

// Variables globales
NodoLista* Lista = NULL;
NodoArbol* Arbol = NULL;

// Prototipos de funciones para la lista
void insertarLista(NodoLista*&, int);
void mostrarLista(NodoLista*);
void generarListaAleatoria(NodoLista*&);
bool existeEnLista(NodoLista*, int);

// Prototipos de funciones para el árbol
void insertarArbol(NodoArbol*&, int);
void cargarArbolDesdeLista(NodoArbol*&, NodoLista*);
void mostrarArbol(NodoArbol*, string, bool);
void mostrarArbolPrincipal(NodoArbol*);
int cantidadNodos(NodoArbol*);
void buscarElemento(NodoArbol*, int);
bool esHoja(NodoArbol*);
bool esPadre(NodoArbol*);
void preOrden(NodoArbol*);
void inOrden(NodoArbol*);
void postOrden(NodoArbol*);
void eliminarNodo(NodoArbol*&, int);
NodoArbol* encontrarMinimo(NodoArbol*);

int main() {
    srand(time(NULL)); // Inicializar semilla aleatoria

    int opcion, numero;

    // Generar lista aleatoria y cargar el árbol
    cout << "=== GENERACION DE LISTA Y ARBOL ===" << endl << endl;
    generarListaAleatoria(Lista);
    cout << endl << "Cargando arbol desde la lista..." << endl;
    cargarArbolDesdeLista(Arbol, Lista);
    cout << "Arbol cargado exitosamente!" << endl << endl;
    system("pause");
    system("cls");

    do {
        cout << "============================================" << endl;
        cout << "    MANEJO DE ARBOLES BINARIOS - ATS" << endl;
        cout << "============================================" << endl;
        cout << "1. Mostrar Arbol" << endl;
        cout << "2. Cantidad de Nodos" << endl;
        cout << "3. Buscar un elemento" << endl;
        cout << "4. Mostrar Recorrido preOrden" << endl;
        cout << "5. Mostrar Recorrido inOrden" << endl;
        cout << "6. Mostrar Recorrido postOrden" << endl;
        cout << "7. Eliminar un elemento" << endl;
        cout << "8. Salir" << endl;
        cout << "============================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1:
            cout << "=== VISUALIZACION DEL ARBOL ===" << endl << endl;
            if (Arbol == NULL) {
                cout << "El arbol esta vacio." << endl;
            } else {
                mostrarArbolPrincipal(Arbol);
            }
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 2:
            cout << "=== CANTIDAD DE NODOS ===" << endl << endl;
            cout << "El arbol contiene " << cantidadNodos(Arbol) << " nodos." << endl << endl;
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "=== BUSCAR ELEMENTO ===" << endl << endl;
            cout << "Ingrese el numero a buscar: ";
            cin >> numero;
            cout << endl;
            buscarElemento(Arbol, numero);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 4:
            cout << "=== RECORRIDO PRE-ORDEN ===" << endl << endl;
            if (Arbol == NULL) {
                cout << "El arbol esta vacio." << endl;
            } else {
                cout << "Recorrido: ";
                preOrden(Arbol);
                cout << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 5:
            cout << "=== RECORRIDO IN-ORDEN ===" << endl << endl;
            if (Arbol == NULL) {
                cout << "El arbol esta vacio." << endl;
            } else {
                cout << "Recorrido: ";
                inOrden(Arbol);
                cout << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 6:
            cout << "=== RECORRIDO POST-ORDEN ===" << endl << endl;
            if (Arbol == NULL) {
                cout << "El arbol esta vacio." << endl;
            } else {
                cout << "Recorrido: ";
                postOrden(Arbol);
                cout << endl;
            }
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 7:
            cout << "=== ELIMINAR ELEMENTO ===" << endl << endl;
            cout << "Ingrese el numero que desea eliminar: ";
            cin >> numero;
            cout << endl;
            eliminarNodo(Arbol, numero);
            cout << endl;
            system("pause");
            system("cls");
            break;

        case 8:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo." << endl << endl;
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 8);

    return 0;
}

// ========== FUNCIONES DE LA LISTA ==========

void insertarLista(NodoLista*& lista, int d) {
    NodoLista* nuevoNodo = new NodoLista();
    nuevoNodo->dato = d;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

void mostrarLista(NodoLista* lista) {
    NodoLista* actual = lista;
    while (actual != NULL) {
        cout << actual->dato;
        if (actual->siguiente != NULL) {
            cout << " -> ";
        }
        actual = actual->siguiente;
    }
    cout << endl;
}

bool existeEnLista(NodoLista* lista, int valor) {
    NodoLista* actual = lista;
    while (actual != NULL) {
        if (actual->dato == valor) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void generarListaAleatoria(NodoLista*& lista) {
    // Generar tamaño aleatorio entre 8 y 14
    int tamano = 8 + rand() % 7; // 8 + (0-6) = 8-14

    cout << "Tamano de la lista: " << tamano << endl << endl;
    cout << "Generando numeros aleatorios sin repetir..." << endl;

    // Generar números aleatorios sin repetir
    for (int i = 0; i < tamano; i++) {
        int numero;
        bool existe;
        do {
            numero = 1 + rand() % 100; // 1-100
            existe = existeEnLista(lista, numero);
        } while (existe);

        insertarLista(lista, numero);
    }

    cout << endl << "Lista generada: " << endl;
    mostrarLista(lista);
}

// ========== FUNCIONES DEL ÁRBOL ==========

void insertarArbol(NodoArbol*& arbol, int d) {
    if (arbol == NULL) {
        NodoArbol* nuevoNodo = new NodoArbol();
        nuevoNodo->dato = d;
        nuevoNodo->izquierdo = NULL;
        nuevoNodo->derecho = NULL;
        arbol = nuevoNodo;
    } else {
        if (d < arbol->dato) {
            insertarArbol(arbol->izquierdo, d);
        } else if (d > arbol->dato) {
            insertarArbol(arbol->derecho, d);
        }
        // Si d == arbol->dato, no se inserta (no duplicados)
    }
}

void cargarArbolDesdeLista(NodoArbol*& arbol, NodoLista* lista) {
    NodoLista* actual = lista;
    while (actual != NULL) {
        insertarArbol(arbol, actual->dato);
        actual = actual->siguiente;
    }
}

void mostrarArbolPrincipal(NodoArbol* arbol) {
    if (arbol == NULL) {
        cout << "El arbol esta vacio." << endl;
        return;
    }
    cout << "Raiz: " << arbol->dato << endl;
    mostrarArbol(arbol, "", true);
}

void mostrarArbol(NodoArbol* arbol, string prefijo, bool esUltimo) {
    if (arbol == NULL) {
        return;
    }

    // Mostrar el prefijo y el conector
    cout << prefijo;

    if (esUltimo) {
        cout << "└── ";
        prefijo += "    ";
    } else {
        cout << "├── ";
        prefijo += "│   ";
    }

    // Determinar si tiene hijos y cuáles
    bool tieneIzq = (arbol->izquierdo != NULL);
    bool tieneDer = (arbol->derecho != NULL);

    if (tieneIzq && tieneDer) {
        cout << arbol->dato << " (I y D)" << endl;
    } else if (tieneIzq) {
        cout << arbol->dato << " (I)" << endl;
    } else if (tieneDer) {
        cout << arbol->dato << " (D)" << endl;
    } else {
        cout << arbol->dato << " (Hoja)" << endl;
    }

    // Recursión para hijos (primero izquierdo, luego derecho)
    if (tieneIzq && tieneDer) {
        mostrarArbol(arbol->izquierdo, prefijo, false);
        mostrarArbol(arbol->derecho, prefijo, true);
    } else if (tieneIzq) {
        mostrarArbol(arbol->izquierdo, prefijo, true);
    } else if (tieneDer) {
        mostrarArbol(arbol->derecho, prefijo, true);
    }
}

int cantidadNodos(NodoArbol* arbol) {
    if (arbol == NULL) {
        return 0;
    }
    return 1 + cantidadNodos(arbol->izquierdo) + cantidadNodos(arbol->derecho);
}

bool esHoja(NodoArbol* nodo) {
    return (nodo != NULL && nodo->izquierdo == NULL && nodo->derecho == NULL);
}

bool esPadre(NodoArbol* nodo) {
    return (nodo != NULL && (nodo->izquierdo != NULL || nodo->derecho != NULL));
}

void buscarElemento(NodoArbol* arbol, int d) {
    if (arbol == NULL) {
        cout << "El elemento " << d << " NO existe en el arbol." << endl;
        return;
    }

    if (d == arbol->dato) {
        cout << "El elemento " << d << " SI existe en el arbol." << endl;
        if (esHoja(arbol)) {
            cout << "Es un NODO HOJA (no tiene hijos)." << endl;
        } else {
            cout << "Es un NODO PADRE (tiene uno o mas hijos)." << endl;
        }
        return;
    }

    if (d < arbol->dato) {
        buscarElemento(arbol->izquierdo, d);
    } else {
        buscarElemento(arbol->derecho, d);
    }
}

void preOrden(NodoArbol* arbol) {
    if (arbol != NULL) {
        cout << arbol->dato << " ";
        preOrden(arbol->izquierdo);
        preOrden(arbol->derecho);
    }
}

void inOrden(NodoArbol* arbol) {
    if (arbol != NULL) {
        inOrden(arbol->izquierdo);
        cout << arbol->dato << " ";
        inOrden(arbol->derecho);
    }
}

void postOrden(NodoArbol* arbol) {
    if (arbol != NULL) {
        postOrden(arbol->izquierdo);
        postOrden(arbol->derecho);
        cout << arbol->dato << " ";
    }
}

NodoArbol* encontrarMinimo(NodoArbol* nodo) {
    while (nodo->izquierdo != NULL) {
        nodo = nodo->izquierdo;
    }
    return nodo;
}

void eliminarNodo(NodoArbol*& arbol, int d) {
    if (arbol == NULL) {
        cout << "El elemento " << d << " no se encuentra en el arbol." << endl;
        return;
    }

    if (d < arbol->dato) {
        eliminarNodo(arbol->izquierdo, d);
    } else if (d > arbol->dato) {
        eliminarNodo(arbol->derecho, d);
    } else {
        // Nodo encontrado
        // Caso 1: Nodo sin hijos (hoja)
        if (arbol->izquierdo == NULL && arbol->derecho == NULL) {
            cout << "Eliminando nodo hoja: " << arbol->dato << endl;
            delete arbol;
            arbol = NULL;
        }
        // Caso 2: Nodo con un solo hijo
        else if (arbol->izquierdo == NULL) {
            cout << "Eliminando nodo con un hijo (derecho): " << arbol->dato << endl;
            NodoArbol* temp = arbol;
            arbol = arbol->derecho;
            delete temp;
        }
        else if (arbol->derecho == NULL) {
            cout << "Eliminando nodo con un hijo (izquierdo): " << arbol->dato << endl;
            NodoArbol* temp = arbol;
            arbol = arbol->izquierdo;
            delete temp;
        }
        // Caso 3: Nodo con dos hijos
        else {
            cout << "Eliminando nodo con dos hijos: " << arbol->dato << endl;
            NodoArbol* temp = encontrarMinimo(arbol->derecho);
            arbol->dato = temp->dato;
            eliminarNodo(arbol->derecho, temp->dato);
        }
    }
}
