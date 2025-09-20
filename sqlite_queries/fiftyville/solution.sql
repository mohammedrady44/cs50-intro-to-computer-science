--intial investigation to know the withness
SELECT * FROM crime_scene_reports
WHERE street = 'Humphrey Street' and day = 28
and month =7

--3 withness's transcripts
SELECT * FROM interviews where month = 7 and
day = 28 and transcript LIKE '%bakery%';


--info about destination
--(based on that third withness say that theif will take earliest(first) flight tomorrow (day29) 

SELECT f.id flight_id,a.city Origin,a_des.city as Destination FROM flights f 
JOIN airports a on a.id = f.origin_airport_id
JOIN airports a_des on 
a_des.id = f.destination_airport_id
WHERE month = 7 and day = 29
and a.city = 'Fiftyville'
ORDER by hour,minute
LIMIT 1 

--info about theif 
SELECT p.id,p.name,p.phone_number,p.passport_number,p.license_plate FROM bakery_security_logs bsl
JOIN people p on p.license_plate = bsl.license_plate
where month = 7 and
day = 28 and hour = 10 and minute BETWEEN 15 and 25 --within 10 minutes of theft
and activity = 'exit'
and p.id in (
    SELECT person_id FROM bank_accounts
    WHERE account_number in (
        SELECT account_number FROM atm_transactions
        where month = 7 and
        day = 28 and transaction_type = 'withdraw'
        and atm_location = 'Leggett Street'
    )
)
and p.phone_number in(

    SELECT caller from phone_calls WHERE
    duration < 60  and month = 7 and
    day = 28
)
and p.passport_number in(
    SELECT passport_number FROM passengers WHERE
    flight_id = 36 --as the result of the  info destination query
)

--info about acomplice
SELECT * from people
where phone_number =(
    SELECT receiver FROM phone_calls WHERE
    duration < 60  and month = 7 and
    day = 28 
    AND caller = '(367) 555-5533' --as the result of the info theif query   
)


