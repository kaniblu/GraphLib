#ifndef H_GRAPHALGO
#define H_GRAPHALGO

#include <unordered_map>
#include <cmath>
#include "graph.h"

namespace graphlib
{
    template<class T> void ppr(const graph<T> &graph, const T &root, std::unordered_map<T, double> &out_ranks, const double damping = 0.85, const double epsilon = 0.001, const int iteration = 20)
    {
        out_ranks.clear();
        double delta = 1;
        double count = 0;

        for (auto it = graph.vertices.begin(); it != graph.vertices.end(); ++it)
            out_ranks.emplace(*it, 1.0 / graph.vertex_size());

        while (delta > epsilon && count != iteration) {
            delta = 0;

            for (auto it = graph.vertices.begin(); it != graph.vertices.end(); ++it) {
                double sum = 0;
                T v1 = *it;

                auto it3 = graph.in_vertices.find(v1);
                if (it3 != graph.in_vertices.end()) {
                    double weight_sum = 0;

                    for (auto it2 = graph.edge_weights.find(v1)->second.begin(); it2 != graph.edge_weights.find(v1)->second.end(); ++it2)
                        weight_sum += it2->second;

                    for (auto it2 = it3->second.begin(); it2 != it3->second.end(); ++it2)
                        sum += out_ranks[*it2] * graph.edge_weights.find(v1)->second.find(*it2)->second / weight_sum;
                }

                const double old_rank = out_ranks[*it];
                out_ranks[*it] = sum * damping + (root == *it ? 1 : 0) * (1 - damping);
                delta += fabs(out_ranks[*it] - old_rank);
            }

            ++count;
        }
    }

    template<typename T> void betweenness(const graph<T> &graph)
    {

    }
}

#endif
