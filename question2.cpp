//Oliver Lin
//1123511
//2024/11/28

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 定義任務的結構體，包含任務名稱和優先級
struct Task {
    string name;    // 任務名稱
    int priority;   // 任務的優先級
    
    // 構造函數，用於初始化任務
    Task(string n, int p) : name(n), priority(p) {}
    
    // 重載 `<` 運算符，定義基於優先級的最大堆 (Max Heap)
    bool operator<(const Task& other) const {
        return priority < other.priority;  // 優先級高的排在前面
    }
};

int main() {
    int N;  // 表示操作的數量
    cin >> N;  // 輸入操作數量

    priority_queue<Task> pq;  // 最大堆，用於存儲任務
    vector<string> results;  // 儲存每個 `GET` 操作的結果

    // 處理每一個操作
    for (int i = 0; i < N; ++i) {
        string operation;  // 操作類型 (ADD 或 GET)
        cin >> operation;

        if (operation == "ADD") {
            // 如果是 ADD 操作，讀取任務名稱和優先級
            string task_name;
            int priority;
            cin >> task_name >> priority;

            // 將任務加入優先隊列 (按照優先級排序)
            pq.push(Task(task_name, priority));
        } else if (operation == "GET") {
            // 如果是 GET 操作
            if (!pq.empty()) {
                // 如果隊列不為空，獲取並移除優先級最高的任務
                Task highest_priority_task = pq.top();  // 獲取優先級最高的任務
                results.push_back(highest_priority_task.name);  // 保存任務名稱到結果中
                pq.pop();  // 從隊列中移除該任務
            }
        }
    }

    // 輸出所有 `GET` 操作的結果
    for (const auto& task_name : results) {
        cout << task_name << endl;  // 每行輸出一個任務名稱
    }

    // 將剩餘任務存儲到向量中
    vector<Task> remaining_tasks;
    while (!pq.empty()) {
        remaining_tasks.push_back(pq.top());  // 獲取剩餘的任務
        pq.pop();  // 移除任務
    }

    // 輸出剩餘任務的名稱和優先級，按照優先級從高到低顯示
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remaining_tasks.size(); ++i) {
        cout << "('" << remaining_tasks[i].name << "', " << remaining_tasks[i].priority << ")";
        if (i != remaining_tasks.size() - 1) {
            cout << ", ";  // 任務之間用逗號分隔
        }
    }
    cout << "]" << endl;

    return 0;
}