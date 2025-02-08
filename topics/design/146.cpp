#include <iostream>
#include <vector>
#include <unordered_map>

class LRUCache
{
public:
    struct ListNode
    {
        int key, val;
        ListNode *next, *prev;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {};
        ListNode(int _key, int _val) : key(_key), val(_val), next(nullptr), prev(nullptr) {};
        ListNode(int _key, int _val, ListNode *_next, ListNode *_prev) : key(_key), val(_val), next(_next), prev(_prev) {};
    };

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;

        dummy_head = new ListNode();
        dummy_tail = new ListNode();

        dummy_head->next = dummy_tail;
        dummy_tail->prev = dummy_head;

        map.clear();
    }

    int get(int key)
    {
        if (map.find(key) != map.end())
        {
            int value = map[key]->val;
            remove(key);
            add(key, value);

            return value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            remove(key);
            add(key, value);

            return;
        }

        size++;
        add(key, value);

        while (size > capacity)
        {
            remove(dummy_tail->prev->key);
            size--;
        }
    }

    void add(int key, int value)
    {
        ListNode *head = new ListNode(key, value);
        ListNode *old_head = dummy_head->next;  

        head->prev = dummy_head;
        dummy_head->next = head;

        head->next = old_head;
        old_head->prev = head;

        map[key] = head;
    }

    void remove(int key)
    {
        ListNode *node = map[key];

        node->prev->next = node->next;
        node->next->prev = node->prev;

        map.erase(key);
        delete (node);
    }

private:
    int capacity, size;
    ListNode *dummy_head, *dummy_tail;
    std::unordered_map<int, ListNode *> map;
};

int main()
{
    LRUCache cache(1);
    cache.put(2, 1);
    std::cout << cache.get(2) << std::endl;
    cache.put(3, 2);
    std::cout << cache.get(2) << std::endl;
    std::cout << cache.get(3) << std::endl;
}