import * as React from "react";

interface IProps {
    greeting: string;
}

export default class HelloWorld extends React.Component<any, any> {
    public render(): JSX.Element {
        return (
            <span>{this.props.greeting}</span>
        );
    }
}
