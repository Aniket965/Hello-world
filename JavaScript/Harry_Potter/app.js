window.addEventListener('DOMContentLoaded',()=>{
    const textDiv = document.getElementById('text');
    const feather = document.querySelector('.feather');
    window.SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;  
    const recognition = new SpeechRecognition();
    
    recognition.start();
    console.log('started');
    recognition.addEventListener('result',(result)=>{
        console.log('listned');
        console.log(result.results[0][0].transcript);
        let listenedWord = result.results[0][0].transcript;
        if(listenedWord.toLowerCase() === 'wingardium leviosa' || listenedWord.toLowerCase() === 'float')
          {
            feather.classList.add('float');
          }
        textDiv.innerHTML="Heard:";
        textDiv.innerHTML = textDiv.innerHTML+" "+listenedWord;
    });
    
    feather.addEventListener('animationstart',()=>{
      
    });
    feather.addEventListener('animationend',()=>{
         feather.classList.remove('float');
         recognition.start();
    });

    recognition.addEventListener('end', recognition.start);
});