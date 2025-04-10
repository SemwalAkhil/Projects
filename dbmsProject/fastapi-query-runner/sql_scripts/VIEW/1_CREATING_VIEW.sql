-- CREATE VIEW view_name AS SELECT column1, column2 FROM table_name WHERE condition;
CREATE VIEW high_scorers AS SELECT name, (marks1 + marks2 + marks3 + marks4) AS total FROM marks WHERE ( marks1 + marks2 + marks3 + marks4 ) > 160;

SELECT * FROM high_scorers ORDER BY total;
