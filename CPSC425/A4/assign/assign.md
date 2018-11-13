# Assignment 4
Julian Mentasti e0q1b 90772385

# Question 3

[insert image]
# Note: I changed the colours of the lines to make it easier to trace each distinct line.


I chose the threshold 0.65 because it produced 22 points with a high probability (>0.95) that a match is correct. I created table 1.0 to compare the different thresholds I used and their respective matches and outliers. If I chose a threshold of 0.70 I would get an increase of 0.18% in matches produced but that would mean that my accuracy rate decreased to bellow 0.90. Its very important for these points to be accurate because TODO FINISH

| Threshold  | Outliers | Inliers | Total Points |  Accuracy % (Inliers/Total) |  Growth (Current Total/Previous Total) |
|------------|----------|---------|--------------|-----------------------------|----------------------------------------|
| 0.60       | 0        | 18      | 18           | 1.00                        | -                                      |
| 0.65       | 1        | 21      | 22           | 0.9545                      | 0.22%                                  |
| 0.70       | 3        | 23      | 36           | 0.8846                      | 0.18%                                  |
| 0.75       | 6        | 28      | 34           | 0.8235                      | 0.307%                                 |
| 0.80       | 13       | 30      | 43           | 0.6978                      | 0.20%                                  |
