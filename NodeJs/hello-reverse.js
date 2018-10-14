Reflect.apply(console.log, {}, [(this.r = ((str = 'Hello, world!') => str.length === 0 ? str : `${this.r(str.substring(1))}${str[0]}`))()]);
