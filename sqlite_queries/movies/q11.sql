SELECT  DISTINCT m.title from movies m
JOIN stars s ON m.id = s.movie_id
JOIN ratings r ON m.id = r.movie_id
JOIN people p on p.id = s.person_id
WHERE  p.name = 'Chadwick Boseman'
ORDER by r.rating DESC
LIMIT 5;