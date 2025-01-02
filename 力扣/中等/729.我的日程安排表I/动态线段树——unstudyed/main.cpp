class MyCalendar {
//   使用动态线段树来存储已经被预定的区间，用懒标记lazy标记区间已经被预定，用树来记录区间[l,r]是否存在标记为1的元素。
    unorder_set<int> tree,lazy;
public:
    MyCalendar() {
        
    }
    bool query(int start,int end,int l,int r,int idx){
        if(r<start||end<l){
            return false;
        }
        //如果该区间已经被预定，则直接返回
        if(lazy.count(idx)){
            return true;
        }
        if(start<=l && r<=end){
            return tree.count(idx);
        }
        int mid = (l+r) >> 1;
        return query(start,end,l,mid, 2*idx) ||
                query(start,end,mid+1,r,2*idx+1);
    }
    void update(int start,int end,int l,int r,int idx){
        if(r<start||end<l){
            return;
        }
        if(start<=l && r<=end){
            tree.emplace(idx);
            lazy.emplace(idx);
        }else{
            int mid = (l+r) >> 1;
            update(start,end,l,mid,2*idx);
            update(start,end,mid+1,r,2*idx+1);
            tree.emplace(idx);
            if(lazy.count(2*idx)&&lazy.count(2*idx+1)){
                lazy.emplace(idx);
            }
        }

    }
    bool book(int start, int end) {
        if(query(start,end-1,0,1e9,1)){
            return false;
        }
        update(start,end-1,0,1e9,1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */