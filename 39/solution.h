class Solution {
public:
    vector<int> candidate;
    vector<vector<int>> res;
    vector<int> tmp;
    int size;
    void deep(vector<int>& tmp, int loc, int target){
        if(target == 0){
            std::sort(tmp.begin(),tmp.end());
            res.push_back(tmp);
        }else{
            //tmp.push_back(0);            tmp.push_back(target);            res.push_back(tmp);            tmp.pop_back();            tmp.pop_back();
            for(int i = loc; i < size ; i++){
                if(target - candidate[i] >= 0){
                    tmp.push_back(candidate[i]);
                    deep(tmp,i,target - candidate[i]);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                deep(tmp,i,target - candidate[i]);
                tmp.pop_back();
            }
        }
        return res;
    }
};