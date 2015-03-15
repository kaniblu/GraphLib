#ifndef H_GRAPHALGO
#define H_GRAPHALGO

#include <unordered_map>
#include <cmath>
#include "graph.h"

namespace graph 
{
	template<class T> void ppr(const graph<T> &graph, const T &root, std::unordered_map<T, double> &out_ranks, const double damping = 0.85, const double epsilon = 0.001, const int iteration = 20)
	{
		out_ranks.clear();
		double delta = 1;
		double count = 0;

		for (auto it = graph.vertices.begin(); it != graph.vertices.end(); ++it)
			out_ranks.emplace(*it, 1.0/graph.vertex_size());

		while (delta > epsilon && count != iteration) {
			delta = 0;

			for (auto it = graph.vertices.begin(); it != graph.vertices.end(); ++it) {
				double sum = 0;

				auto it3 = graph.in_vertices.find(*it);
				if (it3 != graph.in_vertices.end()) {
					for (auto it2 = it3->second.begin(); it2 != it3->second.end(); ++it2)
						sum += out_ranks[*it2] / graph.out_vertices.find(*it2)->second.size();
				}

				const double old_rank = out_ranks[*it];
				out_ranks[*it] = sum * damping + (root == *it ? 1 : 0) * (1 - damping);
				delta += abs(out_ranks[*it] - old_rank);
			}

			++count;
		}
	}

	template <typename T> void betweenness(const graph<T> &graph)
	{

	}
}

#endif
