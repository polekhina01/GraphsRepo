#pragma once
#include <vector>
#include <set>
#include <utility>  // std::pair
#include <cassert>

struct IGraph {
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

// -------------------------
// ListGraph
// -------------------------
struct ListGraph : public IGraph {
    ListGraph(int size);
    ListGraph(const IGraph& graph);
    ~ListGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

// -------------------------
// MatrixGraph
// -------------------------
struct MatrixGraph : public IGraph {
    MatrixGraph(int size);
    MatrixGraph(const IGraph& graph);
    ~MatrixGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> adjacencyMatrix;
};

// -------------------------
// SetGraph
// -------------------------
struct SetGraph : public IGraph {
    SetGraph(int size);
    SetGraph(const IGraph& graph);
    ~SetGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> adjacencySets;
};

// -------------------------
// ArcGraph
// -------------------------
struct ArcGraph : public IGraph {
    ArcGraph(int size);
    ArcGraph(const IGraph& graph);
    ~ArcGraph();

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int verticesCount;
    std::vector<std::pair<int, int>> edges;
};
