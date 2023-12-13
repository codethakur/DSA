// design the class in the most optimal way

class LRUCache
{
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mymap;

    void updateRecent(int key, int value)
    {
        cache.erase(mymap[key]);
        cache.push_front(make_pair(key, value));
        mymap[key] = cache.begin();
    }

    int capacity;

public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        this->capacity = cap;
    }

    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if (mymap.find(key) != mymap.end())
        {
            updateRecent(key, (*mymap[key]).second);
            return (*mymap[key]).second; 
        }
        return -1;
    }

    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if (mymap.find(key) != mymap.end())
        {
            updateRecent(key, value);
        }
        else
        {
            if (mymap.size() >= capacity)
            {
                mymap.erase(cache.back().first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            mymap[key] = cache.begin();
        }
    }
};
