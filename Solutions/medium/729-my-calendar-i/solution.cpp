class MyCalendar {
private:
    std::vector<std::pair<int,int>> bookingSet;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
      std::pair<int,int> newBook = {startTime,endTime};

    if(!bookingSet.empty()){

        for(auto book : bookingSet){
            if(newBook.first < book.first){
                if(newBook.second > book.first)
                    return false;         
            }
            else if(newBook.second > book.second){
                if(newBook.first < book.second)
                    return false;  
            }
            else if (newBook.second <= book.second && newBook.first >= book.first)
                return false;
        }
      }
        bookingSet.push_back(newBook);
        return true;
    }
};
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */