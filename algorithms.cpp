#include "algorithms.h"
#include <cassert>

// Вспомогательная функция для BFS
void BFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func) {
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty()) {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex : graph.GetNextVertices(currentVertex)) {
            if (!visited[nextVertex]) {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

// Обход всех компонент связности графа (BFS)
void mainBFS(const IGraph& graph, const std::function<void(int)>& func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            BFS(graph, i, visited, func);
        }
    }
}

// Вспомогательная функция для DFS
void DFS(const IGraph& graph, int vertex, std::vector<bool>& visited, const std::function<void(int)>& func) {
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex : graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            DFS(graph, nextVertex, visited, func);
        }
    }
}

// Обход всех компонент связности графа (DFS)
void mainDFS(const IGraph& graph, const std::function<void(int)>& func) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i, visited, func);
        }
    }
}

// Вспомогательная функция для топологической сортировки
void topologicalSortInternal(const IGraph& graph, int vertex, std::vector<bool>& visited, std::deque<int>& sorted) {
    visited[vertex] = true;

    for (int nextVertex : graph.GetNextVertices(vertex)) {
        if (!visited[nextVertex]) {
            topologicalSortInternal(graph, nextVertex, visited, sorted);
        }
    }

    sorted.push_front(vertex);
}

// Основная функция топологической сортировки
std::deque<int> topologicalSort(const IGraph& graph) {
    std::deque<int> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            topologicalSortInternal(graph, i, visited, sorted);
        }
    }

    return sorted;
}
