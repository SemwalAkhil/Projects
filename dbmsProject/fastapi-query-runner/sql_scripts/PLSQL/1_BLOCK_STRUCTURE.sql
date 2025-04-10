DECLARE
  v_name VARCHAR2(50);
  v_message VARCHAR2(100);

BEGIN
  v_name := 'Alice';
  v_message := 'Hello, ' || v_name || '! Welcome to PL/SQL.';

  DBMS_OUTPUT.PUT_LINE(v_message);

EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END;
