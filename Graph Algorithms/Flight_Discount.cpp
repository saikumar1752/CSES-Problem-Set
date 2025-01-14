#include <iostream>
#include <vector>
#include <functional>
#include <climits>
#include <queue>
 
using namespace std;
 
int main()
{
    long long nodes, m;
    cin >> nodes >> m;
    vector<vector<pair<long long, long long>>> graph(nodes + 1);
    for (long long i = 0; i < m; i++)
    {
        long long source, destination, price;
        cin >> source >> destination >> price;
        graph[--source].emplace_back(--destination, price);
    }
    struct Pos{
        long long pos;
        bool used;
        long long cost;
 
    };
    vector<vector<long long>> distances(nodes, {INT64_MAX, INT64_MAX});
    distances[0] = {0, 0};
    auto cmp = [&](const Pos &a, const Pos &b) { return a.cost > b.cost; };
	priority_queue<Pos, vector<Pos>, decltype(cmp)> pq(cmp);
    pq.push({0, false, 0});
    distances[0][0] = 0;
    while (!pq.empty()) {
		Pos curr = pq.top();
		pq.pop();
		long long curr_cost = distances[curr.pos][curr.used];
		if (curr_cost != curr.cost) { continue; }
		if (curr.pos == nodes - 1) { break; }
		for (auto [n, nc] : graph[curr.pos]) {
			// if we haven't used the discount yet, try using it now
			if (!curr.used) {
				long long new_cost = curr_cost + nc / 2;
				if (new_cost < distances[n][true]) {
					distances[n][true] = new_cost;
					pq.push(Pos{n, true, new_cost});
				}
			}
			// but we can always just try the normal cost route
			if (curr_cost + nc < distances[n][curr.used]) {
				distances[n][curr.used] = curr_cost + nc;
				pq.push(Pos{n, curr.used, curr_cost + nc});
			}
		}
	}
    cout <<distances[nodes-1][1]<<endl;
}
