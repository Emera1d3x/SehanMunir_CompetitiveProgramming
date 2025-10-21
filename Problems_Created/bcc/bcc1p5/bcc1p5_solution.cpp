#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007; // MOD 10^9 + 7

int N; // # of nodes/nests
vector<vector<int>> adjList; // Adjaceny List
vector<int> visited;

// DP States for each node
// dpEmpty[u] = ways when u is empty
// dpNestParent[u] = ways when u is occupied and parent u is occupied
// dpNestAlone[u] = ways when u is occupied and parent u is empty
vector<long long> dpEmpty, dpNestParent, dpNestAlone;

// Traverse graph and compute the three important values for a given node u
// Memoization is used with visited, (prevents recomputing found information)
void dfs(int u, int parent) {
	if (visited[u]) return;
	visited[u] = 1;

	// (Holds information of combinations that are possible)
	long long prodEmpty = 1;  // product for dpEmpty[u]
	long long prodParent = 1; // product for dpNestParent[u]
	long long prodAllEmpty = 1; // for detecting "all children empty"

	// For all children of u
	for (int v : adjList[u]) {
		if (v == parent) continue;
		dfs(v, u); 

		long long emptyChild = dpEmpty[v];
		long long withParent = dpNestParent[v];
		long long alone = dpNestAlone[v];

		// If u is occupied and its parent is also occupied:
		// child v can be empty or occupied
		prodParent = (prodParent * ((emptyChild + withParent) % MOD)) % MOD;

		// If u is empty:
		// child v can be empty or occupied (alone)
		prodEmpty = (prodEmpty * ((emptyChild + alone) % MOD)) % MOD;

		// For dpNestAlone: subtract the case where all children are empty (not allowed case)
		prodAllEmpty = (prodAllEmpty * emptyChild) % MOD;
	}

	// Setting DP inforamtion
	dpNestParent[u] = prodParent % MOD;
	dpNestAlone[u] = ((prodParent - prodAllEmpty) % MOD + MOD) % MOD; // remove all-empty children case
	dpEmpty[u] = prodEmpty % MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	adjList.assign(N + 1, {});
	dpEmpty.assign(N + 1, 0);
	dpNestParent.assign(N + 1, 0);
	dpNestAlone.assign(N + 1, 0);
	visited.assign(N + 1, 0);

	for (int i = 0; i < N - 1; ++i) {
		int u, v; 
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	dfs(1, -1);

	// Root has no parent, so if it's occupied, it must rely on children (dpNestAlone)
	long long ans;
	if (N == 1) {
		ans = 1; // only option = empty (a single occupied nest has no friend)
	} else {
		ans = (dpEmpty[1] + dpNestAlone[1]) % MOD;
	}
  
	cout << ans << "\n";
}
