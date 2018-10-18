
// DOM SELECTION
const header = document.querySelector(".header");
const container = document.querySelector(".container");
const contSearch = document.querySelector(".container--search");
const contImg = document.querySelector(".container--img");
const contText = document.querySelector(".container--text");
const searchImg = document.querySelector("#search-img");

const output = document.querySelector(".output");
const outputImg = document.querySelector(".output--img");
const outputDL = document.querySelector(".output--download");


const url = "https://api.imgflip.com/get_memes";


// function data(searched) {

//     // searched.toLowerCase();


//     // Fetching data from api and extracting name and url
//     fetch(url)
//     .then(res => res.json())
//     .then(res => {
//         res.data.memes.forEach(meme => {
//             if (meme.name.toLowerCase().includes(searched)) {
//                 name = meme.name;
//                 imgUrl = meme.url;

//                 return {name: name, imgUrl: imgUrl};
//             }
//         })
//     });


// }



// contSearch.addEventListener("keypress", function(e) {
//         let name;
//         let imgUrl;



//             fetch(url)
//     .then(res => res.json())
//     .then(res => {
//         res.data.memes.forEach(meme => {
//             if (meme.name.toLowerCase().includes(contSearch)) {
//                 name = meme.name;
//                 imgUrl = meme.url;
//     console.log(name);
//             }
//         })
//     });

//     if (e.which === 13) {


//     }
// })


// Enter key, keypress event to look for meme
contSearch.addEventListener("keypress", function(e) {
        let names = [];
        let urls = [];

    if (e.which === 13) {
        // Fetching data for meme name and img url
        fetch(url)
        .then(res => res.json())
        .then(res => {
            let memesArr = res.data.memes;
            memesArr.forEach(meme => {
                if (meme.name.toLowerCase().includes(contSearch.value.toLowerCase())) {
                    names.push(meme.name);
                    urls.push(meme.url);
                }
            });
            // Get first meme and put img into img box and name on header
            if(names[0]) {
                header.textContent = `${names[0]} is the one!`;
                searchImg.setAttribute("src", urls[0]);
            }
        });

       
    }
});
