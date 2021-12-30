var fs = require("fs");

fs.readFile('Node.js/input.txt', function (err, data) {
    if (err) return console.error(err);
    console.log(data.toString());
});

console.log("The program is end!");