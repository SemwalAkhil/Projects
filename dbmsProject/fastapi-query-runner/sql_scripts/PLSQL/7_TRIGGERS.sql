CREATE TABLE employees (
  emp_id NUMBER PRIMARY KEY,
  sname VARCHAR2(50),
  salary NUMBER
);

CREATE OR REPLACE TRIGGER salary_check 
BEFORE INSERT OR UPDATE ON employees 
FOR EACH ROW 
BEGIN
  IF :NEW.salary < 0 THEN
    RAISE_APPLICATION_ERROR(-20001, 'Salary cannot be negative');
  END IF;
END;
/

INSERT INTO employees (emp_id, sname, salary) VALUES (1, 'Alice', 50000);
INSERT INTO employees (emp_id, sname, salary) VALUES (2, 'Bob', -1000);
