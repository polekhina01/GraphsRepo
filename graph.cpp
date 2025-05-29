#include "graph.h"
#include <algorithm>

// -------------------------
// ListGraph
// -------------------------
ListGraph::ListGraph(int size) : adjacencyLists(size) {}

ListGraph::ListGraph(const IGraph& graph) {
    adjacencyLists.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        adjacencyLists[i] = graph.GetNextVertices(i);
    }
}

ListGraph::~ListGraph() {}

void ListGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyLists.size());
    assert(0 <= to && to < adjacencyLists.size());
    adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacencyLists.size());
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyLists.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencyLists.size(); ++from) {
        for (int to : adjacencyLists[from]) {
            if (to == vertex)
                prevVertices.push_back(from);
        }
    }
    return prevVertices;
}

// -------------------------
// MatrixGraph
// -------------------------
MatrixGraph::MatrixGraph(int size)
    : adjacencyMatrix(size, std::vector<bool>(size, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : adjacencyMatrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int from = 0; from < graph.VerticesCount(); ++from) {
        for (int to : graph.GetNextVertices(from)) {
            adjacencyMatrix[from][to] = true;
        }
    }
}

MatrixGraph::~MatrixGraph() {}

void MatrixGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencyMatrix.size());
    assert(0 <= to && to < adjacencyMatrix.size());
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return static_cast<int>(adjacencyMatrix.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> nextVertices;
    for (int to = 0; to < adjacencyMatrix[vertex].size(); ++to) {
        if (adjacencyMatrix[vertex][to]) {
            nextVertices.push_back(to);
        }
    }
    return nextVertices;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencyMatrix.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencyMatrix.size(); ++from) {
        if (adjacencyMatrix[from][vertex]) {
            prevVertices.push_back(from);
        }
    }
    return prevVertices;
}

// -------------------------
// SetGraph
// -------------------------
SetGraph::SetGraph(int size) : adjacencySets(size) {}

SetGraph::SetGraph(const IGraph& graph) {
    adjacencySets.resize(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        for (int v : graph.GetNextVertices(i)) {
            adjacencySets[i].insert(v);
        }
    }
}

SetGraph::~SetGraph() {}

void SetGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < adjacencySets.size());
    assert(0 <= to && to < adjacencySets.size());
    adjacencySets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacencySets.size());
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySets.size());
    return std::vector<int>(adjacencySets[vertex].begin(), adjacencySets[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < adjacencySets.size());
    std::vector<int> prevVertices;
    for (int from = 0; from < adjacencySets.size(); ++from) {
        if (adjacencySets[from].count(vertex))
            prevVertices.push_back(from);
    }
    return prevVertices;
}

// -------------------------
// ArcGraph
// -------------------------
ArcGraph::ArcGraph(int size) : verticesCount(size) {}

ArcGraph::ArcGraph(const IGraph& graph) : verticesCount(graph.VerticesCount()) {
    for (int from = 0; from < verticesCount; ++from) {
        for (int to : graph.GetNextVertices(from)) {
            edges.emplace_back(from, to);
        }
    }
}

ArcGraph::~ArcGraph() {}

void ArcGraph::AddEdge(int from, int to) {
    assert(0 <= from && from < verticesCount);
    assert(0 <= to && to < verticesCount);
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return verticesCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);
    std::vector<int> result;
    for (const auto& edge : edges) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(0 <= vertex && vertex < verticesCount);
    std::vector<int> result;
    for (const auto& edge : edges) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}
