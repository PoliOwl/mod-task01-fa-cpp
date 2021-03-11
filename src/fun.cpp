const char *next_word(const char *point) {
    while (*point == ' ') {
        ++point;
    }
    return point;
}

unsigned int faStr1(const char *str)
{
    if(*str == '\0') {
        return 0;
    }
    const char* start = str;
    const char *point = str;
    unsigned int ans = 0;
    point = next_word(point);
    while (*point != '\0') {
        unsigned int add = 1;
        while (*point != ' ' && *point != '\0') {
            if (add && *point - '0' > -1 && *point - '0' < 10) {
                add = 0;
            }
            ++point;
        }
        ans+=add;
        point = next_word(point);
    }
    return ans;
}
unsigned int faStr2(const char *str)
{
    if(*str == '\0') {
        return 0;
    }
    auto point = str;
    unsigned int ans = 0;
    while (*point != '\0') {
        if (*point >= 'A' && *point <= 'Z') {
            ++point;
            unsigned int add = 1;
            while (*point != ' ' && *point != '\0') {
                if (*point < 'a' || *point > 'z') {
                    add = 0;
                    break;
                }
                ++point;
            }
            ans+=add;
        }
        while (*point != ' ') {
            ++point;
        }
        point = next_word(point);
    }
    return ans;
}
unsigned int faStr3(const char *str)
{
    if(*str == '\0') {
        return 0;
    }
    auto point = str;
    unsigned int allLen = 0;
    unsigned int wordNum = 0;
    point = next_word(point);
    while (*point != '\0') {
        ++wordNum;
        while (*point != ' ' && *point != '\0') {
            ++point;
            ++allLen;
        }
        point = next_word(point);
    }
    return int(float(allLen)/float(wordNum)+0.5);
}