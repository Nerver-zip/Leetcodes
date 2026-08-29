class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        constexpr double eps = 1e-5;        

        auto check = [&](double mid){
            double top_area = 0, bottom_area = 0;

            for (int i = 0; i < squares.size(); ++i) {
                double y = squares[i][1], l = squares[i][2];
                
                // Branchless version
                double h = max(0.0, min(mid - y, l));

                bottom_area += h * l;
                top_area += (l - h) * l;
            
                /*
                 *  if(mid >= y + l){
                        bottom_area += l * l;
                    }
                    else if(mid <= y){
                        top_area += l * l;
                    }
                    else{
                        top_area += (y + l - mid) * l;
                        bottom_area += (mid - y) * l;
                    }
                 * */
    
            }
            return bottom_area - top_area >= 0;
            //we try to find the minimum y such that bottom_area >= top_area
            //so if that's true we decrease y
        };

        double left = 0, right = 0;

        for (const auto& square : squares) {
            int y = square[1], l = square[2];
            
            if(y < left)
                left = y;
            if(y + l > right)
                right = y + l; 
        }
        
        while (right - left > eps) {
            double mid = left + (right - left)/2.0;
            if(check(mid)){
                right = mid; // reduce y if true 
            }
            else
                left = mid;
            }

        return (right + left)/2;
    }
};