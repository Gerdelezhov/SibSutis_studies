a1 = document.getElementById("m1");
a2 = document.getElementById("m2");
a3 = document.getElementById("m3");

let flag = true;
let timer;
function Mover(elem) {
    if (!flag) {
        flag = true;
        clearTimeout(timer);
    }
    if (a1.style.display == "block") {
        a1.style.display = "none";
    }
    if (a2.style.display == "block") {
        a2.style.display = "none";
    }
    if (a3.style.display == "block") {
        a3.style.display = "none";
    }

    elem.style.display = "block";
}

function Mout(elem) {
    if (flag) {
        flag = false;
        m = elem;
        timer = setTimeout("m.style.display = 'none'", 2000);
    }
}

function Aover(elem) {
    elem.style.background = "blue";
}

function Aout(elem) {
    elem.style.background = "#01796f";
}
