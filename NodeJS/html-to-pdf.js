var wkhtmltopdf = require('wkhtmltopdf');
 
// URL
wkhtmltopdf('http://google.com/', { pageSize: 'letter' })
  .pipe(fs.createWriteStream('out.pdf'));
  
// HTML
wkhtmltopdf('<h1>Test</h1><p>Hello world</p>')
  .pipe(res);
 
// Stream input and output
var stream = wkhtmltopdf(fs.createReadStream('file.html'));
 
// output to a file directly
wkhtmltopdf('http://apple.com/', { output: 'out.pdf' });
 
// Optional callback
wkhtmltopdf('http://google.com/', { pageSize: 'letter' }, function (err, stream) {
  // do whatever with the stream
});
 
// Repeatable options
wkhtmltopdf('http://google.com/', {
  allow : ['path1', 'path2'],
  customHeader : [
    ['name1', 'value1'],
    ['name2', 'value2']
  ]
});
 
// Ignore warning strings
wkhtmltopdf('http://apple.com/', { 
  output: 'out.pdf',
  ignore: ['QFont::setPixelSize: Pixel size <= 0 (0)']
});
// RegExp also acceptable
wkhtmltopdf('http://apple.com/', { 
  output: 'out.pdf',
  ignore: [/QFont::setPixelSize/]
});