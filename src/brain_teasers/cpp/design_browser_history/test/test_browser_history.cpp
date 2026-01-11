#include "browser_history.h"
#include "gtest/gtest.h"

TEST(BrowserHistoryTest, BasicNavigation) {
    BrowserHistory browser("leetcode.com");
    
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    
    EXPECT_EQ(browser.back(1), "facebook.com");
    EXPECT_EQ(browser.back(1), "google.com");
    EXPECT_EQ(browser.forward(1), "facebook.com");
    
    browser.visit("linkedin.com");  // Clears forward history
    
    EXPECT_EQ(browser.forward(2), "linkedin.com");  // Can't go forward
    EXPECT_EQ(browser.back(2), "google.com");
    EXPECT_EQ(browser.back(7), "leetcode.com");  // Can only go back to homepage
}

TEST(BrowserHistoryTest, CurrentPage) {
    BrowserHistory browser("home.com");
    EXPECT_EQ(browser.current(), "home.com");
    
    browser.visit("page1.com");
    EXPECT_EQ(browser.current(), "page1.com");
}

TEST(BrowserHistoryTest, BackBeyondHistory) {
    BrowserHistory browser("home.com");
    browser.visit("page1.com");
    
    EXPECT_EQ(browser.back(100), "home.com");
}

TEST(BrowserHistoryTest, ForwardBeyondHistory) {
    BrowserHistory browser("home.com");
    browser.visit("page1.com");
    browser.visit("page2.com");
    browser.back(1);
    
    EXPECT_EQ(browser.forward(100), "page2.com");
}

TEST(BrowserHistoryTest, VisitClearsForwardHistory) {
    BrowserHistory browser("home.com");
    browser.visit("page1.com");
    browser.visit("page2.com");
    browser.back(1);  // Now at page1.com
    browser.visit("page3.com");  // Clears page2.com from forward history
    
    EXPECT_EQ(browser.forward(1), "page3.com");  // Can't go to page2.com
}
