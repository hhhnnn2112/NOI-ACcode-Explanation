#include<bits/stdc++.h>
using namespace std;
int n, m;
int f[101][101];
int F[101][101];
int main() {
  scanf("%d%d", &n, &m); // n的值在1到100之间
  memset(f, -1, sizeof(f));
  for(int i = 1; i <= m; i++) {
    int u, v, w; // w的值在0到10000之间
    scanf("%d%d%d", &u, &v, &w);
    f[u][v] = f[v][u] = w;
  }
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if(f[i][k] != -1 && f[k][j] != -1)
          if(f[i][j] == -1||f[i][j]>f[k][j]+f[i][k])
            f[i][j] = f[i][k] + f[k][j];
  int ans = 2147483647;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++)
          F[x][y] = f[x][y];
      F[i][j] = F[j][i] = 0;
      for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++)
          if(F[x][y]==-1||F[x][y]>F[x][i]+F[i][y])
            F[x][y] = F[x][i] + F[i][y];
      for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++)
          if(F[x][y]==-1||F[x][y]>F[x][j]+F[j][y])
            F[x][y] = F[x][j] + F[j][y];
      int res = 0;
      for(int x = 1; x <= n; x++)
        for(int y = 1; y < x; y++)
          res += F[x][y];
      ans = min(res, ans);
    }
  printf("%d\n", ans);
  return 0;
} 
