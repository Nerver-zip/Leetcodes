class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q; // {student}
        
        for (int student : students)
            q.push(student);
        
        int i = 0, count = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            
            if(front != sandwiches[i]){
                ++count;
                q.push(front);

                if(count == q.size())
                    return count;
            }
            else{
                ++i;
                count = 0;
            }
        }


        return 0;
    }
};