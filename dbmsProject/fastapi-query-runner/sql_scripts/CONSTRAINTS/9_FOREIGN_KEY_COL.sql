-- FOREIGN KEY IS A TABLE & COLUMN LEVEL CONSTRAINT;
-- COLUMN LEVEL SYNTAX;
-- CREATE TABLE table_name (col1 datatype, col2 datatype REFERENCES parent_table(col_name), ...);
CREATE TABLE student_copy (rollno INT(4) REFERENCES students(rollno),sname VARCHAR(10));
INSERT INTO student_copy (rollno,sname) VALUES (1,'a');
INSERT INTO student_copy (rollno,sname) VALUES (1,'b');
INSERT INTO student_copy (rollno,sname) VALUES (10,'c');
-- FIRST, SECOND INSERTION SUCCESSFULL THIRD WILL FAIL

