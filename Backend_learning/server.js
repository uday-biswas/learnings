const express = require("express");
const app = express();

require("dotenv").config(); //importing dotenv to use environment variables from .env file and storing in process.env
const port = process.env.PORT || 4000;

app.use(express.json()); //middleware to parse json data from client

const todoRoutes = require("./routes/todos"); // Import todo routes
app.use("/api/v1", todoRoutes); // mount the todo routes on /api/v1

const dbConnect = require("./config/database");
dbConnect();

app.listen(port, () => {
  console.log(`server started on port ${port}`);
});

app.get("/", (req, res) => {
  res.send("<h3>hello jii , welcome to my server<h3>");
});
