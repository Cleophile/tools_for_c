int my_atoi(char* s) {
    int p = 0;
    int negative = 0;
    const int max = 2147483647;
    for(;;++p) {
        if(s[p] >= '0' && s[p] <= '9'){
            break;
        }
        if(s[p]==' ') {
            continue;
        }
        if(s[p]=='-') {
            negative = 1;
            ++p;
            break;
        }
        if(s[p]=='+') {
            ++p;
            break;
        }
        return 0;
    }
    for(;s[p]=='0';++p);
    if(s[p] < '0' || s[p] > '9') {
        return 0;
    }
    int result = (s[p] - '0');
    int digits = 1;
    ++p;
    if(negative) {
        result = -result;
        const int min = -2147483648;
        for(;s[p]>='0' && s[p]<='9';++p) {
            if(digits==9) {
                if(min / result < 10) {
                    return min;
                }
                result *= 10;
                int intercept = result - min;
                int d = s[p] - '0';
                if(d>=intercept) {
                    return min;
                }
                result -= d;
                ++digits;
                continue;
            }
            if(digits>=10) {
                return min;
            }
            result *= 10;
            result -= s[p] - '0';
            ++digits;
        }
        return result;
    }
    for(;s[p]>='0' && s[p]<='9';++p) {
        if (digits == 9) {
            if(max / result < 10) {
                return max;
            }
            result *= 10;
            int intercept = max - result;
            int d = s[p] - '0';
            if(d >= intercept) {
                return max;
            }
            ++digits;
            result += d;
            continue;
        }
        if(digits>=10) {
            return max;
        }
        ++digits;
        result *= 10;
        result += s[p] - '0';
    }
    return result;
}
