#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
	vector<string> removeComments(vector<string> &source)
	{
		vector<string> ans;
		bool multipleLineCommentClosed = true;
		bool newLine = true;
		string des = "";
		for (int i = 0; i < source.size(); i++)
		{
			bool notComment = false;
			string str = source[i];
			if (str.length() == 0) continue;
			for (int j = 0; j < str.length() - 1; j++)
			{
				if (str[j] == '/' && str[j + 1] == '/' && multipleLineCommentClosed) {
					newLine = true;
					break;
				}
				if (str[j] == '/' && str[j + 1] == '*' && multipleLineCommentClosed)
				{
					multipleLineCommentClosed = false;
					j = j + 1;
					continue;
				}
				if (str[j] == '*' && str[j + 1] == '/' && !multipleLineCommentClosed)
				{
					multipleLineCommentClosed = true;
					j = j + 1;
                    if (j == str.length() - 2 && multipleLineCommentClosed && str[j+1] != '/')
                    {
                        des += str[j+1];
                    }
					continue;
				}
				if (multipleLineCommentClosed)
					des += str[j];
				if (j == str.length() - 2 && multipleLineCommentClosed)
				{
					des += str[j + 1];
				}
			}
			if (str.length() == 1)
			{
				des += str[0];
			}
			cout << i << ": " << des << endl;
			if (des != "" && multipleLineCommentClosed) {
				ans.push_back(des);
				des = "";
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	// vector<string> source = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;", "/* This is a test", "   multiline  ", "   comment for ", "   testing */", "a = b + c;", "}"};
	vector<string> source =
		{"main() { ",
		 "  int a = 1; /* Its comments here ",
		 "",
		 "  ",
		 "  */ return 0;",
		 "} "};
	vector<string> ans = s.removeComments(source);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << i << ": " << ans[i] << endl;
	}
}
