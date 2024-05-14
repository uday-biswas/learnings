const Todo = require("../models/Todo"); // Import Todo model

exports.deleteTodo = async (req, res) => {
  try {
    const id = req.params.id; // Fetch todo id from request params
    const response = await Todo.findByIdAndDelete({ _id: id }); // Delete todo by id from database
    if (!response) {
      //no todo found with the given id
      res.status(404).json({
        success: false,
        message: `entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is deleted successfully
      success: true,
      data: response,
      message: `entry for id ${id} deleted successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo deleting process failed
      success: false,
      data: err.message,
      message: "entry deleting failed",
    });
  }
};
