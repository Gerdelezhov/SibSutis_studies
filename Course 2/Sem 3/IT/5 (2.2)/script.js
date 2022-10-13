var image = document.getElementById("image");
var image2 = document.getElementById("image2");

let timer;
let i = 2;
let sec = 200;
let flag = 0;
let count = 0; 

function run() {
    flag = 1;
    clearInterval(timer);
    timer = setInterval(tim, sec);
};

function pause() {
    flag = 0
    clearInterval(timer);
};

function faster() {
    if (flag == 1) {
        sec -= 100;
        clearInterval(timer)
        timer = setInterval(tim, sec);
    }
};

function slower() {
    if (flag == 1) {
        sec += 100;
        clearInterval(timer);
        timer = setInterval(tim, sec);
    }
};

function tim() {
    if (i == 13) {
        i = 1;
    }
    if(i == 9){
        count++;
    }
    if(count % 2 == 0){
        image.src = "s" + i + ".gif";
        i++;
    } else {
        image2.src = "s" + i + ".gif";
        i++;
    }
};