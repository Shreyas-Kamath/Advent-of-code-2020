#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

int main(){
    std::ifstream in("data.txt"); std::string line; std::vector<int> nums; 
    std::unordered_map<int, int> map;
    while (std::getline(in, line)) nums.emplace_back(stoi(line));
    in.close();
    int target{2020}; int complement;
    for (size_t i{}; i < nums.size(); ++i){
        complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            std::cout << complement * nums[i];
            break;
        }
        else map[nums[i]] = i;
    }
}