#ifndef H_GRAPH
#define H_GRAPH

#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace graphlib
{
    template<typename V> class graph
    {
    private:
        static constexpr double DEFAULT_WEIGHT = 1.0;

        int _vertex_size;
        int _edge_size;
        std::unordered_set<V> _vertices_set;

    public:
        std::vector<V> vertices;
        std::unordered_map<V, std::unordered_map<V, double>> edge_weights;
        std::unordered_map<V, std::set<V>> out_vertices;
        std::unordered_map<V, std::set<V>> in_vertices;

        void add_vertex(const V &vertex)
        {
            if (_vertices_set.find(vertex) == _vertices_set.end()) {
                _vertices_set.emplace(vertex);
                vertices.push_back(vertex);
                ++_vertex_size;
            }
        }

        void add_edge(const V &from, const V &to, double weight)
        {
            add_vertex(from);
            add_vertex(to);

            if (out_vertices.find(from) == out_vertices.end())
                out_vertices.emplace(from, std::set<V>());

            if (in_vertices.find(to) == in_vertices.end())
                in_vertices.emplace(to, std::set<V>());

            if (out_vertices[from].find(to) == out_vertices[from].end()) {
                ++_edge_size;
                out_vertices[from].emplace(to);
            }

            if (in_vertices[to].find(from) == in_vertices[to].end())
                in_vertices[to].emplace(from);

            if (edge_weights.find(to) == edge_weights.end())
                edge_weights.emplace(to, std::unordered_map<V, double>());

            edge_weights[to][from] = weight;
        }

        void add_edge(const V &from, const V &to)
        {
            add_edge(from, to, DEFAULT_WEIGHT);
        }

        void add_bidirectional_edge(const V &v1, const V &v2, double weight)
        {
            add_edge(v1, v2, weight);
            add_edge(v2, v1, weight);
        }

        void add_bidirectional_edge(const V &v1, const V &v2)
        {
            add_bidirectional_edge(v1, v2, DEFAULT_WEIGHT);
        }

        int vertex_size() const
        {
            return _vertex_size;
        }

        int edge_size() const
        {
            return _edge_size;
        }

        std::set<V> get_out_vertices(const V &vertex) const
        {
            return out_vertices.find(vertex)->second;
        }

        std::set<V> get_in_vertices(const V &vertex) const
        {
            return in_vertices.find(vertex)->second;
        }
    };

}
#endif
