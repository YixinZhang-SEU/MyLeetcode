#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Solution {
public:
    // 97. 所有可能的路径
    // vector<vector<int>> res;
    // vector<int> path;
    // //
    // void dfs(vector<vector<int>>& graph, int x) {
    //     if (x == graph.size() - 1) {
    //         res.push_back(path);
    //         return;
    //     }
    //     for (int i = 0; i < graph[x].size(); i++) {
    //         path.push_back(graph[x][i]);
    //         dfs(graph, graph[x][i]);
    //         path.pop_back();
    //     }
    // }
    // //
    // vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    //     path.push_back(0);
    //     dfs(graph, 0);
    //     return res;
    // }

    // 200. 岛屿数量（深搜版）
    // // 搜到一个没被探索的陆地，计数器加一，再深搜（广搜）这个点往外能到达的所有的陆地
    // vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    // void dfs(vector<vector<char>>& grid, vector<vector<int>>& isVisited, int x, int y) {
    //     for (int i = 0; i < 4; i++) {
    //         int nextx = x + directions[i][0];
    //         int nexty = y + directions[i][1];
    //         if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
    //             continue;           // 越界
    //         }
    //         if (!isVisited[nextx][nexty] && grid[nextx][nexty] == '1') {
    //             isVisited[nextx][nexty] = 1;
    //             dfs(grid, isVisited, nextx, nexty);
    //         }
    //     }
    // }
    // //
    // int numIslands(vector<vector<char>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<int>>isVisited(n, vector<int>(m, 0));     // 是否被访问过
    //     int res = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (!isVisited[i][j] && grid[i][j] == '1') {
    //                 isVisited[i][j] = 1;
    //                 res++;
    //                 dfs(grid, isVisited, i, j);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 200. 岛屿数量（广搜版）
    // void bfs(vector<vector<int>>& isVisited, vector<vector<char>>& grid, int x, int y) {
    //     vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    //     queue<pair<int, int>> q;
    //     q.push({x, y});
    //     isVisited[x][y] = 1;
    //     while (!q.empty()) {
    //         pair<int, int> now = q.front();
    //         q.pop();
    //         int nowx = now.first;
    //         int nowy = now.second;
    //         for (int i = 0; i < 4; i++) {
    //             int nextx = nowx + directions[i][0];
    //             int nexty = nowy + directions[i][1];
    //             if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
    //                 continue;
    //             }
    //             if (isVisited[nextx][nexty] == 0 && grid[nextx][nexty] == '1') {
    //                 q.push({nextx, nexty});
    //                 isVisited[nextx][nexty] = 1;
    //             }
    //         }
    //     }
    // }
    // //
    // int numIslands(vector<vector<char>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<int>> isVisited(n, vector<int>(m, 0));
    //     int res = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (isVisited[i][j] == 0 && grid[i][j] == '1') {
    //                 res++;
    //                 bfs(isVisited, grid, i, j);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 695. 岛屿的最大面积(深搜)
    // int count = 0;
    // vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    // //
    // void dfs(vector<vector<int>>& isVisited, vector<vector<int>>& grid, int x, int y) {
    //     if (isVisited[x][y] == 1 || grid[x][y] != 1) {
    //         return;
    //     }
    //     isVisited[x][y] = 1;
    //     count++;
    //     for (int i = 0; i < 4; i++) {
    //         int nextx = x + directions[i][0];
    //         int nexty = y + directions[i][1];
    //         if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
    //             continue;
    //         }
    //         dfs(isVisited, grid, nextx, nexty);
    //     }
    // }
    // //
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     int n = grid.size(), m = grid[0].size();
    //     vector<vector<int>> isVisited(n, vector<int>(m, 0));
    //     int res = 0;
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < m; j++) {
    //             if (isVisited[i][j] == 0 && grid[i][j] == 1) {
    //                 count = 0;
    //                 dfs(isVisited, grid, i, j);
    //                 res = max(res, count);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 1020. 飞地的数量
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& isVisited, int x, int y) {
        if (isVisited[x][y] || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        isVisited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nextx = x + directions[i][0];
            int nexty = y + directions[i][1];
            if (nextx < 0|| nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) {
                continue;
            }
            dfs(grid, isVisited, nextx, nexty);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> isVisited(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            dfs(grid, isVisited, i, 0);
            dfs(grid, isVisited, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(grid, isVisited, 0, j);
            dfs(grid, isVisited, m - 1, j);
        }

        int count = 0;
        for (auto g : grid) {
            for (auto n : g) {
                if (n == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    // 

}