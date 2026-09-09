class Solution:
    def isValid(self, s: str) -> bool:
        bracket_pairs = {'(': ')', '[': ']', '{': '}'}
        open_bracket = []
        for bracket in s:
            if bracket in bracket_pairs:
                open_bracket.append(bracket)
                continue
            if not open_bracket:
                return False
            if bracket != bracket_pairs[open_bracket[-1]]:
                return False
            open_bracket.pop()
        return not open_bracket
