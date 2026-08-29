class ProductOfNumbers {
    private:
        std::vector<int> products;
        int size = 0;
        int indexZero;
    public:
        ProductOfNumbers() {
            products.push_back(1);
        }
        
        void add(int num) {
    
            if (num == 0)
            {
                products.push_back(1);
                size++;
                indexZero = size;
                return;
            }
            products.push_back(products[size] * num);
            size++;
            return;
        }
        
        int getProduct(int k) {
            return size - k < indexZero ? 0 : products[size] / products[size - k];
        }
    };