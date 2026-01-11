#pragma once

#include <list>
#include <unordered_map>

/**
 * LRU (Least Recently Used) Cache implementation.
 * 
 * The cache has a fixed capacity. When the cache is full and a new key-value pair
 * is added, the least recently used pair is evicted to make room for the new one.
 */
class LRUCache {
public:
    /**
     * Initialize the LRU cache with a positive capacity.
     * @param capacity Maximum number of key-value pairs the cache can hold
     */
    explicit LRUCache(int capacity);
    
    /**
     * Return the value of the key if it exists, otherwise return -1.
     * Accessing a key makes it the most recently used.
     * @param key Key to look up
     * @return Value associated with the key, or -1 if not found
     */
    int get(int key);
    
    /**
     * Update the value of the key if it exists. Otherwise, add the key-value pair.
     * If the cache is at capacity, evict the least recently used key.
     * @param key Key to insert or update
     * @param value Value to associate with the key
     */
    void put(int key, int value);

private:
    int capacity_;
    std::list<std::pair<int, int>> cache_; // front = most recent, back = least recent
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map_;
    
    void moveToFront(std::list<std::pair<int, int>>::iterator it);
};
