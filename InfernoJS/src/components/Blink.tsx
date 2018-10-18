import './Blink.css';

const getBlinkClasses = (isBlinkOn: boolean): string => {
	return isBlinkOn ? 'blink' : 'blink blink__off';
};

export function Blink({ msg, blinkOn }: { msg: string, blinkOn: boolean }) {
	return <h1 className={getBlinkClasses(blinkOn)}>{msg}</h1>;
}
