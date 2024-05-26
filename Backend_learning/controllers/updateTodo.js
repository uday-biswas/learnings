const Todo = require("../models/Todo"); // Import Todo model

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
        message: `entry for id ${id} not found`,
      });
    }
    res.status(200).json({
      // Send success response to client if the todo is updated successfully
      success: true,
      data: response,
      message: `entry for id ${id} updated successfully`,
    });
  } catch (err) {
    console.log(err);
    res.status(500).json({
      // Send error response to client if the todo updating process failed
      success: false,
      data: err.message,
      message: "entry updating failed",
    });
  }
};
