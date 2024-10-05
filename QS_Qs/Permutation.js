function isPermutation(s1, s2) {
    // Create frequency maps for both strings
    const freqMap1 = new Map();
    const freqMap2 = new Map();
  
    for (const char of s1) {
      freqMap1.set(char, (freqMap1.get(char) || 0) + 1);
    }
  
    for (const char of s2) {
      freqMap2.set(char, (freqMap2.get(char) || 0) + 1);
    }
  
    // Check if all characters in s1 are present in s2 with the same frequency
    for (const [char, freq] of freqMap1) {
      if (!freqMap2.has(char) || freqMap2.get(char) !== freq) {
        return false;
      }
    }
  
    return true;
  }
  
  // Example usage:
  const s1 = "tac";
  const s2 = "catering";
  const result = isPermutation(s1, s2);
  console.log(result); // Output: true