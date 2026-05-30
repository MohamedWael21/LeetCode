function largestNumber(nums: number[]): string {
    const ans =  nums.map((num) => num.toString() ).sort((a, b) => {
        const concat1 = a+b;
        const concat2 = b+a;
        return concat1.localeCompare(concat2) * -1;
        
    }).join("");
    if(ans.startsWith("0")) return "0";
    return ans;
    
};



