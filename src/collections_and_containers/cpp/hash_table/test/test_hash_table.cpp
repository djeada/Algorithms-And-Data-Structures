#include "hash_table.h"
#include "gtest/gtest.h"

TEST(HashTableTest, SimpleConstructor) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  EXPECT_EQ(hash_table.size(), 0);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  EXPECT_EQ(hash_table2.size(), 0);
}

TEST(HashTableTest, Add) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  EXPECT_EQ(hash_table.size(), 1);
  hash_table.add(2, 1);
  EXPECT_EQ(hash_table.size(), 2);
  hash_table.add(3, 1);
  EXPECT_EQ(hash_table.size(), 3);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  EXPECT_EQ(hash_table2.size(), 1);
  hash_table2.add("b", 1);
  EXPECT_EQ(hash_table2.size(), 2);
  hash_table2.add("c", 1);
  EXPECT_EQ(hash_table2.size(), 3);
}

TEST(HashTableTest, Get) {

  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_EQ(hash_table.get(1), 1);
  EXPECT_EQ(hash_table.get(2), 4);
  EXPECT_EQ(hash_table.get(3), 9);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);

  EXPECT_EQ(hash_table2.get("a"), 1);
  EXPECT_EQ(hash_table2.get("b"), 4);
  EXPECT_EQ(hash_table2.get("c"), 9);
}

TEST(HashTableTest, GetException) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_THROW(hash_table.get(4), std::invalid_argument);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);

  EXPECT_THROW(hash_table2.get("d"), std::invalid_argument);
}

TEST(HashTableTest, Contains) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_TRUE(hash_table.contains(1));
  EXPECT_TRUE(hash_table.contains(2));
  EXPECT_TRUE(hash_table.contains(3));
  EXPECT_FALSE(hash_table.contains(4));

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });
}

TEST(HashTableTest, Remove) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  hash_table.remove(1);
  EXPECT_EQ(hash_table.size(), 2);
  hash_table.remove(2);
  EXPECT_EQ(hash_table.size(), 1);
  hash_table.remove(3);
  EXPECT_EQ(hash_table.size(), 0);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);

  hash_table2.remove("a");
  EXPECT_EQ(hash_table2.size(), 2);
}

TEST(HashTableTest, RemoveException) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_THROW(hash_table.remove(4), std::invalid_argument);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);
}

TEST(HashTableTest, AcessOperator) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_EQ(hash_table[1], 1);
  EXPECT_EQ(hash_table[2], 4);
  EXPECT_EQ(hash_table[3], 9);

  hash_table[1] = 2;
  hash_table[2] = 5;
  hash_table[3] = 10;

  EXPECT_EQ(hash_table[1], 2);
  EXPECT_EQ(hash_table[2], 5);
  EXPECT_EQ(hash_table[3], 10);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);

  EXPECT_EQ(hash_table2["a"], 1);
  EXPECT_EQ(hash_table2["b"], 4);
  EXPECT_EQ(hash_table2["c"], 9);

  hash_table2["a"] = 2;
  hash_table2["b"] = 5;
  hash_table2["c"] = 10;
}

TEST(HashTableTest, AcessOperatorException) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  EXPECT_THROW(hash_table[4], std::invalid_argument);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);
  EXPECT_THROW(hash_table2["d"], std::invalid_argument);
}

TEST(HashTableTest, Clear) {
  // int key
  HashTable<int, int> hash_table([](int key) { return key; });
  hash_table.add(1, 1);
  hash_table.add(2, 4);
  hash_table.add(3, 9);
  hash_table.clear();
  EXPECT_EQ(hash_table.size(), 0);

  // string key
  HashTable<std::string, int> hash_table2([](std::string key) {
    int hash = 0;
    for (int i = 0; i < key.length(); i++) {
      hash += key[i];
    }
    return hash;
  });

  hash_table2.add("a", 1);
  hash_table2.add("b", 4);
  hash_table2.add("c", 9);
  hash_table2.clear();
  EXPECT_EQ(hash_table2.size(), 0);
}
