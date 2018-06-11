bool isPalindrome(int x) {
    if (x < 0) return false;
    int tmp[10], i = 0, j, len;
    tmp[i] = x % 10;
    while (x /= 10) {
        tmp[++i] = x % 10;
    }
    len = i + 1;
    printf("%d", len);
    for (i = 0, j = len - 1; i < j ;i++, j--) {
        if (tmp[i] != tmp[j]) return false;
    }
    return true;
}
