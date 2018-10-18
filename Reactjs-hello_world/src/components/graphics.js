import React from 'react';
import './styles/matrix.css';

export class GFX_Matrix {
  constructor(){
    this.wait = false;
  }
  start = async () => {
    if(!this.wait) {
      const animT = await document.getElementById('top');
      const animB = await document.getElementById('bottom');
      const overview_wrapper = await document.getElementById('App-Overviews');
      animT.style.animation = "slide_top 5s linear forwards";
      animB.style.animation = "slide_bottom 5s linear forwards";
      overview_wrapper.style.animation = "fade 7s linear forwards";   
      this.wait = true;
      setTimeout(() => this.reset(animT,animB, overview_wrapper), 5000);
    }    
  }
  reset = (...anims) => {
   anims.forEach((e) => e.style.animation = undefined);
   this.wait = false;
   clearTimeout();
  } 
  
  init = () => {
    return (
      <div onLoad={() => this.start()} >
        {/* TOP */}
        <img  id="top" className="top" style={{position: 'absolute', top: '-200%', opacity: 0, left: 0}} src={'images/gfx_matrix.png'} width="100%"/>
        {/* Bottom */}
        <img id="bottom" className="bottom" style={{position: 'absolute', bottom: '-200%', opacity: 0, left: 0, transform:'Rotate(180deg)'}} src={'images/gfx_matrix.png'} width="100%"/> 
      </div>
    );
  } 
}