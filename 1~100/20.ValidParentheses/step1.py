class Solution:
    def isValid(self, s: str) -> bool:
        bracket_pairs = {'{' : '}',
                         '[': ']',
                         '(': ')'}
        open_brackets = []
        for bracket in s:
            if bracket == '{' or bracket == '[' or bracket == '(':
                open_brackets.append(bracket)
                continue
            if len(open_brackets) == 0 or bracket != bracket_pairs[open_brackets.pop()]:
                return False

        return len(open_brackets) == 0
