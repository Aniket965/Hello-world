/* Run me with `node pull-request-tutorial.js` */
const readline = require("readline");

const terminal = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const askName = () => {
  return new Promise((resolve, reject) => {
    terminal.question("What is your name?: ", name => {
      console.log(
        `Hi ${name}, you're going to learn how to make a pull request.\n`
      );
      resolve(name);
    });
  });
};

const instruction1 = name => {
  return new Promise((resolve, reject) => {
    console.log(
      'First, you need to fork the repository you want to contribute to by pressing\n' +
      `the 'Fork' button at the top-right of the repository's GitHub page. Try that now, ${name}.` +
      '\n\n[Press enter to continue]'
    );

    terminal.on("line", () => {
      resolve();
    });
  });
};

const instruction2 = name => {
  return new Promise((resolve, reject) => {
    console.log(
      'Next, clone your newly forked repository to your computer. To do this click the green\n' +
      `'Clone or download' button on your newly forked repository on GitHub, then copy the link text.\n` +
      `Now open your terminal and type 'git clone' and paste in the repository link.\n` +
      'Example: git clone https://github.com/Hacktoberfest-2018/Hello-world.git' +
      `\n\n[Hit that return key, ${name}]`
    );

    terminal.on("line", () => {
      resolve();
    });
  });
};

const instruction3 = name => {
  return new Promise((resolve, reject) => {
    console.log(
      'Make the code changes you want to, but be sure to adhere to the standards and guidelines\n' +
      `of the repository you're contributing to, ${name}. Then use 'git add' to stage your changes\n` +
      `and 'git commit' to commit your changes with a useful message. Now push your changes\n` +
      `using 'git push -u origin <BRANCH_NAME>\n` +
      'Example: git push -u origin master' +
      '\n\n[Mix it up, press the enter key on the number pad 😲 ]'
    );

    terminal.on("line", () => {
      resolve();
    });
  });
};

const instruction4 = name => {
  return new Promise((resolve, reject) => {
    console.log(
      `Now your changes are pushed to your forked repository, it's time to make your pull request!\n` +
      `Go to your forked repository on GitHub in your browser, and click the 'New pull request' button.\n` +
      `Now click the big, green 'Create pull request' button.` +
      `\n\n[Almost there now ${name}, tap enter!]`
    );

    terminal.on("line", () => {
      resolve();
    });
  });
};

const instruction5 = name => {
  return new Promise((resolve, reject) => {
    console.log(
      `Finally, give your pull request a descriptive title, and describe it using the text box.\n` +
      `Now press the green 'Create pull request' button.` +
      `\n\n[Last time, give it some welly! 😤 ]`
    );

    terminal.on("line", () => {
      resolve();
    });
  });
};

const main = async () => {
  let name = await askName();
  await instruction1(name);
  await instruction2(name);
  await instruction3(name);
  await instruction4(name);
  await instruction5(name);
  console.log(`💚 💚 💚 💚  You made a pull request! Well done, ${name}!  💚 💚 💚 💚`);
  terminal.close();
};

main();
