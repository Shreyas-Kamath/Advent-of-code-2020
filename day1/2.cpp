#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdint>

int main(){
    std::ifstream in("data.txt"); std::string line; std::vector<int> nums; 

    while (std::getline(in, line)) nums.emplace_back(stoi(line));
    in.close();

    int target{2020}; int complement_sum;

    for (size_t i{}; i < nums.size(); ++i){

        std::unordered_map<int, int> map;

        complement_sum = target - nums[i];
        for (size_t j{i + 1}; j < nums.size(); ++j){

            int complement = complement_sum - nums[j];

            if (map.find(complement) != map.end()){
                std::cout << nums[i] * complement * nums[j];
                break;
            }
            else map[nums[j]] = j;
        }
    }
}