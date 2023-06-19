// by watercolor, 2023/03/19

class Solution {
public:
    string findLexSmallestString(string s, int a, int b)
    {
        set<string> st;
        queue<string> q;

        if(s.length() == 1) {
            return s;
        }

        st.insert(s);
        q.push(s);

        int elements = 1;
        while(q.empty() == false) {
            int elements2 = 0;

            for(int i = 0; i < elements; i++) {
                string s2 = q.front();

                elements2 += addStringToQueueAndSet(addNumbersForString(s2, a), q, st);
                elements2 += addStringToQueueAndSet(RollString(s2, b), q, st);

                q.pop();
            }

            elements = elements2;
        }

        return *(begin(st));
    }

private:
    inline char addNumber(char c, int a) 
    {
        string nums = "0123456789";
        int i;

        for(i = 0; i < nums.length(); i++) {
            if(nums[i] == c) {
                break;
            }
        }

        i = (i+a) % nums.length();
        return nums[i];
    }

    string addNumbersForString(string s, int a) 
    {
        for(int i = 1; i < s.length(); i += 2) {
            s[i] = addNumber(s[i], a);
        }

        return s;
    }

    string RollString(string s, int b) 
    {
        b = b % s.length();

        string s1 = s.substr(0, s.length()-b);
        string s2 = s.substr(s.length()-b, b);

        return (s2+s1);
    }

    int addStringToQueueAndSet(string s, queue<string> &q, set<string> &st)
    {
        if(st.count(s) != 0) {
            return 0;
        } else {
            st.insert(s);
            q.push(s);

            return 1;
        }
    }
};
