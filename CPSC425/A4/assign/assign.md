# Assignment 4
Julian Mentasti e0q1b 90772385

# Question 3

![](https://i.imgur.com/9dpy2OQ.jpg)

## Note: I changed the colours of the lines to make it easier to trace each distinct line.


I chose the threshold 0.65 because it produced 22 points with a high probability (>0.95) that a match is correct. I created table 1.0 to compare the different thresholds I used and their respective matches and outliers. If I chose a threshold of 0.70 I would get an increase of 0.18% in matches produced but that would mean that my accuracy rate decreased to bellow 0.90. Its very important for these points to be accurate because if we chose a threshold that was too high we would be eliminating perfectly good matches and if we picked a threshold value that was too low then all our valid matches would be overrun by false positives which when we checked our points though the RANSAC algorithm could result in a higher chance of getting an invalid fitting with a large number of samples. This is because RANSAC could randomly select an outlier and use it as a sample which would cause a greater amount of poor results.  


_table 1.0_
| Threshold  | Outliers | Inliers | Total Points |  Accuracy % (Inliers/Total) |  Growth (Current Total/Previous Total) |
|------------|----------|---------|--------------|-----------------------------|----------------------------------------|
| 0.60       | 0        | 18      | 18           | 1.00                        | -                                      |
| 0.65       | 1        | 21      | 22           | 0.9545                      | 0.22%                                  |
| 0.70       | 3        | 23      | 36           | 0.8846                      | 0.18%                                  |
| 0.75       | 6        | 28      | 34           | 0.8235                      | 0.307%                                 |
| 0.80       | 13       | 30      | 43           | 0.6978                      | 0.20%                                  |

# Question 4

![](https://i.imgur.com/2gMzaSi.jpg)

Angle match bound: +/- 18 degrees (pi/10)
Size scale bound: 0.95
Number of matches found: 37

When we do consistency checking we are able to compare different matches in terms of their orientation and their scale thus we are able to measure and best of all decide if the given matches are compatible based on a threshold. We can increase this threshold if we use RANSAC because it will eliminate any false positives that where not caught by the original threshold. Thus we know that the resulting set of matches we have will be be consistent - enabling us to try to get as many matches as possible while being able to remain highly accurate.
