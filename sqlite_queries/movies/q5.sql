SELECT DISTINCT m.title,m.year from movies m
JOIN stars s ON m.id = s.movie_id
where m.title LIKE 'Harry Potter%'
ORDER by m.year