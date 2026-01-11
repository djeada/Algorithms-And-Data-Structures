"""Browser history navigation simulation."""

from __future__ import annotations


class BrowserHistory:
    """Simulates browser history with back and forward navigation."""

    def __init__(self, homepage: str) -> None:
        """
        Initialize the browser with a homepage.

        Args:
            homepage: The initial URL to display.
        """
        self.history: list[str] = [homepage]
        self.current = 0

    def visit(self, url: str) -> None:
        """
        Visit a new URL, clearing forward history.

        Args:
            url: The URL to navigate to.
        """
        self.history = self.history[: self.current + 1]
        self.history.append(url)
        self.current = len(self.history) - 1

    def back(self, steps: int) -> str:
        """
        Go back in history by the given number of steps.

        Args:
            steps: Number of steps to go back.

        Returns:
            The URL after going back.
        """
        if steps > self.current:
            self.current = 0
            return self.history[self.current]
        self.current -= steps
        return self.history[self.current]

    def forward(self, steps: int) -> str:
        """
        Go forward in history by the given number of steps.

        Args:
            steps: Number of steps to go forward.

        Returns:
            The URL after going forward.
        """
        if steps > len(self.history) - self.current - 1:
            self.current = len(self.history) - 1
            return self.history[self.current]
        self.current += steps
        return self.history[self.current]
