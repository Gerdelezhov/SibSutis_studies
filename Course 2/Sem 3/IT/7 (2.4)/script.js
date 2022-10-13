window.onload = init;
var Timer;

function init() {
    Timer = setInterval('newDate()', 1000);
}

var date = new Date().toLocale

function newDate() {
    date = new Date();
    HourMinPM();
    YMDay();
}

function HourMinPM() {
    var hour = date.getHours();
    if (hour > 11) {
        document.getElementById("pm").src = "dgpm.gif";
        hour = hour - 12;
    }
    else
        document.getElementById("pm").src = "dgam.gif";
    if (hour > 9)
        document.getElementById("h1").src = "dg1.gif";
    document.getElementById("h2").src = "dg" + (hour % 10) + ".gif";

    var min = date.getMinutes();
    document.getElementById("m2").src = "dg" + (min % 10) + ".gif";
    min = min / 10;
    document.getElementById("m1").src = "dg" + (Math.trunc(min)) + ".gif";

    var sec = date.getSeconds();
    console.log(sec);

    document.getElementById("s2").src = "dg" + (sec % 10) + ".gif";
    sec = sec / 10;
    document.getElementById("s1").src = "dg" + (Math.trunc(sec)) + ".gif";
    
}

function YMDay() {
    var day = date.getDate();
    document.getElementById("d2").src = "dg" + (day % 10) + ".gif";
    day = day / 10;
    document.getElementById("d1").src = "dg" + (Math.trunc(day)) + ".gif";

    var month = date.getMonth() + 1;
    document.getElementById("mo2").src = "dg" + (month % 10) + ".gif";
    month = month / 10;
    document.getElementById("mo1").src = "dg" + (Math.trunc(month)) + ".gif";

    var year = date.getFullYear();
    document.getElementById("y4").src = "dg" + (year % 10) + ".gif";
    year = year / 1000;
    document.getElementById("y1").src = "dg" + Math.trunc(year) + ".gif";
    var year = date.getFullYear();
    year = year / 100;
    document.getElementById("y2").src = "dg" + Math.trunc(year % 10) + ".gif";
    var year = date.getFullYear();
    year = year / 10;
    document.getElementById("y3").src = "dg" + Math.trunc(year % 10) + ".gif";
}