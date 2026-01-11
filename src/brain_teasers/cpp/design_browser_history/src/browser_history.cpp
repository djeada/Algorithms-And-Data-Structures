#include "browser_history.h"
#include <algorithm>

BrowserHistory::BrowserHistory(const std::string& homepage) 
    : currentIndex_(0) {
    history_.push_back(homepage);
}

void BrowserHistory::visit(const std::string& url) {
    // Remove all forward history
    history_.resize(currentIndex_ + 1);
    history_.push_back(url);
    currentIndex_++;
}

std::string BrowserHistory::back(int steps) {
    currentIndex_ = std::max(0, currentIndex_ - steps);
    return history_[currentIndex_];
}

std::string BrowserHistory::forward(int steps) {
    currentIndex_ = std::min(static_cast<int>(history_.size()) - 1, 
                              currentIndex_ + steps);
    return history_[currentIndex_];
}

std::string BrowserHistory::current() const {
    return history_[currentIndex_];
}
