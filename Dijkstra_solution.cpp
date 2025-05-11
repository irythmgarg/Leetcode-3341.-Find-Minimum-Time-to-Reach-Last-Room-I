class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize visited matrix with INT_MAX as default time to reach each cell
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        visited[0][0] = 0;

        // 4 possible directions: up, down, left, right
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Min-heap to process the cells based on minimum time required to reach
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({0, {0, 0}});  // Start from cell (0, 0) at time 0

        while (!q.empty()) {
            auto [cost, coord] = q.top();
            q.pop();
            int i = coord.first, j = coord.second;

            // Skip if already visited with a better (lower) cost
            if (cost > visited[i][j]) continue;

            // Explore all 4 directions
            for (auto& dir : directions) {
                int newi = i + dir[0];
                int newj = j + dir[1];

                // Check grid boundaries
                if (newi < 0 || newi >= m || newj < 0 || newj >= n) continue;

                // Wait if we arrive early (grid[newi][newj] - cost > 0)
                int wait = max(0, grid[newi][newj] - cost);
                int newcost = cost + wait + 1;  // +1 for the move itself

                if (visited[newi][newj] > newcost) {
                    visited[newi][newj] = newcost;
                    q.push({newcost, {newi, newj}});
                }
            }
        }

        // Return the minimum time to reach bottom-right cell
        return visited[m - 1][n - 1];
    }
};
