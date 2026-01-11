#include "lru_cache.h"

LRUCache::LRUCache(int capacity) : capacity_(capacity) {}

void LRUCache::moveToFront(std::list<std::pair<int, int>>::iterator it) {
    if (it != cache_.begin()) {
        cache_.splice(cache_.begin(), cache_, it);
    }
}

int LRUCache::get(int key) {
    auto it = map_.find(key);
    if (it == map_.end()) {
        return -1;
    }
    
    // Move to front (most recently used)
    moveToFront(it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = map_.find(key);
    
    if (it != map_.end()) {
        // Key exists, update value and move to front
        it->second->second = value;
        moveToFront(it->second);
    } else {
        // Key doesn't exist
        if (static_cast<int>(cache_.size()) >= capacity_) {
            // Evict least recently used (back of list)
            int evictKey = cache_.back().first;
            cache_.pop_back();
            map_.erase(evictKey);
        }
        
        // Add new entry to front
        cache_.push_front({key, value});
        map_[key] = cache_.begin();
    }
}
