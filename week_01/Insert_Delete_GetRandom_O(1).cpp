class RandomizedSet {
public:
    unordered_map<int, int> valIdxMap;
    vector<int> store;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (valIdxMap.count(val) != 0)  return false;
        
        valIdxMap[val] = store.size();
        store.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (valIdxMap.count(val) == 0) return false;

        int targetIdx = valIdxMap[val];
        int lastIdx = store.size() - 1;
        int lastElem = store[lastIdx];

        swap(store[targetIdx], store[lastIdx]);
        store.pop_back();
        valIdxMap[lastElem] = targetIdx;
        valIdxMap.erase(val);

        return true;
    }
    
    int getRandom() {
        int rndIdx = rand() % store.size();
        return store[rndIdx];
    }
};
