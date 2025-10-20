#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

class LRUCache {
private:
    deque<string> cache;
    int capacity;

public:
    LRUCache(int size) : capacity(size) {}

    void access(const string& key) {
        // Ищем элемент в кэше
        auto it = find(cache.begin(), cache.end(), key);

        if (it != cache.end()) {
            // Элемент найден - перемещаем в начало
            cache.erase(it);
            cache.push_front(key);
        } else {
            // Элемент не найден
            if (cache.size() >= capacity) {
                // Удаляем самый старый элемент
                cache.pop_back();
            }
            cache.push_front(key);
        }

        // Выводим текущее состояние кэша
        printState();
    }

    void printState() {
        for (const string& item : cache) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(3);

    cout << "LRU Cache simulation (size=3):" << endl;
    cout << "Access sequence: A B C A D" << endl << endl;

    cache.access("A");
    cache.access("B");
    cache.access("C");
    cache.access("A");
    cache.access("D");

    return 0;
}
