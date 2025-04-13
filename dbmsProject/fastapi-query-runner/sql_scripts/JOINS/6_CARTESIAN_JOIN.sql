-- Every combination of rows from employees × departments.
-- MYSQL syntax
-- SELECT columns FROM table1 CROSS JOIN table2
-- (CROSS JOIN KEYWORD IS OPTIONAL)

-- Create departments table
CREATE TABLE departments (
  dept_id INT PRIMARY KEY,
  dept_name VARCHAR(50)
);

-- Insert rows into departments
INSERT INTO departments (dept_id, dept_name) VALUES
(10, 'HR'),
(20, 'Engineering'),
(40, 'Marketing');

-- Create employees table
CREATE TABLE employees (
  emp_id INT PRIMARY KEY,
  name VARCHAR(50),
  dept_id INT
);

-- Insert rows into employees
INSERT INTO employees (emp_id, name, dept_id) VALUES
(1, 'Alice', 10),
(2, 'Bob', 20),
(3, 'Charlie', 30);

SELECT e.name, d.dept_name FROM employees AS e, departments AS d;

DROP TABLE departments;
DROP TABLE employees;