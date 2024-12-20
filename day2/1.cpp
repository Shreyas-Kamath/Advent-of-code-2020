#include <string>
#include <regex>
#include <fstream>
#include <iostream>

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

            auto count = std::count(search.begin(), search.end(), to_search);
            if (count > lhs && count <= rhs) ans += 1;
        }
    }
    in.close();
    std::cout << ans;
    return 0;
}
