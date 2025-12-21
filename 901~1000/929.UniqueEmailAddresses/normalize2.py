class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def normalize(email: str) -> str:
            if email.count('@') == 0 or email.count('@') >= 2:
                raise ValueError('invalid email address')
            local, domain = email.split('@')
            local = local.split('+')[0].replace('.', '')
            return local + '@' + domain

        unique_emails = {normalize(email) for email in emails}
        return len(unique_emails)
