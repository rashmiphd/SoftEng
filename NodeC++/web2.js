var http = require('http');


const fs = require('fs');

let txtFile = "sensorlog.txt";
let str = fs.readFileSync(txtFile,'utf8');
var a=str.split(',')

var newa=[];

//a.forEach(function(item, index, array) 
//{
//  console.log(item, index);
  
//});
newa.push({
	"Temperature":a[0],
	"Humidity":a[1],
    "Windspeed":a[2],
	"Time":a[3],
	"Location":a[4]
	});
	
		
	newa.forEach(function(item, index, array) {
    console.log(item, index);
});

var jsonString= JSON.stringify(newa);
   console.log(jsonString)

function handle_incoming_request (req, res) {

    console.log("INCOMING REQUEST: " + req.method + " " + req.url);
	
	load_sensor_data(function(err, readings){

    if (err) { 

       console.log("Couldn't read file");

    }

    console.log(readings);

    res.writeHead(200, { "Content-Type" : "application/json" });

    res.end(JSON.stringify(newa));

    
	});

}

function load_sensor_data(callback) {

   fs.readFile(

   "sensorlog.txt",'utf8',

   function (err, readings) {

   if (err) {

   callback(err);

return;



}

callback(null, readings);

}

);

}

var s = http.createServer(handle_incoming_request);

s.listen(8080);
