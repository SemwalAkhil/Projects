DECLARE
  c_tax_rate CONSTANT NUMBER := 0.18;


  v_price       NUMBER := 1000;    
  v_tax_amount  NUMBER;
  v_total_price NUMBER;

BEGIN
  v_tax_amount := v_price * c_tax_rate;

  v_total_price := v_price + v_tax_amount;

  DBMS_OUTPUT.PUT_LINE('Original Price : ' || v_price);
  DBMS_OUTPUT.PUT_LINE('Tax Rate       : ' || (c_tax_rate * 100) || '%');
  DBMS_OUTPUT.PUT_LINE('Tax Amount     : ' || v_tax_amount);
  DBMS_OUTPUT.PUT_LINE('Total Price    : ' || v_total_price);

EXCEPTION
  WHEN OTHERS THEN
    DBMS_OUTPUT.PUT_LINE('An error occurred: ' || SQLERRM);
END;
