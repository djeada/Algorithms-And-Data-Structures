#include "add_string_numbers.h"
#include <algorithm>

std::string addIntegerStrings(const std::string& s1, const std::string& s2) {
    std::string result;
    int carry = 0;
    int i = static_cast<int>(s1.size()) - 1;
    int j = static_cast<int>(s2.size()) - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? (s1[i] - '0') : 0;
        int digit2 = (j >= 0) ? (s2[j] - '0') : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back('0' + (sum % 10));
        
        --i;
        --j;
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

std::string addStrings(const std::string& s1, const std::string& s2) {
    // Find decimal point positions
    auto pos1 = s1.find('.');
    auto pos2 = s2.find('.');
    
    bool hasDecimal1 = (pos1 != std::string::npos);
    bool hasDecimal2 = (pos2 != std::string::npos);
    
    // If neither has decimal, just add as integers
    if (!hasDecimal1 && !hasDecimal2) {
        return addIntegerStrings(s1, s2);
    }
    
    // Split into integer and fractional parts
    std::string int1 = hasDecimal1 ? s1.substr(0, pos1) : s1;
    std::string frac1 = hasDecimal1 ? s1.substr(pos1 + 1) : "";
    std::string int2 = hasDecimal2 ? s2.substr(0, pos2) : s2;
    std::string frac2 = hasDecimal2 ? s2.substr(pos2 + 1) : "";
    
    // Pad fractional parts to same length
    size_t maxFracLen = std::max(frac1.size(), frac2.size());
    while (frac1.size() < maxFracLen) frac1.push_back('0');
    while (frac2.size() < maxFracLen) frac2.push_back('0');
    
    // Add fractional parts
    std::string fracSum = addIntegerStrings(frac1, frac2);
    
    // Handle carry from fractional part
    std::string fracCarry = "0";
    if (fracSum.size() > maxFracLen) {
        fracCarry = fracSum.substr(0, fracSum.size() - maxFracLen);
        fracSum = fracSum.substr(fracSum.size() - maxFracLen);
    }
    
    // Ensure fracSum has leading zeros if needed
    while (fracSum.size() < maxFracLen) {
        fracSum = "0" + fracSum;
    }
    
    // Add integer parts with carry
    std::string intSum = addIntegerStrings(addIntegerStrings(int1, int2), fracCarry);
    
    return intSum + "." + fracSum;
}
