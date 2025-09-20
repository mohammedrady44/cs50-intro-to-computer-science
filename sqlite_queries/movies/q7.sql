SELECT  m.title,rating from movies m
JOIN ratings r ON m.id = r.movie_id
where m.year = 2010 and rating is not NULL
ORDER by rating DESC,m.title