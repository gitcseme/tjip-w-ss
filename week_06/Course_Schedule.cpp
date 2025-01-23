// TC: O(N) where N is the number of courses
// MC: O(N)
// BFS solution with topological sort concept
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            ++indegree[edge[0]];
        }

        int totalTaken = 0;
        queue<int> Q;
        for (int c = 0; c < numCourses; ++c) {
            if (indegree[c] == 0)
                Q.push(c);
        }

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++totalTaken;

            for (int v : graph[u]) {
                --indegree[v];
                if (indegree[v] == 0)
                    Q.push(v);
            }
        }

        return numCourses == totalTaken;
    }
};


// TC: O(N) where N is the number of courses
// MC: O(N) + O(N) recursive stack space

// DFS solution
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> colors;

    bool hasCycle(int u) {
        colors[u] = 1;
        
        for (auto v : graph[u]) {
            if (colors[v] == 1) {
                return true;
            }
            if (colors[v] == 0 && hasCycle(v)) {
                return true;
            }
        }

        colors[u] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        colors.resize(numCourses, 0);

        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (colors[i] == 0 && hasCycle(i)) {
                return false;
            }
        }

        return true;
    }
};
