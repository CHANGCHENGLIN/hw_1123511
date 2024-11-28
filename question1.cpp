//Oliver Lin
//1123511
//2024/11/28

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// 定義二元樹節點的結構體
struct TreeNode {
    int val;                 // 節點的值
    TreeNode* left;          // 左子節點
    TreeNode* right;         // 右子節點
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 初始化節點
};

// 建立二元樹 (使用層序遍歷輸入資料)
TreeNode* buildTree(const vector<int>& levelOrder) {
    // 如果輸入為空或根節點為空，返回空指標
    if (levelOrder.empty() || levelOrder[0] == -1) return nullptr;

    // 創建根節點
    TreeNode* root = new TreeNode(levelOrder[0]);
    queue<TreeNode*> q; // 使用佇列輔助建立樹
    q.push(root);

    int i = 1; // 指向層序輸入的下一個節點值
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front(); // 取出佇列的最前端節點
        q.pop();

        // 建立左子節點
        if (levelOrder[i] != -1) { // -1 表示空節點
            current->left = new TreeNode(levelOrder[i]);
            q.push(current->left); // 將左子節點加入佇列
        }
        i++;

        // 建立右子節點
        if (i < levelOrder.size() && levelOrder[i] != -1) {
            current->right = new TreeNode(levelOrder[i]);
            q.push(current->right); // 將右子節點加入佇列
        }
        i++;
    }

    return root;
}

// 計算樹的直徑的輔助函數
int calculateDiameter(TreeNode* root, int& diameter) {
    if (!root) return 0; // 空節點的高度為 0

    // 計算左子樹和右子樹的高度
    int leftHeight = calculateDiameter(root->left, diameter);
    int rightHeight = calculateDiameter(root->right, diameter);

    // 更新直徑 (經過當前節點的最大路徑長度)
    diameter = max(diameter, leftHeight + rightHeight + 1);

    // 返回當前節點的高度
    return max(leftHeight, rightHeight) + 1;
}

// 主函數：計算二元樹的直徑
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0; // 初始化直徑為 0
    calculateDiameter(root, diameter);
    return diameter;
}

int main() {
    // 輸入部分
    string input;
    cout << "請輸入二元樹的層序遍歷 (-1 表示空節點): ";
    getline(cin, input); // 接收整行輸入
    stringstream ss(input);
    vector<int> levelOrder;
    int num;
    while (ss >> num) {
        levelOrder.push_back(num); // 將輸入值加入向量
    }

    // 建立二元樹
    TreeNode* root = buildTree(levelOrder);

    // 計算並輸出直徑
    cout << "二元樹的直徑為: " << diameterOfBinaryTree(root) << endl;

    return 0;
}