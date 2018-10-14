Reflect.apply(console.log, 0, [(r = ((str = 'Hello, world!') => str.length === 0 ? str : `${r(str.substring(1))}${str[0]}`))()]);
