a1 = document.getElementById("m1");
a2 = document.getElementById("m2");
a3 = document.getElementById("m3");
a4 = document.getElementById("m4");

let flag = true;
let task_flag = true;
let timer;
let task_timer;

function task_Mover(elem) {
    if (!task_flag) {
        task_flag = true;
        clearTimeout(task_timer);
    }
    if (a4.style.display == "block") {
        a4.style.display = "none";
    }

    elem.style.display = "block";
}

function task_Mout(elem) {
    if (task_flag) {
        task_flag = false;
        task_m = elem;
        task_timer = setTimeout("task_m.style.display = 'none'", 2000);
    }
}

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
