SELECT  p.name from movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p on p.id = s.person_id
WHERE  m.title = 'Toy Story'
