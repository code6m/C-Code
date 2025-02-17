 class MyCalendar {
    set<pair<int,int>> booked;//set会自动排序，如果第一个int相同会根据第二个来排序
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = booked.lower_bound({end,0});  //查找到第一个第一项不小于end的元素，返回它的迭代器，先比较第一个元素，如果不同再比较第二个元素
        if(it == booked.begin() || (--it)->second<=start){
            booked.emplace(start,end);//在集合中适当的位置插入元素
            return true;
            //这里booked.lower_bound的参数需要花括号而emplace的参数就不需要花括号要注意.
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */