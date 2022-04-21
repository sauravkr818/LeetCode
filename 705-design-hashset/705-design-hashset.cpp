class MyHashSet {
public:
    
    vector<int>arr;
    MyHashSet(): arr(1e6+1,-1) {}
    
    void add(int key) {
        arr[key] = key;
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
    
    bool contains(int key) {
        if(arr[key] == -1) return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */