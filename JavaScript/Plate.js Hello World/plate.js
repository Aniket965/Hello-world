// v0.24 - 12 oct 2018 - adding "-" or no w3-row type
// v0.23 - 4 oct 2018 - adding pantry prefix, changed template
// v0.22 - 3 oct 2018 - chaning style to {}
// v0.21 - 28 sep 2018 - padding left
// v0.20 - 24 sep 2018 - added css shorthand : position relative & absolute
// v0.19 - 21 sep 2018 - added pantry & pantry template
// v0.18 - 20 sep 2018 - added important css, global plate html body

var plate = {
  skipTag: ['styl','scri'],
  lt: String.fromCharCode(60),
  gt: String.fromCharCode(62),
  tag: function(t,attr,noClose) {
    var finalAtt = '';
    var content, j, cls;
    for (var i in attr)
    {
      content = '';
      cls = '';
      if (attr[i] !== null)
      {
        switch (i)
        {
          case 'sty':
            content = ' style="';
            for (j=0; j<attr[i].length; j++)
              content += attr[i][j].substring(1,attr[i][j].length-2).replace(/posa/g,'position:absolute').replace(/pl:/g,'padding-left:').replace(/posr/g,'position:relative').replace(/!;/g,'!important;');
            content += '"';
            break;
          case 'att':
            content = ' ';
            for (j=0; j<attr[i].length; j++)
              content += attr[i][j].substring(1,attr[i][j].length-2);
            break;
          case 'cls':
            content = ' class="';
            cls = ' '+attr[i].join('');
            cls = cls.replace(/ \+/g,' w3-');
            cls = cls.replace(/ \./g,' ').trim();
            content += cls+'"';
            break;
          case 'id':
            content = ' id="';
            content += attr[i][0].substring(1).trim();
            content += '"';
            break;
        }
        finalAtt += content;
      }
    }
    
    if (noClose)
    {
      this.closeTag = this.lt+'/'+t+this.gt;
      return this.lt+t+finalAtt+this.gt;
    }
      return this.lt+t+finalAtt+this.gt+attr.innerHTML+this.lt+'/'+t+this.gt;
  },
  grill: function(m,useSlice,fonts,fontStyle) {
    var isPlate = m.indexOf('!'+'--plate-');
    var isPantry = m.indexOf('!'+'--pantry-');
    var id, plateData;
    if (m.charAt(0) == '[' && !useSlice)
    {
      var noClose, type;
      if (m.charAt(m.length-1) == ']')
      {
        m = m.substring(0,m.length-1)+' ';
        noClose = false;
      }
      else
      {
        m += ' ';
        noClose = true;
      }
      
      var data = {
        sty: m.match(/\{.*?\} /g),
        att: m.match(/\|.*?\| /g),
        cls: m.match(/(\.|\+)(\w|\d|-|_)*? /g),
        id: m.match(/@.*? /g),
        innerHTML: ''
      };
      
      if (data.cls === null) data.cls = [];
      
      switch (m.charAt(1))
      {
        case '-':
          m = this.tag('div',data,noClose);
          break;
        case ' ':
          data.cls.push('+row ');
          m = this.tag('div',data,noClose);
          break;
        case 'c':
          if (m.charAt(2) == 'x')
            data.cls.push('+rest ');
          else
            data.cls.push('+col ');
          m = this.tag('div',data,noClose);
          break;
        case 'a':
        case 'b':
        case 's':
        case 'l':
          data.innerHTML = m.split(' ##')[0].substring(3);
          type = 'a';
          if (m.charAt(1) == 'b') type = 'button';
          else if (m.charAt(1) == 's') type = 'span';
          else if (m.charAt(1) == 'l') type = 'label';
          m = this.tag(type,data,noClose);
          break;
        case 'i':
        case 't':
          type = 'input';
          if (m.charAt(1) == 't') type = 'textarea';
          m = this.tag(type,data,noClose);
          break;
        case 'M':
          data.cls.push('.material-icons ');
          data.innerHTML = m.split(' ')[0].substring(3);
          m = this.tag('i',data,noClose);
          break;
        case 'f':
          font = m.substring(3,m.length-1);
          fonts.push(font.replace(/ /g,'+'));
          fontStyle.push('.ft-'+font.charAt(0).toLowerCase()+'{font-family:"'+font+'"}');
          m = '';
          break;
      }
    }
    else if (m.charAt(0) == ']' && !useSlice)
      m = this.closeTag;
    else if (isPlate > 0)
    {
      id = m.split('plate-')[1].split('-->')[0];
      plateData = eval('tmp = '+id.split('@ ')[1]);
      id = id.split(' @')[0];
      if ($('#plate-'+id) !== null)
      {
        if (plateData === undefined)
          m = plate.cook($('#plate-'+id).innerHTML);
        else
          m = plate.cook(o.creps('plate-'+id,plateData));
      }
      else
        console.log('plate template id:'+id+' not found');
    }
    else if (isPantry > 0)
    {
      id = m.split('pantry-')[1].split('-->')[0];
      plateData = eval('tmp = '+id.split('@ ')[1]);
      id = id.split(' @')[0];
      if ($('#pantry-'+id) !== null)
      {
        if (plateData === undefined)
          m = plate.cook($('#pantry-'+id).innerHTML);
        else
          m = plate.cook(o.creps('pantry-'+id,plateData));
      }
      else
        console.log('pantry id:'+id+' not found');
    }
    
    return m;
  },
  cook: function(meat,slice) {
    var useSlice = (slice !== undefined);
    var farm = false;
    if (meat === undefined)
      meat = document.body.innerHTML;
    else
      farm = true;
    
    var fonts = [];
    var fontStyle = [];
    
    meat = meat.split('\n');
    var skip = -1;
    var m, txt, idx;
    for (var i=0; i<meat.length; i++)
    {
      m = meat[i].trim();
      txt = m.split(' ')[0].substring(1,5);
      if (skip >= 0)
      {
        if (txt == '/'+this.skipTag[skip].substring(0,3))
          skip = -1;
        continue;
      }
      
      idx = this.skipTag.indexOf(txt);
      if (idx >= 0)
      {
        if (m.indexOf('/'+this.skipTag[idx]) < 0)
          skip = idx
        continue;
      }
      
      meat[i] = this.grill(m,useSlice,fonts,fontStyle);
    }
    
    meat = meat.join('\n');
    
    if (fonts.length > 0)
    {
      document.head.appendChild(o.cel('link',{rel:'stylesheet',href:'https://fonts.googleapis.com/css?family='+fonts.join('|')}));
      document.head.appendChild(o.cel('style',{innerHTML:'\n'+fontStyle.join('\n')+'\n'}));
    }
    
    if (farm)
      return meat;
    else
      document.body.innerHTML = meat;
  },
  getPantryTemplate: function() {
    if ($('#plate-limbo-invisible') === null)
      document.body.appendChild(o.cel('div',{id:'plate-limbo-invisible',style:'opacity:0;position:absolute;z-index:-1;'}));
    var copy = o.cel('input',{value:"<div id='template'></div><script>window.parent.postMessage({type:'pantry',content:document.getElementById('template').innerHTML},'*'); </script>"})
    $('#plate-limbo-invisible').appendChild(copy)
    copy.select();
    console.log('Pantry template copied. Place pantry file inside folder named "pantry".')
    document.execCommand("copy");
    $('#plate-limbo-invisible').removeChild(copy);
  },
  pantry: function(food,callback,prefix) {
    if (typeof(food) !== 'object')
    {
      console.log('plate.js : Pantry food type should be array.')
      return;
    }
    plate.pantry.loading = food.length;
    window.addEventListener('message',receive);
    
    if ($('#plate-limbo') === null)
      document.body.appendChild(o.cel('div',{id:'plate-limbo',style:'height:0px;overflow:hidden;'}));
      
    o.for(food,function(i,f)
    {
      $('#plate-limbo').appendChild(o.cel('iframe',{src:f+'.html'}));
    })
    
    if (prefix === undefined)
      prefix = 'PT-';
    
    function receive(e) {
      if (e.data.type == 'pantry')
      {
        var data = e.data.content.replace(/<template id="/g,'<template id="'+prefix)
          
        document.body.appendChild(o.cel('div',{innerHTML:data}))
        
        plate.pantry.loading -= 1;
        if (plate.pantry.loading == 0)
        {
          window.removeEventListener('message',receive);
          if (callback !== undefined)
            callback();
        }
      }
    }
  }
};