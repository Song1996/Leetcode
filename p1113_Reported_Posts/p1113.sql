SELECT extra AS report_reason, count(DISTINCT post_id) AS report_count
FROM Actions
WHERE action_date = "2019-07-04" and action = "report"
GROUP BY extra;