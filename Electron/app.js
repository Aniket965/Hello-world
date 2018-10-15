const { app, BrowserWindow } = require('electron');
const url = require('url');
const path = require('path');

let mainWindow;

app.on('ready', () => {
	mainWindow = new BrowserWindow({});
	mainWindow.loadURL(
		url.format({
			pathname: path.join(__dirname, 'index.html'),
			protocol: 'file:',
			slashes: true
		})
	);
});

process.env['APP_PATH'] = app.getAppPath();
