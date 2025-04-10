DECLARE
  v_sales NUMBER := 1200;
  v_discount NUMBER;

BEGIN
  IF v_sales >= 1000 THEN
    v_discount := 0.1;
  ELSIF v_sales >= 500 THEN
    v_discount := 0.05;
  ELSE
    v_discount := 0;
  END IF;

  DBMS_OUTPUT.PUT_LINE('Sales Amount: ' || v_sales);
  DBMS_OUTPUT.PUT_LINE('Discount: ' || (v_discount * 100) || '%');
  DBMS_OUTPUT.PUT_LINE('Final Price: ' || (v_sales - (v_sales * v_discount)));
END;
