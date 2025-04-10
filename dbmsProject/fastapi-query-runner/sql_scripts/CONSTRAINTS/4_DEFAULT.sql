-- DEFAULT IS A COLUMN LEVEL CONSTRAINT;
-- CREATE TABLE table_name (col1 datatype, col2 datatype NOT DEFAULT, ...);
CREATE TABLE students (rollno INT(4), sname VARCHAR(10) DEFAULT 'X');
INSERT INTO students (rollno,sname) VALUES (1,'a');
INSERT INTO students (rollno) VALUES (1);
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL