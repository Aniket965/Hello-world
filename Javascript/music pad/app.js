window.addEventListener('keydown',(e)=>{
    const audio = document.querySelector(`audio[data-key="${e.which}"]`);
    const key = document.querySelector(`.key[data-key="${e.which}"]`);
    const keys = document.querySelectorAll('.key');
    if(!audio) return;

    audio.currentTime = 0;
    audio.play();
    key.classList.add('playing');

    function endTransition(e)
    {
        this.classList.remove('playing');
    }

    keys.forEach(key => key.addEventListener('transitionend',endTransition))
})