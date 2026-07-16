#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> adj[300005];

  for(int i = 0; i < M; i++){
    int u, v;
    cin >> u >> v;
    adj[v].pushback(u);
  }
}