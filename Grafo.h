#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Grafo {
private:
    int V; // Número de vértices
    int E; // Número de arcos
    vector<vector<int>> listaAdj; // Lista de adyacencia para almacenar el grafo

public:
    // Constructor que inicializa el grafo con V vértices
    // Complejidad: O(V)
    // El constructor simplemente redimensiona el vector de adyacencia con la cantidad de vértices V, 
    // lo que toma tiempo proporcional a V.
    Grafo(int V, int E);

    // Método para agregar un arco en el grafo no dirigido
    // Complejidad: O(1)
    // La operación de agregar un arco en la lista de adyacencia es una operación constante.
    void addEdge(int u, int v);

    // Método para cargar el grafo desde la entrada del usuario
    // Complejidad: O(E)
    // El método iterará sobre E arcos, y en cada iteración se agrega un arco al grafo, 
    // lo cual es una operación O(1) por arco.
    void loadGraph();

    // Función para verificar si el grafo es un árbol
    // Complejidad: O(V + E)
    // El método realiza una búsqueda en profundidad o amplitud, visitando todos los vértices 
    // y arcos del grafo una vez. Esto da como resultado una complejidad O(V + E).
    bool isTree();

    // Función auxiliar para detectar ciclos en el grafo
    // Complejidad: O(V + E)
    // Esta función se llama recursivamente para cada vértice y sus vecinos, lo que implica 
    // visitar todos los vértices y arcos, con una complejidad O(V + E).
    bool isCyclicUtil(int v, vector<bool>& visited, int parent);

    // Función para realizar el ordenamiento topológico del grafo
    // Complejidad: O(V + E)
    // El ordenamiento topológico de un grafo dirigido requiere recorrer todos los vértices y 
    // arcos para asegurarse de que se visite cada uno, lo que da una complejidad O(V + E).
    void topologicalSort();

    // Función auxiliar para el ordenamiento topológico
    // Complejidad: O(V + E)
    // Esta función realiza una búsqueda en profundidad para obtener el orden topológico,
    // lo que implica visitar todos los vértices y arcos, resultando en una complejidad O(V + E).
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack);

    // Función para verificar si el grafo es bipartito
    // Complejidad: O(V + E)
    // Para verificar si un grafo es bipartito, se recorre el grafo con una búsqueda en anchura 
    // (BFS) o profundidad (DFS) para verificar que los vértices puedan ser coloreados alternadamente, 
    // lo cual toma O(V + E).
    bool bipartiteGraph();

    // Función auxiliar para verificar si el grafo es bipartito
    // Complejidad: O(V + E)
    // Similar a la función anterior, se realiza una búsqueda en anchura (BFS) sobre los vértices 
    // y arcos del grafo, lo que da como resultado una complejidad O(V + E).
    bool isBipartiteUtil(int src, vector<int>& colorArr);
};

#endif