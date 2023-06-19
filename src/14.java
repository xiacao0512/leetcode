// by watercolor, 2022-11-24

class Solution {
    public String longestCommonPrefix(String[] strs) 
    {
        final int STRING_MAXLEN = 1024;

        int minStringLength = STRING_MAXLEN;
        for(int i = 0; i < strs.length; i++) {
            if(minStringLength > strs[i].length()) {
                minStringLength = strs[i].length();
            }
        }

        int minPrefixLength = 0;
        while(minPrefixLength < minStringLength) {
            int i;
            char c = '\0';
            
            for(i = 0; i < strs.length; i++) {
                if(i == 0) {
                    c = strs[i].charAt(minPrefixLength);
                } else {
                    if(strs[i].charAt(minPrefixLength) != c) {
                        break;
                    }
                }
            }
            
            if(i != strs.length) {
                break;
            }

            minPrefixLength++;
        }

        String answer = strs[0].substring(0, minPrefixLength);
        return answer;
    }
}
