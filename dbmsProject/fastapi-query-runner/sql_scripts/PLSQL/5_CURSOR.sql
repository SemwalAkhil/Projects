CREATE TABLE employees (
  emp_id NUMBER PRIMARY KEY,
  name VARCHAR2(50),
  salary NUMBER(10, 2)
);
INSERT INTO employees (emp_id, name, salary) VALUES (1, 'Alice', 50000);
INSERT INTO employees (emp_id, name, salary) VALUES (2, 'Bob', 60000);
INSERT INTO employees (emp_id, name, salary) VALUES (3, 'Charlie', 55000);
DECLARE
  CURSOR emp_cursor IS
    SELECT emp_id, name, salary FROM employees;
  
  v_emp_id employees.emp_id%TYPE;
  v_name employees.name%TYPE;
  v_salary employees.salary%TYPE;

BEGIN
  OPEN emp_cursor;
  LOOP
    FETCH emp_cursor INTO v_emp_id, v_name, v_salary;
    EXIT WHEN emp_cursor%NOTFOUND;
    DBMS_OUTPUT.PUT_LINE('Employee ID: ' || v_emp_id || ' Name: ' || v_name || ' Salary: ' || v_salary);
  END LOOP;
  CLOSE emp_cursor;
END;
