class BrowserHistory:
    def __init__(self, homepage: str):
        self.history = [homepage]
        self.current = 0

    def visit(self, url: str):
        self.history = self.history[: self.current + 1]
        self.history.append(url)
        self.current = len(self.history) - 1

    def back(self, steps: int) -> str:
        if steps > self.current:
            self.current = 0
            return self.history[self.current]
        self.current -= steps
        return self.history[self.current]

    def forward(self, steps: int) -> str:
        if steps > len(self.history) - self.current - 1:
            self.current = len(self.history) - 1
            return self.history[self.current]
        self.current += steps
        return self.history[self.current]
