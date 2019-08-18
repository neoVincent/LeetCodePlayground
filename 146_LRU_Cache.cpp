146_LRU_Cache.cpp
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = m_.find(key);
        // If key does not exist
        if (it == m_.cend()) return -1;
 
        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = m_.find(key);
        
        // Key already exists
        if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry
        if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
        }
        
        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> m_;
};