class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> bracket;
        if (s.size() == 0) return true;
        char pre='a';
        for (int i = 0; i < s.size(); i++)
        {
            if (pre=='a' || ((s[i]-pre)!=1 && (s[i]-pre) != 2))
            {
                if (s[i] == ']' || s[i] == ')' || s[i] == '}')
                    return false;
                bracket.push(s[i]);
                pre = s[i];
            }
            else
            {
                if (bracket.empty()) return false;
                bracket.pop();
                if (bracket.empty()) {
                    pre = 'a';
                    continue;
                }
                pre = bracket.top();
            }
        }
        if (!bracket.empty())
            return false;
        return true;
    }
};