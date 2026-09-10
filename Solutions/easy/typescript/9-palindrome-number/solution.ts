function isPalindrome(x: number): boolean {
    
    const s = x.toString();

    let left = 0, right = s.length-1;

    while(left < right){
        if(s[left] != s[right]){
            return false;
        }

        ++left;
        --right;
    }

    return true;
};