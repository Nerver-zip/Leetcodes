using ll = long long;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        Robot robot(std::move(obstacles));
        
        int ans = 0;
        for(int x : commands){
            if(x < 0)
                robot.changeDirection(x);
            else {
                robot.move(x);
                ans = max(ans, robot.distFromOrigin());
                cout << robot.x << "," << robot.y << "\n";
            }
        }

        return ans;
    }

private:
    enum Dir {
        NORTH,
        EAST,
        WEST,
        SOUTH
    };
   
    // x | y
    static ll pack(int x, int y){
        return ((unsigned long long)x << 32) | (unsigned int)y;
    }
    
    static int unpack(ll val, bool x = true){
        if(x)
            return val >> 32;
        return (int)(val & 0xFFFFFFFF);
    }

    struct Robot {
        int x;
        int y;

        unordered_set<ll> obstacles;
        uint8_t direction;
        
        Robot(vector<vector<int>>&& obs) : x(0), y(0), direction(NORTH) {
            for(const auto& o : obs)
                obstacles.insert(pack(o[0], o[1]));
        }

        void move(int dist){
            while(direction == NORTH && dist){
                ++y;
                --dist;

                if(obstacles.count(pack(x, y))){
                    --y;
                    return;
                }
            }
            while(direction == SOUTH && dist){
                --y;
                --dist;

                if(obstacles.count(pack(x, y))){
                    ++y;
                    return;
                }
            }
            while(direction == WEST && dist){
                --x;
                --dist;

                if(obstacles.count(pack(x, y))){
                    ++x;
                    return;
                }
            }
            while(direction == EAST && dist){
                ++x;
                --dist;

                if(obstacles.count(pack(x, y))){
                    --x;
                    return;
                }
            }
        }

        void changeDirection(int dir){
            if(direction == NORTH){
                if(dir == -2)
                    direction = WEST;
                else
                    direction = EAST;
            }
            else if(direction == WEST){
                if(dir == -2)
                    direction = SOUTH;
                else
                    direction = NORTH;
            }
            else if(direction == EAST){
                if(dir == -2)
                    direction = NORTH;
                else
                    direction = SOUTH;
            }
            else {
                if(dir == -2)
                    direction = EAST;
                else
                    direction = WEST;
            }
        }

        // Euclidian dist from origin squared
        int distFromOrigin(){
            return x * x + y * y;
        }
    };

};