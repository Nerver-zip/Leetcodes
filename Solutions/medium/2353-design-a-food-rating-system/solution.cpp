struct Compare {
    bool operator()(const shared_ptr<pair<int,string>>& a, const shared_ptr<pair<int,string>>& b) const {
        return a.get()->first == b.get()->first ? a.get()->second < b.get()->second : a.get()->first > b.get()->first;
    }
};

class FoodRatings {
private:
    set<shared_ptr<pair<int, string>>, Compare> foodSet; //Shared set of pairs of {rtg, food}
    unordered_map<string, shared_ptr<pair<int, string>>> foodMap; //Food -> pair of {rtg, food}
    unordered_map<string, set<shared_ptr<pair<int, string>>, Compare>> cuisineMap;//Cuisine -> set of {rtg, food}
    unordered_map<string, string> foodToCuisine;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i){
            
            string food = foods[i], cuisine = cuisines[i];
            
            auto sharedPair = make_shared<pair<int,string>>(ratings[i], food);
        
            foodSet.insert(sharedPair);
            
            foodMap[sharedPair->second] = sharedPair; 
            cuisineMap[cuisine].insert(sharedPair);
            foodToCuisine[food] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        auto ptr = foodMap[food];
        string cuisine = foodToCuisine[food];
        
        foodSet.erase(ptr);
        cuisineMap[cuisine].erase(ptr);

        ptr->first = newRating;

        foodSet.insert(ptr);
        cuisineMap[cuisine].insert(ptr);
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].cbegin()->get()->second;    
    }
};