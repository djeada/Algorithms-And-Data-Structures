
/*
You have a browser of one tab where you start on the homepage and you can visit
another url, get back in the history number of steps or move forward in the
history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the
browser. void visit(string url) Visits url from the current page. It clears up
all the forward history. string back(int steps) Move steps back in history. If
you can only return x steps in the history and steps > x, you will return only x
steps. Return the current url after moving back in history at most steps. string
forward(int steps) Move steps forward in history. If you can only forward x
steps in the history and steps > x, you will forward only x steps. Return the
current url after forwarding in history at most steps.
*/

#include <iostream>
#include <string>
#include <vector>

class BrowserHistory {
  std::vector<std::string> history;
  int current;

public:
  BrowserHistory(std::string homepage) {
    history.push_back(homepage);
    current = 0;
  }

  void visit(std::string url) {
    history.erase(history.begin() + current + 1, history.end());
    history.push_back(url);
    current = history.size() - 1;
  }

  std::string back(int steps) {
    if (steps > current) {
      current = 0;
      return history[current];
    }
    current -= steps;
    return history[current];
  }

  std::string forward(int steps) {
    if (steps > history.size() - current - 1) {
      current = history.size() - 1;
      return history[current];
    }
    current += steps;
    return history[current];
  }

  std::vector<std::string> getHistory() { return history; }
};

void test1() {
  /*
  Input:
["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]
Output:
[null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","google.com","leetcode.com"]
*/
  BrowserHistory bh("leetcode.com");
  bh.visit("google.com");
  bh.visit("facebook.com");
  bh.visit("youtube.com");
  bh.back(1);
  bh.back(1);
  bh.forward(1);
  bh.visit("linkedin.com");
  bh.forward(2);
  bh.back(2);
  bh.back(7);
  std::vector<std::string> res = bh.getHistory();
  for (auto s : res) {
    std::cout << s << std::endl;
  }
}

int main() {
  test1();
  return 0;
}
