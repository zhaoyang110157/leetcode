class Solution {
public:
    vector<int> candidate;
    vector<vector<int>> res;
    vector<int> tmp;
    int size;
    void deep(vector<int>& tmp, int loc, int target){
        if(target == 0){
            std::sort(tmp.begin(),tmp.end());
            for(int i = 0; i < res.size() ; i++){
                if(res[i] == tmp)
                    return;
            }
            res.push_back(tmp);
        }else{
            //tmp.push_back(0);            tmp.push_back(target);            res.push_back(tmp);            tmp.pop_back();            tmp.pop_back();
            for(int i = loc; i < size ; i++){
                if(target - candidate[i] >= 0){
                    tmp.push_back(candidate[i]);
                    deep(tmp,i+1,target - candidate[i]);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidate = candidates;
        std::sort(candidate.begin(),candidate.end());
        size = candidates.size();
        if(size == 0 || target < candidate[0])
            return res;
        tmp.clear();
        
        //tmp.push_back(size);        res.push_back(tmp);        tmp.pop_back();
        for(int i = 0; i < size ; i++){
            if(target - candidate[i] >= 0){
                tmp.push_back(candidate[i]);
                deep(tmp,i+1,target - candidate[i]);
                tmp.pop_back();
            }
        }
        return res;
    }
};

//上方这个解决办法，沿用了39的操作方法，在其基础上，不允许使用反复同一位置上的元素
//问题，向量去重，使用遍历解决，大幅度增加了时间复杂度。


// author:rmokerone
#include <iostream>
#include <vector>

using namespace std;

class Solution2 {

private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            // 元素不可重复利用，使用下一个即i+1
            DFS(i + 1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};
/*
作者：liweiwei1419
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution3 {
public:

    vector<int> input;
    int target;
    vector<vector<int>> result;
    vector<int> vc;

    void dfs(int index, int sum) {
        // index >= input.size() ，写成 index == input.size() 即可
        // 因为每次都 + 1，在 index == input.size() 剪枝就可以了
        if (sum >= target || index == input.size()) {
            if (sum == target) {
                result.push_back(vc);
            }
            return;
        }
        for (int i = index; i < input.size(); i++) {
            if (input[i] > target) {
                continue;
            }

            // 【我添加的代码在这里】：
            // 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
            // 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
            // 因为前一个分支的候选集合一定大于后一个分支的候选集合
            // 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
            // “剪枝”的前提是排序，升序或者降序均可
            if (i > index && input[i - 1] == input[i]) {
                continue;
            }

            vc.push_back(input[i]);
            sum += input[i];
            dfs(i + 1, sum);
            vc.pop_back();
            sum -= input[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // “剪枝”的前提是排序，升序或者降序均可
        sort(candidates.begin(), candidates.end());
        this->input = candidates;
        this->target = target;
        dfs(0, 0);
        return result;
    }
};


int main() {
    cout << "LeetCode 第 40 题：组合问题 II" << endl;
    Solution solution = Solution();

    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    int target = 8;
    vector<vector<int>> res = solution.combinationSum2(candidates, target);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << "" << endl;
    }
    return 0;
}
/*
作者：liweiwei1419
链接：https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。