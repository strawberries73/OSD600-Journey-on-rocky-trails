const fs=require("fs");
const fetch=require("node-fetch");
const path=require("path");
const packageJson = require("./package.json");
const colors = require("colors");

// ExitCode
process.on("SIGTERM", () => {
    server.close(() => {
      console.log("Program is terminated");
    });
  });

//Flag labeling each URL as a good or bad
const _label = ({
    good: "GOOD",
    bad: "BAD"
});

//const getTelescope = fetch('http:/') data
async function getTelescopeData() {
    //fetching data from local host
    const response = await fetch("http://localhost:3000/posts");
    const data = await response.json();

    fs.truncateSync("telescopeData.txt", 0);
    
    const postPromises = [];

    //truncate the data and write to file
    for (i = 0; i < data.length; i++) {
        const promise = fetch(`http://localhost:3000${data[i].url}`)
            .then(res => {
                return res.json();
            })
            .then(postObj => {
                return postObj.feed.url;
            });

        postPromises.push(promise);
    }

    const posts = await Promise.all(postPromises);

    fs.writeFileSync("telescopeData.txt", posts);
}

getTelescopeData(); //taking telescope URL data 

if(process.argv.length==2){
    console.log("Hello");
}
else {
    if (process.argv[2] == "v" || process.argv[2] == "version") {
        console.log(packageJson.name + " Version " + packageJson.version);
    } else {
        const filePath = path.join(__dirname, process.argv[2]);
        processLinks(filePath);
    }
}

async function processLinks(p_filePath) {
    let allGoodLinks = true;

    let data;
    try {
        data = fs.readFileSync(p_filePath, "utf-8");
    } catch (err) {
        console.log("Fail to read file", err);
        return;
    }

    const validUrl = data.match(/(http|https)(:\/\/)([\w+\-&@`~#$%^*.=/?:]+)/gi);

    // arr to store promises
    const urlPromises = [];

    validUrl.forEach(url => {
        // store each fetch call in arr
        const promise = fetch(url, { method: "HEAD", timeout: 2000 })
            .then((res) => {
                if (res.status == 200) {
                    console.log(res.status, url.green, _label.good.rainbow);
                }
                    
                if (res.status == 400 || res.status == 404) {
                    console.log(res.status, url)
                    .then.process(); //termination
                    allGoodLinks = false; 
                }
            })
            .catch((error) => {
                console.log("404", url.red, _label.bad.bgRed);
            });
        
        urlPromises.push(promise);
    });

    // run all fetch call promises
    const fetchResults = await Promise.all(urlPromises);

    return allGoodLinks;
}

module.exports = {
    processLinks
};
