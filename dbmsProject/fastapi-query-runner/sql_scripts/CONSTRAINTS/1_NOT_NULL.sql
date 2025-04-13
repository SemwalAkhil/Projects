-- NOT NULL IS A COLUMN LEVEL CONSTRAINT
-- CREATE TABLE table_name (col1 datatype, col2 datatype NOT NULL, ...)
CREATE TABLE students (rollno INT(4), sname VARCHAR(10) NOT NULL);
INSERT INTO students (rollno,sname) VALUES (1,'a');
INSERT INTO students (rollno,sname) VALUES (1,NULL);
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL