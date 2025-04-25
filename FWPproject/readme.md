# Your To Do - Task Management App

A lightweight, browser-based task management application that helps you organize your daily tasks with deadline tracking.

## Project Overview

"Your To Do" is a simple to-do list web application developed as a practical project for the Fundamentals of Web Programming course. It uses vanilla JavaScript, HTML, and CSS, with browser localStorage for data persistence.

## Features

- **User Account System**: Create an account with username and password
- **Task Management**: Add, edit, and delete tasks
- **Deadline Tracking**: Visual indicators for approaching and missed deadlines
- **Responsive Design**: Works across different screen sizes
- **Profile Management**: View pending tasks and delete account if needed

## Installation

1. Clone or download the repository to your local machine:
   ```
   git clone [repository-url]
   ```
   
2. No additional dependencies or installations required

3. For proper functionality, use VS Code with Live Server extension:
   - Install [Visual Studio Code](https://code.visualstudio.com/)
   - Install the [Live Server extension](https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer)
   - Right-click on `index.html` and select "Open with Live Server"

## Usage

1. **Start at the login page (index.html)**:
   - Create a new account by entering a username and password
   - If returning, enter your existing credentials

2. **Main Dashboard**:
   - View all your existing tasks
   - Click the '+' button to add new tasks
   - Tasks approaching deadlines will pulse with a warning color
   - Overdue tasks will be marked in red

3. **Task Management**:
   - Add tasks with specific deadlines
   - Mark tasks as complete by checking the checkbox
   - Delete tasks using the 'X' button
   - Edit tasks by clicking the settings icon

4. **Profile Management**:
   - View your username and number of pending tasks
   - Delete your account if needed

## Important Notes

- Avoid using special characters, especially commas (,) and forward slashes (/) in tasks as they are used as delimiters in the storage system
- Data is stored in the browser's localStorage, so clearing browser data will remove all tasks and accounts
- The application works best when launched with VS Code Live Server

## Project Structure

- `index.html` - Login page
- `main.html` - Main dashboard with task list
- `list.html` - Add or edit tasks
- `profile.html` - User profile page
- `index.js` - Application logic
- `index.css` - Styling for all pages
- `assets/` - Images and icons

## Contributors

- Akhil Semwal (4033/23 BCA-I Semester-2 PGGC-11)

## Course Information

Developed for Fundamentals of Web Programming, Post Graduate Government College-11.