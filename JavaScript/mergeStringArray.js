function mergeStringArrays(a, b){
    var hash = {};
    var ret = [];

    for(var i=0; i < a.length; i++){
        var e = a[i];
        if (!hash[e]){
            hash[e] = true;
            ret.push(e);
        }
    }

    for(var i=0; i < b.length; i++){
        var e = b[i];
        if (!hash[e]){
            hash[e] = true;
            ret.push(e);
        }
    }

    return ret;
}
