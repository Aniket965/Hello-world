console.log do main = (hello = 'Hello, world!'.split '') -> ([hello[i], hello[j]] = [hello[j], hello[i]] for i in [hello.length-1..1] when (j = Math.floor Math.random() * (i + 1))?) and hello.join ''
