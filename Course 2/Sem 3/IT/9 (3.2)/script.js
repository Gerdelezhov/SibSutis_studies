var count, namec, datec;
var year, mounth, day, hour, min, second;
var ip = location.host;

function setCookie(name, value) {
    document.cookie = name + "=" + encodeURIComponent(value) + "; path=path";
}

function get_cookie(cookie_name) {
    var results = document.cookie.match('(^|;) ?' + cookie_name + '=([^;]*)(;|$)');
    if (results)
        return decodeURIComponent(results[2]);
    else
        return null;
}

window.onload = function () {
    var s_name = get_cookie("name");
    if (s_name == "" || s_name == null) {
        text = "Зарегистрируйтесь!";
        setCookie("countEnter", 0);
    }
    else {
        var text
        var s_lastname = ' ' + get_cookie("lastname") + ' ';
        var s_sity = get_cookie("sity");
        var count = get_cookie("countEnter");
        console.log(s_name);
        console.log(s_lastname);
        console.log(s_sity);
        text = "Привет, " + s_name + s_lastname + 'из города ' + s_sity + '!';
        text += '<br>Количество посещений этой страницы ' + count;
        count++;
        /*namec = sn;
        sn = get_cookie("countEnter");
        count = parseInt(sn);
        count++;
        text += "<br> Количество посещений этой страницы: " + count;
        sn = get_cookie("expires")
        datec = sn;
        var d = new Date();
        d.setTime(Date.parse(datec));
        min = (d1.getMinutes() - d.getMinutes());
        hour = (d1.getHours() - d.getHours());
        second = (d1.getSeconds() - d.getSeconds());
        text += "<br> Вы были на этой странице: " + hour + " часов, " + min + " минут, " + second + " секунд назад";
        var today = new Date()
        var expires = new Date()
        expires.setTime(today.getTime() + 1000 * 60 * 60 * 24 * 365);
        setCookie("expires", expires.toGMTString());*/
        setCookie("countEnter", count);
    }
    document.getElementById('d1').innerHTML = text;
}

function setCookies() {
    var today = new Date()
    var expires = new Date()
    expires.setTime(today.getTime() + 1000 * 60 * 60 * 24 * 365);

    setCookie("name", document.getElementById("text1").value);
    setCookie("lastname", document.getElementById("text2").value);
    setCookie("sity", document.getElementById("text3").value);
    setCookie("countEnter", 0);
    confirm("Куки сохранены");
}

function deleteKookies() {
    setCookie("name", "");
    setCookie("lastname", "");
    setCookie("sity", "");
    setCookie("countEnter", 0);
    alert("Куки удалены");
}