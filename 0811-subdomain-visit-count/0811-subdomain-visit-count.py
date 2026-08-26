class Solution:
    def subdomainVisits(self, cpdomains):
        count = {}

        for cpdomain in cpdomains:
            visits, domain = cpdomain.split()

            visits = int(visits)

            # Add the complete domain
            count[domain] = count.get(domain, 0) + visits

            # Add all parent domains
            while "." in domain:
                domain = domain.split(".", 1)[1]
                count[domain] = count.get(domain, 0) + visits

        result = []

        for domain, visits in count.items():
            result.append(str(visits) + " " + domain)

        return result