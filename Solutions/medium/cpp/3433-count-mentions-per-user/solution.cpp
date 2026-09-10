class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> onlineBy(numberOfUsers, 0), mentions(numberOfUsers, 0);

        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            int timeA = stoi(a[1]), timeB = stoi(b[1]);
            
            //untie with type, OFFLINE will be processed first
            return timeA == timeB ? a[0] > b[0] : timeA < timeB;
        });

        
        for (const auto& event : events) {
            const auto& type = event[0];
            int timestamp = stoi(event[1]);
            const auto& ids = event[2];

            if(type == "MESSAGE"){
                if (ids == "ALL") {
                    for (int user = 0; user < numberOfUsers; ++user) {
                        if(onlineBy[user] < timestamp)
                            onlineBy[user] = timestamp;
                        ++mentions[user];
                    }             
                }
                else if(ids == "HERE"){
                    for (int user = 0; user < numberOfUsers; ++user) {
                        if(onlineBy[user] <= timestamp){
                            ++mentions[user];
                            onlineBy[user] = timestamp;
                        }
                    }
                }
                else {
                    istringstream iss(ids);

                    string token;
                    while (iss >> token) {
                        int id = (stoi(token.substr(2))); // remove "id"
                        cout << id << "\n"; 
                        if(onlineBy[id] < timestamp)
                            onlineBy[id] = timestamp;
                        ++mentions[id];
                    }
                }
            }
            else { //Offline event
                int id = stoi(ids);
                onlineBy[id] = timestamp + 60;
            }
        }
        return mentions;
    }
};