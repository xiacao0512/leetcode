class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1) {
            return s;
        }

        vector<vector<char>> array_char;

        for(int i = 0; i < numRows; i++) {
            vector<char> v;
            for(int j = 0; j < s.size(); j++) {
                v.push_back(0);
            }
            array_char.push_back(v);
        }

        array_char[0][0] = s[0];

        int x = 0, y = 1, step = numRows-1;
        int direction = direction_down;
        for(int i = 1; i < s.size(); i++) {
            array_char[y][x] = s[i];

            step--;
            if(step == 0) {
                step = numRows-1;
                direction = (direction == direction_down) ? direction_left_up : direction_down;
            }

            if(direction == direction_down) {
                y++;
            } else if(direction == direction_left_up) {
                x++;
                y--;
            }
        }

        string result;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < s.size(); j++) {
                if(array_char[i][j] != 0) {
                    result += array_char[i][j];
                }
            }
        }

        return result;
    }

private:
    const int direction_down = 1;
    const int direction_left_up = 2;
};
