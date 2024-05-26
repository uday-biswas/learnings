//install mongoose firstly by typing 'npm install mongoose' in terminal
const mongoose = require("mongoose"); //importing mongoose to connect to mongodb database

//install dotenv by typing 'npm install dotenv' in terminal
require("dotenv").config(); //importing dotenv to use environment variables from .env file

const dbConnect = () => {
  //connecting to mongodb database
  mongoose
    .connect(process.env.DATABASE_URL, {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    })
    .then(() => console.log("connected to mongodb successfully"))
    .catch((err) => console.log(`error occured ${err.message}`));
};

module.exports = dbConnect; //exporting dbConnect function to use in server.js file
