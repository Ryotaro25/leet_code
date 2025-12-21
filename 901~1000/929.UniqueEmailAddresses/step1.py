class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique_mails = set()
        for email in emails:
            local_and_domain = email.split('@')
            normalized_email = ""
            for letter in local_and_domain[0]:
                if letter == '.':
                    continue
                if letter == '+':
                    break
                normalized_email += letter
            normalized_email += '@'
            normalized_email += local_and_domain[1]
            unique_mails.add(normalized_email)
        return len(unique_mails)
