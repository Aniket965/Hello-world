module.exports = {
  srcDir: 'src',
  head: {
    title: 'Hello word',
    link: [
      { rel: 'stylesheet', href: 'https://fonts.googleapis.com/css?family=Roboto:300,400,500,700|Material+Icons' }
    ],
  },
  build: {
    publicPath: '/',
    extend(config, ctx) {
    }
  }
}