/*
 * graph.h
 *
 *  Created on: 2015年5月9日
 *      Author: senyuanwang
 */

#ifndef BIPARTITE_GRAPH_H_
#define BIPARTITE_GRAPH_H_

namespace bipartite {

void init_graph(int V);

void add_edge(int u, int v);

int bipartite_matching();

void clear_graph(int v);

}

#endif /* BIPARTITE_GRAPH_H_ */
