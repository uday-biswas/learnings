const express = require("express");
const router = express.Router();

const {
  createTodo,
  getTodos,
  getTodoById,
  updateTodo,
  deleteTodo,
} = require("../controllers/todoController"); // Import todoController

router.post("/createTodo", createTodo); // defined route with controller
router.get("/getTodos", getTodos); // defined route with controller
router.get("/getTodos/:id", getTodoById); // defined route with controller
router.put("/updateTodo/:id", updateTodo); // defined route with controller
router.delete("/deleteTodo/:id", deleteTodo); // defined route with controller

module.exports = router; // Export router
