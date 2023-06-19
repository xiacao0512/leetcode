// by watercolor, 2022-09-01

#define MAX_SIZE    20001

int trap(int *height, int heightSize)
{
    int stack[MAX_SIZE], top;
    int i, maxpos, max = 0, ans = 0;

    if(heightSize < 3) {
        return 0;
    }

    for(i = 0; i < heightSize; i++) {
        if(height[i] > max) {
            max = height[i];
            maxpos = i;
        }
    }

    i = 0;
    top = 0;
    while(i <= maxpos) {
        if(top != 0 && height[i] >= stack[0]) {
            while(top > 0) {
                ans += stack[0] - stack[--top];
            }
        }

        stack[top++] = height[i++];
    }

    i = heightSize - 1;
    top = 0;
    while(i >= maxpos) {
        if(top != 0 && height[i] >= stack[0]) {
            while(top > 0) {
                ans += stack[0] - stack[--top];
            }
        }

        stack[top++] = height[i--];
    }

    return ans;
}
