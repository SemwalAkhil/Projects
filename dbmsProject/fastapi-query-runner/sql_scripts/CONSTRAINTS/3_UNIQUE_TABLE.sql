-- UNIQUE IS A TABLE & COLUMN LEVEL CONSTRAINT
-- TABLE LEVEL SYNTAX
-- CREATE TABLE table_name (col1 datatype, col2 datatype, ..., UNIQUE (col1, col2, ...))
CREATE TABLE students (rollno INT(4), sname VARCHAR(10), UNIQUE(rollno));
INSERT INTO students (rollno,sname) VALUES (1,'a');
INSERT INTO students (rollno,sname) VALUES (1,'b');
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL