import { render, version, Component } from 'inferno';
import { Blink } from './components/Blink';

const container = document.getElementById('app');

class MyComponent extends Component<any, any> {
	private tsxVersion = '3.0.3';

	constructor(props, context) {
		super(props, context);

		this.state = {
			isBlinkOn: true
		};
	}

	public componentDidMount() {
		setInterval(() => {
			this.setState({ isBlinkOn: !this.state.isBlinkOn });
		}, 1000);
	}

	public render() {
		return (
			<div>
				<h3>{`Welcome to InfernoJS v${version} w/ TS v${this.tsxVersion}`}</h3>
				<Blink msg={'Hello World!'} blinkOn={this.state.isBlinkOn} />
			</div>
		);
	}
}

render(<MyComponent />, container);
