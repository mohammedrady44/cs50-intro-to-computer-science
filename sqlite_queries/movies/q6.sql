SELECT  avg(rating) from movies m
JOIN ratings r ON m.id = r.movie_id
where m.year = 2012