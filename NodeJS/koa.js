const Koa = require('koa');
const app = new Koa();

app.use(ctx => {
  ctx.body = 'Hello World';
});

app.listen(8080, () => {
  console.log('goto http://localhost:8080');
});
