const Todo = require("../models/Todo"); // Import Todo model

exports.createTodo = async (req, res) => {
  try {
    const { title, description } = req.body; // Destructure title and description from req.body
    const response = await Todo.create({ title, description }); // Create new todo object and save to database
    res.status(200).json({
      // Send success response to client if the todo is created successfully
      success: true,
      data: response,
      message: "entry created successfully",
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo creation process failed
      success: false,
      data: err.message,
      message: "entry creation failed",
    });
  }
};
