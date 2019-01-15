This question asks us to get the median of two sorted arrays with O(log(m+n)).
It's obvious that it wants us to use Binart search to find the target.
But the formal parameters it gives us are two vector instead of two arrays, so we have to make some change.
With the iterator taking the place of pointer, we might deal the problem successfully.
