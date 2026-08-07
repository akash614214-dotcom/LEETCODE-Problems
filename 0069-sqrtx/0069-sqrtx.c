int mySqrt(int x) {
    if (x < 2)
        return x;

    long long l = 1, r = x, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (m * m == x)
            return m;

        if (m * m < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return r;
}