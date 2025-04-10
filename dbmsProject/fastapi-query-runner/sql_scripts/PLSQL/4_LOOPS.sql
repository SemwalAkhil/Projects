DECLARE
  v_counter NUMBER := 1;
  v_max_limit NUMBER := 5;

BEGIN
  LOOP
    EXIT WHEN v_counter > v_max_limit;
    DBMS_OUTPUT.PUT_LINE('Iteration: ' || v_counter);
    v_counter := v_counter + 1;
  END LOOP;
END;
