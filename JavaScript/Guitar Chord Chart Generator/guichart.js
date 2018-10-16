// 20 sep 18 - o.js update
$ = function(selector) {
  return (selector.indexOf('.') == 0) ? document.querySelectorAll(selector) : document.querySelector(selector);
};

const guichart = {
  c: null,
  ctx: null,
  scale:1,
  palette:{
    base:'white',
    finger:'white',
    open:'black',
    nut:'black',
    special1:'dodgerblue',
    special2:'violet',
    fretNum:'black',
    fret:'black',
    string:'black',
    name:'black',
    circle:'MidnightBlue',
    circleText:'black'
  },
  drawNut: function() {
    var ctx = this.ctx;
    ctx.fillStyle = this.palette.nut;
    // ctx.fillStyle = '#bbb';
    ctx.fillRect(this.x-1,this.y-3*this.scale,5*this.stringPadding+2,3*this.scale);
    // ctx.fillStyle = '#bbb';
    // ctx.beginPath();
    // ctx.strokeStyle = '#bbb';
    // ctx.lineCap = 'round';
    // ctx.lineWidth = 3*this.scale;
    // ctx.moveTo(this.x+1*this.scale,this.y-2*this.scale);
    // ctx.lineTo(6*this.stringPadding+this.stringPadding/4,this.y-2*this.scale);
    // ctx.stroke();
    
    // ctx.lineWidth = 1;
  },
  drawString: function() {
    var ctx = this.ctx;
    ctx.beginPath();
    ctx.strokeStyle = this.palette.string;
    ctx.lineWidth = 1*this.scale
    // ctx.strokeStyle = '#bbb';
    for (var i=0; i<6; i++)
    {
      ctx.moveTo(this.x+i*this.stringPadding,this.y);
      ctx.lineTo(this.x+i*this.stringPadding,this.y+4*this.fretPadding);
    }
    ctx.stroke();
  },
  drawFret: function() {
    var ctx = this.ctx;
    ctx.beginPath()
    ctx.strokeStyle = this.palette.fret;
    // ctx.strokeStyle = '#bbb';
    for (var i=0; i < 5; i++)
    {
      ctx.moveTo(this.x,this.y+i*this.fretPadding);
      ctx.lineTo(this.x+5*this.stringPadding,this.y+i*this.fretPadding);
    }
    ctx.stroke();
  },
  calculateFret: function(chord) {
    var max = 4;
    var min = 1;
    chord = chord.split(',')
    if (chord.length == 1)
      chord = chord[0].split('');
    
    chord.forEach((t,i) => {
      if (t == 'a')
        chord[i] = 10;
    });
    for (var i=0,c,once=true; c=chord[i]*1,i < chord.length; i++)
    {
      if (c > max && once)
      {
        min = c;
        once = false;
      }
      if (c > max) max = c;
      if (c < min) min = c;
    }
    var fret;
    if (max-min <=2  && max > 4)
    {
      fret = max-2;
      if (max-min == 0)
        fret -= 1;
    }
    else
      fret = max-3;
      
    return fret;
  },
  drawFretNumber: function(fret) {
    var ctx = this.ctx;
    if (fret > 1)
    {
      // ctx.fillStyle = this.palette.fretNum;
      ctx.fillStyle = this.palette.fretNum;
      // ctx.filter = 'opacity(0.9)';
      ctx.font = 8*this.scale+"px monospace";
      var limit = fret+3;
      for (var i=fret,j=0; i < fret+4; i++,j++)
      {
        ctx.fillText(i,this.x+5*this.stringPadding+this.stringPadding/1.5,this.y+j*this.fretPadding+this.fretPadding/1.6);
      }
      // ctx.filter = 'opacity(1)';
    }
  },
  drawChord: function(c,f) {
    var ctx = this.ctx;
    // ctx.clearRect(this.x-this.stringPadding,this.y-this.fretPadding+1,8*this.stringPadding+2,5*this.fretPadding+2);
    ctx.beginPath();
    this.drawBase();
    var chord = c;
    var finger = f;
    var fret = this.calculateFret(chord);
    this.drawFretNumber(fret);
    this.drawString();
    this.drawFret();
    if (fret == 1) this.drawNut();
    chord = chord.split(',');
    if (chord.length === 1)
      chord = chord[0].split('');
    
    finger = finger.split('');
    
    var match = f.match(/1/g);
    var barMode = false;
    if (match !== null && match.length > 1)
    {
      barMode = true;
      col = this.palette.circle;
      var from = -1;
      var to = -1;
      for (var i=0; i<finger.length; i++)
        if (finger[i] == '1') { from=i;break; }
      for (i=finger.length; i>0; i--)
        if (finger[i] == '1') { to=i;break; }
      var jumps = to-from;
    }
    else
      col = this.palette.circle;
    
    for (i=0,c,f,fonce=false; c=chord[i],f=finger[i],i < chord.length; i++)
    {
      if (c == ' ' || c == 'x' || c == 0)
      {
       ctx.font = 10*this.scale+"px monospace";
       ctx.fillStyle = this.palette.open;
      // ctx.filter = 'opacity(0.7)';
       if (c == ' ')
          ctx.fillText(' ',this.x+i*this.stringPadding-3*this.scale,this.y-5*this.scale-this.fretPadding/10);
       else if (c == 0)
       {
        // ctx.beginPath();
        // ctx.arc(this.x+i*this.stringPadding-3*this.scale,this.y-5*this.scale-this.fretPadding/10,3,0,2*Math.PI);
            // ctx.stroke();
        // ctx.fillStyle = col;
        // ctx.fill();
             
          ctx.fillText('o',this.x+i*this.stringPadding-3*this.scale,this.y-5*this.scale-this.fretPadding/10);
       }
        else
          ctx.fillText('x',this.x+i*this.stringPadding-3*this.scale,this.y-5*this.scale-this.fretPadding/10);
      // ctx.filter = 'opacity(1)';
      }
      else
      {
        if (c == 'a')
          c = 10;
        
        if (c >= fret)
        {
          if (barMode && f == 1 && fonce === false)
          {
            fonce = true;
            ctx.beginPath();
            ctx.strokeStyle = col;
            ctx.lineCap = 'round';
            // ctx.shadowBlur = 2;
            // ctx.shadowColor = 'black';
            var xx = this.x+from*this.stringPadding;
            // var yy = this.y+(8*this.scale)+(c-(fret-1))*this.fretPadding-this.fretPadding/1.25;
            var yy = (c-(fret-1))*this.fretPadding+this.y-(this.fretPadding-this.fretPadding/1.5)*1.5;
            ctx.moveTo(xx,yy);
            // ctx.lineTo(xx+jumps*this.fretPadding/2,yy);
            // console.log(xx,jumps)
            ctx.lineTo(xx+jumps*this.stringPadding,yy);
            // ctx.lineWidth = 15*this.scale;
            // ctx.lineWidth = this.fretPadding/1.5;
            ctx.lineWidth = this.stringPadding/2.2*2;
            ctx.stroke();
            ctx.lineWidth = 1;
            // ctx.lineWidth = 0.5;
            // ctx.shadowBlur = 0;
            
             ctx.font = 11*this.scale+"px Cousine";
             ctx.fillStyle = this.palette.finger;
             var midd = this.originX + this.stringPadding*(from+1) + ((this.stringPadding*(to+1) - this.stringPadding*from))/2 - this.stringPadding/2.5;
            // console.log(from,to)
            ctx.fillStyle = this.palette.circleText;
            ctx.fillText(f,midd,this.y+(c-(fret-1))*this.fretPadding-this.fretPadding/2+this.stringPadding/5.2);
          }
          else
          {
            
             if (f == 1 && fonce) continue;
               
             ctx.beginPath();
              ctx.shadowBlur = 2;
              ctx.shadowColor = 'black';
              ctx.arc(this.x+i*this.stringPadding,this.y+(c-(fret-1))*this.fretPadding-this.fretPadding/2,this.stringPadding/2.2,0,2*Math.PI);
            // ctx.stroke();
             ctx.fillStyle = col;
             ctx.fill();
              ctx.shadowBlur = 0;
             
             if (f !== undefined)
             {
               ctx.font = 10*this.scale+"px monospace";
              // ctx.fillStyle = this.palette.finger;
               ctx.fillStyle = this.palette.circleText;
              // ctx.fillText(f,this.x+i*this.stringPadding-3.2*this.scale,this.y+(c-(fret-1))*this.fretPadding-this.fretPadding/2+this.stringPadding/4.5);
               var txtW = ctx.measureText(f).width;
               ctx.fillText(f,this.x+i*this.stringPadding-txtW/2,this.y+(c-(fret-1))*this.fretPadding-this.fretPadding/2+txtW/2);
             }
          }
        }
      }
    }
  },
  drawBase: function() {
    var c = this.c;
    var ctx = this.ctx;
    ctx.fillStyle = this.palette.base;
    ctx.fillRect(this.x,this.y,(this.stringPadding*5),(this.fretPadding*4));
  },
  drawChordName: function(name) {
    var ctx = this.ctx;
    // ctx.clearRect(0,this.y+4*this.fretPadding+5,this.c.width,30);
    ctx.beginPath();
    // ctx.fillStyle = 'rgba(0,0,0,0)';
    // ctx.fillStyle = 'green';
    // ctx.fillRect(0,this.y+4*this.fretPadding+5,this.c.width,30);
    if (name.indexOf('*') > 0)
    {
      ctx.fillStyle = this.palette.special1;
      ctx.fillRect(this.x+6*this.stringPadding-5,this.y+4*this.fretPadding+5,5,5);
      if (name.indexOf('**') > 0)
      {
        ctx.fillStyle = this.palette.special2;
        ctx.fillRect(7*this.stringPadding-5,this.y+4*this.fretPadding+10,5,5);
      }
      name = name.replace(/\*+/,'');
    }
    ctx.fillStyle = this.palette.name;
    ctx.font = 32*this.scale+"px Chathura";
    var txtWidth = ctx.measureText(name).width;
    // ctx.fillText(name,this.x+2+((4*this.stringPadding-(name.length-1)*this.stringPadding))/2,this.y+5*this.fretPadding);
    // if (name.indexOf('#') > 0)
    // {
    //   name = name.replace('#','');
    //   txtWidth = ctx.measureText(name).width;
    //   // var txtWidth = ctx.measureText(name.slice(0,1)).width;
    //   var first = ctx.measureText(name.slice(0,1)).width;
    //   ctx.font = 18*this.scale+"px cousine";
    //   ctx.fillText('#',this.x+(5*this.stringPadding-txtWidth)/2+first,this.y+5*this.fretPadding-this.fretPadding/2.2);
    //   ctx.font = 24*this.scale+"px cousine";
    // }
    
    ctx.fillText(name,this.x+(5*this.stringPadding-txtWidth)/2,this.y+5*this.fretPadding);
    
  },
  init: function(chart,canvas,customChart) {
    if ($('#chartLimbo') === null)
    {
      var el = document.createElement('div');
      el.setAttribute('id','chartLimbo');
      el.setAttribute('style','height:0;overflow:hidden;');
      document.body.appendChild(el);
    }
    
    $('#chartLimbo').innerHTML = '<canvas id="guichartCanvas" width="120" height="170"></canvas>';
    
    if (canvas === undefined)
    {
      this.c = $('#guichartCanvas');
      this.ctx = this.c.getContext("2d");
    }
    else
    {
      this.c = canvas;
      this.ctx = canvas.getContext("2d");
    }
  
    var x = 0;
    var y = 0;
    this.padding = 20*this.scale;
    this.stringPadding = 15*this.scale;
    // this.fretPadding = 30*this.scale;
    // this.fretPadding = 25*this.scale;
    this.fretPadding = 23*this.scale;
    this.originX = x;
    this.originY = y;
    this.x = x+this.padding;
    this.y = y+this.padding+this.padding/5;
  
    this.drawBase();
    
    if (customChart === undefined)
    {
      var d = chartData[chart.id];
      var i = chart.type;
      this.drawChord(d.fret[i],d.finger[i]);
      this.drawChordName(chart.name);
    }
    else
    {
      var d = customChart;
      this.drawChord(d.fret,d.finger);
      this.drawChordName(d.name);
    }
    
    if (canvas === undefined)
    {
      this.c = $('#guichartCanvas').setAttribute('id','');
      return $('#chartLimbo').childNodes[0];
    }
    else
    {
      return this.ctx;
    }
  }
};