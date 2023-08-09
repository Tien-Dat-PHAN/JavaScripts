var x;
let name;

function reg(x) {
    if (x == 1) {
        return 1;
    }
    return x*reg(x-1);
}

console.log(reg(3));

var y = [1,2,3,4,5,6];


var matrix = [[1,2,3],
            [4,5,6]];

for (let i = 0; i < 2; i++) {
        for (let j = 0; j <3; j++ ){
            console.log(matrix[i][j]);
        }
        
                
    }