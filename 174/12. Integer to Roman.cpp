/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    const romans = [["M", 1000], ["D", 500], ["C", 100], ["L", 50], ["X", 10], ["V", 5], ["I", 1]];
    const specials = {4: "IV", 9:"IX", 40:"XL", 90:"XC", 400:"CD", 900: "CM"};
    function convert(n){
        if(n in specials) return specials[n];
        let str = "";
        while(n){
            const f = romans.find((r)=> n-r[1] >=0);
            n -= f[1];
            str += f[0];
        }
        return str;
    }

    let ans = [];
    let mul = 1;
    while(num){
        let curr = num % 10;
        ans.push(convert(curr*mul));
        num = Math.floor(num/10);
        mul *= 10;
    }
    return ans.reverse().join("");
    
};
