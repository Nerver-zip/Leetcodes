class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) { 
        auto myLogs = parse(logs);
        vector<int> functions(n, 0);
        stack<int> st; //id 
        int prev = 0; 
        for (const auto& [id, time, type] : myLogs) {

            if (type == START) {
                if (!st.empty())
                    functions[st.top()] += time - prev;
                st.push(id);
                prev = time;
            } else { // END
                functions[st.top()] += time - prev + 1;
                st.pop();
                prev = time + 1;
            }
        }
        return functions;
    }

private:
    enum status {
        START,
        END
    }; 

    vector<array<int, 3>> parse(const vector<string>& logs){
        vector<array<int, 3>> parsed;
        parsed.reserve(logs.size());
         
        for (const auto& log : logs) {
            string label, time;
            int type = 0; //0 start, 1 end
            bool seenDelim = false;
            
            for (char c : log) {
                if(c == 's'){
                    type = START;
                    continue;
                }
                else if(c == 'e'){
                    type = END;
                    continue;
                }
                else if(c < '0' || c > '9'){
                    seenDelim = true;
                    continue;
                }

                if(!seenDelim)
                    label += c;
                else
                    time += c;
            }
            int l = atoi(label.c_str()), t = atoi(time.c_str());
            parsed.push_back({l,t,type});
        }

        return parsed;    
    }
};
