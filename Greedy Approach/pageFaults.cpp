class LRUCache {
public:
    std::unordered_map<int, int> mp;
    std::unordered_map<int, std::list<int>::iterator> address;
    std::list<int> l;
    int cap;
    int size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        auto it = address[key];
        l.erase(it);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();

        return mp[key];
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            size--;
        }

        if (size == cap) {
            int lastKey = l.back();
            l.pop_back();
            address.erase(lastKey);
            mp.erase(lastKey);
            size--;
        }

        size++;
        l.push_front(key);
        address[key] = l.begin();
        mp[key] = value;
    }
};

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        LRUCache lru(C);
        int pageFaults = 0;

        for (int i = 0; i < N; i++) {
            if (lru.get(pages[i]) == -1) {
                lru.put(pages[i], i);
                pageFaults++;
            }
        }

        return pageFaults;
    }
};
