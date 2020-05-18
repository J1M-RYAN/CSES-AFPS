#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length() == 1)
    {
        cout << s;
        return 0;
    }
    map<char, string> m;
    for (char c : s)
    {
        if (m.count(c))
        {
            m[c] += c;
        }
        else
        {
            m[c] = c;
        }
    }

    string lhs = "";
    string copy;
    if (s.length() % 2 == 0)
    {
        for (auto const &pair : m)
        {

            if (pair.second.length() % 2 == 1)
            {

                cout << "NO SOLUTION";
                return (0);
            }
        }
        for (auto c : m)
        {

            string x = c.second;
            unsigned int j = 0;

            while (j < x.length() / 2)
            {

                lhs += c.first;
                j++;
            }

            copy = lhs;

            reverse(lhs.begin(), lhs.end());
            copy += lhs;
        }
        cout << copy;
    }
    else
    {
        int numOddChars = 0;
        for (auto c : m)
        {
            if (c.second.length() % 2 == 1)
            {
                numOddChars++;
                if (numOddChars > 1)
                {
                    cout << "NO SOLUTION";
                    return 0;
                }
            }
        }
        string middle = "";
        for (auto c : m)
        {
            if (c.second.length() % 2 == 0)
            {
                lhs += c.second.substr(0, c.second.length() / 2);
            }
            else
            {
                middle = c.second;
            }
        }
        copy = lhs;

        reverse(lhs.begin(), lhs.end());
        copy += middle + lhs;
        cout << copy;
    }
}