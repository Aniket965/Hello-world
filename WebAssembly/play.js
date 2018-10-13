
function main(wasm) {
    const memory   = wasm.exports.memory;
    const length   = wasm.exports.length;
    const position = wasm.exports.position;

    const bytes = new Uint8Array(memory.buffer, position, length);
    const s = new TextDecoder('utf8').decode(bytes);

    console.log(s);
}

fetch("main.wasm").then(reponse =>
    reponse.arrayBuffer()
).then(bytes =>
    WebAssembly.instantiate(bytes, {})
).then(result =>
    result.instance
).then(main);
