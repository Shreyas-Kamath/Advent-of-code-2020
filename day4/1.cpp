#include <fstream>
#include <iostream>
#include <vector>

bool test(std::string& passport, std::vector<std::string>& reqs){
    for (auto& req: reqs){
        size_t pos = passport.find(req);
        if (pos == std::string::npos) return false;    
    }
    return true;
}

int main(){
    std::vector<std::string> reqs {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
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
