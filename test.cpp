#include <bits/stdc++.h>
using namespace std;

vector<pair<int, double>> nodes;
unordered_map<int, double> node_score;
vector<pair<int, int>> edges;
map<int, vector<int>> supernode_node;
map<double, int> score_supernode;
vector<pair<int, int>> final_edges;
unordered_map<int, double> m;
int n;
vector<vector<double>> o;

void add_node(int id, double score)
{
    nodes.push_back({id, score});
    node_score[id] = score;
    return;
}
void add_edge(int from, int to)
{
    edges.push_back({from, to});
    return;
}
static bool sortby(pair<int, double> &a, pair<int, double> &b)
{
    return a.second < b.second;
}
void preprocess()
{
    n = 0;
    sort(nodes.begin(), nodes.end(), sortby);
    int supernode = 0;
    bool equal_scores = false;
    for (int i = 0; i < nodes.size(); i++){
        if (score_supernode.find(nodes[i].second) == score_supernode.end()){
            m[supernode] = nodes[i].second;
            score_supernode[nodes[i].second] = supernode;
            supernode_node[supernode].push_back(nodes[i].first);
            supernode++;
        }
        else{
            supernode_node[score_supernode[nodes[i].second]].push_back(nodes[i].first);
            equal_scores = true;
        }
    }
    n = supernode;
    for (int i = 0; i < edges.size(); i++){
        // taking every edge of given graph and converting into new graph by supernodes
        int from = edges[i].first;
        int to = edges[i].second;
        int from_supernode = score_supernode[node_score[from]];
        int to_supernode = score_supernode[node_score[to]];
        // making final graph after making same score nodes to supernode
        if (from != to)
            final_edges.push_back({from_supernode, to_supernode});
    }
    return;
}
void obj_fun()
{
    o.resize(n + 1, vector<double>(n + 1, 0));
    // o[i][j]->number of edges- (number of nodes)^2 in between region [i,j]
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int e = 0;
            for (int k = 0; k < final_edges.size(); k++)
            {
                int a = final_edges[k].first, b = final_edges[k].second;
                if ((a >= i and a <= j) and (b >= i and b <= j))
                    e++;
            }
            o[i][j] = abs((double)e - pow(j - i + 1, 1));
        }
    }
}
vector<int> dp()
{
    // q[i]->best value of cuts(any number of cuts) among all possible cases for 0 to i
    vector<double> q(n + 1, INT_MIN);   
    // stores specific point where cut is better form i to 0
    vector<int> optimal_cutpoint(n, 0); 
    for (int j = 0; j < n; j++){
        q[j] = INT_MIN;
        for (int k = j; k >= 0; k--){
            double quality_of_split = q[k - 1] + o[k][j];
            if (quality_of_split > q[j])
            {
                q[j] = quality_of_split;
                optimal_cutpoint[j] = k;
            }
        }
    }
    vector<int> cuts;
    int cut = optimal_cutpoint[n - 1];
    while (cut != 0){
        cuts.push_back(cut);
        cut = optimal_cutpoint[cut - 1];
    }
    // since from back cut we came
    reverse(cuts.begin(), cuts.end());
    return cuts;
}
void print(vector<int> &a)
{
    cout << "possible cuts are=" << endl;
    int j = 0;
    cout << "region 1" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[j] == i)
        {
            j++;
            cout << m[i] << endl;
            cout << "region " << j + 1 << endl;
        }
        else
        {
            cout << m[i] << " ";
        }
    }
    cout << endl;
}
int main()
{
    add_node(1, 0.3);
    add_node(2, 0.7);
    add_node(3, 0.8);
    add_node(4, 0.1);
    add_node(5, 0.25);
    add_node(6, 2.25);
    add_node(7, 2.35);
    add_node(8, 5.25);
    add_node(9, 5.5);
    add_node(10, 8.25);
    add_node(11, 9.05);
    add_node(12, 8.75);

    add_edge(1, 4);
    add_edge(3, 4);
    add_edge(10, 11);
    add_edge(8, 9);
    add_edge(11, 12);

    preprocess();
    obj_fun();
    vector<int> cuts = dp();
    print(cuts);
    return 0;
}