class Solution:
    def isValid(self, s: str) -> bool:
        valid_parentheses = {
            '(' : ')',
            '[' : ']',
            '{' : '}'
        }

        all_brackets = []
        for bracket in s:
            if bracket in valid_parentheses:
                all_brackets.append(bracket)
                continue
            if len(all_brackets) == 0:
                return False
            if bracket != valid_parentheses[all_brackets[-1]]:
                return False
            all_brackets.pop()
        return len(all_brackets) == 0
