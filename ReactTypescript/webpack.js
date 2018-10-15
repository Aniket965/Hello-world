// const path = require("path");
const { CheckerPlugin } = require("awesome-typescript-loader");

module.exports = {
    mode: "development",
    entry: {
        app: "./src/app.tsx"
    },
    resolve: {
        extensions: [".ts", ".tsx", ".js"]
    },
    module: {
        rules: [
            {
                test: /\.tsx?$/,
                loader: "awesome-typescript-loader",
                exclude: /node_modules/
            }
        ]
    },
    plugins: [
        new CheckerPlugin()
    ]
}