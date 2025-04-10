-- UNIQUE IS A TABLE & COLUMN LEVEL CONSTRAINT;
-- COLUMN LEVEL SYNTAX;
-- CREATE TABLE table_name (col1 datatype, col2 datatype UNIQUE, ...);
CREATE TABLE students (rollno INT(4) UNIQUE, sname VARCHAR(10));
INSERT INTO students (rollno,sname) VALUES (1,'a');
INSERT INTO students (rollno,sname) VALUES (1,'b');
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL

