class Solution {

    bool hasCycle(int course, vector<bool> &visited, vector<bool> &inStack, vector<vector<int>> &prereqs){
        visited[course] = true;
        inStack[course] = true;
        for(int i = 0; i < prereqs.size(); i++){
            int pre = prereqs[i][0];
            int cur = prereqs[i][1];
            if(cur == course){
                if(!visited[pre]){
                    if(hasCycle(pre, visited, inStack, prereqs)){
                        return true;
                    }
                } else {
                    if(inStack[pre]){
                        return true;
                    }
                }
            }
        }
        inStack[course] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> &prereqs = prerequisites;
        vector<bool> inStack(n, false);
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(hasCycle(i, visited, inStack, prereqs)){
                    return false;
                }
            }
        }

        return true;
    }
};