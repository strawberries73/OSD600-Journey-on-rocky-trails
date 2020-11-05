const fs=require('fs')
const fetch=require('node-fetch')
const path=require('path')
const packageJson = require('./package.json');

console.log(process.argv)


//Flag labeling each URL as a good or bad
const _label = ({
    good: "GOOD",
    bad: "BAD"
})

// ExitCode
process.on('SIGTERM', () => {
    server.close(() => {
      console.log('Program is terminated')
    })
  })

if(process.argv.length == 2){
    greetingMessage();
    console.log("Hello");
}
else{ // more then 2

    if (process.argv[2] == "v" || process.argv[2] == "version") {
        console.log(packageJson.name + " Version " + packageJson.version);
    } else{
        const filePath=path.join(__dirname,process.argv[2])
        fs.readFile(filePath,'utf-8',(err,data)=>{
            if(err){
                console.log("Fail to read file",err)
            }
            else{
                const validUrl=data.match(/(http|https)(:\/\/)([\w+\-&@`~#$%^*.=/?:]+)/gi)
                validUrl.forEach((url)=>{
                fetch(url,{method:'HEAD',timeout:2000})
                .then((res)=>{
                    if(res.status==200)
                    console.log(res.status,url.green,_label.good.rainbow)
                    else if(res.status==400||res.status==404)
                    console.log(res.status,url)
                .then.process(); //Termination 
                    
                })
                .catch((error)=>{
                    console.log("404",url.red, _label.bad.bgRed)
                })
            })
            }
        })  
    }
}
// done
