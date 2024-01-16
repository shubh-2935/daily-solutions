// Author : Shubham Chaudhari
// Date : 16/01/2024
// Problem : 380. Insert Delete GetRandom O(1)
// Difficulty : Medium
// Problem Link : https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
// Video Solution : https://youtu.be/m2coqja4FlU?si=7fvidxMTv8-T3DXZ
// Code:
class RandomizedSet {
public:
    unordered_map<int, int> set;
    vector<int> v;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(set.find(val) == set.end()){
            v.push_back(val);
            set[val] = v.size()-1;
            return true;
        }
        else{
            return false;
        }
    }
    
    bool remove(int val) {
        auto it = set.find(val);
        if(it != set.end()){
            v[it->second] = v.back();
            v.pop_back();
            set[v[it->second]] = it->second;
            set.erase(val);
            return true;
        }
        else{
            return false;
        }
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
