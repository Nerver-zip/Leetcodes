class Robot {
public:
    Robot(int width, int height) {
        x = 0;
        y = 0;
        MAX_WIDTH = width;
        MAX_HEIGHT = height;
        direction = EAST;
    }
    
    void step(int num) {
        if (MAX_WIDTH == 1 || MAX_HEIGHT == 1) return;

        int perimeter = 2 * (MAX_WIDTH + MAX_HEIGHT) - 4;

        int pos = 0;

        if (y == 0) {
            pos = x;
        } else if (x == MAX_WIDTH - 1) {
            pos = (MAX_WIDTH - 1) + y;
        } else if (y == MAX_HEIGHT - 1) {
            pos = (MAX_WIDTH - 1) + (MAX_HEIGHT - 1) + (MAX_WIDTH - 1 - x);
        } else {
            pos = (MAX_WIDTH - 1) + (MAX_HEIGHT - 1) + (MAX_WIDTH - 1) + (MAX_HEIGHT - 1 - y);
        }

        int newPos = (pos + num) % perimeter;
        int lastPos = (pos + num - 1 + perimeter) % perimeter;

        // mapear posição
        if (newPos < MAX_WIDTH - 1) {
            x = newPos;
            y = 0;
        } else if (newPos < (MAX_WIDTH - 1) + (MAX_HEIGHT - 1)) {
            x = MAX_WIDTH - 1;
            y = newPos - (MAX_WIDTH - 1);
        } else if (newPos < (MAX_WIDTH - 1) * 2 + (MAX_HEIGHT - 1)) {
            x = MAX_WIDTH - 1 - (newPos - ((MAX_WIDTH - 1) + (MAX_HEIGHT - 1)));
            y = MAX_HEIGHT - 1;
        } else {
            x = 0;
            y = MAX_HEIGHT - 1 - (newPos - ((MAX_WIDTH - 1) * 2 + (MAX_HEIGHT - 1)));
        }

        if (lastPos < MAX_WIDTH - 1) {
            direction = EAST;
        } else if (lastPos < (MAX_WIDTH - 1) + (MAX_HEIGHT - 1)) {
            direction = NORTH;
        } else if (lastPos < (MAX_WIDTH - 1) * 2 + (MAX_HEIGHT - 1)) {
            direction = WEST;
        } else {
            direction = SOUTH;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return cardinals[direction]; 
    }

private:
    int x,y;
    int MAX_WIDTH, MAX_HEIGHT;
    int8_t direction;
    
    enum Directions {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    static constexpr array<string, 4> cardinals = {
        "North",
        "East",
        "South",
        "West"
    };

    bool isOutOfBounds() const {
        return x < 0 || x == MAX_WIDTH || y < 0 || y == MAX_HEIGHT;
    }
};