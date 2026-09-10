class Solution {
private:
    // DFS to verify if a course is dependant on another
    bool dfs(int requirement, int course, vector<bool>& visited, vector<vector<int>>& graph){
        if (requirement == course) return true;
        visited[requirement] = true;
        for (int nextCourse : graph[requirement]) {
            if (!visited[nextCourse] && dfs(nextCourse, course, visited, graph)){
                return true;
            }
        }
        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        //Build graph
        vector<vector<int>> myGraph(numCourses);
        vector<bool> ans;

        for (const auto& pair : prerequisites)
        {
            int requirement = pair[0];
            int course = pair[1];
            myGraph[requirement].push_back(course);
        }

        for (const auto& query : queries)
        {
            int requirement = query[0];
            int course = query[1];
            vector<bool> visited(numCourses,false);
            ans.push_back(dfs(requirement,course,visited,myGraph));
        }
        return ans;
    }
};