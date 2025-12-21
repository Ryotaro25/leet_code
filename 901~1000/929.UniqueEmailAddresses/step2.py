class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_mails = set()
        for email in emails:
            local, domain = email.split('@')
            normalized_email = ""
            for letter in local:
                if letter == '.':
                    continue
                if letter == '+':
                    break
                normalized_email += letter
            normalized_email = normalized_email + '@' + domain
            unique_mails.add(normalized_email)
        return len(unique_mails)
