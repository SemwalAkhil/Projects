CREATE OR REPLACE FUNCTION calculate_bonus (p_salary NUMBER) 
RETURN NUMBER 
IS
  v_bonus NUMBER;
BEGIN
  IF p_salary > 50000 THEN
    v_bonus := p_salary * 0.1;
  ELSE
    v_bonus := p_salary * 0.05;
  END IF;
  RETURN v_bonus;
END;
/

DECLARE
  v_emp_salary NUMBER := 60000;
  v_emp_bonus NUMBER;
BEGIN
  v_emp_bonus := calculate_bonus(v_emp_salary);
  DBMS_OUTPUT.PUT_LINE('Bonus for salary ' || v_emp_salary || ' is ' || v_emp_bonus);
END;
