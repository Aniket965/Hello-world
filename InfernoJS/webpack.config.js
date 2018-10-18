const webpack = require('webpack');
const CleanWebpackPlugin = require('clean-webpack-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
	mode: "none", 											// Can be changed to 'development' or 'production' to have separate dev or prod build configs
	entry: "./src/index.tsx", 								// Point to main file
	output: {
		path: __dirname + "/dist",
		filename: "bundle.js"
	},
	resolve: {
		extensions: ['.js', '.jsx', '.ts', '.tsx']
	},
	performance: {
		hints: false
	},
	module: {
		rules: [
			{
				test: /\.scss$/,
				use: [
					"style-loader", 						// creates style nodes from JS strings
					"css-loader", 							// translates CSS into CommonJS
					"sass-loader" 							// compiles Sass to CSS, using Node Sass by default
				]
			},
			{
				test: /\.css$/,
				use: [
					"style-loader", 						// creates style nodes from JS strings
					"css-loader"							// translates CSS into CommonJS
				]
			},
			{
				test: /\.tsx?$/, 						  	// All ts and tsx files will be process by
				use: ['babel-loader', 'ts-loader'], 		// first babel-loader, then ts-loader
				exclude: /node_modules/                  	// ignore node_modules
			}, {
				test: /\.jsx?$/,                          	// all js and jsx files will be processed by
				use: 'babel-loader',                  		// babel-loader
				exclude: /node_modules/                  	// ignore node_modules
			}
		]
	},
	devServer: {
		contentBase: "src/",
		historyApiFallback: true
	},
	plugins: [
		new HtmlWebpackPlugin(
			{
				template: "./src/index.html",
				inject: "body"
			}
		),
		new CleanWebpackPlugin(
			["dist"], {
				verbose: true
			}
		),
		new webpack.HotModuleReplacementPlugin()
	]
};
