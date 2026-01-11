#pragma once

#include <string>
#include <vector>

/**
 * Browser History implementation with back and forward navigation.
 */
class BrowserHistory {
public:
    /**
     * Initialize with a homepage.
     * @param homepage Starting URL
     */
    explicit BrowserHistory(const std::string& homepage);
    
    /**
     * Visit a new URL from the current page.
     * Clears forward history.
     * @param url URL to visit
     */
    void visit(const std::string& url);
    
    /**
     * Go back steps pages in history.
     * @param steps Number of steps to go back
     * @return URL after going back
     */
    std::string back(int steps);
    
    /**
     * Go forward steps pages in history.
     * @param steps Number of steps to go forward
     * @return URL after going forward
     */
    std::string forward(int steps);
    
    /**
     * Get current URL.
     * @return Current URL
     */
    std::string current() const;

private:
    std::vector<std::string> history_;
    int currentIndex_;
};
