#include <string>
#include <vector>

int countConstructBasic(const std::string &target,
                        const std::vector<std::string> &wordBank);

int countConstructMemo(const std::string &target,
                       const std::vector<std::string> &wordBank);

int countConstructTable(const std::string &target,
                        const std::vector<std::string> &wordBank);
