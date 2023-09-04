
class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int, int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!= mp.end()) return false;

        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()) return false;

        int idx = mp[val];
        int lastelement = v.back();
        v.back() = val;

        v[idx] =lastelement;
        mp[lastelement] = idx;

        v.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int Random = rand()%n;
        return v[Random];
    }
};
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~only 1 DS used~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class RandomizedSet {
public:
    unordered_set<int> s;
    int i;
    RandomizedSet() {
        i = 0;
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()){
            return false;
        }
        s.insert(val);
        i++;
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end()){
            return false;
        }
        s.erase(val);
        i--;
        return true;
    }
    
    int getRandom() {
        int r = rand()%i;
       for(auto x: s){
           if(r==0){
               return x;
           }
           r--;
       }
       return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
