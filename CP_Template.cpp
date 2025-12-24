#include<bits/stdc++.h>
#include<utility>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define mo 1000000007
using namespace std;
 
 
//----------------Graph algorithms----------------//
 
// Dijkstra algorithm for single source shortest path without any negative edge, time complexity is (n+m)logn
void dijkstra(ll start, vector<vector<pair<ll,ll> > > &adj, vector<ll> &dist, vector<ll> &parent) {
    ll n = (ll)adj.size() - 1;
    dist.assign(n + 1, LLONG_MAX);
    parent.assign(n + 1, -1);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
 
    dist[start] = 0;
    pq.push(make_pair(0, start));
 
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d != dist[v]) continue; 
        for (auto &edge : adj[v]) {
            ll to = edge.first;
            ll w  = edge.second;
            if (dist[v] != LLONG_MAX && dist[v] + w < dist[to]) {
                dist[to] = dist[v] + w;
                parent[to] = v;
                pq.push(make_pair(dist[to], to));
            }
        }
    }
}
 
 
 
// Bellman-Ford algorithm: Single source shortest path works with negative edge weights but not negative-weight cyclesm, Time complexity: O(n * m)
// to find negative cycle, simply assign all d[i]=0 intead of just source and run bellman ford for n times and the values should not change in the last run
struct Edge {
    ll u, v, w; // edge from u -> v with weight w
};
bool bellman_ford(ll n, ll source, vector<Edge> &edges, vector<ll> &dist, vector<ll> &parent) {
    const ll INF_LL = (1LL << 60);
    dist.assign(n + 1, INF_LL);
    parent.assign(n + 1, -1);
    dist[source] = 0;
    for (ll i = 1; i <= n - 1; i++) {
        bool any = false;
        for (auto &e : edges) {
            if (dist[e.u] == INF_LL) continue;
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                any = true;
            }
        }
        if (!any) break; 
    }
    for (auto &e : edges) {
        if (dist[e.u] == INF_LL) continue;
        if (dist[e.u] + e.w < dist[e.v]) {
            return false;
        }
    }
    return true;
}
 
 
 
// 0-1 BFS (single source shortest paths when all edge weights are 0 or 1, both directed or undirected), TC: O(n+m)
void zero_one_bfs(ll start, vector<vector<pair<ll,ll> > > &adj, vector<ll> &dist, vector<ll> &parent) {
    ll n = (ll)adj.size() - 1; // assuming 1-based
    dist.assign(n + 1, LLONG_MAX);
    parent.assign(n + 1, -1);
    deque<ll> dq;
    dist[start] = 0;
    dq.push_front(start);
    while (!dq.empty()) {
        ll v = dq.front();
        dq.pop_front();
        for (auto &edge : adj[v]) {
            ll u = edge.first;
            ll w = edge.second; // must be 0 or 1
            if (dist[v] != LLONG_MAX && dist[v] + w < dist[u]) {
                dist[u] = dist[v] + w;
                parent[u] = v;
                if (w == 1) {
                    dq.push_back(u);
                } else { // w == 0
                    dq.push_front(u);
                }
            }
        }
    }
}
 
 
 
// Floyd–Warshall algorithm (All-pairs shortest paths), Works for directed / undirected weighted graphs, TC: O(n^3)
// - Supports negative edge weights, but assumes NO negative cycles
// - After running, if dist[i][i] < 0 for some i, then there is a negative cycle
// - similar approach for number of path of fixed length(directed unweighted, matix multiplication) and and shortest path with less than fix given length
// - To find i j which have arbitrarily small weight(negative cycle), for each intemediate t between i and j, if dist[t][t]<0
void floyd_warshall(ll n, vector<vector<ll> > &dist, vector<vector<ll> > &nxt) {
    const ll INF = (1LL << 60);
    nxt.assign(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (dist[i][j] < INF && i != j) {
                nxt[i][j] = j;
            }
        }
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue; // no path i -> k
            for (ll j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue; 
                ll through_k = dist[i][k] + dist[k][j];
                if (through_k < dist[i][j]) {
                    dist[i][j] = through_k;
                    nxt[i][j] = nxt[i][k]; // first step from i towards j
                }
            }
        }
    }
}
 
 
 
// Prim's algorithm for Minimum Spanning Tree (MST)
// - Works on connected, undirected, weighted graphs.
// - If the graph is disconnected, no spanning tree exists. TC: O(m log n)
 
bool prim_mst(vector<vector<pair<ll,ll> > > &adj, ll &total_weight,
              vector<pair<ll,ll> > &mst_edges) {
 
    ll n = (ll)adj.size() - 1;  // assuming adj[1..n]
    const ll INF = (1LL << 60);
 
    vector<ll> min_e(n + 1, INF);     // minimum edge weight to connect each vertex
    vector<ll> parent(n + 1, -1);     // parent vertex in MST
    vector<ll> selected(n + 1, 0);    // whether vertex is already in MST
 
    // (weight, vertex)
    set<pair<ll,ll> > q;
 
    // Start from vertex 1 (you can change if needed)
    ll start = 1;
    min_e[start] = 0;
    q.insert(make_pair(0, start));
 
    total_weight = 0;
    mst_edges.clear();
 
    for (ll i = 1; i <= n; i++) {
        if (q.empty()) {
            // graph is disconnected, MST doesn't exist
            return false;
        }
 
        ll v = q.begin()->second;
        ll w = q.begin()->first;
        q.erase(q.begin());
 
        if (selected[v]) {
            i--;
            continue;
        }
 
        selected[v] = 1;
        total_weight += w;
 
        if (parent[v] != -1) {
            mst_edges.push_back(make_pair(v, parent[v]));
        }
 
        for (auto &edge : adj[v]) {
            ll to = edge.first;
            ll wt = edge.second;
 
            if (!selected[to] && wt < min_e[to]) {
                // remove old pair if it was in the set
                if (min_e[to] != INF) {
                    q.erase(make_pair(min_e[to], to));
                }
                min_e[to] = wt;
                parent[to] = v;
                q.insert(make_pair(min_e[to], to));
            }
        }
    }
 
    return true;
}
 
 
 
 
// breadth first search 
void bfs(vector<vector<ll> > &adj){
    ll n = adj.size()-1;
    queue<ll> q; q.push(1);
    vector<ll> vis(n+1,0);
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(auto i:adj[top]){
            if(!vis[i]){
                q.push(i);
                vis[i]=1;
            }
        }
    }
}
 
 
 
// Depth first search 
void dfs(vector<vector<ll> > &adj, vector<ll> &vis, ll u) {
    ll n = adj.size()-1;
    vis[u] = 1;
    for (ll v : adj[u])
        if (vis[v] == 0)
            dfs(adj, vis, v);
}
 
 
 
// Find connected components in a graph
void find_comps_dfs(vector<vector<ll> > &adj, vector<ll> &vis, vector<ll> &comp, ll u) {
    ll n = adj.size()-1;
    vis[u] = 1;
    comp.push_back(u);
    for (ll v : adj[u])
        if (vis[v] == 0)
            find_comps_dfs(adj, vis,comp, v);
}
void find_comps(vector<vector<ll> > &adj,vector<vector<ll> > &comps) {
    ll n = adj.size()-1;
    vector<ll> vis(n+1,0);
    for (ll v = 1; v <= n; ++v) {
        if (!vis[v]) {
            comps.push_back(vector<ll> ());
            find_comps_dfs(adj, vis, comps[comps.size()-1], v);
        }
    }
}
 
 
 
// Find bridges in graph
void find_bridges_dfs(vector<vector<ll> > &adj, vector<ll> &vis, vector<pair<ll, ll> > &bridges, vector<ll> &tin, vector<ll> &low, ll u, ll &timer, ll p) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    bool parent_skipped = false;
    for (ll v : adj[u]) {
        if (v == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            find_bridges_dfs(adj, vis, bridges, tin, low, v, timer, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                bridges.push_back(make_pair(u,v));
        }
    }
}
void find_bridges(vector<vector<ll> > &adj, vector<pair<ll, ll> > &bridges) {
    ll timer = 0, n=adj.size()-1;
    vector<ll> vis(n+1,0);
    vector<ll> tin(n+1,-1);
    vector<ll> low(n+1,-1);
    for (ll i = 1; i <= n; ++i) {
        if (!vis[i])
            find_bridges_dfs(adj, vis, bridges, tin, low, i, timer, -1);
    }
}
 
 
 
// Find articulation point in graph
void articulation_dfs(ll u, ll p, vector<vector<ll> > &adj, vector<ll> &vis, vector<ll> &tin, vector<ll> &low, ll &timer, vector<ll> &isAP) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    ll children = 0;
    for (ll v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            articulation_dfs(v, u, adj, vis, tin, low, timer, isAP);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && p != -1)
                isAP[u] = 1;
            children++;
        }
    }
    if (p == -1 && children > 1)
        isAP[u] = 1;
}
vector<ll> find_articulation_points(vector<vector<ll> > &adj) {
    ll n = adj.size() - 1;
    vector<ll> vis(n+1, 0), tin(n+1, -1), low(n+1, -1);
    vector<ll> isAP(n+1, 0);
    ll timer = 0;
    for (ll i = 1; i <= n; i++) {
        if (!vis[i])
            articulation_dfs(i, -1, adj, vis, tin, low, timer, isAP);
    }
    vector<ll> ans;
    for (ll i = 1; i <= n; i++)
        if (isAP[i]) ans.push_back(i);
 
    return ans;
}
 
 
 
//Topological Sort (DFS)
void topo_dfs(ll u, vector<vector<ll> > &adj, vector<ll> &vis, vector<ll> &order) {
    vis[u] = 1;
    for (ll v : adj[u]) {
        if (!vis[v]) {
            topo_dfs(v, adj, vis, order);
        }
    }
    order.push_back(u);
}
vector<ll> topological_sort(vector<vector<ll> > &adj) {
    ll n = (ll)adj.size() - 1;
    vector<ll> vis(n + 1, 0);
    vector<ll> order;
    order.reserve(n);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            topo_dfs(i, adj, vis, order);
        }
    }
    reverse(order.begin(), order.end());
    return order;
}
 
 
 
//Strongly connnected components (Kosaraju) TC: O(n+m)
void dfs_kosaraju(ll u, vector<vector<ll> > &adj, vector<ll> &vis, vector<ll> &result) {
    vis[u] = 1;
    for (ll v : adj[u]) {
        if (!vis[v])
            dfs_kosaraju(v, adj, vis, result);
    }
    result.push_back(u);
}
void scc_and_condensation(vector<vector<ll> > &adj, vector<vector<ll> > &components, vector<vector<ll> > &adj_cond, vector<ll> &comp_id) {
    ll n = (ll)adj.size() - 1;
 
    vector<ll> vis(n + 1, 0);
    vector<ll> order;
    order.reserve(n);
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_kosaraju(i, adj, vis, order);
        }
    }
 
    vector<vector<ll> > adj_rev(n + 1);
    for (ll v = 1; v <= n; v++) {
        for (ll u : adj[v]) {
            adj_rev[u].push_back(v);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    reverse(order.begin(), order.end());
    components.clear();
    components.push_back(vector<ll>()); // dummy at index 0 so SCCs are 1-based
    comp_id.assign(n + 1, 0);
    ll comp_cnt = 0;
    for (ll v : order) {
        if (!vis[v]) {
            vector<ll> component;
            dfs_kosaraju(v, adj_rev, vis, component);
            ++comp_cnt;
            components.push_back(component); // components[comp_cnt] = this SCC
            for (ll u : component) {
                comp_id[u] = comp_cnt;
            }
        }
    }
 
    adj_cond.assign(comp_cnt + 1, vector<ll>());
    for (ll v = 1; v <= n; v++) {
        for (ll u : adj[v]) {
            if (comp_id[v] != comp_id[u]) {
                adj_cond[comp_id[v]].push_back(comp_id[u]);
            }
        }
    }
    for (ll c = 1; c <= comp_cnt; c++) {
        auto &nbrs = adj_cond[c];
        sort(nbrs.begin(), nbrs.end());
        nbrs.erase(unique(nbrs.begin(), nbrs.end()), nbrs.end());
    }
}
 
 
 
//----------------Disjoint Set Union (DSU)----------------//
void dsu_init(ll n, vector<ll> &dsu_parent, vector<ll> &dsu_rank) {
    dsu_parent.resize(n + 1);
    dsu_rank.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        dsu_parent[i] = i;
    }
}
ll dsu_find(ll v, vector<ll> &dsu_parent) {
    if (v == dsu_parent[v]) return v;
    return dsu_parent[v] = dsu_find(dsu_parent[v],dsu_parent); // path compression
}
bool dsu_union(ll a, ll b, vector<ll> &dsu_parent, vector<ll> &dsu_rank) {
    a = dsu_find(a, dsu_parent);
    b = dsu_find(b, dsu_parent);
    if (a == b) return false;
    if (dsu_rank[a] < dsu_rank[b]) swap(a, b);
    dsu_parent[b] = a;
    if (dsu_rank[a] == dsu_rank[b]) dsu_rank[a]++;
    return true;
}
 
 
 
//Kruskal's MST (using DSU) TC: O(mlogn)
struct Edge1 {
    ll u, v, w;
    bool operator<(Edge1 const& other) const {
        return w < other.w;
    }
};
ll kruskal(ll n, vector<Edge1> &edges, vector<Edge1> &mst_edges) {
    sort(edges.begin(), edges.end()); // sort by weight
    vector<ll> dsu_parent, dsu_rank;
    dsu_init(n, dsu_parent,dsu_rank);
 
    ll cost = 0;
    mst_edges.clear();
 
    for (auto &e : edges) {
        if (dsu_union(e.u, e.v, dsu_parent, dsu_rank)) {
            cost += e.w;
            mst_edges.push_back(e);
        }
    }
 
    return cost;
}
 
 
 
// Eulerian path / cycle in an undirected multigraph with loops, TC: O(m)
//   adj: 1-based, adj[v] = list of {to, edge_id}, each undirected edge added twice.
//   edge_id must be in [0 .. m-1] and unique per undirected edge.
vector<ll> euler_path(ll n, vector<vector<pair<ll,ll> > > &adj) {
    vector<ll> deg(n+1);
    ll start = -1, odd = 0;
 
    // degrees + pick start (odd vertex if exists, otherwise any non-isolated)
    for (ll v = 1; v <= n; ++v) {
        deg[v] = (ll)adj[v].size();
        if (deg[v] % 2 == 1) {
            odd++;
            start = v;
        }
        if (start == -1 && deg[v] > 0) start = v;
    }
 
    vector<ll> empty_vec;
    if (start == -1) return empty_vec;                 // no edges at all
    if (!(odd == 0 || odd == 2)) return empty_vec;     // Euler path condition
 
    // connectivity check (ignoring isolated vertices)
    vector<ll> vis(n+1);
    stack<ll> st_check;
    st_check.push(start);
    vis[start] = 1;
    while (!st_check.empty()) {
        ll v = st_check.top(); st_check.pop();
        for (auto &e : adj[v]) {
            ll u = e.first;
            if (!vis[u]) {
                vis[u] = 1;
                st_check.push(u);
            }
        }
    }
    for (ll v = 1; v <= n; ++v)
        if (deg[v] > 0 && !vis[v]) return empty_vec;   // not connected ⇒ no Euler path
 
    // find maximum edge id to size "used"
    ll max_id = -1;
    for (ll v = 1; v <= n; ++v)
        for (auto &e : adj[v])
            max_id = max(max_id, e.second);
 
    vector<char> used(max_id + 1, 0);
    vector<ll> it(n+1, 0);  // current iterator index for each vertex
    vector<ll> st, path;
 
    st.push_back(start);
    while (!st.empty()) {
        ll v = st.back();
        auto &vec = adj[v];
 
        // skip already used edges
        while (it[v] < (ll)vec.size() && used[vec[it[v]].second]) it[v]++;
 
        if (it[v] == (ll)vec.size()) {
            // no more edges from v
            path.push_back(v);
            st.pop_back();
        } else {
            auto e = vec[it[v]];
            used[e.second] = 1;
            st.push_back(e.first);
        }
    }
 
    // for m edges, Euler path must have length m+1
    if ((ll)path.size() != max_id + 2) return empty_vec;
 
    reverse(path.begin(), path.end());
    return path;
}
 
 
 
//----------------LCA (Binary Lifting)----------------//
ll L;                       // max power of 2
vector<ll> tin, tout;
vector<vector<ll> > up;      // up[v][i] = 2^i-th ancestor of v
ll timerLCA;
 
void dfs_lca(ll v, ll p, vector<vector<ll> > &adj) {
    tin[v] = ++timerLCA;
    up[v][0] = p;
 
    for (ll i = 1; i <= L; i++)
        up[v][i] = up[ up[v][i-1] ][i-1];
 
    for (ll u : adj[v]) {
        if (u == p) continue;
        dfs_lca(u, v, adj);
    }
 
    tout[v] = ++timerLCA;
}
bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
 
    for (ll i = L; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void lca_preprocess(ll root, ll n, vector<vector<ll> > &adj) {
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);
    timerLCA = 0;
 
    L = ceil(log2(n));
    up.assign(n+1, vector<ll>(L+1));
 
    dfs_lca(root, root, adj);
}
 
 
 
//----------------Max Flow - Dinic----------------//
struct FlowEdge {
    ll v, u;
    ll cap, flow;
    FlowEdge(ll _v, ll _u, ll _cap) : v(_v), u(_u), cap(_cap), flow(0) {}
};
struct Dinic {
    const ll FLOW_INF = (ll)1e18;
    ll n, s, t;
    vector<FlowEdge> edges;
    vector<vector<ll> > adj;
    vector<ll> level, ptr;
 
    Dinic(ll _n, ll _s, ll _t) : n(_n), s(_s), t(_t) {
        vector<ll> empty_vec;
        adj.assign(n + 1, empty_vec);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }
 
    void add_edge(ll v, ll u, ll cap) {
        // v -> u with capacity cap
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);    // reverse edge
        ll m = (ll)edges.size();
        adj[v].push_back(m - 2);
        adj[u].push_back(m - 1);
    }
 
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        queue<ll> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            ll v = q.front();
            q.pop();
            for (ll id : adj[v]) {
                if (edges[id].cap == edges[id].flow) continue;
                ll u = edges[id].u;
                if (level[u] != -1) continue;
                level[u] = level[v] + 1;
                q.push(u);
            }
        }
        return level[t] != -1;
    }
 
    ll dfs(ll v, ll pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (ll &cid = ptr[v]; cid < (ll)adj[v].size(); cid++) {
            ll id = adj[v][cid];
            ll u = edges[id].u;
            if (level[u] != level[v] + 1) continue;
            ll avail = edges[id].cap - edges[id].flow;
            if (avail <= 0) continue;
            ll tr = dfs(u, min(pushed, avail));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    ll max_flow() {
        ll f = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed = dfs(s, FLOW_INF)) {
                f += pushed;
            }
        }
        return f;
    }
};
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//------------Math algorithms ----------------//
const ll MAXN = 200010;
vector<vector<ll> > spf(MAXN+1);
 
void computeSPF() {
    for(ll i=2; i<=MAXN; i++) {
        if(spf[i].empty()) {
            for(ll j=i; j<=MAXN; j+=i) {
                spf[j].push_back(i);
            }
        }
    }
}
 
