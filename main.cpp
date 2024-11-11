#include <iostream>
#include "grafo.cpp"

using namespace std;

// Act 4.2 - Grafos: Algoritmos complementarios
// Elizabeth Jauregui Zarate (A01253381)

/*  
El presente programa implementa  un programa para analizar un grafo no dirigido utilizando una clase Grafo.
Solicita al usuario que ingrese el número de vértices (n) y arcos (m) del grafo. 
Inicializa el grafo con V vértices y E arcos, y configura la lista de adyacencia como un vector de vectores de enteros.
Comprueba si el grafo es un árbol, si se puede ordenar topológicamente y si es bipartito.
*/  

int main() {
    int n, m;

    // Solicita al usuario el número de vértices y arcos del grafo
    cout << "\n*********************************" << endl;
    cout << "*Bienvenido al programa de Grafo*" << endl;
    cout << "*********************************\n" << endl;

    cout << "Ingrese el número de vértices: ";
    cin >> n;
    cout << "Ingrese el número de arcos: ";
    cin >> m;
    cout << " " <<endl; 

    Grafo grafo(n, m); // Crea el objeto grafo
    grafo.loadGraph(); // Carga el grafo con los arcos ingresados por el usuario

    // Verifica si el grafo es un árbol
    cout << "\n--------------------------------------------" << endl;
    cout << "Verificando si el grafo es un árbol..." << endl;
    if (grafo.isTree()) {
        cout << "El grafo es un árbol." << endl;
    } else {
        cout << "El grafo no es un árbol." << endl;
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