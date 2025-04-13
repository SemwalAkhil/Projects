-- A Self Join is a regular join where a table is joined with itself.
-- It's useful when rows in the same table are related to each other — like employees and their managers.
-- SELECT A.column1, B.column2 FROM table_name AS A JOIN table_name AS B ON A.common_column = B.common_column

-- Create the employees table
CREATE TABLE employees (
  emp_id INT PRIMARY KEY,
  name VARCHAR(50),
  manager_id INT,
  FOREIGN KEY (manager_id) REFERENCES employees(emp_id)
);

-- Insert rows into employees table
INSERT INTO employees (emp_id, name, manager_id) VALUES
(1, 'Alice', NULL),
(2, 'Bob', 1),
(3, 'Charlie', 1),
(4, 'David', 2);

SELECT e.name AS employee, m.name AS manager FROM employees AS e LEFT JOIN employees AS m ON e.manager_id = m.emp_id;

DROP TABLE employees;