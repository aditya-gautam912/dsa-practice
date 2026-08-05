import pytest
from solution_maximum_subarray import Solution


@pytest.fixture
def solution():
    return Solution()


def test_example_1(solution):
    assert solution.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6


def test_example_2(solution):
    assert solution.maxSubArray([1]) == 1


def test_example_3(solution):
    assert solution.maxSubArray([5, 4, -1, 7, 8]) == 23


def test_all_negative(solution):
    assert solution.maxSubArray([-1, -2, -3]) == -1


def test_all_positive(solution):
    assert solution.maxSubArray([1, 2, 3, 4]) == 10


def test_zero_included(solution):
    assert solution.maxSubArray([-2, 0, -1]) == 0


def test_peak_in_middle(solution):
    assert solution.maxSubArray([-1, 3, -2, 4, -5]) == 5
