#include <iostream>
#include "grafo.cpp"

using namespace std;

// Act 4.2 - Grafos: Algoritmos complementarios
// Elizabeth Jauregui Zarate (A01253381)

/*  
El presente programa implementa 
*/  

int main() {
    int n, m;

    // Solicita al usuario el número de vértices y arcos del grafo
    cout << "\n*********************************" << endl;
    cout << "*Bienvenido al programa de Grafo*" << endl;
    cout << "*********************************\n" << endl;

    cout << "Ingrese el numero de vertices: ";
    cin >> n;
    cout << "Ingrese el numero de arcos: ";
    cin >> m;
    cout << " " <<endl; 

    Grafo grafo(n, m); // Crea el objeto grafo
    grafo.loadGraph(); // Carga el grafo con los arcos ingresados por el usuario

    // Verifica si el grafo es un árbol
    cout << "\n--------------------------------------------" << endl;
    cout << "Verificando si el grafo es un arbol..." << endl;
    if (grafo.isTree()) {
        cout << "El grafo es un arbol." << endl;
    } else {
        cout << "El grafo no es un arbol." << endl;
    }
    cout << "--------------------------------------------" << endl;

    // Realiza el ordenamiento topológico del grafo
    cout << "\n--------------------------------------------" << endl;
    cout << "Realizando el ordenamiento topologico..." << endl;
    grafo.topologicalSort();
    cout << "--------------------------------------------" << endl;

    // Verifica si el grafo es bipartito
    cout << "\n--------------------------------------------" << endl;
    cout << "Verificando si el grafo es bipartito..." << endl;
    if (grafo.bipartiteGraph()) {
        cout << "El grafo es bipartito." << endl;
    } else {
        cout << "El grafo no es bipartito." << endl;
    }
    cout << "--------------------------------------------" << endl;

    cout << "\n****************************" << endl;
    cout << "*Fin del analisis del Grafo*" << endl;
    cout << "****************************\n" << endl;

    return 0;
}