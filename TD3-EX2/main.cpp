#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Solution force brute : O(n^2) en temps, O(1) en espace
vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // Retourne un vecteur vide si aucune solution n'est trouvée
}

// Solution optimale avec unordered_map : O(n) en temps, O(n) en espace
vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> map; // Stocke la valeur et son index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        // Si le complément est déjà dans la map, on a trouvé la paire
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        
        // Sinon, on ajoute l'élément actuel et son index dans la map
        map[nums[i]] = i;
    }
    return {}; 
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    if (!indicesBruteForce.empty()) {
        cout << "Brute-Force Solution : [" 
             << indicesBruteForce[0] << ", " 
             << indicesBruteForce[1] << "]" << endl;
    }

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    if (!indicesOptimal.empty()) {
        cout << "Optimal Solution : [" 
             << indicesOptimal[0] << ", " 
             << indicesOptimal[1] << "]" << endl;
    }

    return 0;
}