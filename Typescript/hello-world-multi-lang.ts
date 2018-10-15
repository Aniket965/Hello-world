enum lan {
	en,
	es
}

class HelloWorld {
	private _message: string;
	private _lang: lan;

	constructor(lang: lan) {
		this._lang = lang;
	}

	get message(): string {
		switch(this._lang) {
			case lan.es:
				this._message = 'hola mundo';
				break;
			default:
				this._message = 'Hello world';
				break;
		}

		return this._message;
	}
}


const hw = new HelloWorld(lan.en);

console.log(hw.message);
