-- PRIMARY KEY IS A TABLE & COLUMN LEVEL CONSTRAINT
-- TABLE LEVEL SYNTAX
-- CREATE TABLE table_name (col1 datatype, col2 datatype, ..., PRIMARY KEY (col1, col2, ...))
CREATE TABLE students (rollno INT(4), sname VARCHAR(10), PRIMARY KEY(rollno));
INSERT INTO students (rollno,sname) VALUES (1,'a');
INSERT INTO students (rollno,sname) VALUES (1,'b');
-- FIRST INSERTION SUCCESSFULL SECOND WILL FAIL