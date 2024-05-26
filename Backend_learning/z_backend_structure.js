//learning backend
//firstly create folder and open in vs code and open terminal and type 'npm init -y' to create package.json file
//then install express by typing 'npm install express' in terminal
//then create server.js file and write code in it

//example content of server.js file
const express = require("express"); //importing express
const app = express(); //creating express app

const bodyParser = require("body-parser"); //importing body-parser to parse data from client
app.use(bodyParser.json()); //using body-parser to parse json data and store in req.body

//listen is used to create server, it takes two parameters 1.port 2.callback function
//callback function is used to print message on console when server is started.
app.listen(3000, () => {
  //creating server on port 3000 and printing message on console
  console.log("server started");
});

//then type 'node server.js' in terminal to run the server
//now to automate the server we use nodemon, to install nodemon type 'npm install nodemon' in terminal
//now update package.json file by updating "scripts" object
// "scripts": {
//     "start": "node server.js",
//     "dev": "nodemon server.js"
//   },
//now type 'npm run dev' in terminal to run the server

//the http methods are get,post,put,delete (crud operations)

//get method is used to get data from server, it takes two parameters 1.path 2.callback function
//callback function is used to send response to client
app.get("/", (request, response) => {
  response.send("hello jii");
});

//post method is used to send data to server, it takes two parameters 1.path 2.callback function
app.post("/api/cars", (request, response) => {
  const { name, price } = request.body; //destructuring data from request.body
  console.log(name, price);
  response.send("car added");
});

//mongoose is used to connect to mongodb database
//firstly install mongoose by typing 'npm install mongoose' in terminal
const mongoose = require("mongoose"); //importing mongoose to connect to mongodb database
mongoose
  .connect("mongodb://127.0.0.1:27017/profit", {
    //connecting to mongodb database
    useNewUrlParser: true,
    useUnifiedTopology: true,
  }) //this is promise based so we use then and catch
  .then(() => console.log("connected to mongodb successfully"))
  .catch((err) => console.log(`error occured ${err.message}`));
