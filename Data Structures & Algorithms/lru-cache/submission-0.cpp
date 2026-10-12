class LRUCache {
public:
    int cap;
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int,int>>::iterator> map;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        lst.splice(lst.begin(), lst, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.count(key))
        {
            map[key]->second = value;
            lst.splice(lst.begin(), lst, map[key]);
            return;
        }
        if ((int) lst.size() == cap)
        {
            int oldKey = lst.back().first;
            lst.pop_back();
            map.erase(oldKey);
        }
        lst.push_front({key, value});
        map[key] = lst.begin();
    }
};
