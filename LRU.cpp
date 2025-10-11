#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

class LRUCache {
    int capacity;
    std::stack<int> stk;
    std::unordered_map<int, int> cache; // key -> value
    std::unordered_map<int, bool> inStack; // key -> in stack

    void moveToTop(int key) {
        std::vector<int> temp;
        // Remove all elements above the key
        while (!stk.empty() && stk.top() != key) {
            temp.push_back(stk.top());
            inStack[stk.top()] = false;
            stk.pop();
        }
        // Remove the key itself
        if (!stk.empty() && stk.top() == key) {
            stk.pop();
        }
        // Push the key to top
        stk.push(key);
        inStack[key] = true;
        // Push back the removed elements
        for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
            stk.push(*it);
            inStack[*it] = true;
        }
    }

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        moveToTop(key);
        return cache[key];
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            moveToTop(key);
            return;
        }
        if (cache.size() == capacity) {
            // Remove least recently used (bottom of stack)
            std::vector<int> temp;
            while (stk.size() > 1) {
                temp.push_back(stk.top());
                inStack[stk.top()] = false;
                stk.pop();
            }
            int lru = stk.top();
            stk.pop();
            inStack[lru] = false;
            cache.erase(lru);
            // Push back the removed elements
            for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                stk.push(*it);
                inStack[*it] = true;
            }
        }
        cache[key] = value;
        stk.push(key);
        inStack[key] = true;
    }
};

// Example usage
int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    std::cout << lru.get(1) << std::endl; // returns 1
    lru.put(3, 3); // evicts key 2
    std::cout << lru.get(2) << std::endl; // returns -1 (not found)
    lru.put(4, 4); // evicts key 1
    std::cout << lru.get(1) << std::endl; // returns -1 (not found)
    std::cout << lru.get(3) << std::endl; // returns 3
    std::cout << lru.get(4) << std::endl; // returns 4
    return 0;
}