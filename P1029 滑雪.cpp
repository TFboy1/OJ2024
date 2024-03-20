//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 1001;
//
//int dp[MAXN][MAXN];
//int heights[MAXN][MAXN];
//
//int dx[] = { 1, -1, 0, 0 };
//int dy[] = { 0, 0, 1, -1 };
//
//int dfs(int x, int y, int R, int C) {
//    if (dp[x][y] > 0) {
//        return dp[x][y];
//    }
//
//    dp[x][y] = 1;
//    for (int k = 0; k < 4; ++k) {
//        int nx = x + dx[k];
//        int ny = y + dy[k];
//        if (nx >= 0 && nx < R && ny >= 0 && ny < C && heights[nx][ny] < heights[x][y]) {
//            dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny, R, C));
//        }
//    }
//
//    return dp[x][y];
//}
//
//int main() {
//    int R, C;
//    cin >> R >> C;
//
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//            cin >> heights[i][j];
//        }
//    }
//
//    int ans = 0;
//    for (int i = 0; i < R; ++i) {
//        for (int j = 0; j < C; ++j) {
//            ans = max(ans, dfs(i, j, R, C));
//        }
//    }
//
//    cout << ans << endl;
//    return 0;
//}
