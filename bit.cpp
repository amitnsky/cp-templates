// Define MXN !!
struct FenwickTree {
    int bit[MXN]={0};  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
    }
    
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
