class BrowserHistory {
private:
    string homepage;
    vector<string> webPages;
    int maxIndex;
    int currIndex;
public:
    BrowserHistory(string homepage) {
        this->homepage = homepage;
        webPages.push_back(homepage);
        maxIndex = 0;
        currIndex = 0;
    }
    
    void visit(string url) {
        if (currIndex == maxIndex) 
        {
            webPages.push_back(url);
            maxIndex++;
            currIndex++;
            return;
        }
        if (currIndex < maxIndex) //Clear forward
        {
            for (maxIndex; maxIndex > currIndex; maxIndex--)
            {
                webPages.pop_back();
            }
            maxIndex = currIndex;
            webPages.push_back(url);
            maxIndex++;
            currIndex++;
            return;
        }
    }
    
    string back(int steps) {
        currIndex = currIndex - steps;
        if (currIndex < 0)
            currIndex = 0;
        return this->webPages[currIndex];
    }
    
    string forward(int steps) {
        currIndex = currIndex + steps;
        if (currIndex >= maxIndex)
            currIndex = maxIndex;
        return this->webPages[currIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */