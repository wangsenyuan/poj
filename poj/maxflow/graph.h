/*
 * graph.h
 *
 *  Created on: 2015年5月9日
 *      Author: senyuanwang
 */

#ifndef MAXFLOW_GRAPH_H_
#define MAXFLOW_GRAPH_H_


namespace maxflow {
	void add_edge(int from, int to, int cap);

	int max_flow(int s, int t);
}


#endif /* MAXFLOW_GRAPH_H_ */
