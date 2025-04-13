-- UPDATE table_name SET column1=value1, column2=value2 (WHERE condition)
-- condition is optional
UPDATE students SET sname='z';
UPDATE students SET sname='b' WHERE rollno=2;
UPDATE students SET rollno=5,sname='c' WHERE rollno=3;