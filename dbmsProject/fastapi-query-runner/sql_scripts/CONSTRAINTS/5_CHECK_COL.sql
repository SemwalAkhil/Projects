-- CHECK IS A TABLE & COLUMN LEVEL CONSTRAINT;
-- COLUMN LEVEL SYNTAX;
-- CREATE TABLE table_name (col1 datatype, col2 datatype CHECK condition, ...);
CREATE TABLE students (rollno INT(4) CHECK (rollno > 3) , sname VARCHAR(10));
INSERT INTO students (rollno,sname) VALUES (4,'a');
INSERT INTO students (rollno,sname) VALUES (2,'b');
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL

