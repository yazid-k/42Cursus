class calculator:
    def __init__(self, vec):
        self.vec = vec

    def __add__(self, object) -> None:
        return [i + object for i in self.vec]

    def __mul__(self, object) -> None:
        return [i * object for i in self.vec]

    def __sub__(self, object) -> None:
        return [i - object for i in self.vec]

    def __truediv__(self, object) -> None:
        try:
            return [i / object for i in self.vec]
        except ZeroDivisionError:
            return 'Cannot divide by zero'

    def __repr__(self) -> None:
        return f'{self.vec}'

    def __str__(self) -> None:
        return f'{self.vec}'
