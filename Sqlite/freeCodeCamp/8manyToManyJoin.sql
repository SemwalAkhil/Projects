INSERT INTO User (name,Email) VALUES ('Jane','jane@tsugi.org');
INSERT INTO User (name,Email) VALUES ('Ed','ed@tsugi.org');
INSERT INTO User (name,Email) VALUES ('Sue','sue@tsugi.org');

INSERT INTO Course (title) VALUES ('Python') ;
INSERT INTO Course (title) VALUES ('SQL') ;
INSERT INTO Course (title) VALUES ('PHP') ;

INSERT INTO Member (user_id,course_id,role) VALUES (1,1,1) ;
INSERT INTO Member (user_id,course_id,role) VALUES (2,1,0) ;
INSERT INTO Member (user_id,course_id,role) VALUES (3,1,0) ;

INSERT INTO Member (user_id,course_id,role) VALUES (1,2,0) ;
INSERT INTO Member (user_id,course_id,role) VALUES (2,2,1) ;

INSERT INTO Member (user_id,course_id,role) VALUES (2,3,1) ;
INSERT INTO Member (user_id,course_id,role) VALUES (3,3,0) ;

SELECT User.Name,Member.role,Course.title FROM User JOIN Member JOIN Course ON User.Id = Member.user_id AND Course.id = Member.course_id ORDER BY Course.title,Member.role,User.Name;