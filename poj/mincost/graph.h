/*
 * graph.h
 *
 *  Created on: 2015年5月10日
 *      Author: senyuanwang
 */

#ifndef MINCOST_GRAPH_H_
#define MINCOST_GRAPH_H_


namespace mincost {
void init_graph(int V);
void add_edge(int from, int to, int cap, int cost);
int min_cost_flow(int s, int t, int f);
}


#endif /* MINCOST_GRAPH_H_ */
