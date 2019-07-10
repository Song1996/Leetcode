SELECT min_date AS login_date, count(DISTINCT user_id) AS user_count
FROM (
SELECT user_id, min(activity_date) as min_date
FROM Traffic
WHERE activity = "login"
GROUP BY user_id
) tmp
WHERE min_date >= "2019-06-30" - interval 90 day
GROUP BY min_date;
