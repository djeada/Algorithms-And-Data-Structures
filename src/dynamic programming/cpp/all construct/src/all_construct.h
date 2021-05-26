#include <string>
#include <vector>

std::vector<std::vector<std::string>>
allConstructBasic(const std::string &target,
                  const std::vector<std::string> &wordBank);

std::vector<std::vector<std::string>>
allConstructMemo(const std::string &target,
                 const std::vector<std::string> &wordBank);

std::vector<std::vector<std::string>>
allConstructTable(const std::string &target,
                  const std::vector<std::string> &wordBank);
