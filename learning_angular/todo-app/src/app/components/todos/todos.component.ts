import { Component } from '@angular/core';
import { Todo } from '../../Todo';
import { CommonModule, NgFor } from '@angular/common';

@Component({
  selector: 'app-todos',
  standalone: true,
  imports: [NgFor, CommonModule],
  templateUrl: './todos.component.html',
  styleUrl: './todos.component.css'
})
export class TodosComponent {
  todos: Todo[];
  constructor() {
    this.todos = [
      {
        sno: 1,
        title: 'Todo One',
        desc: 'This is Todo One',
        active: true
      },
      {
        sno: 2,
        title: 'Todo Two',
        desc: 'This is Todo Two',
        active: true
      },
      {
        sno: 3,
        title: 'Todo Three',
        desc: 'This is Todo Three',
        active: true
      }
    ]
  }

}
