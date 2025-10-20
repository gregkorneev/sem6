#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class CommitGraph {
private:
    unordered_map<string, vector<string>> graph;

public:
    void addCommit(const string& commit, const vector<string>& parents) {
        graph[commit] = parents;
    }

    void dfsTraversal(const string& startCommit) {
        stack<pair<string, int>> st; // <commit, depth>
        unordered_map<string, bool> visited;

        st.push({startCommit, 0});

        while (!st.empty()) {
            auto current = st.top();
            st.pop();

            string commit = current.first;
            int depth = current.second;

            if (visited[commit]) continue;
            visited[commit] = true;

            // Выводим коммит с отступами
            for (int i = 0; i < depth; i++) {
                cout << "  ";
            }
            cout << "Commit: " << commit << endl;

            // Добавляем родителей в стек (в обратном порядке для правильного обхода)
            const vector<string>& parents = graph[commit];
            for (auto it = parents.rbegin(); it != parents.rend(); ++it) {
                if (!visited[*it]) {
                    st.push({*it, depth + 1});
                }
            }
        }
    }
};

int main() {
    CommitGraph git;

    // Добавляем коммиты и их родителей
    git.addCommit("C1", {});
    git.addCommit("C2", {"C1"});
    git.addCommit("C3", {"C1"});
    git.addCommit("C4", {"C2", "C3"});

    cout << "DFS traversal starting from C4:" << endl;
    git.dfsTraversal("C4");

    return 0;
}
