const hello = async (name) => {
  console.time('hello')
  console.log(`Hello ${name}`)
}

hello('World')
  .then(res => {
    console.timeEnd('hello')
  })
  .catch(err => {
    console.log(err)
    console.timeEnd('hello')
  })
