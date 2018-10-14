cache = {0:0, 1:1}

function fibonacci(n) {
    if (n in Object.keys(cache)) {
        return cache[n];
    } else {
        cache[n] = fibonacci(n-1) + fibonacci(n-2);
        return cache[n];
    }
}
