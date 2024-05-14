const Todo = require("../models/Todo"); // Import Todo model

exports.createTodo = async (req, res) => {
  try {
    const { title, description } = req.body; // Destructure title and description from req.body
    const response = await Todo.create({ title, description }); // Create new todo object and save to database
    res.status(200).json({
      // Send success response to client if the todo is created successfully
      success: true,
      data: response,
      message: "yay, entry created successfully",
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo creation process failed
      success: false,
      data: err.message,
      message: "oops, entry creation failed",
    });
  }
};

exports.deleteTodo = async (req, res) => {
  try {
    const id = req.params.id; // Fetch todo id from request params
    const response = await Todo.findByIdAndDelete({ _id: id }); // Delete todo by id from database
    if (!response) {
      //no todo found with the given id
      res.status(404).json({
        success: false,
        message: `oops, entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is deleted successfully
      success: true,
      data: response,
      message: `yay, entry for id ${id} deleted successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo deleting process failed
      success: false,
      data: err.message,
      message: "oops, entry deleting failed",
    });
  }
};

exports.getTodos = async (req, res) => {
  try {
    const response = await Todo.find(); // Fetch all todos from database
    res.status(200).json({
      // Send success response to client if the todos are fetched successfully
      success: true,
      data: response,
      message: "yay, entries fetched successfully",
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todos fetching process failed
      success: false,
      data: err.message,
      message: "oops, entries fetching failed",
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
        message: `oops, entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is fetched successfully
      success: true,
      data: response,
      message: `yay, entry for id ${id} fetched successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo fetching process failed
      success: false,
      data: err.message,
      message: "oops, entry fetching failed",
    });
  }
};

exports.updateTodo = async (req, res) => {
  try {
    const id = req.params.id; // Fetch todo id from request params
    const { title, description } = req.body; // Destructure title and description from req.body
    const response = await Todo.findByIdAndUpdate(
      { _id: id },
      { title, description, updateAt: Date.now() }
    ); // Update todo by id from database
    if (!response) {
      //no todo found with the given id
      res.status(404).json({
        success: false,
        message: `oops, entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is updated successfully
      success: true,
      data: response,
      message: `yay, entry for id ${id} updated successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo updating process failed
      success: false,
      data: err.message,
      message: "oops, entry updating failed",
    });
  }
};
