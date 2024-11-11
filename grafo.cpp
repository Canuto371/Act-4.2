#include "Grafo.h"
#include <iostream> 
#include <stdexcept>
#include <vector>   
#include <stack>
#include <limits>    
#include <queue>    

using namespace std;

// Constructor que inicializa el grafo con V vértices
// Complejidad: O(V)
Grafo::Grafo(int V, int E) : V(V), E(E) {
    listaAdj.resize(V);
}

// Método para agregar un arco en el grafo no dirigido
// Complejidad: O(1)
void Grafo::addEdge(int u, int v) {
    listaAdj[u].push_back(v);
}

// Método para cargar el grafo desde la entrada del usuario
// Complejidad: O(E)
void Grafo::loadGraph() {
    int u, v;
    cout << "-------------------------------------------------------" << endl;
    cout << "Ingrese los arcos en formato de pares de vértices u v:" << endl;
    cout << "-------------------------------------------------------" << endl << endl;
    
    //Bucle para asegurar que la entrada sea válida: 
    for (int i = 0; i < E; i++) {
        bool validInput = false;  // Indicador de entrada válida

        while (!validInput) {
            cout << "Arco " << i + 1 << ": ";
            cin >> u >> v;

            if (cin.fail()) { // Verifica si la entrada no es válida
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "Error: Entrada no valida. Intente de nuevo." << endl;
            } else if (u < 0 || u >= V || v < 0 || v >= V) { // Verifica si los vértices están en el rango
                cerr << "Error: Los vertices deben estar en el rango [0, " << V - 1 << "]. Intente de nuevo." << endl;
            } else {
                validInput = true; // Entrada válida
                addEdge(u, v); // Agrega el arco
            }
        }
    }
}

// Función para verificar si el grafo es un árbol
// Complejidad: O(V + E)
bool Grafo::isTree() {
    vector<bool> visited(V, false); 
    if (isCyclicUtil(0, visited, -1))
        return false; // Si el grafo tiene un ciclo, no es un árbol

    for (int u = 0; u < V; u++)
        if (!visited[u])
            return false; // Si algún vértice no fue visitado, el grafo no es conexo y no es un árbol

    return true;
}

// Función auxiliar para detectar ciclos en el grafo
// Complejidad: O(V + E)
bool Grafo::isCyclicUtil(int v, vector<bool>& visited, int parent) {
    visited[v] = true; // Marca el nodo actual como visitado

    for (auto i : listaAdj[v]) { // Itera sobre los vecinos de v
        if (!visited[i]) { // Si el vecino no fue visitado, realiza una llamada recursiva
            if (isCyclicUtil(i, visited, v))
                return true;
        }
        else if (i != parent) // Si encuentra un vecino visitado que no es el padre, hay un ciclo
            return true;
    }
    return false;
}

// Función para realizar el ordenamiento topológico del grafo
// Complejidad: O(V + E)
void Grafo::topologicalSort() {
    vector<bool> visited(V, false); 
    stack<int> Stack;

    for (int i = 0; i < V; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack); 

    cout << "Orden Topológico: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

// Función auxiliar para el ordenamiento topológico
// Complejidad: O(V + E)
void Grafo::topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true; // Marca el nodo actual como visitado

    for (auto i : listaAdj[v]) // Itera sobre los vecinos del nodo actual
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

    Stack.push(v); // Inserta el nodo en la pila
}

// Función para verificar si el grafo es bipartito
// Complejidad: O(V + E)
bool Grafo::bipartiteGraph() {
    vector<int> colorArr(V, -1); // Inicializa el vector de colores con -1 (sin color)

    for (int i = 0; i < V; ++i) 
        if (colorArr[i] == -1) // Si el nodo no está coloreado, aplica la verificación
            if (!isBipartiteUtil(i, colorArr))
                return false;

    return true;
}

// Función auxiliar para verificar si el grafo es bipartito
// Complejidad: O(V + E)
bool Grafo::isBipartiteUtil(int src, vector<int>& colorArr) {
    colorArr[src] = 1; // Asigna un color inicial al nodo de origen

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : listaAdj[u]) { // Itera sobre los vecinos del nodo actual
            if (colorArr[v] == -1) { // Si el vecino no tiene color, se le asigna el opuesto
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (colorArr[v] == colorArr[u]) // Si el vecino tiene el mismo color, no es bipartito
                return false;
        }
    }
    return true;
}