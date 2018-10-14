import * as ReactDOM from "react-dom";
import * as React from "react";
import HelloWorld from "./compoents/helloWorld";

const rootElement: HTMLElement = document.getElementById("rootElement");
if (rootElement) {
    ReactDOM.render(
        <HelloWorld greeting="Hello World!"/>,
        rootElement,
    );
}
