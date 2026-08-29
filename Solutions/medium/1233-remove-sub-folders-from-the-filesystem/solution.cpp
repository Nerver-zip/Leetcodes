class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        auto isSubdirectory = [&](const string& parentFolder, const string& subFolder){
            int i = 0;
            for (i; i < parentFolder.size(); ++i) {
                if(parentFolder[i] != subFolder[i])
                    return false;
            }
            return subFolder.size() > i && subFolder[i] != '/' ? false : true;
        }; 

        sort(folder.begin(),folder.end());
        vector<string> ans;   
        string curr = folder[0];
        ans.push_back(curr);
        for (int i = 1; i < folder.size(); ++i) {
            if(!isSubdirectory(curr, folder[i])){
                curr = folder[i];
                ans.push_back(curr);
            }
        }
        return ans;
    }
};