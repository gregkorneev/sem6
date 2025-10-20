#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Request {
    int id;
    string name;

    Request(int i, const string& n) : id(i), name(n) {}
};

int main() {
    queue<Request> requests;

    // Добавляем запросы в очередь
    requests.emplace(1, "Login");
    requests.emplace(2, "QueryData");
    requests.emplace(3, "Logout");

    cout << "Processing requests:" << endl;

    // Обрабатываем запросы в порядке FIFO
    while (!requests.empty()) {
        const Request& current = requests.front();
        cout << "Processing: " << current.name
             << " (ID: " << current.id << ")" << endl;
        requests.pop();
    }

    return 0;
}
