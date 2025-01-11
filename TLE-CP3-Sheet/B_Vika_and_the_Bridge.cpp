function mergeArrays(a, b) {
    const ans = [];
    let i = 0, j = 0;
    while (i < a.length && j < b.length) {
        if (a[i] <= b[j]) {
            ans.push(a[i]);
            i++;
        } else {
            ans.push(b[j]);
            j++;
        }
    }
    while (i < a.length) {
        ans.push(a[i]);
        i++;
    }
    while (j < b.length) {
        ans.push(b[j]);
        j++;
    }
    return ans;
}
