/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    // i/n  -> row
    // i%n -> col
    let m =  matrix.length;
    let n = matrix[0].length;
    let l = 0, r = m*n-1;
    while(l<=r){
        let mid = Math.floor(l+(r-l)/2);
        let row = Math.floor(mid/n);
        let col = mid%n;
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) r = mid-1;
        else l = mid+1;
    }
    return false;

};
