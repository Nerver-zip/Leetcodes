class DiningPhilosophers {
private:
    mutex forks[5];
public:
    DiningPhilosophers() {
       
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;

        unique_lock<mutex> leftLock(forks[left], defer_lock);
        unique_lock<mutex> rightLock(forks[right], defer_lock);

        if(philosopher % 2 == 0){
            leftLock.lock();
            rightLock.lock();
            pickLeftFork();
            pickRightFork();
        }
        else{
            rightLock.lock();
            leftLock.lock();
            pickLeftFork();
            pickRightFork();
        }
    
        eat();
        putLeftFork();
        putRightFork();
    }
};