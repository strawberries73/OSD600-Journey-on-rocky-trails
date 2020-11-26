How to use and set up

Important:  You must have node installed for this to run

Steps:

1. Clone repository
2. Install project dependencies:

npm install
npm install node-fetch
npm install colors
Run command: node index.js argv.html

3. Formatting using [prettier](https://prettier.io/):

run npm run prettier        -> will auto fomat all the code in project. 
run npm run prettier-check  -> will check are all files match the Prettier code style. 
If you prefer to ignore certain files for prettier, add file in the '.prettierignore' file.

4. Formatting using [Linter](https://eslint.org/)

run npm run eslint for checking any linter problem you need to fix before a commit.
If you want to ignore certain files for prettier, add the file in the '.eslintignore' file.

IDE Integration:

Prettier and Linter automatically work when you save files. 
NOTE: If you notice that prettier and linter are not working, 
please check install the recommendation extentions 'Prettier' and 'linter'.
