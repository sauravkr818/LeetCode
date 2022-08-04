class MyCalendar {
public:
    
    int i = 0;
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto place = st.lower_bound({start,end});
        if(place != st.end() && (place->first<end) || place != st.begin() && (prev(place)->second>start)) return false;
        st.insert({start,end});
        return true;
    }
    };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */