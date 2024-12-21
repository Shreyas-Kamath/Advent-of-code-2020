#include <fstream>
#include <iostream>
#include <vector>
#include <regex>

bool test(std::string& passport, std::vector<std::regex>& reqs){
    for (auto& req: reqs){
        if (!std::regex_search(passport, req)) return false;    
    }
    return true;
}

int main(){
    std::regex byr(R"(byr:(192[0-9]|19[3-9][0-9]|200[0-2]))");
    std::regex iyr(R"(iyr:(201[0-9]|2020))");
    std::regex eyr(R"(eyr:(202[0-9]|2030))");
    std::regex hgt(R"(hgt:(1[5-8][0-9]|19[0-3])cm|hgt:(59|6[0-9]|7[0-6])in)");
    std::regex hcl(R"(hcl:(#[0-9a-f]{6}))");
    std::regex ecl(R"(ecl:(amb|blu|brn|gry|grn|hzl|oth))");
    std::regex pid(R"(pid:(\d{9})\b)");

    std::vector<std::regex> reqs {byr, iyr, eyr, hgt, hcl, ecl, pid};
    std::ifstream in("data.txt");
    std::string input((std::istreambuf_iterator<char>(in)),
                      std::istreambuf_iterator<char>());

    std::vector<std::string> passports;
    std::string delim = "\n\n";
    size_t pos = 0;

    int ans{};

    while ((pos = input.find(delim)) != std::string::npos) {
        passports.push_back(input.substr(0, pos));
        input.erase(0, pos + delim.length());
    }
    passports.push_back(input);
    for (auto& passport: passports){
        if (test(passport, reqs)) ans += 1;
    }
    std::cout << ans;
    return 0;
}
