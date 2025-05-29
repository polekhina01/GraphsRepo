#include <iostream>
#include "graph.h"
#include "algorithms.h"

int main() {
    // --- Исходный граф: ListGraph ---
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);

    std::cout << "BFS on ListGraph: ";
    mainBFS(listGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nDFS on ListGraph: ";
    mainDFS(listGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nTopSort on ListGraph: ";
    for (int v : topologicalSort(listGraph)) std::cout << v << " ";
    std::cout << "\n\n";

    // --- Копируем из ListGraph в MatrixGraph ---
    MatrixGraph matrixGraph(listGraph);

    std::cout << "BFS on MatrixGraph: ";
    mainBFS(matrixGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nDFS on MatrixGraph: ";
    mainDFS(matrixGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nTopSort on MatrixGraph: ";
    for (int v : topologicalSort(matrixGraph)) std::cout << v << " ";
    std::cout << "\n\n";

    // --- Копируем из MatrixGraph в SetGraph ---
    SetGraph setGraph(matrixGraph);

    std::cout << "BFS on SetGraph: ";
    mainBFS(setGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nDFS on SetGraph: ";
    mainDFS(setGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nTopSort on SetGraph: ";
    for (int v : topologicalSort(setGraph)) std::cout << v << " ";
    std::cout << "\n\n";

    // --- Копируем из SetGraph в ArcGraph ---
    ArcGraph arcGraph(setGraph);

    std::cout << "BFS on ArcGraph: ";
    mainBFS(arcGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nDFS on ArcGraph: ";
    mainDFS(arcGraph, [](int v) { std::cout << v << " "; });
    std::cout << "\nTopSort on ArcGraph: ";
    for (int v : topologicalSort(arcGraph)) std::cout << v << " ";
    std::cout << std::endl;
}
