// timeStamp should be in UNIX timestamp (seconds since 1 JAN 1970)

export function timeSince(timeStamp) {
    var time = new Date(timeStamp);
    var ago = " ago";
    var now = new Date(),
        secondsPast = (now.getTime() - time.getTime()) / 1000;
    if (secondsPast < 60) {
        return parseInt(secondsPast) + 's' + ago;
    }
    if (secondsPast < 3600) {
        return parseInt(secondsPast / 60) + 'm' + ago;
    }
    if (secondsPast <= 86400) {
        return parseInt(secondsPast / 3600) + 'h' + ago;
    }
    if (secondsPast > 86400) {
        var day = time.getDate();
        var month = time.toDateString().match(/ [a-zA-Z]*/)[0].replace(" ", "");
        var year = time.getFullYear() == now.getFullYear() ? "" : " " + time.getFullYear();
        return day + " " + month + year;
    }
}
