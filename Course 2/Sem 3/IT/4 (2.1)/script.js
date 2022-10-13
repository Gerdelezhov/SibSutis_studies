var i;

function set_image() {
    var swap;
    swap = document.one.src;
    document.one.src = document.two.src;
    document.two.src = swap;
}
