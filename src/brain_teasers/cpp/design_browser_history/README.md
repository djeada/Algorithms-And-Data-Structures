## Design Browser History
This is an implementation of a class representing a browser's history. It provides methods for visiting a new URL, going back to a previously visited URL, and going forward to a URL that has been previously navigated back from.

## Examples

Here are some examples of how the class can be used:

```python
# Initialize a new BrowserHistory with the homepage "www.google.com"
browser = BrowserHistory("www.google.com")

# Visit the URL "www.google.com/search?q=cats"
browser.visit("www.google.com/search?q=cats")

# Visit the URL "www.google.com/search?q=dogs"
browser.visit("www.google.com/search?q=dogs")

# Go back to the previous URL
assert browser.back(1) == "www.google.com/search?q=cats"

# Go forward to the next URL
assert browser.forward(1) == "www.google.com/search?q=dogs"

# Go back to the homepage
assert browser.back(2) == "www.google.com"

# Attempt to go back beyond the first URL in the history
assert browser.back(1) == "www.google.com"

# Attempt to go forward beyond the last URL in the history
assert browser.forward(1) == "www.google.com/search?q=dogs"
```

## Approach

The class maintains a list of URLs representing the browser's history and an integer representing the current position in the history. The visit method appends the new URL to the end of the history list and updates the current position to the end of the list. The back method decrements the current position by the number of steps specified, but caps it at 0 to ensure that the current position never goes below the beginning of the history list. The forward method increments the current position by the number of steps specified, but caps it at the end of the history list to ensure that the current position never goes beyond the end of the list.

## Complexity

The time complexity of all methods in the class is $O(1)$, as they perform a constant number of operations. The space complexity is $O(n)$, where $n$ is the number of URLs in the history list. 