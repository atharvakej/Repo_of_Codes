function majorElement(arr) {
    let candidate = arr[0];
    let count = 1;
  
    for (let i = 1; i < arr.length; i++) {
      if (arr[i] === candidate) {
        count++;
      } else if (count === 0) {
        candidate = arr[i];
        count = 1;
      } else {
        count--;
      }
    }
  
    count = 0;
    for (let i = 0; i < arr.length; i++) {
      if (arr[i] === candidate) {
        count++;
      }
    }
  
    if (count > arr.length / 2) {
      return candidate;
    } else {
      return -1;
    }
  }
  
  // Example usage:
  const arr = [2, 2, 3, 4, 2, 3, 2, 2];
  const result = majorElement(arr);
  console.log(result); // Output: 2