#include <string>
#include <regex>
#include <fstream>
#include <iostream>

bool test(int& lhs, int& rhs, std::string& search, char& to_search){
    return (search[lhs - 1] == to_search) != (search[rhs - 1] == to_search);
}

int main() {
    std::regex pattern(R"((\d+-\d+) ([a-z]): ([a-z]+))");

    std::ifstream in("data.txt"); std::string line; std::smatch match; int ans{};
    while (std::getline(in, line)){
        if (std::regex_match(line, match, pattern)){

            std::string index_range = match[1].str();

            int split = index_range.find('-'); //index

            int lhs = stoi(index_range.substr(0, split));
            int rhs = stoi(index_range.substr(split + 1));

            auto search = match[3].str();
            auto to_search = match[2].str()[0];
             
            if (test(lhs, rhs, search, to_search)) ans += 1;
        }
    }
    in.close();
    std::cout << ans;
    return 0;
}
