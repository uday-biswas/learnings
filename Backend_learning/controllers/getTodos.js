const Todo = require("../models/Todo"); // Import Todo model

exports.getTodos = async (req, res) => {
  try {
    const response = await Todo.find(); // Fetch all todos from database
    res.status(200).json({
      // Send success response to client if the todos are fetched successfully
      success: true,
      data: response,
      message: "entries fetched successfully",
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todos fetching process failed
      success: false,
      data: err.message,
      message: "entries fetching failed",
    });
  }
};

exports.getTodoById = async (req, res) => {
  try {
    const id = req.params.id; // Fetch todo id from request params
    const response = await Todo.findById({ _id: id }); // Fetch todo by id from database
    if (!response) {
      //no todo found with the given id
      res.status(404).json({
        success: false,
        message: `entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is fetched successfully
      success: true,
      data: response,
      message: `entry for id ${id} fetched successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo fetching process failed
      success: false,
      data: err.message,
      message: "entry fetching failed",
    });
  }
};
