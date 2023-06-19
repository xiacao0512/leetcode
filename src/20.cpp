// by watercolor, 2022-09-03

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {
            switch(s[i]) {
                case ')':
                    if(st.empty() == true || st.top() != '(') {
                        return false;
                    }
                    st.pop();
                    break;

                case ']':
                    if(st.empty() == true || st.top() != '[') {
                        return false;
                    }
                    st.pop();
                    break;

                case '}':
                    if(st.empty() == true || st.top() != '{') {
                        return false;
                    }
                    st.pop();
                    break;

                default:
                    st.push(s[i]);
            }
        }

        return st.empty();
    }
};
