SELECT avg(energy) FROM songs 
WHERE artist_id = (SELECT id from artists WHERE name = 'Drake');