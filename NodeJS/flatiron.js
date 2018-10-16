var flatiron = require('flatiron');
var app = flatiron.app;

app.use(flatiron.plugins.http);

app.router.get('/', function () {
  this.res.writeHead(200, {
    'Content-Type': 'text/plain'
  });

  this.res.end('Hello world!\n');
});

app.start(8080, function(err) {
  if (err) {
    app.log.error(err.message);

    return process.exit(1);
  }

  app.log.info('Listening at http://localhost:8080');
});
