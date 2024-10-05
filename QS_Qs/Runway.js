function countPlatforms(n, arr, dep) {
    for (let i = 0; i < n; i++) {
        if (dep[i] < arr[i]) {
            dep[i] += 2400; 
        }
    }
    arr.sort((a, b) => a - b);
    dep.sort((a, b) => a - b);
    let count = 1, ans = 1;
    let i = 1, j = 0;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            count++;
            i++;
        } else {
            count--;
            j++;
        }
        ans = Math.max(ans, count);
    }
    return ans;
}

// Example usage:
let arr = [0900, 0920, 0950, 1000, 1100, 1800];
let dep = [0930, 1200, 1120, 1130, 1900, 2000];
let n = dep.length;
console.log("Minimum number of Platforms required " + countPlatforms(n, arr, dep));