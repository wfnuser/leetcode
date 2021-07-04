class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> cnt;

        for (auto cpdomain: cpdomains) {
            int index = cpdomain.find(' ');
            int num = stoi(cpdomain.substr(0, index));
            string domain = cpdomain.substr(index+1);

            while (index > 0) {
                cnt[domain] += num;
                index = domain.find('.');
                domain = domain.substr(index+1);
            }
        }

        for (auto p: cnt) {
            ans.push_back(to_string(p.second) + " " + p.first);
        }

        return ans;
    }
};
