(async () => {
	const text = await Promise.resolve('Hello world')
	console.log(text)
})()
