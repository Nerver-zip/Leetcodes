class TaskManager {
private:
    set<pair<int,int>> taskSet; //{priority, id}
    unordered_map<int, pair<int,int>> taskToPair;
    unordered_map<int, int> taskToUser;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); ++i){
            int userId = tasks[i][0], taskId = tasks[i][1], priority = tasks[i][2];
            
            pair<int, int> pair = {priority, taskId};
            
            taskSet.insert(pair);
            taskToPair[taskId] = pair;
            taskToUser[taskId] = userId;

        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        pair<int, int> pair = {priority, taskId};

        taskSet.insert(pair);
        taskToPair[taskId] = pair;
        taskToUser[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        if(!taskToPair.count(taskId))
            return;
        auto rm = taskToPair[taskId];
        taskSet.erase(rm);

        pair<int, int> pair = {newPriority, taskId};
        
        taskSet.insert(pair);
        taskToPair[taskId] = pair;
    }
    
    void rmv(int taskId) {
        if(!taskToPair.count(taskId))
            return;
        auto rm = taskToPair[taskId];
        taskSet.erase(rm);
        taskToUser.erase(taskId);
        taskToPair.erase(taskId);
    }

    int execTop() {
        if (taskSet.empty()) 
            return -1;
        auto rm = *taskSet.rbegin();
        int res = taskToUser[rm.second];

        taskSet.erase(rm);
        taskToUser.erase(rm.second);
        taskToPair.erase(rm.second);

        return res;
    }
};