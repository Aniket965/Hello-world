document.body.onload = function() {
   var canvasHidden = document.createElement('canvas')
   var ctxHidden = canvasHidden.getContext('2d') 
   var canvasShown = document.querySelector('canvas')
   canvasShown.width = 800
   canvasShown.height = 400
   var ctxShown = canvasShown.getContext('2d')

   

   function init() {
      canvasHidden.width = 800
      canvasHidden.height = 400

      ctxHidden.clearRect(0, 0, ctxHidden.width, ctxHidden.height)
      ctxHidden.textAlign = 'center'
      ctxHidden.textBaseLine = 'middle'
      ctxHidden.font = 'bold 100px VT323, monospace'
      ctxHidden.fillStyle = '#F44';

      ctxHidden.fillText('Namaskar Sansar', canvasHidden.width/2, canvasHidden.height/2)
      
      ctxShown.clearRect(0, 0, canvasShown.width, canvasShown.height)
      ctxShown.drawImage(canvasHidden, 0, 0)
      var i = 10; while(i--){ glitch() }
   }

   function glitch() {
      var width = 100 + Math.random()*100
      var height = 50 + Math.random()*50

      var x = Math.random()*canvasHidden.width
      var y = Math.random()*canvasHidden.height

      var dx = x + (Math.random() * 40 - 20)
      var dy = y + (Math.random() * 30 - 15)

      ctxShown.clearRect(x, y, width, height)
      ctxShown.fillStyle = '#4a6';
      //ctxShown.fillRect(x, y, width, height)
      ctxShown.drawImage(canvasHidden, x, y, width, height, dx, dy, width, height)
   }

   setInterval(function() {
       init()
   }, 1000/15)
}