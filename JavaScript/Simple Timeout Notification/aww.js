const aww = {
  pop: function(txt,persistence,timeout) {
    peristence = (persistence === undefined) ? false : persistence;
    if (document.getElementById('_awwPop') === null)
    {
      var d = document.createElement('div');
      d.setAttribute('id','_awwPop');
      d.setAttribute('style','top:0;position:fixed;padding:4px;z-index:1000;-webkit-transform:translateY(-100px);transform:translateY(-100px);-webkit-transition:-webkit-transform 500ms;transition:transform 500ms;width:100%;text-align:center;width:auto;');
      d.innerHTML = "<p style='background:white;border-radius:2px;display:inline-block;padding:4px 8px;margin:0;font-size:0.8em;color:#000!important;'>"+txt+"</p>";
      document.body.appendChild(d);
      d.style.left = 50-document.getElementById('_awwPop').offsetWidth/screen.width*100+'%';
    }
    else
      document.getElementById('_awwPop').innerHTML = "<p style='background:white;border-radius:2px;display:inline-block;padding:4px 8px;margin:0;font-size:0.8em;color:#000!important;'>"+txt+"</p>";
    
    setTimeout(function() {
      document.getElementById('_awwPop').style.webkitTransform = 'translateY(0px)';
      document.getElementById('_awwPop').style.transform = 'translateY(0px)';
      if (!persistence)
      {
        if (timeout === undefined)
          timeout = 2000;
        setTimeout(function() {
          document.getElementById('_awwPop').style.webkitTransform = 'translateY(-100px)';
          document.getElementById('_awwPop').style.transform = 'translateY(-100px)';
        },timeout);
      }
    },1);
  }
};
