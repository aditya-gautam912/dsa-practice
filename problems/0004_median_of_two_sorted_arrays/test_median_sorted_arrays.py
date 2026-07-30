import pytest
from solution_median_sorted_arrays import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.findMedianSortedArrays([1, 3], [2]) == 2.0


def test_example_2(solution):
    assert solution.findMedianSortedArrays([1, 2], [3, 4]) == 2.5


def test_one_empty(solution):
    assert solution.findMedianSortedArrays([], [1]) == 1.0


def test_both_single(solution):
    assert solution.findMedianSortedArrays([1], [2]) == 1.5


def test_same_values(solution):
    assert solution.findMedianSortedArrays([1, 1], [1, 1]) == 1.0


def test_negative_numbers(solution):
    assert solution.findMedianSortedArrays([-5, 3, 6], [1, 4, 7, 9]) == 4.0


def test_uneven_lengths(solution):
    result = Solution().findMedianSortedArrays([1, 2, 3, 4, 5], [6, 7, 8, 9, 10, 11])
    assert result == 6.0
