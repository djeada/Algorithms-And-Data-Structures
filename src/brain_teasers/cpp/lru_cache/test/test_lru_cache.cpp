#include "lru_cache.h"
#include "gtest/gtest.h"

TEST(LRUCacheTest, BasicOperations) {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    EXPECT_EQ(cache.get(1), 1);    // returns 1
    
    cache.put(3, 3);               // evicts key 2
    EXPECT_EQ(cache.get(2), -1);   // returns -1 (not found)
    
    cache.put(4, 4);               // evicts key 1
    EXPECT_EQ(cache.get(1), -1);   // returns -1 (not found)
    EXPECT_EQ(cache.get(3), 3);    // returns 3
    EXPECT_EQ(cache.get(4), 4);    // returns 4
}

TEST(LRUCacheTest, UpdateExistingKey) {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(1, 10);              // update value
    EXPECT_EQ(cache.get(1), 10);   // returns updated value
    EXPECT_EQ(cache.get(2), 2);    // key 2 still exists
}

TEST(LRUCacheTest, GetMakesRecent) {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);                  // access key 1, making it most recent
    cache.put(3, 3);               // should evict key 2, not key 1
    
    EXPECT_EQ(cache.get(1), 1);    // key 1 still exists
    EXPECT_EQ(cache.get(2), -1);   // key 2 was evicted
    EXPECT_EQ(cache.get(3), 3);    // key 3 exists
}

TEST(LRUCacheTest, SingleCapacity) {
    LRUCache cache(1);
    
    cache.put(1, 1);
    EXPECT_EQ(cache.get(1), 1);
    
    cache.put(2, 2);               // evicts key 1
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(2), 2);
}

TEST(LRUCacheTest, GetNonExistentKey) {
    LRUCache cache(2);
    EXPECT_EQ(cache.get(1), -1);
    EXPECT_EQ(cache.get(100), -1);
}

TEST(LRUCacheTest, PutMakesRecent) {
    LRUCache cache(2);
    
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(1, 100);             // update makes key 1 most recent
    cache.put(3, 3);               // should evict key 2
    
    EXPECT_EQ(cache.get(1), 100);
    EXPECT_EQ(cache.get(2), -1);
    EXPECT_EQ(cache.get(3), 3);
}
