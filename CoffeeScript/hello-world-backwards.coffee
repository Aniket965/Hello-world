Reflect.apply console.log, {}, [do r = ((str = 'Hello, world!') -> if str.length is 0 then str else "#{r str.substr 1}#{str[0]}")]
