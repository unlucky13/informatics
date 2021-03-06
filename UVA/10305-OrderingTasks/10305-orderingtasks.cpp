#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

vector<vector<int> > AdjList(105);
bool visited[105];
vector<int> topological_sort;

int N, M;

void dfs(int i) {
  visited[i] = true;

  for(vector<int>::const_iterator adj = AdjList[i].begin(); adj != AdjList[i].end(); ++adj)
    if(!visited[*adj]) dfs(*adj);

  topological_sort.push_back(i);
}

int main()
{
  while(scanf("%d %d", &N, &M) == 2) {
    memset(visited, false, sizeof visited);
    topological_sort.clear();
    AdjList.clear();

    if(N == 0 && M == 0) return 0;

    AdjList.resize(N);

    for(size_t k = 1; k <= M; ++k) {
      size_t i, j; scanf("%ld %ld", &i, &j);
      AdjList[i].push_back(j);
    }

    // size_t i = 1;
    // for(vector<vector<int> >::const_iterator list = AdjList.begin(); list != AdjList.end(); ++list) {
    //   printf("Adjacent to %ld\n", i);
    //   for(vector<int>::const_iterator adj = (*list).begin(); adj != (*list).end(); ++adj) {
    //     printf("%d\n", *adj);
    //   }
    //   i++;
    // }

    for(size_t i = 1; i <= N; i++) 
      if(!visited[i]) dfs(i);

    reverse(topological_sort.begin(), topological_sort.end());

    for(vector<int>::const_iterator it = topological_sort.begin(); 
        it != topological_sort.end(); ++it)
      printf("%d ", *it);

    printf("\n");
  }

  return 0;
}
