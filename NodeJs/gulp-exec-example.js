var exec = require('child_process').exec;
 
gulp.task('task', function (cb) {
  exec('ping localhost', function (err, stdout, stderr) {
    console.log(stdout);
    console.log(stderr);
    console.log('Task executed successfully.');
    cb(err);
  });
})