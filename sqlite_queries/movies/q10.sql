SELECT  DISTINCT p.name from movies m
JOIN directors d ON m.id = d.movie_id
JOIN people p on p.id = d.person_id
JOIN ratings r on r.movie_id = m.id
WHERE rating >= 9.0

