class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        shops.resize(n);
        for(const auto& entry : entries){
            int shop = entry[0], movie = entry[1], price = entry[2];
            pair<int,int> p = {price, shop};

            unrentedMovieMap[movie].insert(p);
            shops[shop].insert({movie, p}); 
        }
    }
    
    vector<int> search(int movie) {
        const auto& list = unrentedMovieMap[movie];
        
        vector<int> res;
        res.reserve(5);

        for(const auto& [price, shop] : list){
            if(res.size() == 5)
                break;
            res.push_back(shop);
        }

        return res;
    }
    
    void rent(int shop, int movie) {
        auto& unrentedList = unrentedMovieMap[movie];
        
        auto it = shops[shop].find(movie);
        
        if(it == shops[shop].end())
            return;

        pair<int,int> p = it->second;
         
        unrentedList.erase(p);
        
        auto& rentedList = rentedMovieMap[movie];
        rentedList.insert(p);
        rentedMovies.insert({p.first, p.second, movie});
    }
    
    void drop(int shop, int movie) {
        auto& rentedList = rentedMovieMap[movie];

        auto it = shops[shop].find(movie);

        if(it == shops[shop].end())
            return;

        pair<int,int> p = it->second;

        rentedList.erase(p);
        rentedMovies.erase({p.first, p.second, movie});

        auto& unrentedList = unrentedMovieMap[movie];
        unrentedList.insert(p);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        res.reserve(5);

        for(const auto& [price, shop, movie] : rentedMovies){
            if(res.size() == 5)
                break;
            res.push_back({shop, movie});
        }

        return res;
    }
private:
    
    // {price, shop, movie}
    set<array<int, 3>> rentedMovies;
    // movie -> set{price, shop}
    unordered_map<int, set<pair<int,int>>> rentedMovieMap;
    unordered_map<int, set<pair<int,int>>> unrentedMovieMap;
    
    // shop -> map{movie -> pair{price, shop}}
    vector<unordered_map<int, pair<int,int>>> shops;
};