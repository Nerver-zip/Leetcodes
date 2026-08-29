class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        doneFoo = false;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
        	doneFoo.wait(true);
            printFoo();
            doneFoo.store(true);
            doneFoo.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            doneFoo.wait(false);
        	printBar();
            doneFoo.store(false);
            doneFoo.notify_one();
        }
    }
private:
    std::atomic<bool> doneFoo;
};