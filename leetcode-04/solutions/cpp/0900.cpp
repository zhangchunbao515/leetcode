class RLEIterator {
 public:
  RLEIterator(vector<int>& A) {
    index = 0;
    this->A = A;
  }

  int next(int n) {
    while (index < A.size() && A[index] < n) {
      n -= A[index];
      index += 2;
    }

    if (index >= A.size()) return -1;

    A[index] -= n;

    return A[index + 1];
  }

 private:
  int index;
  vector<int> A;
};