INSERT INTO Artist (name) VALUES ("Led Zepplin") ;
INSERT INTO Artist (name) VALUES ("AC/DC") ;

INSERT INTO Genre (name) VALUES ("Rock") ;
INSERT INTO Genre (name) VALUES ("Metal") ;

INSERT INTO Album (Title,ArtistId) VALUES ("Who Made Who",2) ;
INSERT INTO Album (Title,ArtistId) VALUES ("IV",1) ;

INSERT INTO Track (Title,Rating,Length,Count,AlbumId,GenereId) VALUES ("Black Dog",5,297,0,2,1) ;
INSERT INTO Track (Title,Rating,Length,Count,AlbumId,GenereId) VALUES ("Stairway",5,482,0,2,1) ;
INSERT INTO Track (Title,Rating,Length,Count,AlbumId,GenereId) VALUES ("About to Rock",5,313,0,1,2) ;
INSERT INTO Track (Title,Rating,Length,Count,AlbumId,GenereId) VALUES ("Who Made Who",5,207,0,1,2) ;

SELECT Album.Title,Artist.Name FROM Album JOIN Artist ON Album.ArtistId = Artist.Id ;
SELECT Album.Title,Album.ArtistId,Artist.Id,Artist.Name FROM Album JOIN Artist ON Album.ArtistId = Artist.Id ;
SELECT Track.Title,Track.GenereId,Genre.Id,Genre.name FROM Track JOIN Genre ;
SELECT Track.Title,Track.GenereId,Genre.Id,Genre.name FROM Track JOIN Genre ON Track.GenereId = Genre.Id ;
SELECT Track.Title,Artist.Name,Track.AlbumId,Album.Id,Album.Title,Album.ArtistId,Artist.Id,Genre.Name,Genre.Id,Track.GenereId FROM Track JOIN Genre JOIN Album JOIN Artist ON Track.GenereId=Genre.Id AND Track.AlbumId=Album.Id AND Album.ArtistId = Artist.Id ;