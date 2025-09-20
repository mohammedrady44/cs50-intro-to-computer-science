SELECT  title from movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p on p.id = s.person_id
WHERE  p.name = 'Bradley Cooper' or p.name = 'Jennifer Lawrence'
GROUP by movie_id,title
HAVING count(person_id)>1
