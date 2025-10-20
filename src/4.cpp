#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class TopologicalSorter {
private:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;

public:
    void addDependency(const string& from, const string& to) {
        graph[from].push_back(to);
    }

    void calculateInDegree() {
        // Инициализируем счетчики
        for (const auto& pair : graph) {
            inDegree[pair.first]; // Гарантируем существование
            for (const string& neighbor : pair.second) {
                inDegree[neighbor]++;
            }
        }
    }

    vector<string> topologicalSort() {
        calculateInDegree();
        vector<string> result;
        queue<string> q;

        // Добавляем вершины с нулевой входящей степенью
        for (const auto& pair : inDegree) {
            if (pair.second == 0) {
                q.push(pair.first);
            }
        }

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            result.push_back(current);

            for (const string& neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Проверяем наличие цикла
        if (result.size() != inDegree.size()) {
            return vector<string>(); // Пустой вектор означает цикл
        }

        return result;
    }
};

int main() {
    TopologicalSorter sorter;

    // Добавляем зависимости: A -> B означает "A зависит от B"
    sorter.addDependency("A", "B");
    sorter.addDependency("B", "C");
    sorter.addDependency("D", "C");

    vector<string> sorted = sorter.topologicalSort();

    if (sorted.empty()) {
        cout << "Cycle detected! Cannot perform topological sort." << endl;
    } else {
        cout << "Topological order: ";
        for (const string& item : sorted) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
