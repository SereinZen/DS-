//
// Created by lenovo on 2023/10/20.
//
#include "iostream"
#include "string"
#include "vector"

using namespace std;
struct Bi_tree{
    char data;
    Bi_tree *left;
    Bi_tree *right;
};

Bi_tree* creat_tree(int i, int n, string str, int nums[]){
    /*
     * i 所处位置
     * n 数组长度
     */
    if (i >= n){
        return nullptr;
    }
    if (str[i] == '0'){
        nums[i] = 1;
        return nullptr;
    }

    Bi_tree *node = new Bi_tree();
    node->data = str[i];
    nums[i] = 1;
    node->left = creat_tree(i + 1, n, str, nums);
    while (nums[i] == 1){
        i ++;
    }
    node->right = creat_tree(i, n, str, nums);
    return node;
}

void find_max_deep(Bi_tree *node, vector<int> &nums, int x){
    if (node != nullptr){
        if (node->left == nullptr and node->right == nullptr){
            x ++;
            nums.push_back(x);
            x = 1;
        }
        else{
            x ++;
            find_max_deep(node->left, nums, x);
            find_max_deep(node->right, nums, x);
        }
    }

}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        int a = size(str);
        int nums[a];
        for (int j = 0; j < a; j++){
            nums[j] = 0;
        }
        Bi_tree *node = creat_tree(0, a, str, nums);
        vector<int> vector1;
        find_max_deep(node, vector1, 0);
        int max = 0;
        for (int j = 0; j < vector1.size(); j++){
            if (vector1[j] > max){
                max = vector1[j];
            }
        }
        cout << max << endl;
    }


    return 0;
}






