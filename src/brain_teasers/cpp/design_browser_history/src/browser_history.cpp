#include "browser_history.h"
#include <algorithm>

BrowserHistory::BrowserHistory(const std::string &homepage) : currentIndex_(0) {
  history_.push_back(homepage);
}

void BrowserHistory::visit(const std::string &url) {
  // Remove all forward history
  history_.resize(currentIndex_ + 1);
  history_.push_back(url);
  currentIndex_++;
}

std::string BrowserHistory::back(int steps) {
  currentIndex_ -= std::min(steps, currentIndex_);
  return history_[currentIndex_];
}

std::string BrowserHistory::forward(int steps) {
  int remaining = static_cast<int>(history_.size()) - 1 - currentIndex_;
  // Compare against remaining pages to avoid signed overflow of index + steps
  currentIndex_ += std::min(steps, remaining);
  return history_[currentIndex_];
}

std::string BrowserHistory::current() const { return history_[currentIndex_]; }
