import functools


class Solution:
    def titleToNumber(self, s: str) -> int:
        return functools.reduce(lambda a, b: a * 26 + b, [ord(c) - 64 for c in s])
